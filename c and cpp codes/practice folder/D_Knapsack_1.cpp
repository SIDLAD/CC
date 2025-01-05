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
    int n,w;
    cin>>n>>w;
    vector weight(n,0ll), val(n,0ll);
    rep(i,0,n)cin>>weight[i]>>val[i];

    auto dp = vector(n + 1, vector(w + 1, 0ll));
    dp[0][0] = 0;
    rep(i,1,n + 1)rep(j,0, w + 1)
    {
        dp[i][j] = max({dp[i][j],dp[i-1][j],j == 0 ? 0 :dp[i][j-1]});
        if(j >= weight[i-1])dp[i][j] = max(dp[i][j],dp[i - 1][j-weight[i-1]] + val[i-1]);
    }
    cout<<dp.back().back()<<endl;
}