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
#define cout(x) cout << ((x) ? "YES" : "NO") << endl
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


struct SparseTable
{
    vector<int>& a;
    vector<vector<int>> table;
    int n;

    bool _compare(auto a, auto b) { return a < b; } // Change according to QUERY operation
    int identity = INF; // Change according to QUERY operation

    SparseTable(vector<int>& a) : a(a), n(a.size())
    {
        int lgN = (int)bit_width((unsigned int)n) - 1;
        table.resize(lgN + 1,vector<int>(n));
        rep(i,0,lgN + 1)rep(j,0,n - (1<<i) + 1)
        {
            if(i == 0)
                table[i][j] = j;
            else if(_compare (a[table[i-1][j]] , a[table[i-1][j + (1<<i-1)]]) )
                table[i][j] = table[i-1][j];
            else
                table[i][j] =  table[i-1][j + (1<<i-1)];
        }
    }

    int query_i(int l, int r)
    {
        assert(l <= r and l < n and r >= 0);
        l = max(l, (int)0), r = min(r, n - 1);

        int lgN = (int)bit_width((unsigned int)(r - l + 1)) - 1;
        if(_compare (a[table[lgN][l]] , a[table[lgN][r - (1<<lgN) + 1]]) )
            return table[lgN][l];
        else
            return table[lgN][r - (1<<lgN) + 1];
    }

    int query_val(int l, int r) { return (l > r || l >= n || r < 0) ? identity : a[query_i(l,r)]; }
};

struct segnode {
    int lmx;
    int rmx;
    int tot;
    int mx;
    segnode(int x) {
        lmx = max(0ll,x);
        rmx = max(0ll,x);
        mx = max(0ll, x);
        tot = x;
    }
    segnode(segnode& l, segnode& r) {
        lmx = max(l.lmx, l.tot + r.lmx);
        rmx = max(r.rmx, r.tot + l.rmx);
        tot = l.tot + r.tot;
        mx = max({l.mx, r.mx, r.lmx + l.rmx});
    }
};


struct segtree //~
{

#define LID id + 1
#define RID id + 2 * (mid - segl + 1)
#define TREESZ 2 * n - 1

    using T = segnode; //~
    // using V = T; //~

    int n;
    vector<T> tree;
    // vector<V> lazy;
    int mn = INF;
    // V lazy_zero = 0; //~
    SparseTable& st;

    segtree(int sz, SparseTable& st): st(st) //~
    {
        n = sz;
        tree.assign(TREESZ, -1);
        build();
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size()) { build(v); } //~

    inline void init_node(int id, int index) { tree[id] = -1; } //~
    inline T combine(T &c1, T &c2) { return T(c1,c2); } //~

    void build(int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (segl == segr)
        {
            init_node(id, segl);
            return;
        }
        int mid = (segl + segr) / 2;
        build(LID, segl, mid);
        build(RID, mid + 1, segr);
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
    inline void update_tree_node(int id, int segl, int segr, U &upd)
    {
        tree[id] = upd; //~
        mn = min(mn, st.query_val(segl, segl));
    }
    // inline void update_tree_node(int id, int segl, int segr, V &pTag)
    // {
        // tree[id] = pTag; //~
    // }

    // template <typename U>
    // inline void update_lazy_node(V &tag, U &upd)
    // {
        // tag = upd; //~
    // }
    // inline void update_lazy_node(V &tag, V &pTag)
    // {
        // tag = pTag; //~
    // }

    // void propagate(int id, int segl, int segr)
    // {
        // if (lazy[id] == lazy_zero)
            // return;
        // if (segl != segr)
        // {
            // int mid = (segl + segr) / 2;
            // array<array<int, 3>, 2> children = {{{LID, segl, mid}, {RID, mid + 1, segr}}};
            // for (auto [child, csegl, csegr] : children)
                // update_lazy_node(lazy[child], lazy[id]), update_tree_node(id, csegl, csegr, lazy[id]);
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
        if (tag_condition(index_l, index_r, id, segl, segr, val))
        {
            // update_lazy_node(lazy[id], val); //~
            update_tree_node(id, segl, segr, val);
            return;
        }
        // propagate(id, segl, segr); //~
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, LID, segl, mid);
        modify(val, index_l, index_r, RID, mid + 1, segr);

        tree[id] = combine(tree[LID], tree[RID]);

        auto rid = query_walk(tree[LID].rmx, RID, mid + 1, segr, 1);
        auto lid = query_walk(tree[RID].lmx, LID, segl, mid, 0);
        debug(segl, segr);
        debug(lid, mid);
        debug(mid + 1, rid);
        debug(tree[5].lmx, tree[5].rmx, tree[5].mx, tree[5].tot);
        mn = min({mn, (st.query_val(mid + 1, rid)), (st.query_val(lid, mid))});
        debug(mn);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    int query_walk(int val, int id, int segl, int segr, int dirR) {
        if(dirR) {
            debug(dirR, val, segl, segr);
            if(val + tree[id].lmx < 0) return -1;
            if(segl == segr) {if(val + tree[id].tot < 0) return segl - 1; else return segl;}
            int mid = segl + segr >> 1;
            if(val + tree[LID].tot + tree[RID].lmx < 0) return query_walk(val, LID, segl, mid, dirR);
            else return query_walk(val + tree[LID].tot, RID, mid + 1, segr, dirR);
        }
        else {
            debug(dirR, val, segl, segr);
            if(val + tree[id].rmx < 0) return n;
            if(segl == segr){ if(val + tree[id].tot < 0) return segl + 1; else return segl;}
            int mid = segl + segr >> 1;
            if(val + tree[RID].tot + tree[LID].rmx < 0) return query_walk(val, RID, mid + 1, segr, dirR);
            else return query_walk(val + tree[RID].tot, LID, segl, mid, dirR);
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        vi v(n);
        arrput(v);

        vector<pair<int,int>> pts(n);
        for(int i=0;i<n;++i) pts[i] = {v[i], i};
        sort(all(pts)); reverse(all(pts));
        int ans = 0;
        SparseTable st(v);
        debug(pts);
        segtree seg(n, st);
        for(auto [val, i]: pts) {
            seg.modify(1, i);
            debug();
            ans = max(ans, (val) - seg.mn);
        }
        cout << ans << endl;
    }
}