#include <bits/stdc++.h>
const long double EPS = 1e-7;
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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

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
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];

        partial_sum(a.rbegin(),a.rend(),a.rbegin());
        a.push_back(0);
        debug(a);

        vector<vector<int>> dp(m + 1,vector<int>(n + 1,INF));
        dp[m][n] = 0;

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n;j>=0;j--)
            {
                dp[i][j] = min(dp[i][j],dp[i + 1][j]);
                // debug(j,i,dp[j][i]);
                if(dp[i][j] >= INF)continue;
                int start = a[j];
                auto rr = --upper_bound(a.rbegin(),a.rend(), start + b[i]);
                debug(start+b[i],*rr);
                int endind = distance(begin(a), rr.base()) - 1;
                debug(endind);
                assert(endind <= j);
                dp[i][endind] = min(dp[i][endind],dp[i][j] + m - i- 1);
            }
        }
        debug();
        if(dp[0][0] == INF)dp[0][0] = -1;
        cout<<dp[0][0]<<endl;
    }
}