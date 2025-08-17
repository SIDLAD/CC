#include <bits/stdc++.h>
constexpr long double EPS = 1e-10;
constexpr long long int M = static_cast<long long int>(1e9) + 7; //998'244'353;
using namespace std;

//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include("Debug.h")
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
#include "Debug.h"
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n' //comment out for interactive problems
#define cout(x) ((x)?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

#define int long long
#define double long double

constexpr int INF =
#ifdef int
        LLONG_MAX >> 2
#else
        INT_MAX >> 2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;

    for (int TT = 1; TT <= T; ++TT) {
        int n,k;
        cin >> n >> k;
        vi v(n + 1);

        for (int i = 1; i <= n; ++i) cin >> v[i];

        int ll = 0;
        int ul = n + 1;

        int l = -1, r = -1;
        while (ul - ll > 1) {
            int mid = (ul + ll) / 2;
            vi pre(n + 1);
            for (int i = 1; i <= n; ++i) pre[i] = (v[i] >= mid) ? 1 : -1;

            partial_sum(pre.begin(), pre.end(), pre.begin());
            vi minpre(n + 1);
            vi minprePos(n + 1);
            for (int i=1;i<=n;++i) {
                if (minpre[i - 1] > pre[i]) minpre[i] = pre[i], minprePos[i] = i;
                else minpre[i] = minpre[i-1], minprePos[i] = minprePos[i-1];
            }

            int curL = -1, curR = -1;
            for (int i=k;i<=n;++i) {
                if (pre[i] - minpre[i-k] >= 0) {
                    curL = minprePos[i-k] + 1;
                    curR = i;
                    break;
                }
            }

            if (curL != -1) {
                l = curL;
                r = curR;
                ll = mid;
            }
            else ul = mid;
        }

        cout << ll << " " << l << " " << r << endl;
    }
}
