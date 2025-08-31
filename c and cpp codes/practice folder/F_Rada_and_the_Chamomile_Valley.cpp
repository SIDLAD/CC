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

void dfs(int cur, int par, vector<vector<int>>& edges, vector<int>& tin, vector<int>& lo, vector<int>& possi, int& timer, vector<pair<int,int>>& edgeList, int n) {
    tin[cur] = lo[cur] = timer ++;
    if(cur == n) possi[cur] = true;
    for(auto nbr: edges[cur]) if(nbr != par) {
        if(tin[nbr] == -1)
        dfs(nbr, cur, edges, tin, lo, possi, timer, edgeList, n);
        lo[cur] = min(lo[cur], lo[nbr]);
        possi[cur] |= possi[nbr];
        if(possi[nbr] && lo[nbr] > tin[cur]) edgeList.emplace_back(cur, nbr);
    }
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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> edges(n + 1);
        map<pair<int,int>, int> mp;
        for(int i=0;i<m;++i) {
            int a,b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
            mp[{a,b}] = mp[{b,a}] = i + 1;
        }


        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i=0;i<q;++i) cin >> queries[i];

        vector<int> tin(n + 1, -1);
        vector<int> lo(n + 1, -1);
        vector<int> possi(n + 1, 0);

        vector<pair<int,int>> edgeList;

        int _timer = 0;
        dfs(1, 1, edges, tin, lo, possi, _timer, edgeList, n);

        if(!sz(edgeList)) {
            for(auto e: queries) cout << -1 << " "; cout << endl;
            continue;
        }

        set<int> st;

        vector<int> minDist(n + 1, INF);
        vector<int> correspLane(n + 1, INF);


        for(auto [a,b]: edgeList)
        st.insert(a), st.insert(b), minDist[a] = 0, minDist[b] = 0,
        correspLane[a] = min(correspLane[a], mp[{a,b}]),
        correspLane[b] = min(correspLane[b], mp[{a,b}]);

        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        for(auto ele: st)
            pq.push({0, correspLane[ele], ele});

        while(pq.size()) {
            auto [md, id, e] = pq.top(); pq.pop();
            if(minDist[e] == md and correspLane[e] == id);
            else continue;

            for(auto nbr: edges[e]) {
                if(make_pair(md + 1, id) < make_pair(minDist[nbr], correspLane[id])) {
                    minDist[nbr] = md + 1;
                    correspLane[nbr] = id;
                    pq.push({md + 1, id, nbr});
                }
            }
        }

        for(auto e: queries) cout << correspLane[e] << " "; cout << endl;
    }
}