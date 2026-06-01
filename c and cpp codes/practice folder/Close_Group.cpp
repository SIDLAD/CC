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

int n, m;
int edges[18];
int u, v;

int minCC[1 << 18]{};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        --u, --v;
        edges[u] |= (1 << v);
        edges[v] |= (1 << u);
    }

    for(int i=0; i < 1<<n; ++i) {
        minCC[i] = __builtin_popcount(i);
        bool ch =  true;
        for(int j=0; j < n; ++j) if (i >> j & 1) {
            if((edges[j] & i) != (i ^ 1 << j))
            {
                ch = false;
                break;
            }
        }
        if(ch) minCC[i] = 1;
    }

    for(int S=0; S < 1 << n; ++S) {
        for(int SS=S;SS = (SS - 1) & S;) { //all proper subsets other than null set
            minCC[S] = min(minCC[S], minCC[SS] + minCC[S^SS]);
        }
    }
    cout << minCC[(1<<n) - 1] << endl;
}