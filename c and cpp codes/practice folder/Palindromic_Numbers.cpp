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
int dp[18][2];
int calculate(int dig, int under, string a)
{
    if(dp[dig][under] != -1)return dp[dig][under];
    if(dig == (a.size() +1)/2)return 1;
    int upper = under?a[dig] - '0':10;
    int ans = 0;
    for(int i=(dig==0);i<=min(9ll,upper);i++)
    {
        ans += calculate(dig+1,upper==i,a);
    }
    return dp[dig][under] = ans;
}

int calculate(string a)
{
    if(a == "-1")return calculate("0") - 1;
    string tmp = a.substr(0,(a.size() + 1)>>1);
    for(int i = tmp.size() - 1 - (a.size()&1);i>=0;i--)
    tmp.push_back(tmp[i]);
    int ans = 0;

    string x = "";
    for(int i=1;i<a.size();i++)
    {
        x.push_back(9+'0');
        memset(dp,-1,sizeof(dp));
        ans += (calculate(0,1,x));
    }
    memset(dp,-1,sizeof(dp));
    ans += (calculate(0,1,a));
    if((a < (tmp)))ans--;
    cerr<<endl;

    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    int TT = 1;
    for(;T--;TT ++)
    {
        int a,b;
        cin>>a>>b;
        if(a > b)swap(a,b);
        cout<<"Case "<<TT<<": ";
        cout<<(calculate(to_string(b))) - (calculate(to_string(a-1)))<<endl;
    }
}