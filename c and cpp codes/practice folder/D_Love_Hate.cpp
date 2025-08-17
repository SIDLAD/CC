#include<bits/stdc++.h>
using namespace std;

mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());

int n,m,p;
long long v[(int)2e5 + 1];
long long vv[(int)2e5 + 1];
long long sos[(int)5e4];

int main() {
    cin >> n >> m >> p;
    string s;
    for(int ii=0;ii<n;++ii) {
        cin >> s;
        for(int i=0;i<m;++i) if(s[m - i - 1] == '1') v[ii] += 1ll << i;
    }

    vector<int> order(n); iota(order.begin(), order.end(), 0ll);
    shuffle(order.begin(),order.end(), rngl);

    long long mxAns = 0;
    for(int i=0;i<min(50, n);++i) {
        long long mask = v[order[i]];
        memset(vv, 0ll, sizeof(long long) * n);
        int kk = 0;
        for(int i=0;i<n;++i) for(int j=63, k = 0;j>=0;--j) if(mask >>j & 1) {
            if(v[i] >> j & 1) vv[i] += 1ll << k;
            ++k;
            kk = max(k, kk);
        }

        memset(sos, 0ll, sizeof(long long) * (1ll << kk));
        for(int i=0;i<n;++i) sos[vv[i]] ++;
        for(int i=kk - 1;i>=0;--i) for(int j = 0; j < (1ll << kk); ++j)
        if(~j >> i & 1) sos[j] += sos[j ^ (1ll << i)];

        for(int j=0;j< (1ll << kk); ++j) if(sos[j] >= n + 1 >> 1 && __builtin_popcountll(j) > __builtin_popcountll(mxAns)) {
            long long curAns = 0;
            for(int jj=63, k=0; jj >= 0; --jj) if(mask >> jj & 1) {
                curAns += (1ll << jj) * (j >> k & 1);
                ++k;
            }
            mxAns = curAns;
        }
    }
    for(int i=m - 1;i>=0;--i)
    cout << (mxAns >> i & 1);
    cout << endl;
}