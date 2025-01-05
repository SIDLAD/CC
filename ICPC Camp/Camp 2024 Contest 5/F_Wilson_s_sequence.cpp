#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

vector<int> isprime(2e5 + 1,1);

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    isprime[0] = isprime[1] = false;
    for(int i=2;i<isprime.size();i++)if(isprime[i])
    {
        for(int j = i*i;j< isprime.size();j += i)isprime[j] = false;
    }

    int n;
    cin>>n;
    vector<int> v(n);
    arrPut(v);
    int dp[4][n];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = dp[2][0] = dp[3][0] = 1;

    auto update = [](auto& var, auto val)
    {
        var = min(var,val);
    };

    for(int i=1;i<n;i++)
    {
        if(isprime[v[i] + v[i-1]]) update(dp[0][i],dp[0][i-1]);
        if(isprime[v[i] + 1]) update(dp[0][i],dp[1][i-1]);
        if(v[i]&1) update(dp[0][i],dp[2][i-1]);
        else update(dp[0][i],dp[3][i-1]);

        update(dp[1][i],dp[1][i-1] + 1);
        update(dp[1][i],dp[2][i-1] + 1);
        if(isprime[v[i-1] + 1]) update(dp[1][i],dp[0][i-1] + 1);

        update(dp[2][i],dp[1][i-1] + 1);
        update(dp[2][i],dp[3][i-1] + 1);
        if(v[i-1]&1)update(dp[2][i],dp[0][i-1] + 1);

        update(dp[3][i],dp[2][i-1] + 1);
        if(~v[i-1]&1)update(dp[3][i],dp[0][i-1] + 1);
    }
    int ans = min({dp[0][n-1],dp[1][n-1],dp[2][n-1],dp[3][n-1]});
    cout<<ans<<endl;
}