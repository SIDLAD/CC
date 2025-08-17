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
#define sz(x) (int)(x).size()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define rep(it, start, end) for (auto it = start; it != end; ++it)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		// if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void getTimes(auto& edges, auto cur, auto& times, auto& timer) {
    times[cur].first = ++timer;
    for(auto nbr: edges[cur]) getTimes(edges, nbr, times, timer);
    times[cur].second = timer;
}

struct rightsegtree
{

#define LID id + 1
#define RID id + 2 * (mid - segl + 1)
#define TREESZ 2 * sz - 1

    using T = pair<int,int>;
    using V = int;

    int n;
    vector<T> tree;
    vector<V> lazy;
    vector<int> mxNodeVal;
    T zero = {-1,-1};
    V lazy_zero = -1;

    rightsegtree(int sz)
    {
        n = sz;
        tree.assign(TREESZ, zero);
        lazy.assign(TREESZ, lazy_zero);
        mxNodeVal.assign(TREESZ, -1);
    }

    template <typename U>
    rightsegtree(vector<U> &v) : rightsegtree(v.size()) { 
        build(v);
        for(int i=0;i<sz(mxNodeVal); ++i) mxNodeVal[i] = tree[i].second;
    }

    template <typename U>
    inline void init_node(int id, const U &val, int index) { tree[id] = {0, val}; }
    inline T combine(T &c1, T &c2) { return max(c1, c2); }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (segl == segr)
        {
            init_node(id, v[segl], segl);
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, LID, segl, mid);
        build(v, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
    }

    bool break_condition(int index_l, int index_r, int id, int segl, int segr, int upd)
    {
        if (index_l > index_r || index_l > segr || segl > index_r)
            return true;
        return false;
    }
    bool tag_condition(int index_l, int index_r, int id, int segl, int segr, int upd)
    {
        if (segl >= index_l && segr <= index_r)
            return true;
        return false;
    }

    template <typename U>
    inline void update_tree_node(T &node, U &upd, int segl, int segr, int id)
    {
        node.first = upd;
        node.second = mxNodeVal[id];
    }
    inline void update_tree_node(T &node, V &pTag, int segl, int segr, int id)
    {
        node.first = pTag;
        node.second = mxNodeVal[id];
    }

    template <typename U>
    inline void update_lazy_node(V &tag, U &upd)
    {
        tag = upd;
    }
    inline void update_lazy_node(V &tag, V &pTag)
    {
        tag = pTag;
    }

    void propagate(int id, int segl, int segr)
    {
        if (lazy[id] == lazy_zero)
            return;
        if (segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<array<int, 3>, 2> children = {{{LID, segl, mid}, {RID, mid + 1, segr}}};
            for (auto [child, csegl, csegr] : children)
                update_lazy_node(lazy[child], lazy[id]), update_tree_node(tree[child], lazy[id], csegl, csegr, child);
        }
        lazy[id] = lazy_zero;
    }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (break_condition(index_l, index_r, id, segl, segr, val))
        {
            return;
        }
        if (tag_condition(index_l, index_r, id, segl, segr, val))
        {
            update_lazy_node(lazy[id], val);
            update_tree_node(tree[id], val, segl, segr, id);
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, LID, segl, mid);
        modify(val, index_l, index_r, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, LID, segl, mid);
        T rightVal = query(index_l, index_r, RID, mid + 1, segr);
        return combine(leftVal, rightVal);
    }
    auto query(int index) { return query(index, index); }
};

struct leftsegtree
{

#define LID id + 1
#define RID id + 2 * (mid - segl + 1)
#define TREESZ 2 * sz - 1

    using T = pair<int,int>;
    using V = int;

    int n;
    vector<T> tree;
    vector<V> lazy;
    vector<int> mxNodeVal;
    T zero = {-1,-1};
    V lazy_zero = -1;

    leftsegtree(int sz)
    {
        n = sz;
        tree.assign(TREESZ, zero);
        lazy.assign(TREESZ, lazy_zero);
        mxNodeVal.assign(TREESZ, -1);
    }

    template <typename U>
    leftsegtree(vector<U> &v) : leftsegtree(v.size()) { 
        build(v);
        for(int i=0;i<sz(mxNodeVal); ++i) mxNodeVal[i] = tree[i].second;
    }

    template <typename U>
    inline void init_node(int id, const U &val, int index) { tree[id] = {0, val}; }
    inline T combine(T &c1, T &c2) { if(c1.first != c2.first) return max(c1, c2); return min(c1, c2); }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (segl == segr)
        {
            init_node(id, v[segl], segl);
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, LID, segl, mid);
        build(v, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
    }

    bool break_condition(int index_l, int index_r, int id, int segl, int segr, int upd)
    {
        if (index_l > index_r || index_l > segr || segl > index_r)
            return true;
        return false;
    }
    bool tag_condition(int index_l, int index_r, int id, int segl, int segr, int upd)
    {
        if (segl >= index_l && segr <= index_r)
            return true;
        return false;
    }

