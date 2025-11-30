#include<iostream> // inherits from istream and ostream
#include<thread>
#include<fstream> // btw inherits from iostream
#include<string>
#include<functional>

using std::string; // string
using std::thread; // thread
using std::mutex; // thread
using std::ofstream; // fstream
using std::lock_guard; // thread
using std::ref;

class ThreadSafeLogFile {
    std::mutex _mu; // thread
    std::ofstream _f; // fstream
public:
    ThreadSafeLogFile() {
        _f.open("log.txt");
    }
    void threadSafePrint(string id, int val) {
        std::lock_guard<std::mutex> locker(_mu); // thread
        _f << "From " << id << ": " << val << std::endl; // endl is from ostream
    }
};

void function_t1(ThreadSafeLogFile& log) {
    for (int i=0;i<100;++i) {
        log.threadSafePrint("t1", i);
    }
}

int main () {
    ThreadSafeLogFile log{};
    thread t1{function_t1, ref(log)};
    for(int i=0;i<1000;++i) {
        log.threadSafePrint("main", - i - 1);
    }
    t1.join();
}