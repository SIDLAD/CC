#include <bits/stdc++.h>
const long double EPS = 1e-7;
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
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    mint one(1,m);
    vector<vector<mint>> subanswer(n + 1);
    vector<vector<mint>> answer(n + 1);
    vector<vector<mint>> presub(n + 1),sufsub(n + 1);
    vector<mint> accsubanswer(n + 1, one);
    vector<mint> accanswer(n + 1,one);
    vector<vector<int>> edges(n + 1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b),edges[b].push_back(a);
    }
    auto dfs1 = [&](auto self, int cur, int p)->void
    {
        for(auto child:edges[cur])if(child != p)
        {
            self(self,child,cur);
            subanswer[cur].push_back(accsubanswer[child] + 1);
            accsubanswer[cur] *= accsubanswer[child] + 1;
        }
        presub[cur] = sufsub[cur] = subanswer[cur];
        partial_sum(all(presub[cur]),presub[cur].begin(),[](auto a, auto b){return a*b;});
        partial_sum(sufsub[cur].rbegin(),sufsub[cur].rend(),sufsub[cur].rbegin(),[](auto a, auto b){return a*b;});
        debug(cur,subanswer[cur],presub[cur],sufsub[cur]);
    };
    dfs1(dfs1,1,1);
    auto dfs2 = [&](auto self, int cur, int p, int childind = -1)-> void
    {
        if(cur == p)
        {
            accanswer[cur] = accsubanswer[cur];
        }
        else
        {
            accanswer[cur] = accsubanswer[cur] * (answer[p][childind] + 1);
        }
        answer[cur].resize(subanswer[cur].size());
        for(int i=0,j=0;i<edges[cur].size();i++)if(edges[cur][i] != p)
        {
            answer[cur][j] = (j == 0 ? one : presub[cur][j-1]) * (j == sufsub[cur].size() - 1 ? one : sufsub[cur][j+1]) * ((p != cur ? answer[p][childind] : mint(0,m)) + 1);
            j++;
        }
        debug(cur,answer[cur]);

        for(int i=0,j=0;i<edges[cur].size();i++)if(edges[cur][i] != p)
        {
            auto child = edges[cur][i];
            
            self(self,child,cur,j);
            j++;
        }
    };
    dfs2(dfs2,1,1);
    range(i,1,n + 1)cout<<accanswer[i]<<endl;
}