    template <typename U>
    inline void update_tree_node(T &node, U &upd, int segl, int segr, int id)
    {
        node.first = upd;
        node.second = mxNodeVal[id];
    }
    inline void update_tree_node(T &node, V &pTag, int segl, int segr, int id)
    {
        node.first = pTag;
        node.second = mxNodeVal[id];
    }

    template <typename U>
    inline void update_lazy_node(V &tag, U &upd)
    {
        tag = upd;
    }
    inline void update_lazy_node(V &tag, V &pTag)
    {
        tag = pTag;
    }

    void propagate(int id, int segl, int segr)
    {
        if (lazy[id] == lazy_zero)
            return;
        if (segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<array<int, 3>, 2> children = {{{LID, segl, mid}, {RID, mid + 1, segr}}};
            for (auto [child, csegl, csegr] : children)
                update_lazy_node(lazy[child], lazy[id]), update_tree_node(tree[child], lazy[id], csegl, csegr, child);
        }
        lazy[id] = lazy_zero;
    }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (break_condition(index_l, index_r, id, segl, segr, val))
        {
            return;
        }
        if (tag_condition(index_l, index_r, id, segl, segr, val))
        {
            update_lazy_node(lazy[id], val);
            update_tree_node(tree[id], val, segl, segr, id);
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, LID, segl, mid);
        modify(val, index_l, index_r, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, LID, segl, mid);
        T rightVal = query(index_l, index_r, RID, mid + 1, segr);
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
    
    int n,q;
    cin >> n >> q;
    vector<array<int,3>> edges;
    rep(i,0,n-1) {
        int a,b,w;
        cin >> a >> b >> w;
        edges.push_back({w, a, b});
    }

    sort(all(edges));
    UF dsu(2 * n);
    vector<vector<int>> reachTree(n + 1);

    map<int,int> findA;
    for(auto [w, a, b] : edges) {
        if(dsu.sameSet(a,b)) assert(false);
        auto newN = reachTree.size();
        reachTree.emplace_back();
        a = dsu.find(a), b = dsu.find(b);
        reachTree[newN].emplace_back(a);
        reachTree[newN].emplace_back(b);
        findA[newN] = w;

        dsu.join(newN, a), dsu.join(newN, b);
    }

    vector<pair<int,int>> times(reachTree.size());
    int timer = -1;
    getTimes(reachTree, sz(reachTree) - 1, times, timer);

    vector<int> sv(n + 1);
    vector<int> revsv(timer + 1);
    for(int i=1;i<=n;++i) sv[i] = times[i].first, revsv[times[i].first] = i;
    rightsegtree rst(sv);
    leftsegtree lst(sv);

    int rts = sz(reachTree);
    int lgN = bit_width((unsigned ll)rts - 1) + 1;

    vector lca(lgN, vector<int>(rts));
    lca[0][rts - 1] = rts - 1;
    for(int i=1;i<rts;++i) for(auto e: reachTree[i]) lca[0][e] = i;
    for(int i=1;i<lgN;++i) for(int j=1;j<rts;++j) lca[i][j] = lca[i-1][lca[i-1][j]];
    vector<int> depth(rts);
    auto calcDepth = [&](auto self, int cur, int val = 0)-> void {
        depth[cur] = val++;
        for(auto nbr: reachTree[cur])  self(self, nbr, val);
    };
    calcDepth(calcDepth, rts - 1);
    auto checkAnc = [&](int u, int d) -> bool {
        return times[d].first >= times[u].first && times[d].second <= times[u].second;
    };
    auto getLCA = [&](int a, int b) {
        if(checkAnc(a,b)) return a;
        if(checkAnc(b,a)) return b;
        for(int i=lgN-1;i>=0;--i) if(!checkAnc(lca[i][a], b)) a = lca[i][a];
        return lca[0][a];
    };
    while(q--) {
        int t, l, r, x;
        cin >> t;
        switch(t) {
            case 1:
                cin >> l >> r;
                rst.modify(1, l, r);
                lst.modify(1, l, r);
                break;
            case 2:
                cin >> l >> r;
                rst.modify(0, l, r);
                lst.modify(0, l, r);
                break;
            case 3:
                cin >> x;
                auto tmp = lst.query(1, lst.n).first;
                assert(tmp == rst.query(1, rst.n).first);
                l = lst.query(1, lst.n).second;
                r = rst.query(1, rst.n).second;
                l = revsv[l], r = revsv[r];
                if(!tmp || l == -1 || l == r&&l == x) {
                    cout << -1 << endl;
                }
                else {
                    cout<< max(findA[(getLCA(l, x))], findA[(getLCA(r,x))]) << endl;
                }
                break;
        }
    }
}