#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;++i) cin >> v[i];
        int tot = accumulate(v.begin(),v.end(), 0ll);
        
        if(tot&1) {
            cout << -1 << endl;
            continue;
        }
        int curSum = 0;
        int i;
        int hf = tot >> 1;
        for(i=0;i<n;++i) {
            curSum += v[i];
            if(curSum >= hf) break;
        }
        if(curSum == hf) {
            cout << 1 << endl;
            for(int i=0;i<n;++i) cout << v[i] << " ";
            cout << endl;
            continue;
        }
        int dir = -1;
        if(i != 0){
            int prevSum = curSum - v[i];
            if(hf - prevSum < curSum - hf) {dir = 1;
            curSum = tot - curSum + v[i];}
        }

        int delta = 2 * abs(curSum - hf);

        vector<int> b(n);
        b[i] = delta / 2;
        delta >>= 1;
        for(i += dir;i >= 0 && i < n; i += dir) {
            b[i] = min(v[i], delta);
            delta -= b[i];
        }

        if(delta) {
            cout << -1 << endl;
            continue;
        }
        else {
            cout << 2 << endl;
            for(auto&e: b) {
                cout << e << " ";
            }
            cout << endl;
            for(int i=0;i<n;++i) {
                cout << v[i] - b[i] << " ";
            }
            cout << endl;
        }
    }
}