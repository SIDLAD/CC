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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m,d0,d1,d2;
    cin>>n>>m>>d0>>d1>>d2;

    vector<vector<char>> v(n,vector<char> (m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];

    mint expectedval = 0;

    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        if(v[i][j] == 'V')
        {
            expectedval += d0;
        }
        else
        {
            if(v[i][j] =='?')
            {
                expectedval += (mint)d0/2;
            }

            int cnt1full = 0, cnt1half = 0, cnt2full = 0,cnt2half = 0;
            vector<int> di1 = {0,-1,0,1};
            vector<int> dj1 = {-1,0,1,0};
            for(int k=0;k<4;k++)
            {
                if(i + di1[k] < 0 or i + di1[k] >= n)continue;
                if(j + dj1[k] < 0 or j + dj1[k] >= m)continue;
                int idi = i + di1[k];
                int jdj = j + dj1[k];
                if(v[idi][jdj] == 'V')cnt1full++;
                else if(v[idi][jdj] == '?')cnt1half++;
            }

            vector<int> di2 = {-1,-1,1,1};
            vector<int> dj2 = {-1,1,-1,1};
            for(int k=0;k<4;k++)
            {
                if(i + di2[k] < 0 or i + di2[k] >= n)continue;
                if(j + dj2[k] < 0 or j + dj2[k] >= m)continue;
                int idi = i + di2[k];
                int jdj = j + dj2[k];
                if(v[idi][jdj] == 'V')cnt2full++;
                else if(v[idi][jdj] == '?')cnt2half++;
            }

            if(cnt1full > 0)
            {
                expectedval += (mint)d1/ ((v[i][j] == '?') + 1);
            }
            else
            {
                expectedval += (mint)d1 * (1 - ((mint)1/2)[cnt1half])/((v[i][j] == '?') + 1);

                if(cnt2full > 0)
                {
                    expectedval += (mint)d2 * ((mint)1/2)[cnt1half] /((v[i][j] == '?') + 1);
                }
                else
                {
                    expectedval += (mint)d2 * ((mint)1/2)[cnt1half] /((v[i][j] == '?') + 1) * (1 - ((mint)1/2)[cnt2half]);
                }
            }
        }
    }

    cout<<expectedval<<endl;
}