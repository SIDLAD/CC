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
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
int dp[1001][(int)1e5 +1]={};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("test_input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,x;
    cin>>n>>x;
    vector<int> c(n),p(n);
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=x;j++)
    {
        dp[i][j] = max({dp[i-1][j],dp[i][j-1]});
        if(j-c[i-1] >=0)dp[i][j] = max(dp[i][j],dp[i-1][j-c[i-1]] + p[i-1]);
    }
    cout<<dp[n][x]<<endl;
}