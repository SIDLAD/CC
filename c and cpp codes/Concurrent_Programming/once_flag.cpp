#include<iostream>
#include<thread>
#include<mutex>
#include<fstream>
#include<vector>

using namespace std;

class LogFile {
    std::mutex _mu;
    std::once_flag _once_flag;
    std::ofstream _f;
public:
    void shared_print(thread::id id, string value) {
        std::call_once(_once_flag, [&]() {_f.open("log.txt");});

        std::unique_lock<mutex> locker(_mu);
        _f << "Id: " << id << " Value: " << value << endl;
    }
} logger;

void thread_function(LogFile& logger) {
    logger.shared_print(this_thread::get_id(), "Printing my arrival");
}

int main() {
    vector<thread> v;
    for(int i=0;i<100;++i) {
        v.emplace_back(thread_function, ref(logger));
    }

    for(auto& t: v) t.join();
}