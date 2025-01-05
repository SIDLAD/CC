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

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int C = (int)ceill(2e5l * 100 /99 );

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> w(n),p(n);
    for(int i=0;i<n;i++)cin>>p[i]>>w[i];

    vector<vector<int>> pwbuckets(100);

    int ansll = 0;
    for(int i=0;i<n;i++)
    {
        if(p[i] == 100)
        {
            ansll += w[i];
            continue;
        }
        pwbuckets[p[i]].push_back(w[i]);
    }
    if(ansll >= C)
    {
        cout<<(double)ansll<<endl;
        return 0;
    }

    debug(ansll);
    vector<pair<int,int>> wipi;

    for(int i=99;i>=1;i--)
    {
        sort(all(pwbuckets[i]),greater<double>());
        int lim = (100.0l/(100-i));
        for(int j=0;j<(min(lim,(int)pwbuckets[i].size()));j++)
        {
            wipi.push_back({pwbuckets[i][j],i});
        }
    } 

    debug(wipi);

    vector<double> dp(C + 1);
    dp[0] = dp[ansll] = 1.0l;
    for(int i=0;i<wipi.size();i++)
    {
        auto [wi,pi] = wipi[i];
        for(int j=C;j-wi >= 0;j--)
        {
            dp[j] = max(dp[j],dp[j-wi]*pi*0.01l);
        }
    }

    double mx = 0;
    for(int i=0;i<=C;i++)
    {
        mx = max(mx,i * dp[i]);
    }

    cout<<mx<<endl;
}