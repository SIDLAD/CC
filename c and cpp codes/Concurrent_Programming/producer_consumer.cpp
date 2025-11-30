#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<string>
#include<fstream>
#include<stdexcept>

using namespace std;

void atomicLog(string s){
    static mutex printMu_;
    static ofstream output;
    lock_guard locker(printMu_);
    if(!output) {
        output.open("log.txt");
    }
    output << s << endl;
}

void atomicPrint(string s) {
    static mutex printMu_;
    lock_guard locker(printMu_);

    cout << s << endl;
}

struct AtomicQueue {
    private:
        mutex qMu_;
        queue<int> data_;
        condition_variable queueStateChange;
        int SIZE_LIMIT = 10;
    public:
        void push(int dataItem) {
            unique_lock locker(qMu_);
            if(data_.size() == SIZE_LIMIT) {
                queueStateChange.wait(locker,
                    [&data_=this->data_, SIZE_LIMIT=this->SIZE_LIMIT](){
                        return data_.size() < SIZE_LIMIT;
                });
            }
            data_.push(dataItem);
            queueStateChange.notify_all();
        }
        
        int pop() {
            unique_lock locker(qMu_);
            if(data_.empty()) {
                queueStateChange.wait_for(locker,
                    1s,
                    [this](){
                        return this->data_.size();
                });
            }
            if(data_.empty()) throw invalid_argument("Data stream empty for a while.. terminating!");
            auto dataItem = data_.front();
            data_.pop();
            queueStateChange.notify_all();
            return dataItem;
        }
} dataQueue;

void ProducerThread() {
    for(int i=0;i<100;++i) {
        dataQueue.push(i);
        atomicLog(to_string(i) + " has been pushed to the queue successfully!");
    }
    atomicPrint("Producer Completed!");
}

void ConsumerThread(int threadId) {
    try {
        while(true) {
            auto dataItem = dataQueue.pop();
            atomicLog(to_string(dataItem) + " has been consumed from the queue successfully by thread " + to_string(threadId));
        }
    } catch(invalid_argument& e) {
        atomicPrint("Terminating Consumer... " + string(e.what()));
    }
}

int main () {
    thread producerThread{ProducerThread};
    thread producerThread2{ProducerThread};
    thread consumerThread{ConsumerThread, 1};
    thread consumerThread2{ConsumerThread, 2};

    producerThread.join(), producerThread2.join();
    consumerThread.join(), consumerThread2.join();
    return 0;
}