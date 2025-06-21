#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    set<int> badNums;
    for(int n=1;n<=5e5;n++) {
        int tot = n * (n + 1) / 2;
        int i = (int)floorl(sqrtl(tot));
        if(n == 57121)
        cerr << n << " " << tot << " " << i*i << endl;
        if(i*i == tot)badNums.insert(n);
    }
    while(t--) {
        int n;
        cin >> n;
        if(badNums.count(n)){
            cout << -1 << endl;
            continue;
        }
        vector<int> v(n);
        iota(v.begin(),v.end(),1);
        for(int i=1;i<=n;i++){
            if(badNums.count(i))swap(v[i-1],v[i]);
        }
        
        for(auto e:v)cout << e << " ";
        cout << endl;
        int u =  accumulate(v.begin(), v.end(),0ll);
        cerr << u << endl;
        int x = sqrtl(u);
        cerr << x << " " << x * x << endl;
        cerr << badNums.count(u) << endl;
    }
}