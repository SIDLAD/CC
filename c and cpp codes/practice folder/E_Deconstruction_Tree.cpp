#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 998'244'353;
using namespace std;
//insert policy here


#define MINT_MACRO

template<int _MOD = M>
struct Mint {
    static constexpr int MOD = _MOD;
    
    int val;
    Mint(long long v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    Mint& operator=(long long v) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; return *this; }
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const { return val; }
    explicit operator bool() const { return val; }
    Mint& operator+=(const Mint &o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { val -= o.val; if (val < 0) val += MOD; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
           asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
    Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    template<typename T>
    friend Mint operator+(const T& a, const Mint &b) { return Mint(a) += b; }
    template<typename T>
    friend Mint operator-(const T& a, const Mint &b) { return Mint(a) -= b; }
    template<typename T>
    friend Mint operator*(const T& a, const Mint &b) { return Mint(a) *= b; }
    template<typename T>
    friend Mint operator/(const T& a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
    Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const { return val == 0 ? 0 : MOD - val; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const { return mod_inv(val); }
    Mint operator[](long long p) {
        assert(p >= 0);
        Mint a = *this, res = 1;
        while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
        return res;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream& operator >> (istream &stream, Mint &m) { return stream >> m.val; } 
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

template<typename T=int>
T input() {
    T x;
    cin >> x;
    return x;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SparseTable
{
    vector<int>& a;
    vector<vector<int>> table;
    int n;

    bool _compare(auto a, auto b) { return a > b; } // Change according to QUERY operation
    int identity = -INF; // Change according to QUERY operation

    SparseTable(vector<int>& a) : a(a), n(a.size())
    {
        int lgN = (int)bit_width((unsigned int)n) - 1;
        table.resize(lgN + 1,vector<int>(n));
        rep(i,0,lgN + 1) rep(j,0,n - (1<<i) + 1)
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

    int specialQ(int i) {
        assert(0<=i and i < n);
        return max(query_val(0, i - 1), query_val(i + 1, n - 1));
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
        vector<vi> edges(n + 1);
        for(int i=0;i<n-1;++i) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v), edges[v].push_back(u);
        }

        vi parent(n + 1, -1);
        vi subtreeMx(n + 1, 0); // not including self
        vi rootSubtreeInd(n + 1, 0);

        int mxLf = -1;
        
        auto dfs1 = [&](auto self, int cur, int p = -1, int rootSub = -1) -> void {
            rootSubtreeInd[cur] = rootSub;
            int chN = 0;

            for(auto x: edges[cur]) if(x != p) {
                parent[x] = cur;
                self(self, x, cur, rootSub == -1 ? chN : rootSub);
                subtreeMx[cur] = max({subtreeMx[cur], subtreeMx[x], x});
                ++chN;
            }
            if(sz(edges[cur]) == 1) mxLf = max(mxLf, cur);
        }; dfs1(dfs1, n);

        assert(mxLf != -1);

        vi stAr{};
        for(auto c: edges[n]) stAr.push_back(max(subtreeMx[c], c));
        SparseTable st(stAr);

        vector<mint> preDp(n + 1);
        preDp[mxLf] = 1;

        for(int i = mxLf + 1; i < n; ++i) {
            preDp[i] = preDp[i - 1];
            assert(subtreeMx[i] != i);
            if(subtreeMx[i] > i) continue;
            preDp[i] += preDp[i-1] - preDp[subtreeMx[i]];
        }
        for(int i=n-1;i>1;--i)
            preDp[i] -= preDp[i-1];
        
        for(int i=mxLf;i<n;++i) {
            if(st.specialQ(rootSubtreeInd[i]) < i) preDp[n] += preDp[i];
        }


        debug(preDp);
        debug(mxLf);
        cout << preDp[n] << endl;
    }
}