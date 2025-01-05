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
#define rep(i, a, n) for(int i = a; i < n; i++)

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin>>T;
    rep(CUR_T,1,T+1)
    {
        int n,m;
        cin>>n>>m;
        vector a(n,0ll);
        rep(i,0,n)cin>>a[i];
        vector b(m,0ll);
        rep(i,0,m)cin>>b[i];
        vector prea(a);
        partial_sum(all(a),prea.begin());

        vector dp(n + 1, vector(m + 1, INF));
        dp[0][0] = 0;
        rep(j,1,m + 1)rep(i,0,n+1)
        {
            dp[i][j] = min(dp[i][j],dp[i][j-1]);
            if(dp[i][j] == INF)continue;
            int reachable = (i == 0?0:prea[i - 1]) + b[j - 1];
            auto nexti = upper_bound(all(prea),reachable) - prea.begin() - 1;
            dp[nexti + 1][j] = min(dp[nexti + 1][j],dp[i][j] + m - j);
        }
        if(dp.back().back() == INF)dp.back().back() = -1;
        cout<<dp.back().back()<<endl;
    }
}