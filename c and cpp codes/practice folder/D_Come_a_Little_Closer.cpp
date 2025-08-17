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

int solve(vector<pair<int,int>>& v) {
    debug(v);
    int mnx = INF, mxx = -INF, mny = INF, mxy = -INF;
    for(auto [x,y] : v) mxx = max(mxx, x), mxy = max(mxy, y), mnx = min(mnx, x), mny = min(mny, y);
    int ret = (mxx - mnx + 1) * (mxy - mny + 1); debug(ret);
    if(ret == sz(v)) ret += min(mxx - mnx + 1, mxy - mny + 1), debug(ret);
    return ret;
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
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
        if(v.size() == 1) { cout << 1 << endl; continue;}
        auto vc1 = v;
        sort(all(vc1));
        vc1.pop_back();
        int ans = INF;
        ans = min(ans, solve(vc1));
        debug(ans);

        vc1 = v;
        sort(all(vc1));
        reverse(all(vc1));
        vc1.pop_back();
        ans = min(ans, solve(vc1));
        debug(ans);


        vc1 = v;
        sort(all(vc1), [](auto a, auto b){return a.second < b.second;});
        auto vc2 = vc1;
        reverse(all(vc2));
        vc1.pop_back();
        ans = min(ans, solve(vc1));
        debug(ans);

        vc2.pop_back();
        ans = min(ans, solve(vc2));
        debug(ans);
        debug();
        cout << ans << endl;
    }
}