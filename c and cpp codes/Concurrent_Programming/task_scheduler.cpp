#include<iostream>
#include<thread>
#include<condition_variable>
#include<queue>
#include<chrono>
#include<map>
#include<functional>
#include<vector>
#include<semaphore>

using namespace std;
condition_variable interruptScheduler_; // wait, notify
bool confirmInterruptScheduler = true; // run once post initialization

mutex schedule_mu;
bool isComplete = false;

struct Task {
    chrono::time_point<chrono::system_clock> time;
    function<void()> performTask;
    strong_ordering operator<=> (const Task& other) const {
        return (other.time <=> time);
    }
};

int getNextActiveTaskId() {
    static int activeTaskId = 0;
    return activeTaskId++;
}

priority_queue<
    Task
> pq_tasks;

map<int, thread> activeTasks;
vector<int> zombieTasks;
mutex activeAndZombieMu;

void interruptScheduler() {
    confirmInterruptScheduler = true;
    interruptScheduler_.notify_one();
}

void zombieReaper() {
    unique_lock lock(activeAndZombieMu);
    if(zombieTasks.empty())
        return;
    for(auto taskId: zombieTasks) {
        activeTasks[taskId].join();
        activeTasks.erase(taskId);
    }
    zombieTasks.clear();
}

void taskDispatcher(function<void()>&& performTask) {
    // unique_lock lock(activeTasksMu);
    unique_lock activeTaskLock(activeAndZombieMu);
    int activeTaskId = getNextActiveTaskId();

    auto taskFn = [activeTaskId, performTask] () {
        cerr << "Current time: " << chrono::high_resolution_clock::now() << endl;
        cerr << "Processing task" << endl << endl;
        performTask();
        struct callDestructor { // this destructor will be called before lock's destructor
            int activeTaskId;
            ~callDestructor() {
                unique_lock zombieTaskLock(activeAndZombieMu);
                zombieTasks.push_back(activeTaskId);
                interruptScheduler();
            }
        } _(activeTaskId);
    };
    activeTasks[activeTaskId] = thread(taskFn);
}

void taskScheduler() {
    vector<Task> taskList;
    unique_lock lock(schedule_mu); // confirmInterruptScheduler and pq_tasks
    while(activeTasks.size() or pq_tasks.size() or !isComplete) {
        cerr << "Current time: " << chrono::high_resolution_clock::now() << endl;
        cerr << "PQ TASKS SIZE " << pq_tasks.size() << endl;
        cerr << "IS COMPLETE " << isComplete << endl;
        cerr << endl;

        if(!confirmInterruptScheduler) {
            interruptScheduler_.wait(lock, [&]() {return confirmInterruptScheduler;});
            // this thread has to be woken up by other threads,
            // which can be either the main thread adding another task,
            // or its child thread waking it up telling it that it is time to pick up a task
        }
        confirmInterruptScheduler = false;
        

        zombieReaper();

        if(pq_tasks.empty())    
            continue;

        
        // check time to next task
        
        auto next_task = pq_tasks.top();
        if(next_task.time <= chrono::high_resolution_clock::now()) {
            pq_tasks.pop();
            // schedule the task to start now in a separate thread
            taskDispatcher(move(next_task.performTask));
        }
        else {
            // start a thread that is supposed to wake up this thread when the next task time arrives
            taskDispatcher(
                [time = next_task.time]() {
                    cerr << "This task is for going to sleep" << endl << endl;
                    this_thread::sleep_until(time);
                    unique_lock lock(schedule_mu);
                    interruptScheduler();
                }
            );
        }

        // in the next iteration, interruptScheduler will make sure that this thread relinquishes control of the mutex
    }
}

void scheduleNewTask(function<void()>&& task, optional<chrono::time_point<chrono::system_clock>> scheduledTime) {
    auto currentTime = chrono::high_resolution_clock::now();
    if(!scheduledTime) {
        scheduledTime = chrono::high_resolution_clock::now();
    }
    cerr << "Current Time: " << currentTime << endl;
    cerr << "Scheduled Time: " << scheduledTime.value() << endl;
    cerr << endl;
    unique_lock lock(schedule_mu);
    pq_tasks.emplace(
        scheduledTime.value(),
        move(task)
    );
    interruptScheduler();
}

int main() {
    thread taskSchedulerThread {taskScheduler};

    chrono::time_point<chrono::system_clock>
    currentTime = chrono::high_resolution_clock::now(),
    scheduledTime = currentTime + 20ms;
    // cerr << "Current Time: " << currentTime << endl;
    // cerr << "Scheduled Time: " << scheduledTime << endl;
    // cerr << endl;
    scheduleNewTask(
        []() {
            cout << "Hello World 1" << endl;
        },
        scheduledTime
    );

    scheduleNewTask(
        []() {
            cout << "Hello World 2" << endl;
        },
        scheduledTime
    );

    //=======
    isComplete = true;
    unique_lock lock(schedule_mu);
    interruptScheduler();
    lock.unlock();
    //=======

    taskSchedulerThread.join();
}