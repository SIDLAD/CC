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
int n;

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
        int s;
        cin >> n >> s;
        vi a(n);
        arrput(a);
        vector<pii> split(n);
        for(int i=1;i<n-1;++i){
            split[i].first = a[i] > s ? s : 0;
            split[i].second = a[i] - split[i].first;
            if(split[i].first > split[i].second) swap(split[i].first, split[i].second);
        }
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][1] = split[1].first * a[0];
        dp[1][1] = split[1].second * a[0];
        for(int i=2;i<n-1;++i) {
            dp[0][i] = min(dp[0][i-1] + split[i-1].second * split[i].first, dp[1][i-1] + split[i-1].first * split[i].first);
            dp[1][i] = min(dp[0][i-1] + split[i-1].second * split[i].second, dp[1][i-1] + split[i-1].first * split[i].second);
        }
        cout << min(dp[0][n-2] + split[n-2].second * a[n-1], dp[1][n-2] + split[n-2].first * a[n-1]) << endl;
    }
}