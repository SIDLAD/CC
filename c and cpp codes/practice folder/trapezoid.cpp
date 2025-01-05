#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 30013;
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order


#define MINT_MACRO

template<int _MOD = M>
struct Mint {
    int val;
    int MOD = _MOD;
    Mint(long long v = 0, int MOD = _MOD) : MOD(MOD) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    Mint& operator=(long long v) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; return *this; }
    static int mod_inv(int a, int m) {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const { return val; }
    explicit operator bool()const { return val; }
    Mint& operator+=(const Mint &o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { val -= o.val; if (val < 0) val += MOD; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
           asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val, MOD); return *this; }
    Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
    Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const { return val == 0 ? 0 : MOD - val; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const { return mod_inv(val, MOD); }
    Mint operator[](long long p) {
        assert(p >= 0);
        Mint a = *this, res = 1;
        while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
        return res;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream& operator >> (istream &stream, Mint &m) { return stream>>m.val; } 
};

using mint = Mint<>;

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

#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define range(it, start, end) for (auto it = start; it < end; it++)

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

template <typename T = int, typename V = T>
struct segtreemax
{
    int n;
    vector<T> tree;
    // vector<V> lazy;
    T zero = 0; // Change according to QUERY operation
    // V lazy_zero = 0; // Change according to MODIFY operation

    segtreemax(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(2 * sz - 1, zero);
        // lazy.resize(2 * sz - 1, lazy_zero);
    }

    template <typename U>
    segtreemax(vector<U> &v) : segtreemax(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return max(a,b);
    }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = v[segl];  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    // void propagate(int id, int segl, int segr)
    // {
        // if(lazy[id] == lazy_zero)return;
        // if(segl != segr)
        // {
            // int mid = (segl + segr) / 2;
            // array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            // for(auto child : children)
            // {
                // tree[child] = lazy[id];  // Change according to MODIFY operation
                // lazy[child] = lazy[id];  // Change according to MODIFY operation
            // }
        // }
        // lazy[id] = lazy_zero;
    // }

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
            tree[id] = val; // Change according to MODIFY operation
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


template <typename T = int, typename V = T>
struct segtreeadd
{
    int n;
    vector<T> tree;
    vector<V> lazy;
    T zero = 0; // Change according to QUERY operation
    V lazy_zero = -INF; // Change according to MODIFY operation

    segtreeadd(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(2 * sz - 1, zero);
        lazy.resize(2 * sz - 1, lazy_zero);
    }

    template <typename U>
    segtreeadd(vector<U> &v) : segtreeadd(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return a + b;
    }

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id] == lazy_zero)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            for(auto child : children)
            {
                tree[child] = lazy[id];  // Change according to MODIFY operation
                lazy[child] = lazy[id];  // Change according to MODIFY operation
            }
        }
        lazy[id] = lazy_zero;
    }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = val; // Change according to MODIFY operation
            lazy[id] = val; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, id + 1, segl, mid);
        modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    template <typename U>
    auto add(U val, int index) { mint cur = query(index); modify(val + cur,index); }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        propagate(id, segl, segr);
        
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
    int n;
    cin>>n;
    vector<array<int,4>> inp;
    vector<pair<int,int>> up,down;
    set<int> st;
    range(i,0,n)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        inp.push_back({a,b,c,d});
    }
    sort(all(inp));
    range(i,0,n)
    {
        auto [a,b,c,d] = inp[i];
        up.push_back({a,b}),down.push_back({c,d});
        st.insert(a);
        st.insert(b);
        st.insert(c);
        st.insert(d);
    }

    umap<int,int> mapping;
    int _ = 0;
    for(auto ele:st)mapping[ele] = _++;
    for(auto& [a,b]: up)a = mapping[a],b = mapping[b];
    for(auto& [a,b]: down)a = mapping[a],b = mapping[b];

    int len = _;

    vector<int> maxind(n);
    segtreemax stmx(len);

    vector<array<int,3>> pts;
    for(int i=0;i<n;i++)
    {
        pts.push_back({up[i].first,0,i});
        pts.push_back({up[i].second,-1,i});
    }
    sort(all(pts));

    for(int i=0;i < pts.size(); i++)
    {
        if(pts[i][1] == 0)
        maxind[pts[i][2]] = stmx.query(0,down[pts[i][2]].first) + 1;
        else
        stmx.modify(maxind[pts[i][2]],down[pts[i][2]].second);
    }
    int mxval = stmx.query(0,INF);
    cout<<mxval<<" ";

    segtreeadd<mint> stadd(len);
    
    vector<vector<array<int,3>>> sortedpts(mxval + 2);
    for(int i=0;i<n;i++)
    {
        int val = maxind[i];
        sortedpts[val].push_back({up[i].first,0,i});
        sortedpts[val + 1].push_back({up[i].second,-1,i});
    }
    for(int i=1;i<=mxval;i++)sort(all(sortedpts[i]));
    
    vector<mint> numways(n);
    for(auto [_,__,i]:sortedpts[1])numways[i] = 1;

    for(int i=2;i<=mxval;i++)
    {
        stadd.modify(0,0,INF);
        debug(stadd.query(0,INF));
        for(auto [_,t,ind]:sortedpts[i])
        {
            if(t == 0)
            numways[ind] = stadd.query(0,down[ind].first);
            else{
            stadd.add(numways[ind],down[ind].second);
            debug(numways[ind],ind);
            debug(stadd.query(0,INF));
            }
        }
        debug(stadd.query(0,INF));
        debug();
    }
    mint ans = 0;
    for(int i=0;i<n;i++)if(maxind[i] == mxval)ans += numways[i];
    cout<<ans<<endl;
}