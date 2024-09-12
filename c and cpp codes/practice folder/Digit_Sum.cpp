#include<bits/stdc++.h>
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
int countererer = 0;
pair<int,int> calculate(int dig, int eq, pair<int,int> dp[][2], string& a)
{
    if(dp[dig][eq]!=make_pair(-1ll,-1ll))return dp[dig][eq];
    if(dig ==a.size())return {0,1};
    int diglim = 10;
    if(eq)diglim = a[dig] - '0';
    pair<int,int> ans = {0,0};
    for(int i=0;i<10 and i <= diglim;i++)
    {
        auto x = calculate(dig+1,i==diglim,dp,a);
        // debug(i,diglim,dig+1,i==diglim,x,a.size());
        ans.second += x.second;
        ans.first += x.first + x.second * i;
    }
    countererer++;
    // debug(dig,eq,ans);
    return dp[dig][eq] = ans;
}

int calculate(int a)
{
    if(a<=0)return 0;
    int adigitc = (int)log10(a) + 1;
    pair<int,int> dp[adigitc+1][2];
    for(int i=0;i<=adigitc;i++)for(int j=0;j<2;j++)dp[i][j] = {-1,-1};
    string s = to_string(a);
    return calculate(0ll, 1ll, dp, s).first;
}

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
        int a,b;
        cin>>a>>b;
        cout<<calculate(b) - calculate(a-1)<<endl;
        debug(countererer);
    }
}