#include <bits/stdc++.h>
const long double EPS = 1e-8;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
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

int x, y, k;
int ax,ay,bx,by;
vector<int> cx, cy;

int gauss(vector<vector<double>>& mat, vector<double>& ans) {
    int n = mat.size(), m = 0;
    if(n) m = mat[0].size();

    vector<int> where(m, -1);

    for(int row=0, col=0; row < n and col < m; ++ col) {
        int sel = row;
        for(int nrow = row + 1; nrow < n; ++ nrow) {
            if (abs(mat[nrow][col]) > abs(mat[row][col]))
                sel = nrow;
        }
        if(abs(mat[sel][col]) < EPS) continue;
        swap(mat[sel], mat[row]);

        where[col] = row;

        for(int nrow = 0; nrow < n; ++ nrow) if(nrow != row and abs(mat[nrow][col]) >= EPS) {
            auto mul = mat[nrow][col] / mat[row][col];
            for(int ncol = col; ncol < m; ++ncol)
                mat[nrow][ncol] -= mul * mat[row][ncol];
        }
        ++row;
    }
    ans.assign(m - 1, 0);
    for(int i=0;i<m - 1;++i) if(where[i] != -1) ans[i] = mat[where[i]][m - 1] / mat[where[i]][i];
    for(int i=0;i<n;++i) {
        double sum = 0;
        for(int j=0; j < m - 1; ++j ) sum += ans[j] * mat[i][j];
        if(abs(sum - mat[i][m-1]) >= EPS) return 0;
    }
    for(int i=0;i<m-1;++i) if(where[i] == -1) return INF;
    return 1;
}

bool isBlocked(int x, int y) {
    for(int i=0;i<k;++i) if(x == cx[i] and y == cy[i]) return true;
    return false;
}

int getHash(int a, int b) {
    return a * 1'000'000 + b;
}

mint calculateCnt(int aC, int bC, umap<int, mint>& cache, int curAMul = 0, int curBMul = 0) {
    if(cache.find(getHash(curAMul,curBMul)) != cache.end()) return cache[getHash(curAMul, curBMul)];
    if(curAMul == aC and curBMul == bC) return cache[getHash(curAMul, curBMul)] = 1;
    if(curAMul > aC or curBMul > bC or isBlocked(curAMul * ax + curBMul * bx, curAMul * ay + curBMul * by)) return cache[getHash(curAMul, curBMul)] = 0;

    return cache[getHash(curAMul, curBMul)] = calculateCnt(aC, bC, cache, curAMul + 1, curBMul) + calculateCnt(aC, bC, cache, curAMul, curBMul + 1);
}

vector<int> normalBlockers;

bool isNormalizedBlocked(int x) {
    for(auto val: normalBlockers) if (val == x) return true;
    return false;
}

int solveNormalized() {

    if(min(abs(ax), abs(bx)) == 0 and x == 0) {
        return -1;
    } 

    bool _startReachable[2010]{}, _endReachable[2010]{}, _isLoopable[2010]{}, _active[2010]{};
    bool* startReachable = _startReachable + 1005;
    bool* endReachable = _endReachable + 1005;
    bool* isLoopable = _isLoopable + 1005;
    bool* active = _active + 1005;

    bool infEscapePos{}, minInfEscapePos{}, infEscapeNeg{}, minInfEscapeNeg{};
    
    auto dfs = [](auto self, int cur, bool* reachable, bool* active, int ax, int bx, bool* loopable, bool& infEscape, bool& minInfEscape) -> void {
    
        if(active[cur]) {
            if(loopable != nullptr) loopable[cur] = true;
        }
        if(reachable[cur]) return;
        reachable[cur] = true;
        active[cur] = 1;
        if(cur + max(ax, bx) > 1000)
            infEscape = true;
        if(cur + min(ax, bx) < -1000)
            minInfEscape = true;
        if(abs(cur + ax) <= 1000 and !isNormalizedBlocked(cur + ax))
            self(self, cur + ax, reachable, active, ax, bx, loopable, infEscape, minInfEscape);
        if(ax != bx and abs(cur + bx) <= 1000 and !isNormalizedBlocked(cur + bx))
            self(self, cur + bx, reachable, active, ax, bx, loopable, infEscape, minInfEscape);
        active[cur] = 0;
    };

    dfs(dfs, 0, startReachable, active, ax, bx, isLoopable, infEscapePos, minInfEscapePos);
    dfs(dfs, x, endReachable, active, -ax, -bx, nullptr, infEscapeNeg, minInfEscapeNeg);

    if(infEscapePos and infEscapeNeg) return -1;
    if(minInfEscapePos and minInfEscapeNeg) return -1;

    for(int i=-1000; i<= 1000; ++i)
        if(endReachable[i] and isLoopable[i])
            return -1;

    auto dfsSolve =
    [](auto self, int cur, map<int,mint>& cache, int ax, int bx, int x, bool* startReachable, bool* endReachable) ->mint {
        if(abs(cur) > 1000 or ! startReachable[cur] or ! endReachable[cur]) return 0;
        if(cur == x) return 1; // there is no loop
        if(cache.contains(cur)) return cache[cur];
        return cache[cur] = self(self, cur + ax, cache, ax, bx, x, startReachable, endReachable)
        + (ax == bx ? 0 : self(self, cur + bx, cache, ax, bx, x, startReachable, endReachable));
    };
    map<int,mint> cache;
    return dfsSolve(dfsSolve, 0, cache, ax, bx, x, startReachable, endReachable).val;
}

