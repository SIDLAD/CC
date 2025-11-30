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

int n,e;


#define RANDOM_GEN_MACRO

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());

int oneOrZero() {
    return rng() % 2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin >> n >> e;
    vector<vector<int>> edges(n + 1);
    rep(_,0,e) {
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        edges[b].push_back(a);
    }

    int mx = -1;
    vector<vector<int>> list(n + 1);

    rep(i,1,n + 1) {
        int s; cin >> s;
        list[i].resize(s);
        for(auto& e: list[i]) cin >> e, mx = max(mx, e);
    }

    vector<bool> assignment(mx + 1);
    vector<int> choose0(n + 1), choose1(n + 1);
    while(true) {
        rep(i,1, mx + 1) assignment[i] = oneOrZero();
        bool chT = true;

        rep(i,1,n + 1) {
            bool ch0 = false, ch1 = false;
            for(auto e: list[i])
            if(assignment[e]) ch1 = true, choose1[i] = e;
            else ch0 = true, choose0[i] = e;

            if(!ch0 or !ch1) {
                chT = false;
                break;
            }
        }

        if(chT) break;
    }

    vector<bool> coloring(n + 1);

    for(int i=1;i<=n;++i) {
        int zc = 0, oc = 0;
        for(auto nbr: edges[i])
        if(coloring[nbr]) oc++;
        else zc++;
        if(oc < zc) coloring[i] = 1;
    }

    for(int i=1;i<=n;++i) {
        if(coloring[i]) cout << choose1[i] << " ";
        else cout << choose0[i] << " ";
    } cout << endl;

    for(int i=1;i <= mx; ++i) cout << assignment[i] + 1 << " ";
    cout << endl;
}