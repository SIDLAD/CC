#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 998'244'353;
using namespace std;
//insert policy here

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
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int binexp(int base, int exp) {
    int ans = 1;
    while(exp) {
        if(exp&1) (ans *= base) %= M;
        (base *= base) %= M;
        exp >>= 1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        vi a(n);
        arrput(a);
        int oc = accumulate(all(a), 0);
        int zc = n - oc;
        int cnt = 0;
        for(int i=0;i<n;++i)
        if(i < zc and a[i] == 1) cnt++;
        else if(i >= zc and a[i] == 0) cnt++;
        cnt /= 2;
        auto append = [&](int cnt) -> int {
            int ans = n * (n - 1) / 2 % M;
            ans *= binexp(cnt * cnt, M-2);
            ans %= M;
            return ans;
        };
        int ans = 0;
        for(int i=1;i<=cnt; ++i) {
            (ans += append(i)) %= M;
        }
        cout << ans << endl;
    }
}