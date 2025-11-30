#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 998'244'353;
using namespace std;
//insert policy here


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
    template<typename T>
    friend Mint operator+(const T& a, const Mint &b) { return Mint(a,b.MOD) += b; }
    template<typename T>
    friend Mint operator-(const T& a, const Mint &b) { return Mint(a,b.MOD) -= b; }
    template<typename T>
    friend Mint operator*(const T& a, const Mint &b) { return Mint(a,b.MOD) *= b; }
    template<typename T>
    friend Mint operator/(const T& a, const Mint &b) { return Mint(a,b.MOD) /= b; }
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
        Mint a = *this, res(1, this->MOD);
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
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct segtree {
    int n;
    vector<mint> tree;
    vector<mint> lazy;
    segtree(int n): n(n), tree(4 * n, 0), lazy(4 * n, 1) {}

    void propagate(int segl, int segr, int id) {
        if(segl == segr) {lazy[id] = 1;}
        if(lazy[id] == 1) return;
        int mid = segl + segr >> 1;
        int lid = 2 * id;
        int rid = 2 * id + 1;
        lazy[lid] *= lazy[id];
        tree[lid] *= lazy[id];
        lazy[rid] *= lazy[id];
        tree[rid] *= lazy[id];
        lazy[id] = 1;
    }
    void add(int pos, int val, int segl= 0, int segr = -1, int id = 1) {
        if(segr == -1) segr = n - 1;
        if(segl > pos || segr < pos) return;
        propagate(segl,segr, id);
        if(segl == segr) {
            tree[id] += val;
            return;
        }
        int mid = segl + segr >> 1;
        int lid = 2 * id;
        int rid = 2 * id + 1;
        add(pos, val, segl, mid, lid);
        add(pos, val, mid + 1, segr, rid);
        tree[id] = tree[lid] + tree[rid];
    }
    void lazy_mult(int l, int r, int mult, int segl=0, int segr = -1, int id = 1) {
        if(segr == -1) segr = n - 1;
        if(r < segl || segr < l) return;
        if(segl >= l and segr <= r) {
            lazy[id] *= mult;
            tree[id] *= mult;
            return;
        }
        propagate(segl, segr, id);
        int mid = segl + segr >> 1;
        int lid = 2 * id;
        int rid = 2 * id + 1;
        lazy_mult(l, r, mult, segl, mid, lid);
        lazy_mult(l, r, mult, mid + 1, segr, rid);
        tree[id] = tree[lid] + tree[rid];
    }

    mint query(int pos, int segl=0, int segr = -1, int id = 1) {
        if(segr == -1) segr = n - 1;
        if(segl > pos || segr < pos) return 0;
        propagate(segl,segr, id);
        if(segl == segr) {
            return tree[id];
        }
        int mid = segl + segr >> 1;
        int lid = 2 * id;
        int rid = 2 * id + 1;
        return query(pos, segl, mid, lid) + query(pos, mid + 1, segr, rid);
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
        vi ls, rs;
        for(int i=0;i<n;++i) {
            if(!ls.size() || ls.back() < v[i]) ls.push_back(v[i]);
        }
        for(int i=n-1;i>=0;--i) {
            if(!rs.size() || rs.back() < v[i]) rs.push_back(v[i]);
        }
        int mxE = ls.back();
        rs.pop_back();

        
        // vector<mint> dpl(ls.size() + 1);
        // dpl[0] = 1;

        segtree stl(ls.size() + 1);
        stl.add(0, 1);
        vector<mint> answersl(n);
        for(int i=0;i<n;++i) {

            int ind = lower_bound(all(ls), v[i]) - ls.begin();
            stl.lazy_mult(ind + 1, ls.size(), 2);
            if(ls[ind] == v[i])  {
                mint addVal = stl.query(ind);
                stl.add(ind + 1, addVal.val);
            }

            // for(int j=0;j<ls.size();++j) {
            //     if(ls[j] >= v[i]) dpl[j + 1] *= 2;
            //     if(ls[j] == v[i]) dpl[j + 1] += dpl[j];
            // }
            answersl[i] = stl.query(ls.size());
        }

        segtree str(rs.size() + 1);
        str.add(0, 1);
        // vector<mint> dpr(rs.size() + 1);
        // dpr[0] = 1;
        vector<mint> answersr(n);
        for(int i=n-1;i>=0;--i) {

            int ind = lower_bound(all(rs), v[i]) - rs.begin();
            str.lazy_mult(ind + 1, rs.size(), 2);
            if(rs[ind] == v[i]) {
                mint addVal = str.query(ind);
                str.add(ind + 1, addVal.val);
            }
            // for(int j=0;j<rs.size(); ++j) {
            //     if(rs[j] >= v[i]) dpr[j + 1] *= 2;
            //     if(rs[j] == v[i]) dpr[j + 1] += dpr[j];
            // }
            answersr[i] = str.query(rs.size());
        }
        debug(answersl, answersr);
        mint ans = 0;
        mint prevSub = 0;
        for(int i=0;i<n;++i) if(v[i] == mxE) ans += (answersl[i] - (i == 0 ? 0 : answersl[i-1]))* answersr[i];
        cout << ans << endl;
    }
}