#include<bits/stdc++.h>
using namespace std;
int main () {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& e:v)cin >> e;
    int ll = 0;
    int ul = n + 1;
    while(ul - ll > 1) {
        int mid = (ll + ul) >> 1;
        vector<int> pre(n + 1);
        for(int i=0;i<n;++i) pre[i + 1] = (v[i] >= mid ? 1 : -1);
        partial_sum(pre.begin(), pre.end(), pre.begin());
        bool ch = false;
        int mn = 0;
        for(int i=k;i<=n;++i) {
            mn = min(mn, pre[i - k]);
            if(pre[i] - mn > 0) {ch = true; break;}
        }
        if(ch) ll = mid;
        else ul = mid;
    }
    cout << ll << endl;
}