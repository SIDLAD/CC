// #include <bits/stdc++.h>
// const long double EPS = 1e-7;
const long long int M = (long long int) 998'244'353;
// using namespace std;
// //insert policy here


// #define MINT_MACRO

// template<int MOD = M>
// struct Mint {
//     int val;
//     Mint(long long v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
//     static int mod_inv(int a, int m = MOD) {
//         int g = m, r = a, x = 0, y = 1, q;
//         while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
//         return x < 0 ? x + m : x;
//     } 
//     explicit operator int() const { return val; }
//     explicit operator bool()const { return val; }
//     Mint& operator+=(const Mint &o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
//     Mint& operator-=(const Mint &o) { val -= o.val; if (val < 0) val += MOD; return *this; }
//     static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
//            #if !defined(_WIN32) || defined(_WIN64)
//                 return x % m;
//            #endif
//            unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
//            asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
//            return rem;
//     }
//     Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
//     Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
//     friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
//     friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
//     friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
//     friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
//     Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
//     Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
//     Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
//     Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
//     Mint operator-() const { return val == 0 ? 0 : MOD - val; }
//     bool operator==(const Mint &other) const { return val == other.val; }
//     bool operator!=(const Mint &other) const { return val != other.val; }
//     Mint inv() const { return mod_inv(val); }
//     Mint operator[](long long p) {
//         assert(p >= 0);
//         Mint a = *this, res = 1;
//         while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
//         return res;
//     }
//     friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
//     friend istream& operator >> (istream &stream, Mint &m) { return stream>>m.val; } 
// };

// using mint = Mint<>;

// #if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
//     void _exe() {}
//     template <typename T, typename... V>
//     const T& _exe(const T &t,const V&... v) {return t;}
//     template <typename T, typename... V>
//     T& _exe(T &t,V&... v) {return t;}
//     #define debug(x...) (_exe(x))
    
//     class CNothing {} cnothing;
//     template <typename T>
//     const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
//     const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
//     #define cerr cnothing
// #else
//     #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
// #endif


// const int MAXN = 1e6;

// vector<mint> tot(MAXN + 1,0);
// vector<vector<int>> primedivs(MAXN + 1);
// vector<int> isprime(MAXN + 1,1);


// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cout.precision(numeric_limits<double>::max_digits10);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     vector<int> primes;
//     isprime[0] = isprime[1] = 0;
//     for(int i=2;i<=MAXN;i++)
//     {
//         if(isprime[i])primes.push_back(i);
//         else continue;
//         for(int j = i*i;j<=MAXN;j += i)
//         {
//             isprime[j] = false;
//         }
//     }
//     // debug(primes);
//     for(int i=0;i<primes.size();i++)
//     {
//         for(int j=primes[i];j<=MAXN;j+=primes[i])
//         {
//             primedivs[j].push_back(primes[i]);
//         }
//     }
//     // debug(primedivs);
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     arrPut(v);

//     int bitw = primedivs[v[0]].size();
//     for(int j=1;j<(1<<bitw);j++)
//     {
//         int jc = j;
//         int prod = 1;
//         while(jc)
//         {
//             prod *= primedivs[v[0]][debug(bit_width((unsigned long long)jc) - 1)];
//             jc ^= 1<<(bit_width((unsigned long long)jc) -1);
//             if(prod > MAXN){prod = -1; break;}
//         }
//         if(prod == -1)continue;
//         tot[prod] = 1;
//         debug(prod,tot[prod]);
//     }

//     for(int i=1;i<n;i++){
//         int bitw = primedivs[v[i]].size();
//         mint curans = 0;
//         vector<int> prods;
//         for(int j=1;j<(1<< bitw);j++)
//         {
//             int multf = __builtin_popcountll(j)&1?1:-1;
//             int jc = j;
//             int prod = 1;
//             while(jc)
//             {
//                 prod *= primedivs[v[i]][bit_width((unsigned long long)jc) - 1];
//                 jc ^= 1<<(bit_width((unsigned long long)jc) -1);
//                 if(prod > MAXN){prod = -1; break;}
//             }
//             if(prod == -1)continue;
//             curans  += multf*tot[prod];
//             prods.push_back(prod);
//         }
//         debug(curans);
//         for(auto prod:prods)tot[prod] += curans;
//         if(i == n - 1)cout<<curans<<endl;
//     }
// }

#include<bits/stdc++.h>

using namespace std;

#define endl "\n" //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int mobius[(int)1E6 + 1];
int val[(int)1E6 + 1] = {};

int main()
{
#define int long long
    mobius[1] = 1;
    for(int i=1;i<=1E6;i++)
    {
        mobius[i] *= -1;
        for(int j=i*2;j<=1E6;j += i)
        {
            mobius[j] += mobius[i];
        }
    }

    int n;
    cin>>n;
    vector<int> v(n);
    arrPut(v);
    
    for(int x=1;x*x<=v[0];x++)if(v[0]%x==0){if(x!=1)val[x]++;if(x*x!=v[0])val[v[0]/x]++;}

    for(int i=1;i<n;i++)
    {
        vector<int> tmp;
        int curans = 0;
        for(int x=1;x*x<=v[i];x++)if(v[i]%x==0)
        {
            if(x!=1)
            curans = (curans + val[x]*mobius[x] + M)%M,tmp.push_back(x);
            if(x*x!=v[i])
            curans = (curans + val[v[i]/x]*mobius[v[i]/x] + M)%M,tmp.push_back(v[i]/x);
        }
        for(auto ele:tmp)val[ele] = (val[ele] + curans)%M;
        if(i==n-1)cout<<curans<<endl;
    }
}