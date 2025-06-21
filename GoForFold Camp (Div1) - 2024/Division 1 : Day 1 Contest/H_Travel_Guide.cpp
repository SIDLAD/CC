#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int n,m;
vector<int> calc(int src, vector<vector<pair<int, int>>> &graph) {
    vector<int> dist(n, INF);
    set<pair<int, int>> s;
    s.insert({0, src});
    dist[src] = 0;
    while(!s.empty()) {
        auto start = *s.begin();
        s.erase(s.begin());
        for(auto &val : graph[start.second]) {
            if(dist[val.first] > dist[start.second] + val.second) {
                s.erase({dist[val.first], val.first});
                dist[val.first] = dist[start.second] + val.second;
                s.insert({dist[val.first], val.first});
            }
        }
    }
    return dist;
}



template <typename T = int, typename V = T>
struct segtree
{
    int n;
    vector<T> tree;
    // vector<V> lazy;
    T zero = INF; // Change according to QUERY operation
    // V lazy_zero = 0; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(2 * sz - 1, zero);
        // lazy.resize(2 * sz - 1, lazy_zero);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return min(a,b);
    }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = min(tree[id],val); // Change according to MODIFY operation
            // lazy[id] = val; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, id + 1, segl, mid);
        modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }
    auto query(int index) { return query(index, index); }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    set<array<int,3>> st;
    map<array<int,3>,bool> ans;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> inp[3];
    for(int i = 0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); 
        graph[v].push_back({u, w}); 
    }

    inp[0] = calc(0,graph);
    inp[1] = calc(1,graph);
    inp[2] = calc(2,graph);

    debug(inp[0],inp[1],inp[2]);
    for(int i=0;i<n;i++)
    {
        st.insert({inp[0][i],inp[1][i],inp[2][i]});
    }

    segtree segt(1e7 + 10);
    for(auto [d1,d2,d3] : st)
    {
        if(segt.query(0,d2) <= d3)
        {
            ans[{d1,d2,d3}] = true;
        }
        else
        {
            ans[{d1,d2,d3}] = false;
        }
        segt.modify(d3,d2);
    }

    for(auto [a,b]:ans)debug(a,b);
    int cntuseless = 0;
    for(int i=3;i<n;i++)
    {
        cntuseless += ans[{inp[0][i],inp[1][i],inp[2][i]}];
    }

    cout<<n - cntuseless<<endl;
}