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
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
        vector<vector<int>> dp(n + 1,vector<int>(k+1,INF));
        dp[0][0] = 0;
        for(int i=0;i<n;i++)
        {
            int xy = v[i].first + v[i].second;
            vector<int> costs(xy);
            costs[0] = min(v[i].first,v[i].second);
            for(int j=1;j<xy;j++)
            {
                if(v[i].first > v[i].second)v[i].first --;
                else v[i].second--;
                costs[j] = costs[j-1] + min(v[i].first,v[i].second);
            }
            dp[i + 1][0] = 0;
            for(int j=1;j<=k;j++)
            {
                dp[i + 1][j] = dp[i][j];
                for(int g=1;g<=min(j,(int)costs.size());g++)
                {
                    dp[i + 1][j] = min(dp[i + 1][j],dp[i][j-g] + costs[g-1]);
                }
            }
        }
        if(dp[n][k] >= INF)cout<<-1<<endl;
        else
        cout<<dp[n][k]<<endl;
    }
}