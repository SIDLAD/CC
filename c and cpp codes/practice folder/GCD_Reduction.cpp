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

vector<int> Primes() {
    int cap = 3e6;
    vector<int> isPrime(cap + 1, 1);
    isPrime[0] = 0;
    for(int i=2;i*i<=cap;++i) {
        if(isPrime[i])
        for(int j=i*i;j <= cap; j += i) isPrime[j] = 0;
    }
    vector<int> ans;
    for(int i=2;i<=cap;++i) if(isPrime[i]) ans.push_back(i);
    return ans;
}

int n,x,y;

bool check(vi &a){
    int i=0,j=1;
    while(j<n-1){
        if(i>=n-5){
            // show(i,j,a[i],a[j],a[j+1],_gcd(a[i],a[j+1]),_gcd(a[j],a[j+1]));
        }
        if(gcd(a[i],a[j+1])<=gcd(a[j],a[j+1])){
            i =j;
        }
        j++;
    }
    return a[i] !=y;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    auto primes=  Primes();
    auto getFirstCoPrime = [&](int x){
        for(auto e: primes) if(x % e) return e;
        return -1ll;
    };
    for(int TT = 1; TT <= T; ++TT)
    {
        cin >> n >> x >> y;
        int xg[n + 1];
        for(int i=1;i<=n;++i) {
            xg[i] = gcd(x,i);
            if(i == x) xg[i] = -1;
        }
        int mx = *max_element(xg + 1 , xg + n + 1);
        vector<int> mxl;
        for(int i=1;i<=n;++i) if(mx == xg[i]) mxl.emplace_back(i);
        if(mx == xg[y] || mx == 1 || n == 2) {cout << -1 << endl; continue;}
        
        auto r = mxl.front();

        vector<int> ans1;
        {
            ans1.clear();
            for(int i=n;i>=1;--i) if(i != r && i != x && i != y) ans1.push_back(i);
            ans1.push_back(r), ans1.push_back(y), ans1.push_back(x);
            assert(check(ans1));
            arrprint(ans1);
        }
    }
}