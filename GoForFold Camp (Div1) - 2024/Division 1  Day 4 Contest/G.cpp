#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

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
#define cout(x) (x?cout<<"First"<<endl:cout<<"Second"<<endl)
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
using ull = unsigned long long;


ull modmul(ull a, ull b, ull M)
{
    long long ret = a*b -M * ull(1.L/M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (long long)M);
}

int modpow(int a, int b, int MOD = M) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (__uint128_t)res * a % MOD;
        a =  (__uint128_t)a * a % MOD;
        b >>= 1;
    }
    return res;
}

bool isPrime(ull n)
{
    if(n < 2 || n%6%4 != 1) return (n|1) == 3;
    ull A[] = {2,325,9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n - 1),d = n >> s;
    for(ull a: A)
    {
        //count trailing zeros
        ull p = modpow(a%n,d,n),i = s;
        while(p!=1 and p!=n-1 and a%n and i--)
            // p = (__uint128_t)p * p % n;
            p = modmul(p,p,n);
        if(p != n-1 and i != s)return 0;
    }
    return 1;
}

ull pollard(ull n)
{
    if(isPrime(n))return n;
    auto f = [n](ull x){ return modmul(x,x,n) + 1; };
    ull x = 0, y = 0, t= 30, prd = 2, i = 1, q;
    while(t++ % 40 || __gcd(prd,n) == 1){
        if(x == y) x = ++i, y = f(x);
        if((q = modmul(prd,max(x,y) - min(x,y),n))) prd=q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd,n);
}

vector<ull> factor(ull n)
{
    if(n == 1)return{};
    if(isPrime(n))return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(),all(r));
    return l;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    arrPut(v);
    
    int xorval = 0;

    for(int i=0;i<n;i++)
    {
        if(v[i] == 1)continue;
        auto factors = factor(v[i]);
        set<int> st(all(factors));
        
        for(auto x:st)
        {
            int len = 0;
            int j = i;
            while(j < n and v[j] % x == 0)
            {
                while(v[j]%x == 0)v[j]/=x;
                len++;
                j++;
            }
            xorval ^= len;
        }
    }
    cout(xorval);
}