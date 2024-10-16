#include <bits/stdc++.h>
using namespace std;

int n;
int v[101];
int dp[101][3];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];

    dp[1][0] = 1;
    if(v[0]&1)dp[1][1] = 0;
    else dp[1][1] = 101;
    if(v[0]&2)dp[1][2] = 0;
    else dp[1][2] = 101;

    for(int i=2;i<=n;i++)
    {
        dp[i][0] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2]}) + 1;
        if(v[i-1]&1)dp[i][1] = min({dp[i-1][0], dp[i-1][2]});
        else dp[i][1] = 101;
        if(v[i-1]&2)dp[i][2] = min({dp[i-1][0], dp[i-1][1]});
        else dp[i][2] = 101;
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2]});
}