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

int dp[20][10][2][2][2];
string as,bs;
int solve(int dig, int last_digit, int over, int under, int started)
{
    if(dp[dig][last_digit][over][under][started] != -1)return dp[dig][last_digit][over][under][started];
    auto& ans = dp[dig][last_digit][over][under][started];
    ans = 0;
    if(dig == as.size())return ans = 1;
    int lower = -1;
    if(under)lower = as[dig] - '0';
    int upper = 10;
    if(over)upper = bs[dig] - '0';
    for(int i=max(0ll,lower);i<=min(9ll,upper);i++)
    {
        if(started and i == last_digit)continue;
        ans += solve(dig+1,i,over && i==upper,under && i==lower,started||(i!=0));
    }
    // debug(dig, last_digit, over, under, started, lower,upper,ans);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout); 
    int a,b;
    cin>>a>>b;
    as = to_string(a);
    bs = to_string(b);
    memset(dp,-1,sizeof(dp));
    string tmp = "";
    for(int i=0;i<bs.size()-as.size();i++)tmp+='0';
    as = tmp + as;
    cout<<solve(0,0,1,1,0)<<endl;
}