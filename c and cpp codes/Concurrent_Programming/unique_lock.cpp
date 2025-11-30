// unique lock can be moved but not copied
// lock guard can never be moved

#include<iostream>
#include<thread>
#include<fstream>
#include<mutex>

using namespace std;

class LogFile {
    ofstream _f;
    mutex _mu;
    LogFile() {
        _f.open("log.txt");
    }

    void print(string s, int threadId) {
        _f << "[Thread ID " << threadId << "]: " << s << endl;
    }

public:
    void threadSafePrint1(string s, int threadId) {
        _mu.lock();
        print(s, threadId);
        _mu.unlock();
    }

    void threadSafePrint2(string s, int threadId) {
        lock_guard<mutex> locker(_mu);
        print(s, threadId);
    }

    void threadSafePrint3(string s, int threadId) {
        unique_lock<mutex> locker(_mu);
        print(s, threadId);
    }

    void threadSagePrint4(string s, int threadId) {
        scoped_lock<mutex> locker(_mu); // C++ 17 +
    }
};