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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define forn(i, a, n) for(int i = a; i < n; i++)

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
    // cin>>T;
    forn(CUR_T,1,T+1)
    {
        int n,q;
        cin>>n>>q;
        
        auto dp = vector(n + 1,vector(n + 1,bitset<901>()));
        dp[0][0][0] = 1;
        forn(X,0,n + 1)forn(Y,0,n+1)forn(x,0,X-1)forn(y,0,Y-1)dp[X][Y] |= dp[x][y] << (X - x) * (Y - y);
        bitset<901> sum;
        forn(X,0,n+1)forn(Y,0,n+1)sum |= dp[X][Y];

        forn(_,0,q)
        {
            int k;
            cin>>k;
            cout(sum[n*n - k]);
        }
    }
}