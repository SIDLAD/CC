#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
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

void print(int x, int TT) {
    cout << "Case #" << TT << ": " << x << endl;
}

const int MAXN = (int) 1e6;
vector<int> primeCount(MAXN + 1);

vi primeFactorize(int n) {
    vector<int> ans;
    for(int i=2;i*i <= n;++i) {
        int cnt = 0;
        while(n%i == 0) {
            ++cnt;
            n /= i;
        }
        if(cnt) ans.push_back(cnt);
    }
    if(n > 1) ans.push_back(1);
    return ans;
}

vi calculateDivs(int n) {
    vector<int> divs;
    vector<int> divs2;
    for(int i=1;i*i <= n;++i) if(n%i == 0) {
        divs.push_back(i);
        if(i*i != n) divs2.push_back(n/i);
    }
    divs.insert(divs.end(), divs2.rbegin(), divs2.rend());
    return divs;
}

mint nck(int n, int k) {
    if(k > n || n < 0 || k < 0) return 0;
    if(n - k > k) k = n - k;
    mint ans = 1;
    for(int i=n, j=1;i>k;--i, ++j) ans *= i, ans /= j;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("final_product_chapter_2_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n, a,b;
        cin >> n >> a >> b;
        mint ans = 0;
        auto divs = calculateDivs(b);
        for(auto div: divs) if(div <= a) {
            mint curans = 1;
            vector<int> solve{div, b/div};
            for(auto e: solve) {
                auto pf = primeFactorize(e);
                for(auto cnt: pf) {
                    curans *= nck(cnt + n - 1, n - 1);
                }
            }
            ans += curans;
        }

        print(ans.val, TT);
    }
}