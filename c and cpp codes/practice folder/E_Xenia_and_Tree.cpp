#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

constexpr int LIM = (int)100000;

int n,m;
vector<int> edges[LIM + 1];
int is_removed[LIM + 1];
int subtree_sz[LIM + 1];

vector<pair<int,int>> ancestors[LIM + 1];
int min_dist[LIM + 1];

void dfs_subsz(int node = 1, int p = -1)
{
    subtree_sz[node] = 1;
    for(auto child: edges[node])if(p != child and !is_removed[child])
    {
        dfs_subsz(child,node);
        subtree_sz[node] += subtree_sz[child];
    }
}

void set_ancestor(int node, int centroid, int parent = -1, int dist = 0)
{
    for(auto child: edges[node])if(!is_removed[child] and child != parent)
    {
        set_ancestor(child,centroid,node,dist + 1);
    }

    ancestors[node].emplace_back(centroid,dist);
}

int get_centroid(int node, int totsize, int parent = -1)
{
    for(auto child: edges[node])if(!is_removed[child] and child != parent)
    {
        if(subtree_sz[child] > totsize/2)return get_centroid(child,totsize, node);
    }
    return node;
}

void centroid_decomposition(int node = 1)
{
    dfs_subsz(node);
    int centroid = get_centroid(node, subtree_sz[node]);
    is_removed[centroid] = 1;
    set_ancestor(centroid,centroid);
    for(auto nxt: edges[centroid])if(!is_removed[nxt])centroid_decomposition(nxt);
}

void update(int node)
{
    for(auto [ancestor, dist] : ancestors[node])
        min_dist[ancestor] = min(min_dist[ancestor], dist);
}

int query(int node)
{
    int ans = INF;
    for(auto [ancestor, dist]: ancestors[node])
        ans = min(ans, dist + min_dist[ancestor]), debug(ancestor, min_dist[ancestor]);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    memset(min_dist,0x3f,sizeof(min_dist));
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    centroid_decomposition();
    update(1);

    while(m--)
    {
        int t,v;
        cin>>t>>v;
        if(t == 1)update(v);
        else cout<<query(v)<<endl;
    }
}