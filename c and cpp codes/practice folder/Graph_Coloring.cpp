#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

#define MINT_MACRO_RUNTIME_MOD

struct Mint {
    int val;
    int MOD;
    Mint(long long v = 0, int MOD = M) : MOD(MOD) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    Mint& operator=(long long v) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; return *this; }
    Mint& operator=(const Mint& o) { assert(MOD == o.MOD); val = o.val; return *this; }
    static int mod_inv(int a, int m) {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const { return val; }
    explicit operator bool() const { return val; }
    Mint& operator+=(const Mint &o) { assert(MOD == o.MOD); val += o.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { assert(MOD == o.MOD); val -= o.val; if (val < 0) val += MOD; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
           asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) { assert(MOD == other.MOD); val = fast_mod((uint64_t) val * other.val, MOD); return *this; }
    Mint& operator/=(const Mint &other) { assert(MOD == other.MOD); return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    template<typename T>
    friend Mint operator+(const T& a, const Mint &b) { return Mint(a, b.MOD) += b; }
    template<typename T>
    friend Mint operator-(const T& a, const Mint &b) { return Mint(a, b.MOD) -= b; }
    template<typename T>
    friend Mint operator*(const T& a, const Mint &b) { return Mint(a, b.MOD) *= b; }
    template<typename T>
    friend Mint operator/(const T& a, const Mint &b) { return Mint(a, b.MOD) /= b; }
    template<typename T>
    friend Mint operator+(const Mint &a, const T& b) { return Mint(a) += Mint(b, a.MOD); }
    template<typename T>
    friend Mint operator-(const Mint &a, const T& b) { return Mint(a) -= Mint(b, a.MOD); }
    template<typename T>
    friend Mint operator*(const Mint &a, const T& b) { return Mint(a) *= Mint(b, a.MOD); }
    template<typename T>
    friend Mint operator/(const Mint &a, const T& b) { return Mint(a) /= Mint(b, a.MOD); }
    Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
    Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const { return Mint(val == 0 ? 0 : MOD - val, MOD); }
    bool operator==(const Mint &other) const { assert(MOD == other.MOD); return val == other.val; }
    bool operator!=(const Mint &other) const { assert(MOD == other.MOD); return val != other.val; }
    Mint inv() const { return Mint(mod_inv(val, MOD), MOD); }
    Mint operator[](long long p) {
        assert(p >= 0);
        Mint a = *this, res(1, MOD);
        while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
        return res;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream& operator >> (istream &stream, Mint &m) { return stream >> m.val; } 
};

using mint = Mint;

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

void print(int TT, int ans) {
    cout << "Case " << TT << ": " << ans << endl;
}

int gauss(int n, int m, vector<vector<mint>>& mat, vector<mint>& ans, vector<int>& where) {
    if(n) assert(mat[0].size() == m + 1);
    where.assign(m, -1);
    for(int row = 0, col = 0; row < n and col < m; ++col) {
        int sel = -1;
        for(int nrow = row; nrow < n; ++ nrow) if(mat[nrow][col].val) {
            sel = nrow;
            break;
        }
        if(sel == -1) continue;
        swap(mat[row], mat[sel]);
        where[col] = row;

        for(int nrow = 0; nrow < n; ++ nrow) if(nrow != row and mat[nrow][col].val) {
            auto mult = mat[nrow][col] / mat[row][col];
            for(int j=0;j<=m;++j) mat[nrow][j] -= mult * mat[row][j];
        }
        row++;
    }

    debug(mat);

    ans.assign(m, mint(0, mat[0][0].MOD));
    for(int i=0;i<m;++i) if(where[i] != -1) {
        ans[i] = mat[where[i]][m] / mat[where[i]][i];
    }

    for(int i=0;i<n;++i) {
        mint sum {0, mat[0][0].MOD};
        for(int j=0;j<m;++j) sum += ans[j] * mat[i][j];
        if(sum != mat[i][m]) return 0;
    }

    if(*min_element(all(where)) == -1) return INF;
    return 1;
}

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
        int n,m,k;
        cin >> n >> m >> k; // k is prime
        vector mat(n, vector(n + 1, mint(0, k)));
        for(int i=0;i<n;++i) {
            mat[i][i] = 1;
        }
        for(int i=0;i<m;++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            mat[u][v] = mat[v][u] = -1;
        }
        vector<mint> ans;
        vector<int> where;
        auto solutions = gauss(n, n, mat, ans, where);
        if(! solutions) assert(false);
        int cnt{};
        for(int i=0;i<n;++i) if(where[i] == -1) cnt += 1;
        print(TT, mint(k)[cnt].val);
    }
}