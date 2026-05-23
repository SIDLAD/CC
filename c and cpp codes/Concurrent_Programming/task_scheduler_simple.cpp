#include<queue>
#include<functional>
#include<condition_variable>
#include<thread>
#include<stdexcept>
#include<iostream>
using namespace std;

void atomicLog(string s) {
    static mutex logMu;
    lock_guard lock(logMu);
    cout << "[Log]: " << s << endl;
}

class Scheduler {
    queue<function<void()>> qTask;
    bool stop = false;
    condition_variable condition;
    mutex qMu; // condition + qTask + stop

    vector<thread> workerThreads;

    void dispatch() {
        while(true) {
            function<void()> task;
            {
                unique_lock lock(qMu);
                if(stop and qTask.empty()) return;

                if(qTask.empty()) {
                    condition.wait(lock,
                        [this]() {
                            return this->stop or this->qTask.size();
                        }
                    );
                }

                if(qTask.empty()) return;

                //qTask is not empty
                task = move(qTask.front());
                qTask.pop();
            }
            try {
                task();
                atomicLog("Task completed!");
            } catch(exception& e) {
                atomicLog("Task resulted in exception: " + string(e.what()));
            }
        } 
    }

    void initWorker() {
        workerThreads.emplace_back(
            &Scheduler::dispatch, this
        );
    }

public: 

    Scheduler(int num_workers = thread::hardware_concurrency()) {
        for(int worker=0;worker<num_workers;++worker) initWorker();
    }

    ~Scheduler() {
        {
            lock_guard lock(qMu);
            if(!stop) {
                stop = true;
                condition.notify_all();
            }
        }

        for(auto& thread: workerThreads) if(thread.joinable())
            thread.join();
    }

    void schedule(function<void()>&& task) {
        lock_guard lock(qMu);
        if(stop) throw runtime_error("Scheduler scheduled to stop, cannot schedule!");
        if(task) qTask.emplace(move(task));
        condition.notify_all();
    }

    void markStopped() {
        lock_guard lock(qMu);
        stop = true;
        condition.notify_all();
    }
};


int main() {
    Scheduler s;
    s.schedule(
        []() {
            atomicLog(to_string(1 + 2));
        }
    );
    s.schedule(
        []() {
            for(int i=0;i<100;++i) {
                atomicLog("Hello! " + to_string(i));
            }
        }
    );
    atomicLog("Scheduling Tasks completed!");
}