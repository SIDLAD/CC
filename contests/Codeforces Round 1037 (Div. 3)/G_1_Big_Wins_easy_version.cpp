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

struct walkseg
{

#define LID id + 1
#define RID id + 2 * (mid - segl + 1)
#define TREESZ 2 * n - 1

    using T = pair<int,int>;
    // using V = T;

    int n;
    vector<T> tree;
    // vector<V> lazy;
    T zero = {-1, INF};
    // V lazy_zero = 0;

    walkseg(int sz)
    {
        n = sz;
        tree.assign(TREESZ, zero);
        // lazy.assign(TREESZ, lazy_zero);
    }

    template <typename U>
    walkseg(vector<U> &v) : walkseg(v.size()) { build(v); }

    template <typename U>
    inline void init_node(int id, const U &val, int index) { tree[id] = {index, val}; }
    inline T combine(T &c1, T &c2) { if(c1.second == c2.second) return min(c1, c2); if(c1.second > c2.second) return c2; return c1; }

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
    inline void update_tree_node(int id, int segl, int segr, U &upd)
    {
        tree[id] = upd;
    }
    // inline void update_tree_node(int id, int segl, int segr, V &pTag)
    // {
        // tree[id] = pTag;
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
            // update_lazy_node(lazy[id], val);
            update_tree_node(id, segl, segr, val);
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

    T query(int val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        if(val < tree[id].second) return {-1, INF};
        if(segl == segr) return tree[id];
        
        // propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(val, index_l, index_r, LID, segl, mid);
        if(leftVal.first != -1) return leftVal;
        return query(val, index_l, index_r, RID, mid + 1, segr);
    }
    auto query(int val, int index) { return query(val, index, index); }
};

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
        SparseTable st(v);
        int ans = -INF;
        for(int i=1;i<=min(n, 100); ++i ){
            vi pre(n);
            for(int j=0;j<n;++j) pre[j] = (v[j] < i) ? -1 : 1;
            partial_sum(all(pre), pre.begin());
            debug(i);
            debug(pre);
            walkseg tree(pre);
            for(int j=n-1;j>=0;--j) {
                auto qr = tree.query(pre[j], 0, j - 1);
                if(pre[j] >= 0) qr = {-2, -2};
                if(qr.first == -1) continue;
                if(qr.first == -2) qr.first = -1;

                qr.first ++;
                if(i == 5)
                debug(qr.first);
                auto mn = st.query_val(qr.first, j);
                ans = max(ans, i - mn);
                if( i == 5)
                debug(i - mn, mn, i, j, v[j]);
            }
            debug();
        }
        cout << ans << endl;
    }
}