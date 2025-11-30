#include<mutex>
#include<condition_variable>
using namespace std;

class Foo {
    bool executed[4] = {};
    mutex _mu;
    condition_variable _cond;
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(_mu);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        executed[1] = true;
        _cond.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(_mu);
        if(!executed[1]) {
            _cond.wait(lock, [&]() {return executed[1];});
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        executed[2] = true;
        _cond.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(_mu);
        if(!executed[2]) {
            _cond.wait(lock, [&]() {return executed[2];});
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};