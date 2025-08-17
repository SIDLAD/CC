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
#define sz(x) (int)(x).size()
#define endl '\n' //comment out for interactive problems
#define cout(x) cout << ((x) ? "YES" : "NO") << endl
#define rep(it, start, end) for (auto it = start; it != end; ++it)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> pDivs() {
    vector<int> sieve(1001);
    vector<int> pdivs;
    for(int i=2;i<=1000;i++) {
        if(sieve[i]) continue;
        pdivs.push_back(i);
        for(int j = i * i;j<=1000;j += i) sieve[j] = 1;
    }
    return pdivs;
}

vector<int> divs(int num) {
    vi v;
    for(int i=1; i*i <= num; ++i)
        if(num%i == 0) v.push_back(i), v.push_back(num/i);

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    return v;
}

int greatestP(int x, vector<int>& p) {
    int g = -1;
    for(auto e: p) if(x % e == 0) g = e;
    if(g == -1) g = x;
    return g;
}
int getAns(int num, int k, auto& primes) {
    auto divisors = divs(num);
    int dpsz = sz(divisors);
    vector<int> dp(dpsz,INF);
    dp[0] = 0;  
    for(int i=1;i<dpsz;++i)
    {
        if(divisors[i] <= k) dp[i] = 1;
        else for(int j=0;j<i;++j) {
            if(divisors[i] % divisors[j] == 0 && divisors[i] / divisors[j] <= k) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    debug(num, k, dp.back());
    return dp.back();
}
 
int solve(int x, int y, int k, auto& primes) {
    int g = gcd(x,y);
    int cnt = getAns(x/g, k, primes) + getAns(y/g, k, primes);
    if(cnt >= INF) cnt = -1;
    return cnt;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    auto primes = pDivs();

    int T = 1;
    cin >> T;
    for(int TT = 1; TT <= T; ++TT)
    {
        int x,y,k;
        cin >> x >> y >> k;
        if(x == y) {cout << 0 << endl;continue;}
        int g = gcd(x,y);
        int gx = greatestP(x/g, primes);
        int gy = greatestP(y/g, primes);

        if(max(gx, gy) > k) {cout << -1 << endl; continue;}

        cout << solve(x,y, k, primes) << endl;
    }
}