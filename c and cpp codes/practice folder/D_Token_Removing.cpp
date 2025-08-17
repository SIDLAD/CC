#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b;++i)
#define int long long
void solve() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    rep(i,1,n + 1) rep(j, 0, n + 1)
        dp[i][j] = ( (j == 0 ? 0 : dp[i-1][j-1]) + dp[i - 1][j] * (n - i + 1) * (j + 1) % m) % m;
    int ans = 0;
    for(int i=0;i<=n;++i) ans = (ans + dp[n][i]) % m;
    cout << ans << endl;
} 
#undef int
int main() {
    int t;
    cin >> t;
    while(t--) solve();
}