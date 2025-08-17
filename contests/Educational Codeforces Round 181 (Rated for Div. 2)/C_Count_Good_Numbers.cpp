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

int solve(int x) {
    if(x < 10) return 0;
    vector<int> v{2,3,5,7};
    int n = sz(v);
    int ans = x - 1;
    debug(ans);
    for(auto e: v) {
        ans -= x/e;
    }
    debug(ans);
    for(int i=0;i<n;++i) for(int j=i + 1;j<n;++j) ans += x/lcm(v[i],v[j]);
    debug(ans);
    for(int i=0;i<n;++i) for(int j=i + 1;j<n;++j) for(int k=j + 1;k<n;++k)ans -= x/lcm(lcm(v[i],v[j]), v[k]);
    debug(ans);
    ans += x/lcm(6, lcm(5,7));
    debug(ans);
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
    debug(solve(11));
    for(int TT = 1; TT <= T; ++TT)
    {
        int l,r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
}