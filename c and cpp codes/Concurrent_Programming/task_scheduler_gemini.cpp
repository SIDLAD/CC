#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <map>
#include <functional>
#include <vector>
#include <mutex>
#include <algorithm>
#include <sstream>

using namespace std;

// Use steady_clock for calculating durations, as it is monotonic.
using Clock = chrono::steady_clock;
using TimePoint = Clock::time_point;

condition_variable cond; 
mutex schedule_mu;
bool should_exit = false; // Signals the scheduler loop to stop.

// Task structure for the priority queue
struct Task {
    TimePoint time;
    function<void()> performTask;
    int id; // Unique ID for debugging and future cancellation
    
    // Greater operator for std::priority_queue (Min-Heap: earliest time at top)
    bool operator>(const Task& other) const {
        return time > other.time;
    }
};

// Use std::greater for a Min-Heap (earliest time at top)
priority_queue<Task, vector<Task>, greater<Task>> pq_tasks;

// Map to hold threads for explicit management (used mainly for shutdown joins)
map<int, thread> activeTasks;
mutex activeTasksMu;
int nextTaskId = 0;

int getNextTaskId() {
    lock_guard lock(activeTasksMu);
    return nextTaskId++;
}

/**
 * @brief Dispatches a task to a new thread for immediate execution.
 * * This thread is designed to be self-cleaning (removes its entry from activeTasks)
 * and is DETACHED to prevent std::terminate() when the thread object is destroyed.
 * * @param performTask The function to run in the new thread.
 */
void taskDispatcher(function<void()>&& performTask) {
    // Get a unique ID for the thread entry in the map
    int taskId = getNextTaskId();

    // The thread function runs the task and then removes its entry from the map.
    auto taskFn = [taskId, performTask = move(performTask)] () {
        performTask();
        
        // Self-cleaning: The thread removes its entry from the map after execution.
        lock_guard lock(activeTasksMu);
        // The thread has finished, and it was detached, so it is safe to erase the std::thread object.
        activeTasks.erase(taskId);
    };

    unique_lock lock(activeTasksMu);
    try {
        // 1. Create the thread object and insert it into the map
        auto it_success = activeTasks.emplace(taskId, thread(taskFn));
        
        // 2. Detach the thread immediately. This is the CRITICAL FIX.
        // Detaching tells the std::thread object that we are not responsible
        // for joining it, preventing std::terminate() when its destructor is called 
        // when we call activeTasks.erase() later.
        if (it_success.second && it_success.first->second.joinable()) {
            it_success.first->second.detach();
        } else {
             cerr << "Error: Could not emplace or thread was not joinable." << endl;
        }

    } catch (const system_error& e) {
        cerr << "Error starting thread for task " << taskId << ": " << e.what() << endl;
        // Clean up map entry if thread creation failed
        activeTasks.erase(taskId);
    }
}

/**
 * @brief The main loop of the scheduler thread.
 * * It manages the priority queue, waits for the next task time, and dispatches tasks.
 */
void taskScheduler() {
    unique_lock lock(schedule_mu);

    while (!should_exit || !pq_tasks.empty()) {
        if (pq_tasks.empty()) {
            cerr << "Scheduler waiting for new tasks or exit signal..." << endl;
            // Wait indefinitely until new tasks are added or should_exit is true
            cond.wait(lock, [&]() { return !pq_tasks.empty() || should_exit; });
            
            // Re-check exit condition after waking up
            if (should_exit && pq_tasks.empty()) {
                break; 
            }
        }

        // Get the next task without popping it yet
        TimePoint next_task_time = pq_tasks.top().time;
        TimePoint now = Clock::now();

        if (next_task_time <= now) {
            // Task is ready to run: pop it and dispatch
            // We use const_cast<Task&> to move the top element out of the const reference
            // provided by priority_queue::top(), which is safe since we pop immediately.
            Task task_to_run = move(const_cast<Task&>(pq_tasks.top()));
            pq_tasks.pop();
            
            cerr << "Dispatching task " << task_to_run.id << " (Worker ID: " << nextTaskId << ") for immediate execution." << endl;
            taskDispatcher(move(task_to_run.performTask));

            // Immediately loop to check the next task
        } else {
            // Task is in the future: calculate wait time
            auto wait_duration = next_task_time - now;

            cerr << "Waiting for " << chrono::duration_cast<chrono::milliseconds>(wait_duration).count() 
                 << "ms until next task (" << pq_tasks.top().id << ") is due." << endl;

            // Wait until the task is due, or until a new task is added (spurious wake-up)
            cond.wait_until(lock, next_task_time, [&]() {
                // The condition for waking up early is if a new task arrived 
                // AND that new task is scheduled sooner than the current one, OR if we need to exit.
                return should_exit || (!pq_tasks.empty() && pq_tasks.top().time < next_task_time);
            });
            
            if (should_exit) {
                break;
            }
            // If woken up early or timer expired, loop again to re-evaluate the queue.
        }
    }

    // Since all worker threads are detached, they will continue to run and clean up
    // their map entries. No need for complex joining logic here.
    cerr << "Scheduler thread is exiting. Active tasks will continue to run (detached)." << endl;
    lock.unlock(); // Release schedule_mu before returning.
}


int main() {
    cerr << "Starting task scheduler example." << endl;
    
    thread taskSchedulerThread {taskScheduler};

    // To add tasks, we must lock the schedule_mu mutex
    unique_lock lock(schedule_mu);

    TimePoint currentTime = Clock::now();
    
    // Task 1 will be ID 0, Task 2 will be ID 1, Task 3 will be ID 2.
    // The scheduler will process them in order: 1 (ID 1) -> 3 (ID 2) -> 0 (ID 0)

    // Add task 1: runs in 500ms
    TimePoint scheduledTime1 = currentTime + chrono::milliseconds(500);
    pq_tasks.emplace(Task{
        scheduledTime1,
        []() {
            // Add a slight delay to ensure the other tasks are submitted first.
            this_thread::sleep_for(chrono::milliseconds(10));
            cout << "[TASK 0] Hello World - 500ms" << endl;
        },
        getNextTaskId() // ID 0
    });
    
    // Add task 2: runs immediately
    TimePoint scheduledTime2 = currentTime;
    pq_tasks.emplace(Task{
        scheduledTime2,
        []() {
            cout << "[TASK 1] Immediate Execution" << endl;
        },
        getNextTaskId() // ID 1
    });
    
    // Add task 3: runs in 200ms (will jump ahead of task 1)
    TimePoint scheduledTime3 = currentTime + chrono::milliseconds(200);
    pq_tasks.emplace(Task{
        scheduledTime3,
        []() {
            cout << "[TASK 2] Early Bird - 200ms" << endl;
        },
        getNextTaskId() // ID 2
    });
    
    cerr << "3 tasks submitted. Notifying scheduler." << endl;
    // Notify the scheduler that new tasks are available
    cond.notify_one();
    lock.unlock(); // Release lock

    // Let the tasks run for a bit (e.g., 2 seconds)
    this_thread::sleep_for(chrono::seconds(2));
    
    // Signal the scheduler to exit
    lock.lock();
    should_exit = true;
    cond.notify_one();
    lock.unlock();

    // Wait for the scheduler thread to finish
    taskSchedulerThread.join();
    
    cerr << "Main thread exiting successfully." << endl;
    return 0;
}