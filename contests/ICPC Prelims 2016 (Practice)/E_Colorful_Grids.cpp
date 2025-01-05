#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

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



int phiM;
int phiphiM;
int N,C;

int binpow(int a, int b, int MOD) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

inline int Minv(int n)
{
    return binpow(n,phiM - 1,M);
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int TOT()
{
    int sqc = (__int128_t)5 * N %phiM * N %phiM;
    assert(sqc >= 0);
    return binpow(C,sqc,M);
}

int TOT90()
{
    if(N&1)
    {
        int n2minus1by4 = (__int128_t)((__int128_t)N*N - 1)/4 % phiM;
        int sqc =  ((__int128_t)N * N % phiM + n2minus1by4 + 1)%phiM;
        assert(sqc >= 0);
        return binpow(C,sqc,M);
    }
    else
    {
        int n2by4 = (__int128_t)N*N /4 %phiM;
        int sqc =  ((__int128_t)N * N % phiM +n2by4) % phiM;
        assert(sqc >= 0);
        return binpow(C,sqc,M);
    }
}

int TOT180()
{
    if(N&1)
    {
        int n2minus1by2 = (__int128_t)((__int128_t)N*N - 1)/2%phiM;
        int sqc = ((__int128_t)2 * N % phiM *N %phiM + n2minus1by2 + 1)%phiM;
        assert(sqc >= 0);
        return binpow(C,sqc,M);
    }
    else
    {
        int n2by2 = (__int128_t)N*N/2%phiM;
        int sqc = ((__int128_t)2 * N % phiM *N %phiM + n2by2)%phiM;
        assert(sqc >= 0);
        return binpow(C,sqc,M);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    phiM = phi(M);
    phiphiM = phi(phiM);
    int T;
    cin>>T;
    int twoinv = Minv(2);
    int fourinv = Minv(4);
    for(;T--;)
    {
        int n,c;
        cin>>n>>c;
        N = n,C =c;
        int t90 = TOT90();
        int t180 = TOT180();
        int t = TOT();
        int ans = (t90 + (t180 - t90 + M)%M*twoinv%M)%M + (t - t180 + M)%M*fourinv%M;
        ans %= M;
        cout<<ans<<endl;
    }
}