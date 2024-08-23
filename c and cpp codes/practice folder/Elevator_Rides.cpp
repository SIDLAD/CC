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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems
pair<int,int> add_modulo(pair<int,int>& a,int add, int lim)
{
    pair<int,int> ans = a;
    ans.second += add;
    if(ans.second > lim)
    {
        ans.second -= lim;
        ans.first ++;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,x;
    cin>>n>>x;
    vector<int> w(n);
    for(int i=0;i<n;i++)cin>>w[i];

    vector<pair<int,int>> dp((int)2e6,{INF,INF});
    dp[0] = {0,x};
    for(int i=0;i<dp.size();i++)
    {
        for(int bit=n-1;bit>=0;bit--)
        {
            if(i&(1<<bit))continue;
            dp[i|(1<<bit)] = min(dp[i|(1<<bit)], add_modulo(dp[i],w[bit],x));
        }
    }
    cout<<dp[(1<<n) - 1].first<<endl;
    // debug(dp);
}