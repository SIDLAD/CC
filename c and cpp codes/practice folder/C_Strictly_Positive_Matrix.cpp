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

bool inp() {
    int x;
    cin >> x;
    return x;
}

constexpr int MAXN = 2000;
vector<int> edges[MAXN];
int tin[MAXN]{};
int lo[MAXN]{};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout.precision(numeric_limits<double>::max_digits10);

    int n;
    cin >> n;
    rep(i,0,n) rep(j,0,n) if(inp()) edges[i].push_back(j);
    int curC = 0;
    int timer = 1;
    auto tarjan = [&](auto self, int i=0) -> void {
        lo[i] = tin[i] = timer++;
        for(auto nbr: edges[i]) {
            if(!tin[nbr]) {
                self(self, nbr);
                lo[i] = min(lo[i], lo[nbr]);
            }
            else lo[i] = min(lo[i], tin[nbr]);
        }
        if(tin[i] == lo[i]) curC++;
    }; tarjan(tarjan);
    cout(*min_element(tin, tin + n) && curC == 1);
}