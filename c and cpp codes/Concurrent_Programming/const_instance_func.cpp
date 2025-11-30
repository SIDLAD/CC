#include<map>
using namespace std;

struct newStruct {
    mutable map<int,int> mp;
    newStruct operator+(const newStruct& other) const {
        if(mp.contains(0)) {
            auto x = mp[0];
        }
    }
};

int main() {
    map<int,int> mp;
    // mp.find()
}