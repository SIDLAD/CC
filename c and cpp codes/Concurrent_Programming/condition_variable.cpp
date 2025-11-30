#include<mutex>
#include<thread>
#include<iostream>
#include<fstream>
#include<condition_variable>
#include<deque>
#include<atomic>
using namespace std;

condition_variable newItem;
mutex mu;
atomic<bool> isDone = false;

deque<int> dq_remcount;

class Logfile {
    ofstream _f;
    mutex mu;
    once_flag _once;
public:
    void log(string s) {
        call_once(_once, [this](){_f.open("log.txt");});
        unique_lock lock(mu);
        _f << s << endl;
    }
} logger;

void producer() {
    int count = 1000;
    while(count--) {
        unique_lock<mutex> lock(mu);
        dq_remcount.push_back(count);
        newItem.notify_one();
        string logString = "Produced " + to_string(count);
        logger.log(logString);
    }
    isDone = true;
}

void consumer() {
    while(true) {
        unique_lock<mutex> lock(mu);
        if(dq_remcount.empty()) {
            if(isDone) break;
            newItem.wait(lock, [&]() {return dq_remcount.size();});
        }
        int remcount = dq_remcount.front();
        dq_remcount.pop_front();

        string logString = "Consumed " + to_string(remcount);
        logger.log(logString); 
    }
}

int main() {
    thread prod_thread{producer};
    thread cons_thread{consumer};
    prod_thread.join();
    cons_thread.join();
}