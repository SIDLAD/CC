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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> edges(n + 1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int lgn = 1 + log2l(n);
    vector<vector<int>> binlift(n + 1, vector<int>(lgn));
    vector<int> tin(n + 1),tout(n + 1);
    vector<int> depth(n + 1);
    int timer = 1;
    auto dfs = [&](auto self, auto node, auto p, int d)->void
    {
        depth[node] = d;
        tin[node] = timer++;
        binlift[node][0] = p;
        for(int i=1;i<lgn;i++)binlift[node][i] = binlift[binlift[node][i-1]][i-1];
        for(auto c:edges[node])if(c != p)self(self,c,node, d + 1);
        tout[node] = timer++;
    };
    dfs(dfs,1,1,1);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int l= a;
        for(int i=lgn - 1;i>=0;i--)
        {
            if(tin[binlift[l][i]] > tin[b] || tout[b] > tout[binlift[l][i]])l = binlift[l][i];
        }
        if(tin[l] > tin[b] || tout[b] > tout[l])l = binlift[l][0];
        cout<< depth[a] + depth[b] - 2 * depth[l]<<endl;
    }
}