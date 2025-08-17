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

// #define int long long
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

struct segtree
{

#define LID id + 1
#define RID id + 2 * (mid - segl + 1)
#define TREESZ 2 * sz - 1

    using T = pair<int,int>;
    using V = int;

    int n;
    vector<T> tree;
    vector<V> lazy;
    T zero = {-INF, -1};
    V lazy_zero = 0;

    segtree(int sz)
    {
        n = sz;
        tree.assign(TREESZ, zero);
        lazy.assign(TREESZ, lazy_zero);
        vector<int> init(n, 0);
        build(init);
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size()) { build(v); }

    template <typename U>
    inline void init_node(int id, const U &val) { tree[id] = val; }
    inline T combine(T &c1, T &c2) { 
        if(c1.first == c2.first) return min(c1,c2);
        return max(c1, c2);
     }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (segl == segr)
        {
            init_node(id, T({v[segl], segl}));
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
    inline void update_tree_node(T &node, U &upd, int segl, int segr)
    {
        node.first += upd;
    }
    inline void update_tree_node(T &node, V &pTag, int segl, int segr)
    {
        node.first += pTag;
    }

    template <typename U>
    inline void update_lazy_node(V &tag, U &upd)
    {
        tag += upd;
    }
    inline void update_lazy_node(V &tag, V &pTag)
    {
        tag += pTag;
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
                update_lazy_node(lazy[child], lazy[id]), update_tree_node(tree[child], lazy[id], csegl, csegr);
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
            update_tree_node(tree[id], val, segl, segr);
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

    T query(int val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        if(tree[id].first <  val) return zero;
        if (segl == segr)
        {
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(val, index_l, index_r, LID, segl, mid);
        if(leftVal != zero) return leftVal;
        return query(val, index_l, index_r, RID, mid + 1, segr);
    }
    auto query(int val, int index) { return query(val, index, index); }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int n,m;
    cin >> n >> m;
    segtree st(n);
    for(int i=0;i<m;++i) {
        int q;
        cin >> q;
        int l, r, v, x;
        switch(q) {
            case 1:
                cin >> l >> r >> v;
                --r;
                st.modify(v, l, r);
                break;
            case 2:
                cin >> x >> l;
                auto u = st.query(x, l, n).second;
                cout << u << endl;
                break;
        }
    }
}