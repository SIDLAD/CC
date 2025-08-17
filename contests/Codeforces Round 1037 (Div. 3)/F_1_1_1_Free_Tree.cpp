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
        int n,q;
        cin >> n >> q;
        vi a(n);
        arrput(a);
        vector<vector<pair<int,int>>> edges(n);
        for(int i=0;i<n-1;i++) {
            int x,y, w;
            cin >> x >> y >> w; --x, --y;
            edges[x].emplace_back(y,w);
            edges[y].emplace_back(x,w);
        }
        vector<int> parent(n);
        vector<int> parentEdge(n);
        auto putParent = [&](auto self, int cur, int p=-1, int pEdge = 0) -> void {
            parent[cur] = p;
            parentEdge[cur] = pEdge;
            for(auto [nbr, ed]: edges[cur]) if(p!=nbr) {
                self(self, nbr, cur, ed);
            }
        };
        putParent(putParent, 0);

        int curAns = 0;
        vector<map<int,int>> vmp(n);
        for(int i=0;i<n;++i) {
            if(parent[i] == -1)continue;
            vmp[parent[i]][a[i]] -= parentEdge[i];
            if(a[i] != a[parent[i]]) curAns += parentEdge[i];
        }
        while(q--) {
            int v,x;
            cin >> v >> x;
            --v;

            //uncolor
            if(v) {
                if(a[parent[v]] != a[v]) curAns -= parentEdge[v];
                vmp[parent[v]][a[v]] += parentEdge[v];
            }
            curAns -= vmp[v][a[v]];

            //color
            a[v] = x;
            if(v) {
                if(a[parent[v]] != a[v]) curAns += parentEdge[v];
                vmp[parent[v]][a[v]] -= parentEdge[v];
            }
            curAns += vmp[v][a[v]];

            cout << curAns << endl;
        }
    }
}