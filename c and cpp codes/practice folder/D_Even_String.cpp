#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 5e5 + 1;
const int M = 998244353;

long long binexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

int factorial(int n) {
    static int fact[N];
    if(fact[0] == 0) {
        fact[0] = fact[1] = 1;
        for(int i=2;i<N;++i) {
            fact[i] = fact[i-1] * i %M;
        }
    }
    return fact[n];
}

int rfactorial(int n) {
    static int rfact[N];
    if(rfact[0] == 0) {
        rfact[0] = rfact[1] = 1;
        for(int i=2;i<N;++i) {
            rfact[i] = binexp(factorial(i), M-2);
        }
    }
    return rfact[n];
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<int> c(26);
        int tot = 0;
        for(auto&e:c) cin >> e, tot += e;
        int hfl = tot/2;
        int hfr = tot - hfl;
        int factMulti = factorial(hfl) * factorial(hfr) % M;
        for(auto& e: c) factMulti = factMulti * rfactorial(e) % M;

        vector<vector<int>> dp(26 + 1, vector<int>(hfl + 1));
        dp[0][0] = 1;
        for(int i=1;i<=26;i++) for(int j=0;j<=hfl;j++) {
            dp[i][j] = dp[i-1][j];
            if(c[i-1] && j >= c[i-1]) dp[i][j] += dp[i-1][j-c[i-1]];
            dp[i][j] = dp[i][j] % M;
        }
    

        cout << dp.back().back() * factMulti % M << endl;
    }
    
}