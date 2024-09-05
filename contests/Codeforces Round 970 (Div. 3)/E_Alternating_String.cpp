#include <bits/stdc++.h>
const int INF = INT_MAX/2;
using namespace std;
#pragma GCC optimize("Ofast")
#define endl "\n" //comment out for interactive problems

using namespace std;

int dp[4][(int)2e5 + 10];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        int min_ans = INF;
        for(char c1 = 'a';c1<='z';c1++)for(char c2 = 'a';c2<='z';c2++)
        {
            dp[1][0] = dp[3][0] = 0;
            dp[0][0] = dp[2][0] = INF;
            for(int i=1;i<=n;i++)
            {
                if(s[i-1] == c1)
                {
                    dp[0][i] = dp[1][i-1];
                    dp[2][i] = min(dp[3][i-1],dp[0][i-1] + 1);
                }
                else
                {
                    dp[0][i] = dp[1][i-1] + 1;
                    dp[2][i] = min(dp[0][i-1] + 1,dp[3][i-1] + 1);
                }
                if(s[i-1] == c2)
                {
                    dp[1][i] = dp[0][i-1];
                    dp[3][i] = min(dp[2][i-1],dp[1][i-1] + 1);
                }
                else
                {
                    dp[1][i] = dp[0][i-1] + 1;
                    dp[3][i] = min(dp[1][i-1] + 1,dp[2][i-1] + 1);
                }
            }
            min_ans = min(min_ans,(dp[3][n]));
        }

        cout<<min_ans<<endl;
    }
}