#include<mutex>
#include<thread>
#include<iostream>
#include<fstream>

using namespace std;

class LogFile {
    mutex _mu;
public:
    void fn() {
        _mu.lock();
        cout << "Hello world" << endl;
        _mu.unlock();
    }
} logger;

int main() {
    logger.fn();
}
