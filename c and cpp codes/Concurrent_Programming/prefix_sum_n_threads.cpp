#include<thread>
#include<iostream>
#include<vector>
#include<future>
#include<stdexcept>
#include<fstream>
#include<numeric>
#include<assert.h>
#include<semaphore>

using namespace std;

// Simulation (not actual) of SIMD

// class ThreadSafeLogFile {
//     std::mutex _mu; // thread
// public:
//     void print(string str) {
//         std::lock_guard<std::mutex> locker(_mu); // thread
//         cout << str << std::endl; // endl is from ostream
//     }
// } logger;


// thread::hardware_concurrency() = 8
counting_semaphore<8> parallelTasks(8);

int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    // for(auto& e: v) cin >> e;
    iota(v.begin(), v.end(), 1ll);
    for(int preLen = 1; preLen < n; preLen <<= 1) {
        // logger.print("preLen: " + to_string(preLen));
        shared_future<void> futures[n - preLen];
        
        auto performAsync = [&](int ind) {

            struct SemaphoneReleaser {
                ~SemaphoneReleaser() {parallelTasks.release();}
            } releaser;

            if(ind + preLen < n)  {
                // assert(n - 1 - ind - preLen >= 0 and n - 1 - ind - preLen < n - preLen);
                futures[n - 1 - ind - preLen].get();
            }  
            if(ind < preLen)
                throw runtime_error("Invalid Operation");
            v[ind] += v[ind - preLen];
        };
        
        for(int i=n; i --> preLen;) {
            assert(n - 1 - i >= 0 and n - 1 - i < n - preLen);
            // logger.print("Attempting to acquire thread for " + to_string(i));
            parallelTasks.acquire();
            futures[n - i - 1] = async(std::launch::async, performAsync, i);
        }
        for(int i=preLen;i<min(2 * preLen, n);++i) {
            // assert(n - 1 - i >= 0 and n - 1 - i < n - preLen);
            futures[n - 1 - i].get();
        }
        // logger.print("This iteration is complete!");
    }

    // logger.print("Final task count: " + to_string(curParallelTaskCount));
    cout << "Final Prefix Sum: " << endl;

    for(auto& e: v) cout << e << " ";
    cout << endl;
}