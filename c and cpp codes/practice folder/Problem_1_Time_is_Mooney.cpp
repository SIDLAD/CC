#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here
#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
// #define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<vector<int>> e(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        e[a].push_back(b);
    }
    vector<vector<int>> dp(n,vector<int>(1001,-1));
    dp[0][0] = 0;
    int ans = 0;
    for(int x = 0;x<1000;x++){
    for(int i=0;i<n;i++)
    {
        if(dp[i][x]!= -1)
        {
            for(int y: e[i])
                dp[y][x+1] = max(dp[y][x+1],dp[i][x] + v[y]);
        }
    }
    ans = max(ans, (dp[0][x+1]) - (c*(x+1)*(x+1)));
    }

    cout<<ans<<endl;
}