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


struct SegmentTree
{
    using T = int;
    vector<T> t;
    int n;
    function<T(T, T)> cmb = [&](T a, T b)
    { return a + b; };

    T def = 0;
    SegmentTree(int sz) : n(sz) { t.assign(2 * n, def); }

    void modify(int p, const T &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = cmb(t[p << 1], t[p << 1 | 1]);
    }

    T query(int l, int r)
    {
        debug(l,r);
        r++;
        T resl = def, resr = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resl = cmb(resl, t[l++]);
            if (r & 1)
                resr = cmb(t[--r], resr);
        }
        return cmb(resl, resr);
    }
};

struct hld
{
    vector<int> parent;
    vector<int> root;
    vector<int> heavy;
    vector<int> segpos;
    vector<int> depth;
    vector<vector<int>> &edges;
    int curpos = 0;
    SegmentTree st;

    int dfs(int node = 0, int p = -1, int d = 0)
    {
        depth[node] = d;
        parent[node] = p;
        int mxsz = 0;
        int sz = 1;
        for(auto child:edges[node])if(child != parent[node])
        {
            int csz = dfs(child, node, d + 1);
            if(csz > mxsz)
            {
                mxsz = csz;
                heavy[node] = child;
            }
            sz += csz;
        }
        return sz;
    }

    void dfs2(int node=0, int r=0)
    {
        root[node] = r;
        segpos[node] = curpos++;

        if(heavy[node] != -1)
        {
            dfs2(heavy[node],r);
        }

        for(auto child:edges[node])if(child != parent[node] and child != heavy[node])
        {
            dfs2(child,child);
        }
    }

    hld(vector<vector<int>>& edges): edges(edges),st(edges.size())
    {
        int n = edges.size();
        parent.assign(n,-1);
        root.assign(n,-1);
        heavy.assign(n,-1);
        segpos.assign(n,-1);
        depth.assign(n,-1);
        dfs();dfs2();
        assert(curpos == n);
        for(int i=0;i<n;i++)st.modify(segpos[i],1);
    }

    int query(int l, int r)
    {
        int ans = st.def;
        for(;root[l] != root[r];r = parent[root[r]])
        {
            if(depth[root[l]] > depth[root[r]])swap(l,r);
            ans = st.cmb(ans,st.query(segpos[root[r]],segpos[r]));
        }
        
        if(depth[l] > depth[r])swap(l,r);
        ans = st.cmb(ans, st.query(segpos[l],segpos[r]));
        return ans;
    }

    void update(int nodeind, int x)
    {
        st.modify(segpos[nodeind],x);
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for(int i = 0;i<n - 1;i++) {
        int x;
        cin >> x;
        edges[i + 1].push_back({x});
        edges[x].push_back({i + 1});
    }
    hld myHld(edges);
    int q;
    cin >> q;
    vector<int> queries1;
    vector<vector<int>> queries2;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int c;
            cin >> c;
            queries1.push_back(c);
        }
        else {
            int a, b, k, y;
            cin >> a >> b >> k >> y;
            queries2.push_back({a, b, k, y});
        }
    }
    

}