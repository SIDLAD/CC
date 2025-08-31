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

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
// #define endl '\n' //comment out for interactive problems
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
        cin >> n >> m >> k;
        vector<pii> pts;
        bool primaryCheck = true;
        set<pii> blackOut;
        for(int i=0;i<=k;++i) {
            int a,b;
            cin >> a >> b;
            pts.emplace_back(a,b);
            if(i) {
                int d1 = a - pts[i-1].first;
                int d2 = b - pts[i-1].second;
                if((d1 + d2)&1) primaryCheck = false;
                else if(max(abs(d1),abs(d2)) > 2) primaryCheck = false;
                else if(max(abs(d1), abs(d2)) == 2) {
                    if(min(abs(d1), abs(d2)) != 0) primaryCheck = false;
                    pair<int,int> pp = {a + pts[i-1].first >> 1,  b + pts[i-1].second >> 1};
                    if(blackOut.contains(pp)) primaryCheck = false;
                    else blackOut.insert(pp);
                }
            }
        }
        if(!primaryCheck) {cout << 0 << endl; continue;}
        map<pii, set<pii>> edges;
        for(int i=1;i<=k;++i) {
            if(max(abs(pts[i].first - pts[i-1].first), abs(pts[i].second - pts[i-1].second)) != 1) continue;
            pii p1 = {pts[i].first, pts[i-1].second};
            pii p2 = {pts[i-1].first, pts[i].second};
            edges[p1].emplace(p2);
            edges[p2].emplace(p1);
        }

        set<pii> curActive;
        set<pair<pii,pii>> curSet;
        auto blackitout = [&](auto self, pii pr, pii par) -> int {
            blackOut.insert(pr);
            curActive.insert(pr);
            int ret = 1;
            bool flag = true;
            if(edges.contains(pr)) for(auto nbr : edges[pr])
            if(nbr != par) {
                if(!blackOut.contains(nbr))
                {
                    curSet.insert({min(pr,nbr), max(pr, nbr)});
                    auto ret1 = self(self, nbr, pr);
                    if(ret1 == -2) return -2;
                    else ret += ret1;
                }
                else if (curActive.contains(nbr)) curSet.insert({min(pr,nbr), max(pr, nbr)});
                else if(blackOut.contains(nbr)) return -2;
            }
            return !flag ? -1 : ret;
        };
        auto bcc = blackOut;
        for(auto p: bcc) 
        {
            curSet.clear();
            curActive.clear();
            int ret = blackitout(blackitout, p, p);
            if(ret == -2 || ret <= sz(curSet)){primaryCheck = false;break;}
        }
        if(!primaryCheck) {cout << 0 << endl; continue;}

        mint ans = 1;
        for(auto [p,_]:  edges) if(!blackOut.contains(p))
        {
            curActive.clear();
            curSet.clear();
            curActive.clear();
            auto ret = blackitout(blackitout, p, p);
            int ret2 = sz(curSet);
            if(ret == ret2) ans *= 2;
            else if(ret2 > ret) {ans = 0; break;}
            else ans *= ret;

        }
        cout << ans << endl;
    }
}