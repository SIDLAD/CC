#include<bits/stdc++.h>
#define int long long
using namespace std;
using trygub = map<int,int>;

void addTo(trygub& a, trygub b) {
    for(auto [k, val] : b) {
        int ind = k;
        while(1) {
            a[ind] += val;
            if(a[ind] == 0) a.erase(ind);
            else if(abs(a[ind]) == 2) {a.erase(ind++); continue;}
            break;
        }
    }
}

bool isNotNeg(trygub& a) {
    return (!a.size() || a.rbegin()->second > 0);
}

void addTo(trygub& a, int ind, int val) {
    trygub b; b[ind] = val;
    addTo(a, b);
}

trygub negative(trygub& a) {
    trygub ans;
    for(auto [i, v] : a) ans[i] = -v;
    return ans;
}

void reset(trygub& a) {a = trygub();}

int x;

const long long M = 998244353;


int binpow(int a, int b, int MOD = M) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (__int128_t)res * a % MOD;
        a = (__int128_t)a * a % MOD;
        b >>= 1;
    }
    return res;
}


signed main() {
    int n;
    cin >> n;
    trygub mx;
    trygub cur;
    trygub dif;
    
    for(int i=0;i<n;++i) {
        cin >> x;
        int sgn = x > 0 ? 1 : -1;
        addTo(cur, x * sgn, sgn);
        addTo(dif, x * sgn, sgn);
        if(isNotNeg(dif)) {
            addTo(mx, dif);
            reset(dif);
        }
        if(!isNotNeg(cur)) {
            addTo(dif, negative(cur));
            reset(cur);
        }
    }
    long long ans = 0;
    for(auto [ind, val] : mx) {
        ans += (binpow(2, ind) * val + M);
        ans %= M;
    }
    ans %= M; if(ans < 0) ans += M;
    cout << ans << endl;
}