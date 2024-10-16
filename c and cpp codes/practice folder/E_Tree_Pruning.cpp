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
        int n;
        cin>>n;
        vector<vector<int>> edges(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[--a].push_back(--b);
            edges[b].push_back(a);
        }

        vector<int> depths(n),maxdepths(n);
        auto dfs = [&](auto self, int cur, int p, int depth)->int
        {
            depths[cur] = depth;
            int cnt = 0;
            int dp = depth;
            for(auto& child:edges[cur])if(child!=p)
            {
                cnt ++;
                dp = max(dp,self(self,child,cur,depth + 1));
            }
            return maxdepths[cur] = dp;
        };
        dfs(dfs,0,0,0);
        debug(depths,maxdepths);
        vector<int> pre(n+1);
        for(int i=0;i<n;i++)
        {
            pre[depths[i]]++;
            pre[maxdepths[i] + 1]--;
        }
        partial_sum(all(pre),pre.begin());
        cout<<n - *max_element(all(pre)-1)<<endl;
    }
}