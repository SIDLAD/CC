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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5 + 1;

int n,k;
int w[N], c[N];

vector<int> edges[N];
int isEmpty[N];
int isCutie[N];

void dfs1(int cur=1, int par=1) {
    isEmpty[cur] = c[cur] == 0;
    for(auto nbr: edges[cur]) if(nbr != par) {
        dfs1(nbr, cur);
        if(!isEmpty[nbr]) isEmpty[cur] = 0;
    }
}

void dfs2(int cur=1, int par=1) {
    if(isEmpty[cur]) c[cur] = c[par];
    for(auto nbr: edges[cur]) if(nbr != par) dfs2(nbr, cur);
}

set<int> stol(int cur=1, int par=1) {
    isCutie[cur] = false;
    set<int> st;
    set<int> intersect;
    for(auto nbr: edges[cur]) if(nbr != par and !isEmpty[nbr]) {
        auto ret = stol(nbr, cur);
        if(sz(ret) > sz(st)) swap(ret, st);

        for(auto e: ret) if(st.contains(e)) intersect.insert(e);
        st.insert(all(ret));
    }

    if(!c[cur]) if(sz(intersect)) c[cur] = *intersect.begin();
    else c[cur] = *st.begin();
    intersect.erase(c[cur]);
    if(sz(intersect)) isCutie[cur] = true;

    st.insert(c[cur]);
    return st;
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
        int n,k;
        cin >> n >> k;
        for(int i=1;i<=n;++i) edges[i].clear(), isEmpty[i] = 0, isCutie[i] = 0;
        rep(i,1,n+1) cin >> w[i];
        rep(i,1,n+1) cin >> c[i];
        if(accumulate(c + 1, c + 1 + n, 0ll) == 0) rep(i,1,n + 1) c[i] = 1;
        rep(_,0,n-1) {
            int a,b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        dfs1();
        stol();
        dfs2();

        int ans = 0;
        rep(i,1,n+1) ans += isCutie[i] * w[i];

        cout << ans << endl;
        rep(i,1,n + 1) cout << c[i] << " "; cout << endl;
    }
}