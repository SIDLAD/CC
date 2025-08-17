#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LLONG_MAX/2;
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

int n;
int v[5000];
int dp[5000][5000];


int solve (int i, int j)
{
    if(dp[i][j] != -INF) return dp[i][j];
    bool turn = ((j - i + 1) ^ n ^ 1) & 1;
    if(i == j) return dp[i][j] = v[i] * (turn ? 1 : 0);
    int f = solve(i + 1, j) + (turn ? v[i] : 0);
    int s = solve(i, j - 1) + (turn ? v[j] : 0);
    if(turn) return dp[i][j] = max(f,s);
    else return dp[i][j] = min(f,s);
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("test_input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) dp[i][j] = -INF;
    cout<<solve(0,n-1)<<endl;
}