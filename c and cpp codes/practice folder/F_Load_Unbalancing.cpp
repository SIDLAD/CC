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
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

template<typename T=int>
T input() {
    T x;
    cin >> x;
    return x;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
        // int n, k;
        // cin >> n >> k;
        // vi a(n);
        // for(int i=0;i<n;++i) cin >> a[i];
        // sort(all(a));
        // int s = accumulate(all(a), 0ll);
        // int ul = s / k + 1;
        // int ll = max(s / k - *max_element(all(a)), 0ll);

        // while(ul - ll > 1) {
        //     int mid = ll + ul >> 1;
        //     vector<pii> dp(1 << n - 1);
        //     for(int i=0;i< 1 << n - 1; ++i) for(int bit=0;bit < n - 1; ++bit) if(i >> bit & 1)
        //     {
        //         auto val = dp[i ^ 1 << bit];
        //         val.second += a[bit];
        //         if(val.second >= mid) val.first ++, val.second = 0;
        //         dp[i] = max(dp[i], val);
        //     }
        //     if(dp[(1 << n - 1) - 1].first >= k) ll = mid;
        //     else ul = mid;
        // }

        // cout << ll + a[n-1] << endl;

        // int n, k;
        // cin >> n >> k;
        // vi a(n);
        // arrput(a);
        // sort(all(a));
        // --n;
        // vector<int> W(1 << n);
        // for(int i=0;i<n;++i) W[1 << i] = a[i];
        // for(int i=1;i< (1 << n); ++i) {
        //     int trailing = __builtin_ctz(i);
        //     assert(trailing < n);
        //     W[i] = W[i ^ 1 << trailing] + W[1 << trailing];
        // }
        // vector<int> masks(1 << n);
        // iota(all(masks), 0);

        // sort(all(masks), [&](auto a, auto b){ return W[a] > W[b]; });
        // int dp[1 << n] {};
        // int ans = -1;
        // for(auto i: masks) {
        //     int complement = ~i & (1 << n) - 1;
        //     for(int c=complement;; c = (c - 1) & complement) {
        //         assert(i | c == i ^ c);
        //         dp[i ^ c] = max(dp[i ^ c], dp[c] + 1);
        //         if(dp[i ^ c] == k) {
        //             ans = W[i];
        //             goto outer;
        //         }
        //         if(c == 0) break;
        //     }
        // }
        // outer:;
        // assert(ans != -1);
        // cout << ans + a.back() << endl;

        int n, k;
        cin >> n >> k;
        vi a(n);
        arrput(a);
        sort(all(a));
        --n;
        vector<int> W(1 << n);
        for(int i=0;i<n;++i) W[1 << i] = a[i];
        for(int i=1;i< (1 << n); ++i) {
            int trailing = __builtin_ctz(i);
            assert(trailing < n);
            W[i] = W[i ^ 1 << trailing] + W[1 << trailing];
        }

        vector<pair<int,int>> dp(1 << n);
        for(int i=1;i < 1 << n; ++i) {
            int complement = (1 << n) - 1 & ~i;
            int remWt = W[complement];
            for(int bit = 0; bit < n; ++bit) if(i >> bit & 1) {
                auto cur = dp[i ^ 1 << bit];
                cur.second += a[bit];
                if(k - cur.first - 1 > 0 and cur.second * (k - cur.first - 1) >= remWt) cur.second = 0, cur.first++;
                dp[i] = max(dp[i], cur);
            }
        }
        debug(dp);
        auto [mxG, mxW] = dp[(1 << n) - 1];
        if(mxG < k - 1) mxW = 0;
        cout << mxW + a[n] << endl;
    }
}