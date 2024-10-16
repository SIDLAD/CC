#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

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
#define ll long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

int isqrt(int n) { return sqrtl(n); }
__attribute__((target("avx"), optimize("O3", "unroll-loops"))) int prime_pi(const int N) {
    if (N <= 1)
        return 0;
    if (N == 2)
        return 1;
    const int v = isqrt(N);
    int s = (v + 1) / 2;
    vector<int> smalls(s);
    for (int i = 1; i < s; ++i) smalls[i] = i;
    vector<int> roughs(s);
    for (int i = 0; i < s; ++i) roughs[i] = 2 * i + 1;
    vector<int> larges(s);
    for (int i = 0; i < s; ++i) larges[i] = (N / (2 * i + 1) - 1) / 2;
    vector<bool> skip(v + 1);
    const auto divide = [](int n, int d) -> int { return (double)(n) / d; };
    const auto half = [](int n) -> int { return (n - 1) >> 1; };
    int pc = 0;
    for (int p = 3; p <= v; p += 2)
        if (!skip[p]) {
            int q = p * p;
            if ((q) * q > N)
                break;
            skip[p] = true;
            for (int i = q; i <= v; i += 2 * p) skip[i] = true;
            int ns = 0;
            for (int k = 0; k < s; ++k) {
                int i = roughs[k];
                if (skip[i])
                    continue;
                int d = (i) * p;
                larges[ns] =
                    larges[k] - (d <= v ? larges[smalls[d >> 1] - pc] : smalls[half(divide(N, d))]) + pc;
                roughs[ns++] = i;
            }
            s = ns;
            for (int i = half(v), j = ((v / p) - 1) | 1; j >= p; j -= 2) {
                int c = smalls[j >> 1] - pc;
                for (int e = (j * p) >> 1; i >= e; --i) smalls[i] -= c;
            }
            ++pc;
        }
    larges[0] += (s + 2 * (pc - 1)) * (s - 1) / 2;
    for (int k = 1; k < s; ++k) larges[0] -= larges[k];
    for (int l = 1; l < s; ++l) {
        int q = roughs[l];
        int M = N / q;
        int e = smalls[half(M / q)] - pc;
        if (e < l + 1)
            break;
        int t = 0;
        for (int k = l + 1; k <= e; ++k) t += smalls[half(divide(M, roughs[k]))];
        larges[0] += t - (e - l) * (pc + l - 1);
    }
    return larges[0] + 1;
}

vector<int> primes;
int isnotprime[(int)1e6 + 1] = {};
int32_t main()
{
    for(int i = 2; i<= 1e6;i++)
    {
        if(isnotprime[i])continue;
        primes.push_back(i);
        for(int j=i*i; j<= 1e6; j+=i)isnotprime[j] = 1;
    }
    int n;
    cin>>n;
    int i;
    for(i=1;i*i*i <=n;i++);
    i--;
    int ans = prime_pi(i);
    for(auto i: primes)
    {
        if(n/i < i)break;
        ans += prime_pi(n/i) - prime_pi(i);
    }
    cout<<ans<<endl;

}