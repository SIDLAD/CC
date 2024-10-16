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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

class DSU {
public:
    int n;
    vector<int> p,sz,rank;
    int start;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int n):DSU(0,n-1){}

    int count()
    {
        std::set<int> st;
        for(int i=start;i<=n;i++)
        {
            st.insert(find(p[i]));
        }
        return st.size();
    }
 
    int find(int x) {
        if(x == p[x]) return x;
        return find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[find(p[x])];
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);
            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
            return true;
        }
        return false;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<array<int,4>> edgelist;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edgelist.push_back({w,a,b,i});
    }

    DSU dsu(1,n);
    sort(all(edgelist));
    set<int> selected;
    vector<vector<pair<int,int>>> edges(n+1);
    
    int minans = 0;
    for(int i=0;i<m;i++)
    {
        if(dsu.unite(edgelist[i][1],edgelist[i][2]))
        {
            minans += edgelist[i][0];
            selected.insert(edgelist[i][3]);
            edges[edgelist[i][1]].push_back({edgelist[i][2],edgelist[i][0]});
            edges[edgelist[i][2]].push_back({edgelist[i][1],edgelist[i][0]});
        }
    }

    vector<pair<int,int>> timings(n +1);

    int N = log2(n) + 1;
    vector<vector<pair<int,int>>> binlift(n + 1,vector<pair<int,int>>(N));
    binlift[1][0] = {1,-INF};
    int tmp = 0;
    auto dfs = [&](auto self, int cur, int p)->void
    {
        timings[cur].first = tmp++;
        for(auto [child,w]:edges[cur])if(child!=p)
        {
            binlift[child][0] = {cur,w};
            self(self,child,cur);
        }
        timings[cur].second = tmp++;
    };
    dfs(dfs,1,-1);
    debug(selected,timings);
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=n;j++)
        binlift[j][i] = binlift[binlift[j][i-1].first][i-1],binlift[j][i].second = max(binlift[j][i].second,binlift[j][i-1].second);
    }

    debug(binlift);

    auto lca = [&](int u, int v)->pair<int,int> // returns lca, maxweight
    {
        int mx = -INF;
        for(int i = N-1;i>=0;i--)
        {
            auto top = binlift[u][i].first;
            if(timings[top].first <= timings[v].first and timings[top].second >= timings[v].second);
            else
            {
                mx = max(mx,binlift[u][i].second);
                u = top;
            }
        }
        if(timings[u].first <= timings[v].first and timings[u].second >= timings[v].second);
        else
        {
            mx = max(mx,binlift[u][0].second);
            u = binlift[u][0].first;
        }
        return {u,mx};
    };

    sort(all(edgelist),[&](auto& a, auto& b){return a[3] < b[3];});
    for(int i=0;i<m;i++)
    {
        if(selected.count(i))
        {
            cout<<minans<<endl;
        }
        else
        {
            auto [w,a,b,_] = edgelist[i];
            int p = lca(a,b).first;
            int mx = lca(a,p).second;
            mx = max(mx,lca(b,p).second);
            debug(mx,p,edgelist[i],i);
            cout<<minans - mx + w<<endl;
        }
    }
}