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
#define cout(x) cout << ((x) ? "DA" : "NE") << endl
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

int n, k;
vector<int> edges[401];
int mxDepth[401] {}, depth[401];
int u, v;
int kCnt = 0;

int timer = 0;
int inTime[401], outTime[401];
vector<int> dMap[20];
int dp[1 << 20] {};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    memset(depth, 0x3F, sizeof(depth));
    
    cin >> n >> k;
    rep(i, 0, n - 1) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    auto dfs = [&](auto self, int cur, int d=0, int p=-1) -> void {
        mxDepth[cur] = depth[cur] = d;
        if(d) dMap[d - 1].push_back(cur);
        if(mxDepth[cur] == k) {
            kCnt ++;
            return;
        }
        for(auto c: edges[cur]) if(c != p) {
            self(self, c, d + 1, cur);
            mxDepth[cur] = max(mxDepth[cur], mxDepth[c]);
        }
    }; dfs(dfs, 1);

    if(kCnt <= k or k >= 20) { cout(true); return 0; }

    auto dfs2 = [&](auto self, int cur, int p = -1) -> void {
        inTime[cur] = timer;
        for(auto c: edges[cur]) if(c != p and mxDepth[c] == k)
            self(self, c, cur);
        if(depth[cur] == k)
            ++timer;
        outTime[cur] = timer;
    }; dfs2(dfs2, 1);

    for(int i=0;i < 1 << k; ++i) for(int bit=0; bit < k; ++ bit) if(!(i >> bit & 1)) {
        for(auto node: dMap[bit]) if(inTime[node] <= dp[i]) dp[i ^ 1 << bit] = max(dp[i ^ 1 << bit], outTime[node]);
    }

    cout(dp[(1 << k) - 1] == timer);
}