#include<stdexcept>
#include<iostream>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;


#define RANDOM_GEN_MACRO

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());


int main() {
    // std::exception_ptr ptr = std::make_exception_ptr(std::runtime_error("Error message"));
    // std::rethrow_exception(ptr);
    int n = 10;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1ll);
    
    shuffle(v.begin(),v.end(), rng);
    for(auto& e: v) cout << e  << " ";
    cout << endl;

    vector<int> vv(n);
    iota(vv.begin(), vv.end(),1ll);

    for(int i=10;i>=1;++i) {
        int nextInd = rng() * i;
        if()
    }
}