bool isMultiple(int big, int small) {
    if(big == small) return true;
    if(small == 0) return false;
    if(big % small == 0) return true;
    return false;
}

int gaussWrapper(int x, int y, vector<double>& ans) {
    vector<vector<double>> mat = { {(double) ax, (double) bx, (double) x} , {(double) ay, (double) by, (double) y} };
    auto solCnt = gauss(mat, ans);
    if(solCnt == 1) {
        for(auto val: ans) {
            if(llround(val) < 0) return 0;
            if(abs(val - llround(val)) >= EPS) return 0;
        }
    }
    return solCnt;
}

vector<int> getIntV(vector<double>& a)
{
    vector<int> b;
    for(auto e: a) b.push_back(llround(e));
    return b;
}

const int factLim = (int)5e6;

mint factorial(int x) {
    static mint fact[factLim + 1] {};
    if(! fact[0]) {
        fact[0] = 1;
        for(int i=1;i<=factLim; ++i) fact[i] = fact[i-1] * i;
    }
    return fact[x];
}

mint rfactorial(int x) {
    static mint rfact[factLim + 1] {};
    if(!rfact[0]) {
        rfact[factLim] = factorial(factLim).inv();
        for(int i=factLim - 1; i>=0; --i) {
            rfact[i] = rfact[i + 1] * (i + 1);
        }
    }

    return rfact[x];
}

mint nck(int n, int k) {
    if(n < 0 or k < 0 or n < k) return 0;
    return factorial(n) * rfactorial(n - k) * rfactorial(k);
}

mint calculateCnt2(vector<double>& _ans) {
    auto ans = getIntV(_ans);
    vector<vector<int>> cAnss;
    for(int i=0;i<k;++i) {
        vector<double> cAns;
        if(gaussWrapper(cx[i], cy[i], cAns)) { // can only return 0 or 1 since solCnt was 1
            cAnss.push_back(getIntV(cAns));
        }
    }
    sort(all(cAnss), [](auto a, auto b) {return a[0] + a[1] < b[0] + b[1];});
    cAnss.push_back(ans);

    vector<mint> dp(cAnss.size());
    for(int i=0;i<cAnss.size();++i) {
        dp[i] = nck(cAnss[i][0] + cAnss[i][1], cAnss[i][0]);
        for(int j=0;j<i;++j) if(cAnss[i][0] >= cAnss[j][0] and cAnss[i][1] >= cAnss[j][1]) {
            dp[i] -= nck(cAnss[i][0] + cAnss[i][1] - cAnss[j][0] - cAnss[j][1], cAnss[i][1] - cAnss[j][1]) * dp[j];
        }
    }

    return dp.back();
}

int solve() {
    vector<double> ans;
    auto solCnt = gaussWrapper(x, y, ans);
    if(solCnt == 0) return 0;
    if(solCnt == 1) {
        // umap<int, mint> cache;
        // return calculateCnt(llround(ans[0]), llround(ans[1]), cache).val;
        return calculateCnt2(ans).val;
    }

    // solcnt is INF
    int gx = gcd(ax, bx), gy = gcd(ay, by);
    if(!isMultiple(x, gx) or !isMultiple(y, gy)) return 0;

    if(gx < gy) {
        swap(gx, gy);
        swap(ax, ay);
        swap(bx, by);
        swap(cx, cy);
        swap(x, y);
    }

    if(abs(ax) < abs(bx)) {
        swap(ax, bx);
        swap(ay, by);
    }

    normalBlockers.clear();

    for(int i=0;i<k;++i) {
        if(cx[i] * ay == cy[i] * ax and isMultiple(cx[i], gx) and isMultiple(cy[i], gy)) {
            normalBlockers.push_back(cx[i] / gx);
        }
    }
    if(gx) x /= gx, ax /= gx, bx /= gx;
    if(gy) y /= gy, ay /= gy, by /= gy;
    return solveNormalized();
}

int maxAbs() {
    int mx = max(abs(x), abs(y));
    if(cx.size()) mx = max({mx, *max_element(all(cx)), -*min_element(all(cx))});
    if(cy.size()) mx = max({mx, *max_element(all(cy)), -*min_element(all(cy))});
    return mx;
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
        cin >> x >> y >> k;
        cin >> ax >> ay >> bx >> by;
        cx.assign(k, 0);
        cy.assign(k, 0);
        rep(i,0,k) cin >> cx[i] >> cy[i];
        if(maxAbs() > 500)
            assert(false);
        cout << solve() << endl;
    }
}