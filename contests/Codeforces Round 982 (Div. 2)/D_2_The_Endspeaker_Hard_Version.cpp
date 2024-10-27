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
    
    class CNothing {};

    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&)
    {
        return proxy;
    }

    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
    {
        return proxy;
    }
    CNothing cnothing;
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

using T = pair<int,int>;
struct segtree
{
    int n;
    vector<T> tree;
    vector<T> lazy;
    T zero = {INF,0}; // Change according to QUERY operation
    T lazy_zero = {INF,0}; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(4 * sz + 1, zero);
        lazy.resize(4 * sz + 1, lazy_zero);
    }

    void updatelazy(T& a, T b)
    {
        if(a.first == b.first) a.second = (a.second + b.second)%M;
        if(a.first > b.first) a = b;
    }

    void propagate(int id, int segl, int segr)
    {
        if(segl == segr){updatelazy(tree[id], lazy[id]);lazy[id] = lazy_zero;return;}
        if(lazy[id] == lazy_zero)return;
        int mid = (segl + segr) / 2;
        array<int , 2> children= {2 * id + 1, 2 * id + 2};
        for(auto child : children)
        {  // Change according to MODIFY operation
            // debug(lazy[id],lazy[child]);
            updatelazy(lazy[child],lazy[id]);
            // debug(lazy[id],lazy[child]);
        }
        lazy[id] = lazy_zero;
    }

    void modify(T val, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if(index_l > index_r)return;
        if (index_l > segr || segl > index_r)
        {
            return;
        }
        if (segl >= index_l && segr <= index_r)
        {
            // debug(index_l,id);
            // debug(lazy[id],val);
            updatelazy(lazy[id],val);
            propagate(id, segl, segr);
            // if(segl == segr)updatelazy(tree[id], lazy[id]);
            // debug(lazy[id],val);
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, 2 * id + 1, segl, mid);
        modify(val, index_l, index_r, 2 * id + 2, mid + 1, segr);
    }

    T query(int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > segr || segl > index_r)
        {
            return zero;
        }
        if (segl >= index_l && segr <= index_r)
        {
            // debug(index_l,id);
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, 2 * id + 1, segl, mid);
        T rightVal = query(index_l, index_r, 2 * id + 2, mid + 1, segr);
        if(leftVal == zero)return rightVal;
        else return leftVal;
    }
};

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
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
            // a[i] = 0;
        }
        for(int i=0;i<m;i++)cin>>b[i];

        partial_sum(a.rbegin(),a.rend(),a.rbegin());
        a.push_back(0);
        // debug(a);
        // debug(b);
        vector<segtree> dp(m + 1, segtree(n + 1));
        dp[m].modify({0,1},n);
        // debug(dp[m].query(n));

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n;j>=0;j--)
            {
                // debug(i,j);
                // dp[j][i] = min(dp[j][i],dp[j][i + 1]);
                dp[i].modify(dp[i + 1].query(j),j);
                // debug(dp[i + 1].query(j),dp[i].query(j));
                // debug(j,i,dp[j][i]);
                // if(dp[j][i] >= INF)continue;
                if(dp[i].query(j).first >= INF)continue;
                int start = a[j];
                auto rr = --upper_bound(a.rbegin(),a.rend(), start + b[i]);
                // debug(start+b[i],*rr);
                int endind = distance(begin(a), rr.base()) - 1;
                assert(endind <= j);
                // dp[i][endind] = min(dp[i][endind],dp[i][j] + m - j- 1);
                auto tmppr = dp[i].query(j);
                // debug(tmppr,m-i-1);
                tmppr.first += m - i - 1;
                // debug(j,i,dp[i].query(j));
                if(endind <= j-1)
                dp[i].modify(tmppr,endind,j-1);
            }
        }
        // debug();
        if(dp[0].query(0).first == INF)cout<<-1<<endl;
        else cout<<dp[0].query(0).first<<" "<<dp[0].query(0).second<<endl;
    }
}