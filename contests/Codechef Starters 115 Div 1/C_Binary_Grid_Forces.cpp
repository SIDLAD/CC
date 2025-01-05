#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here


#define MINT_MACRO

template<int MOD = M>
struct Mint {
    int val;
    Mint(long long v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const { return val; }
    explicit operator bool()const { return val; }
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


class DSU {
public:
    int n;
    vector<int> p,sz,rank,onecount;
    int start, count = 0;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        onecount.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
            count++;
        }
    }

    void onecountsetup(string& s, bool setuprest)
    {
        vector<int> temp;
        for(int i=0;i<s.length();i++)
        {
            onecount[i] = s[i] == '1';
            if(s[i] == '1')temp.push_back(i);
        }
        if(setuprest)
        while(temp.size() > 1)
        {
            unite(temp.back(),temp.front());
            temp.pop_back();
        }
    }

    DSU(int n):DSU(0,n-1){}
 
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[p[x] = find(p[x])];
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);
            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
            onecount[c] += onecount[d];
            count--;
            return true;
        }
        return false;
    }
};

DSU recurse(vector<string>& v, int index = 0, int onecountsetupflag = false)
{
    int n = v.size();
    int m = v[index].size();
    DSU dsu(m);
    dsu.onecountsetup(v[index],onecountsetupflag);

    if(index == n - 1)return dsu;

    unordered_map<int,vector<int>> pre;
    auto belowdsu = recurse(v,index + 1,true);
    for(int i=0;i<m;i++)
    {
        if(belowdsu.onecount[belowdsu.find(i)] <= 1)continue;
        pre[belowdsu.find(i)].push_back(i);
    }
    for(auto [id,v]: pre)
    {
        for(auto ele:v)
        {
            dsu.unite(ele,id);
        }
    }
    return dsu;
}

const int LIM = 1e6 + 10;
mint fact(int n)
{
    static mint factorial[LIM + 1];
    if(factorial[0] == 0)
    {
        factorial[0] = 1;
        for(int i=1;i<=LIM;i++)
        {
            factorial[i] = i * factorial[i-1];
        }
    }

    return factorial[n];
}

mint rfact(int n)
{
    static mint rfactorial[LIM + 1];
    if(rfactorial[0] == 0)
    {
        rfactorial[0] = 1;
        for(int i=1;i<=LIM;i++)
        {
            rfactorial[i] = fact(i).inv();
        }
    }

    return rfactorial[n];
}

mint ncr(int n, int r)
{
    if(r > n or n < 0 or r < 0)return 0;
    return fact(n)*rfact(n-r)*rfact(r);
}

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
        int n,m;
        cin>>n>>m;
        vector<string> v(n);
        arrPut(v);
        debug(v);
        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }
        DSU firstrow = recurse(v);
        set<int> st;
        for(int i=0;i<m;i++)
        {
            st.insert(firstrow.find(i));
        }
        debug(st);
        mint ans = 1;
        for(auto ele:st)
        {
            ans *= ncr(debug(firstrow.size(ele)),debug(firstrow.onecount[ele]));
            debug();
        }

        cout<<ans<<endl;
    }
}