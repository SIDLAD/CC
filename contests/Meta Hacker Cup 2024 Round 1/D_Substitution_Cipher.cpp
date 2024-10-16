#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 998'244'353;
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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("substitution_cipher_input.txt","r",stdin);
    // freopen("D_output.txt","w",stdout);
    int T;
    cin>>T;
    int tt = 1;
    int lim1,lim2;
    for(;T--;tt++)
    {
        string s;
        int k;
        cin>>s>>k;
        int n = s.length();
        int strays = 0;
        bool trail = false;
        bool doubletrail = false;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '?')
            {
                if(i!=n-1 and s[i+1] != '?' and s[i+1] > '6')
                {
                    s[i] = '1';
                    continue;
                }
                if(i == n-1){
                    trail = true;
                    if(n != 1 and s[i-1] == '?')
                    {
                        lim1 = 6;
                        lim2 = 9;
                    }
                    else if(n == 1 or s[i-1] != '2')
                    {
                        lim1 = 9;
                        lim2 = 9;
                    }
                    else
                    {
                        lim1 = 6;
                        lim2 = 6;
                    }
                }
                else strays ++;
            }
        }


        int x = (1<<20) - 1;
        int last = lim1;
        for(int i=0;i<k-1;i++)
        {
            if(!trail)x--;
            else
            {
                if(last>1)last--;
                else{
                    x--;
                    if(x&1)last = lim1;
                    else last = lim2;
                }
            }
        }
        // debug(bitset<8>(x).to_string());
        // string ans = s;
        int count = 0;
        for(int i=n-1;i>=0;i--)if(s[i] == '?')
        {
            if(i==n-1)
            {
                s[i] = (last) + '0';
            }
            else
            {
                if(count > 20)
                {
                    s[i] = '2';
                }
                else
                {
                    if(x & (1<<count))s[i] = '2';
                    else s[i] = '1';
                }
                count++;
            }
        }

        // cout<<s<<endl;

        vector<mint> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1];
            if((s[i-2] == '1') or (s[i-2] == '2' and s[i-1] <= '6'))
            {
                dp[i] += dp[i-2];
            }
            if(s[i-1] == '0')dp[i] -= dp[i-1];
        }
        cout<<"Case #"<<tt<<": "<<s<<" "<<dp.back()<<endl;
    }
}