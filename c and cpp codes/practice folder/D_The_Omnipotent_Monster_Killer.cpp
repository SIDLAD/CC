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

void dfs(int node, int p, vector<vector<int>>& edges, vector<array<int,3>>& dp, vector<int>& a,int max_rounds)
{
    vector<int> round_reports(max_rounds);
    for(auto child: edges[node])if(child != p)
    {
        dfs(child,node,edges,dp,a,max_rounds);
    }

    for(int i=0;i<max_rounds;i++)
    {
        round_reports[i] = (i+1) * a[node];
        for(auto child:edges[node])if(child!=p)
        {
            if(dp[child][1] == i)round_reports[i] += dp[child][2];
            else round_reports[i] += dp[child][0];
        }
    }

    array<int,3> ans = {INF,-1,INF};
    for(int i=0;i<max_rounds;i++)
    {
        if(ans[0] > round_reports[i])
        {
            ans[2] = ans[0];
            ans[0] = round_reports[i];
            ans[1] = i;
        }
        else
        {
            ans[2] = min(ans[2],round_reports[i]);
        }
    }
    dp[node] = ans;
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
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<vector<int>> edges(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[--a].push_back(--b);
            edges[b].push_back(a);
        }
        int max_rounds = (int)log2(n) + 1;
        vector<array<int,3>> dp(n);
        dfs(0,-1,edges,dp,a,max_rounds);
        cout<<dp[0][0]<<endl;
    }
}