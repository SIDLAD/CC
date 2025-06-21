#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int n;
string s;
vector<array<long long,4>> form;
vector<long long> len;
vector<mint> prep;
vector<mint> sum;

mint solve(int id, long long r, auto& memo)
{
    if(r <= 0)return 0;
    if(memo[id].count(r))return memo[id][r];

    if(id == 0)
    {
        mint ans = 0;
        for(long long i=0;i<r;i++)
        {
            ans += s[i];
        }
        return memo[id][r] = ans.val;
    }

    if(form[id][0] == 's')
    {
        auto [_,x,lp,rp] = form[id];
        return memo[id][r] = (solve(x,r + lp,memo) - prep[id]).val;
    }
    else
    {
        auto [_,id1,id2,__] = form[id];
        mint ans = 0;
        if(r > len[id1])
        {
            ans = sum[id1] + solve(id2,r - len[id1],memo);
        }
        else ans = solve(id1,r,memo);

        return memo[id][r] = ans.val;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // unordered_map<int,unordered_map<long long,int>> memo;
    unordered_map<long long,int> memo[2501];
    cin>>n;
    for(auto mp:memo)
    {
        mp.reserve(1024);
        mp.max_load_factor(0.25);
    }
    cin>>s;
    form.resize(n);
    len.resize(n);
    prep.resize(n);
    sum.resize(n);
    len[0] = s.length();
    sum[0] = solve(0,len[0],memo);
    range(i,1,n)
    {
        string tmp;
        cin>>tmp;
        if(tmp[0] == 'S')
        {
            long long x,l,r;
            cin>>x>>l>>r;
            form[i] = {'s',x,l,r};
            len[i] = r - l;
            prep[i] = solve(x,l,memo);
            sum[i] = solve(x,r,memo) - prep[i];
        }
        else
        {
            long long l,r;
            cin>>l>>r;
            form[i] = {'a',l,r,-1};
            len[i]  = len[l] + len[r];
            sum[i] = sum[l] + sum[r];
        }
    }

    cout<<solve(n-1,len[n-1],memo)<<endl;
}


/*Below implementation doesn't work*/
// #include <bits/stdc++.h>
// const long double EPS = 1e-7;
// const long long int M = (long long int) 1e9 + 7;//998'244'353;
// using namespace std;
// //insert policy here


// #define MINT_MACRO

// template<int _MOD = M>
// struct Mint {
//     int val;
//     int MOD = _MOD;
//     Mint(long long v = 0, int MOD = _MOD) : MOD(MOD) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
//     Mint& operator=(long long v) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; return *this; }
//     static int mod_inv(int a, int m) {
//         int g = m, r = a, x = 0, y = 1, q;
//         while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
//         return x < 0 ? x + m : x;
//     } 
//     explicit operator int() const { return val; }
//     explicit operator bool()const { return val; }
//     Mint& operator+=(const Mint &o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
//     Mint& operator-=(const Mint &o) { val -= o.val; if (val < 0) val += MOD; return *this; }
//     static unsigned fast_mod(uint64_t x, unsigned m) {
//            #if !defined(_WIN32) || defined(_WIN64)
//                 return x % m;
//            #endif
//            unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
//            asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
//            return rem;
//     }
//     Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val, MOD); return *this; }
//     Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
//     friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
//     friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
//     friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
//     friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
//     template<typename T>
//     friend Mint operator+(const T& a, const Mint &b) { return Mint(a,b.MOD) += b; }
//     template<typename T>
//     friend Mint operator-(const T& a, const Mint &b) { return Mint(a,b.MOD) -= b; }
//     template<typename T>
//     friend Mint operator*(const T& a, const Mint &b) { return Mint(a,b.MOD) *= b; }
//     template<typename T>
//     friend Mint operator/(const T& a, const Mint &b) { return Mint(a,b.MOD) /= b; }
//     Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
//     Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
//     Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
//     Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
//     Mint operator-() const { return val == 0 ? 0 : MOD - val; }
//     bool operator==(const Mint &other) const { return val == other.val; }
//     bool operator!=(const Mint &other) const { return val != other.val; }
//     Mint inv() const { return mod_inv(val, MOD); }
//     Mint operator[](long long p) {
//         assert(p >= 0);
//         Mint a = *this, res(1, this->MOD);
//         while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
//         return res;
//     }
//     friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
//     friend istream& operator >> (istream &stream, Mint &m) { return stream>>m.val; } 
// };

// using mint = Mint<>;

// //insert randnum here

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

// #define int long long
// #define double long double
// #define all(x) (x).begin(),(x).end()
// #define endl '\n' //comment out for interactive problems
// #define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
// #define range(it, start, end) for (auto it = start; it < end; it++)
// #define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
// #define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

// const int INF =
// #ifdef int
//     LONG_LONG_MAX/2
// #else
//     INT_MAX/2
// #endif
// ;

// map<array<int,3>, pair<int,int>> mp;
// vector<array<int,4>> form;
// string s;
// int n;

// pair<int,int> solve(int id, int l, int r)
// {
//     if(mp.count({id,l,r}))return mp[{id,l,r}];
//     if(id == 0)
//     {
//         mint sum = 0;
//         int rd = min((int)s.length(),r);
//         if(l >= rd)
//         {
//             return mp[{id,l,r}] = {0,r + rd - 2*l};
//         }
//         for(int i=l;i<rd;i++)
//         {
//             sum += s[i];
//         }
//         return mp[{id,l,r}] = {sum.val,r - rd};
//     }
//     mint ans = 0;
//     if(form[id][0] == 's')
//     {
//         int remmm = 0;
//         auto [_,x,ld,rd] = form[id];
//         l += ld;
//         r += ld;
//         if(l >= rd)
//         {
//             return mp[{id,l,r}] = {0,r + rd - 2*l};
//         }
//         else if(r > rd)
//         {
//             ans = solve(x,l,rd).first;
//             remmm = r - rd;
//         }
//         else
//         {
//             ans = solve(x,l,r).first;
//             remmm = 0;
//         }
//         return mp[{id,l,r}] = {ans.val,remmm};
//     }
//     else
//     {
//         auto [_,id1,id2,__] = form[id];
//         auto [val,remmm] = solve(id1,l,r);
//         ans += val;
//         int ld = 0;
//         if(remmm > r - l)
//         {
//             ld = remmm - (r - l);
//             remmm = r - l;
//         }
        
//         auto [val2,remmm2] = solve(id2,ld,ld + remmm);
//         ans += val2;
//         return mp[{id,l,r}] = {ans.val,remmm2};
//     }
// }

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cout.precision(numeric_limits<double>::max_digits10);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     cin>>n;
//     cin>>s;
//     form.resize(n);
//     debug(n,s);
//     range(i,1,n)
//     {
//         string tmp;
//         cin>>tmp;
//         if(tmp[0] == 'S')
//         {
//             int x,l,r;
//             cin>>x>>l>>r;
//             form[i] = {'s',x,l,r};
//         }
//         else
//         {
//             int l,r;
//             cin>>l>>r;
//             form[i] = {'a',l,r,-1};
//         }
//     }
//     cout<<solve(n-1,0,INF).first<<endl;
// }