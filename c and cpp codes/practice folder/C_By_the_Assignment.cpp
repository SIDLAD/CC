#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 998'244'353;
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
const int MAX_N = (int) 2e5 + 1;
int a[MAX_N];
int visited[MAX_N];
int bip[MAX_N];
int tin[MAX_N];
int lo[MAX_N];
int cycleTag[MAX_N];
vector<int> edges[MAX_N];
uset<int> bridges;

constexpr int hasher(int a, int b) {
    return a + (MAX_N + 1)  * b;
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
        int n,m,V;
        cin >> n >> m >> V;
        for(int i=1;i<=n;++i) cin >> a[i];
        memset(visited + 1, 0, sizeof(int) * n);
        memset(bip + 1, -1, sizeof(int) * n);
        memset(tin + 1, -1, sizeof(int) * n);
        memset(lo + 1, -1, sizeof(int) * n);
        memset(cycleTag + 1, -1, sizeof(int) * n);
        bridges.clear();
        for(int i=1;i<=n;++i) edges[i].clear();
        for(int i=0;i<m;++i) {
            int a,b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int curT = 0;

        auto dfs2 = [&curT](auto self, int cur=1, int parent=1, int parity=0) -> void {
            bip[cur] = parity;
            visited[cur] = 1;
            tin[cur] = curT++;
            lo[cur] = INF;
            for(auto nbr: edges[cur]) if(nbr != parent) {
                if(!visited[nbr]) {
                    self(self, nbr, cur, parity^1);
                    if(lo[nbr] > tin[cur]) {
                        bridges.insert(hasher(nbr,cur));
                        bridges.insert(hasher(cur, nbr));
                    }
                }
                lo[cur] = min({lo[cur], lo[nbr], tin[nbr]});
            }
        };
        dfs2(dfs2);
        auto dfs25 = [] (auto self, int cur, int cc) -> void {
            visited[cur] = 2;
            cycleTag[cur] = cc;
            for(auto nbr: edges[cur]) if(visited[nbr] != 2) if(bridges.find(hasher(nbr,cur)) == bridges.end()) {
                self(self, nbr, cc);
            }
        };
        for(int i=1;i<=n;++i) if(visited[i] != 2) dfs25(dfs25, i, i);
        
        bool ch1 = true;
        
        auto dfs3 = [&ch1] (auto self, int cur, int aval) -> void {
            if(a[cur] != -1 && a[cur] != aval) {
                ch1 = false;
                return;
            }
            visited[cur] = 3;
            for(auto nbr:edges[cur]) if(cycleTag[nbr] == cycleTag[cur]) if(visited[nbr] != 3)
                self(self, nbr, aval);
        };
        for(int i=1;i<=n;++i) for(auto nbr: edges[i]) if(bip[i] == bip[nbr]) {
            if(bip[i] == bip[nbr]) dfs3(dfs3, i, 0);
            else dfs3(dfs3, i, a[i]);
        }
        for(int i=1;i<=n;++i) for(auto nbr: edges[i]) if(visited[i] == 2 && a[i] != -1) {
            if(bip[i] == bip[nbr]) dfs3(dfs3, i, 0);
            else dfs3(dfs3, i, a[i]);
        }
        if(ch1 == false) {
            cout << 0 << endl;
            continue;
        }
        mint ans = 1;
        for(int i=0;i++<n;) if(visited[i] != 3) {
            if(a[i] != -1) {
                assert(visited[i] != 2);
                continue;
            }
            if(visited[i] != 2) ans *= V;
            else {
                ans *= V;
                dfs3(dfs3, i, -1);
            }
        }
        cout << ans << endl;
    }
}