#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    
    #define debug(x...) (_exe(x))
    
    class CNothing {};

    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&)
    {
        return proxy;
    }

    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
    {
        return proxy;
    }
    CNothing cnothing;
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("cbarn2.in","r",stdin);
    freopen("cbarn2.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> r(n);
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    int ans = INF;
    for(int i=0;i<n;i++)
    {
        vector<vector<int>> dp(k+1,vector<int>(n+1,INF));
        dp[0][n] = 0;
        for(int g=1;g<=k;g++)
        for(int i=n-1;i>=0;i--)
        {
            int val = 0;
            for(int j=i+1;j<=n;j++)
            {
                val += r[j-1] * (j-1-i);
                if(dp[g-1][j] == INF)continue;
                dp[g][i] = min(dp[g][i], val + dp[g-1][j]);
            }
        }
        ans = min(ans, dp[k][0]);
        rotate(r.begin(),r.begin() + 1,r.end());
    }

    cout<<ans<<endl;
}