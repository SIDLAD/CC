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

struct N {
    int sum;
    int max;
} defN{0,0};

struct segtree
{
using T = N;
using V = T;

#define LID id + 1
#define RID id + 2 * (mid - segl + 1)

    int n;
    vector<T> tree;
    // vector<V> lazy;
    T zero = defN;
    // V lazy_zero = 0;

    segtree(int sz)
    {
        n = sz;
        tree.assign(2 * sz - 1, zero);
        // lazy.assign(2 * sz - 1, zero);
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size()) { build(v); }

    template <typename U>
    inline void init_node(int id, U &val) { tree[id] = {val, val}; }
    inline T combine(T &c1, T &c2) { return {c1.sum + c2.sum, max(c1.max, c2.max)}; }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (segl == segr)
        {
            init_node(id, v[segl]);
            debug(tree[id].sum, tree[id].max, segl);
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, LID, segl, mid);
        build(v, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
        debug(tree[id].sum, segl, segr);
    }

    bool break_condition(int index_l, int index_r, int id, int segl, int segr, optional<int> upd = nullopt)
    {
        if (index_l > index_r || index_l > segr || segl > index_r)
            return true;
        
        if(upd != nullopt && *upd > tree[id].max) return true;
        return false;
    }

    // inline void update_tree_node(T &node, V &pTag, int segl, int segr)
    // {
    //     node = pTag;
    // }

    // template <typename U>
    // inline void update_lazy_node(V &tag, U &upd)
    // {
        // tag = upd;
    // }
    // inline void update_lazy_node(V &tag, V &pTag)
    // {
        // tag = pTag;
    // }

    // void propagate(int id, int segl, int segr)
    // {
        // if (lazy[id] == lazy_zero)
            // return;
        // if (segl != segr)
        // {
            // int mid = (segl + segr) / 2;
            // array<array<int, 3>, 2> children = {{LID, segl, mid}, {RID, mid + 1, segr}};
            // for (auto [child, csegl, csegr] : children)
                // update_lazy_node(lazy[child], lazy[id]), update_tree_node(tree[child], lazy[id]);
        // }
        // lazy[id] = lazy_zero;
    // }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (break_condition(index_l, index_r, id, segl, segr, val))
        {
            return;
        }
        if(segl == segr) {
            val = tree[id].max % val;
            tree[id] = {val,val};
            return;
        }
        // propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, LID, segl, mid);
        modify(val, index_l, index_r, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    template <typename U>
    void set(U val, int index, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (segl > index || segr < index)
        {
            return;
        }
        if (segl == segr && segl == index)
        {
            // update_lazy_node(lazy[id], val, segl, segr);
            tree[id] = {val, val};
            return;
        }
        // propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        set(val, index, LID, segl, mid);
        set(val, index, RID, mid + 1, segr);
        tree[id] = combine(tree[LID], tree[RID]);
    }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (break_condition(index_l, index_r, id, segl, segr))
        {
            return zero;
        }
        if(index_l <= segl && segr <= index_r) return tree[id];
        // propagate(id, segl, segr);
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
    
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    arrput(v);
    debug(v);
    segtree st(v);
    debug(st.query(0,0).sum, st.query(1,1).sum, st.query(2,2).sum, st.query(3,3).sum, st.query(4,4).sum);
    for(int i=0;i<m;++i) {
        int qT;
        cin >> qT;
        int l,r,x,k;
        switch(qT) {
            case 1:
                cin >> l >> r;
                --l, --r;
                cout << st.query(l, r).sum << endl;
                break;
            case 2:
                cin >> l >> r >> x; --l, --r;
                st.modify(x, l, r);
                break;
            case 3:
                cin >> k >> x; --k;
                st.set(x, k);
                break;
        }
        debug(i + 1, st.query(0,0).sum, st.query(1,1).sum, st.query(2,2).sum, st.query(3,3).sum, st.query(4,4).sum);
    }
}