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

enum color {
    green,
    darkGreen,
    yellow,
    black,
    col_cnt
};

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
        vector<int> edges[n + 1];
        rep(_,0,n-1) {
            int u,v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<color> assigned(n + 1);
        auto dfs1 = [&assigned, &edges](auto self, int cur, int p) -> void {
            vector<int> ctype(col_cnt);
            for(auto nbr: edges[cur]) if(nbr != p) {
                self(self, nbr, cur);
                ctype[assigned[nbr]] ++;
            }
            if(ctype[green] + ctype[darkGreen] <= 1 and ctype[yellow] == 0) 
                assigned[cur] = ctype[green] + ctype[darkGreen] == 0 ? green : darkGreen;
            else if(ctype[yellow] > 0 or ctype[green] + ctype[darkGreen] > 2) assigned[cur] = black;
            else assigned[cur] = yellow;
        };
        vector<pair<int,int>> ans;
        vector<bool> visited(n + 1);
        dfs1(dfs1, 1, 1);
        auto dfs2 = [&ans, &visited, &edges, &assigned](auto self, int cur) -> void {
            ans.emplace_back(1,cur);
            visited[cur] = 1;
            if(assigned[cur] != black) for(auto nbr: edges[cur]) if(assigned[nbr] != black and !visited[nbr]) self(self, nbr);
        };
        for(int i=0;i++<n;) if(assigned[i] == black) ans.emplace_back(2, i);
        for(int i=0;i++<n;) if(!visited[i]  && (assigned[i] == green || assigned[i] == black)) {
            dfs2(dfs2, i);
        }
        cout << ans.size() << endl;
        for(auto [a,b]: ans) cout << a << " " << b << endl;
    }
}