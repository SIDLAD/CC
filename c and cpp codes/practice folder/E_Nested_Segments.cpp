#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int)998'244'353;
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

mint factorial(int n) {
    static mint fact[(int)1e6 + 1];
    if(fact[0] == 0) {
        fact[0] = 1;
        for(int i=1;i<=1e6;i++)fact[i] = i * fact[i-1];
    }
    return fact[n];
}

mint rfactorial(int n) { 
    static mint rfact[(int)1e6 + 1];
    if(rfact[0] == 0) { 
        for(int i=0;i<=1e6;i++) { 
            rfact[i] = factorial(i).inv();
        }
    }
    return rfact[n];
}

mint nck(int n, int k) { 
    return factorial(n) * rfactorial(k) * rfactorial(n-k);
}

mint catalan(int n) { 
    return nck(2*n , n) / (n  + 1 ) ;
}

struct treenode {
    int firstchild;
    int lastchild;
    int parent;
    int brother;
    pair<int,int> pr;
    treenode() : firstchild(-1),parent(-1),brother(-1), lastchild(-1) {}
} treenodelist[(int)1e6];

int emptyptr;

int addbrother(int nodeind, pair<int,int> pr) {
    treenode& node = treenodelist[nodeind];
    int i = treenodelist[node.parent].lastchild = node.brother = emptyptr++;
    treenodelist[i] = treenode();
    treenodelist[i].parent = node.parent;
    treenodelist[i].pr = pr;
    return i;
}

int addchild(int nodeind, pair<int,int> pr) {
    treenode& node = treenodelist[nodeind];
    if(node.firstchild == - 1) { 
        int i = node.firstchild = node.lastchild = emptyptr++;
        treenodelist[i] = treenode();
        treenodelist[i].parent = nodeind;
        treenodelist[i].pr = pr;
        return i;
    }
    else return addbrother(node.lastchild, pr);
}

int gotonext(int nodeind) {
    treenode& node =  treenodelist[nodeind];
    if(node.brother != -1)return node.brother;
    if(node.parent != -1)return node.parent;
    assert(false);
}

bool inside(pair<int,int> pr1, pair<int,int> pr2) {return pr1.first <= pr2.first and pr1.second >= pr2.second;}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> vp;
        for(int i=0;i < m; i++) {
            int a,b;
            cin >> a >> b;
            vp.emplace_back(a, b);
        }
        sort(all(vp),[&](auto f, auto s){return f.first == s.first ? f.second > s.second : f.first < s.first;});
        
        if(vp.size() == 0 or vp[0].first != 1 or vp[0].second != n) vp.insert(vp.begin(), {1,n});
        debug(n,m, vp);
        treenodelist[0] = treenode();
        treenodelist[0].pr = {1,n};
        int cur = 0;
        emptyptr = 1;
        for(int i=1;i<vp.size(); i ++) {
            debug(cur, treenodelist[cur].pr, vp[i]);
            while(!inside(treenodelist[cur].pr, vp[i])) {
                debug(cur, treenodelist[cur].pr, vp[i]);
                cur = gotonext(cur);
                assert(cur != -1);
            }
            debug(cur);
            cur = addchild(cur, vp[i]);
            debug(cur);
        }
        vector<int> cnm1;
        auto calculateMissingLen = [&](auto self, int nodeid) -> int {
            debug(nodeid);
            int curchild = treenodelist[nodeid].firstchild;
            int sum = 0;
            int childcnt = 0;
            while(curchild != -1) { 
                sum += self(self, curchild);
                childcnt ++;
                curchild = treenodelist[curchild].brother;
            }
            auto pr = treenodelist[nodeid].pr;
            cnm1.push_back(pr.second - pr.first + 1 - sum + childcnt);
            return pr.second - pr.first + 1;
        };
        calculateMissingLen(calculateMissingLen, 0);
        debug(cnm1);
        debug(treenodelist[0].firstchild);
        mint ans = 1;
        for(auto ele: cnm1) {ans *= catalan(ele - 1);}
        cout << ans << endl;
    }
}