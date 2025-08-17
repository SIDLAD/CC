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

int n;
vector<int> edges[(int)2e5 + 1];

int in[(int)2e5 + 1];
int out[(int)2e5 + 1];
int subsz[(int)2e5 + 1];
int superparent[(int)2e5 + 1];

int timer;

void dfs(int node=0, int p = -1, int spp = -1) {
    if(p == -1) timer = 0;
    else if(p == 0) spp = node;
    subsz[node] = 1;
    superparent[node] = spp;
    in[node] = ++timer;
    for(auto nbr: edges[node]) if(nbr != p) {
        dfs(nbr, node, spp);
        subsz[node] += subsz[nbr];
    }
    out[node] = timer;
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
        for(int i=0;i<n;++i) edges[i].clear();

        for(int i=0;i<n-1;++i) {
            int u,v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<int> gmex(n + 1);
        gmex[0] = n * (n - 1) >> 1;
        dfs();

        set<array<int,3>> lt({{in[0], out[0], 0}}), rt({{in[0], out[0], 0}});
        for(auto c: edges[0]) gmex[1] += subsz[c] * (n - 1 - subsz[c]);
        gmex[1] >>= 1;
        gmex[1] += n - 1;

        auto check = [&](int i, set<array<int,3>>& st) -> int {
            auto par = *--st.lower_bound({in[i], -1, -1});
            if(par[1] < in[i]) return 0;
            auto ch = st.lower_bound({in[i], -1, -1});
            if(ch == st.end()) return 1;
            else if((*ch)[0] <= out[i]) return 1;
            return 0;
        };

        auto branch = [&](int i, set<array<int,3>>& st) -> int {
            return superparent[(*st.rbegin())[2]] == superparent[i];
        };

        for(int i=1;i<n;++i) {
            if(branch(i, lt) && !check(i, lt)) break;
            if(branch(i, rt) && !check(i, rt)) break;
            if(check(i, lt)) {
                lt.insert({in[i], out[i], i});
            }
            else if(check(i, rt)) {
                rt.insert({in[i], out[i], i});
            }
            else break;

            auto l = (*lt.rbegin())[2];
            auto r = (*rt.rbegin())[2];
            
            if(l > r) swap(l,r);
            int lsz = subsz[l], rsz = subsz[r];
            if(l == 0) {
                auto spp = superparent[r];
                lsz -= subsz[spp];
            }
            gmex[i + 1] = lsz * rsz;
        }

        for(int i=0;i<n;++i) {
            gmex[i] = gmex[i] - gmex[i + 1];
        }
        arrprint(gmex);
    }
}