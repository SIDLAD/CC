#include<iostream>
#include<future>

using namespace std;

int factorial(int N) {
    int ans = 1;
    for(int i=1;i<=N;++i) ans *= i;
    return ans;
}

int main() {
    future<int> fu = async(factorial, 4);
    future<int> fu2 = async(launch::deferred, factorial, 4);
    future<int> fu3 = async(launch::async, factorial, 4);
    future<int> fu4 = async(launch::async | launch::deferred, factorial, 4);

    cout << fu.get() << " " << fu2.get() << " " << fu3.get() << " " << fu4.get() << endl;
}