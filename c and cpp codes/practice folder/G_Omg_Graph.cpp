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
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;


vector<int> computeDijkstra(vector<vector<pair<int,int>>>& edges, int start) { 
    auto n = edges.size();
    vector<int> dists(n, INF);
    dists[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({dists[start], start});
    while(pq.size()) {
        auto [d, cur] = pq.top(); pq.pop();
        if(dists[cur] != d) continue;

        for(auto [nbr, wt]: edges[cur]) {
            if(max(d, wt) < dists[nbr]) {
                dists[nbr] = max(d, wt);
                pq.emplace(max(d,wt), nbr);
            }
        }
    }
    return dists;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,m;
        cin >> n >> m;

        vector<vector<pair<int,int>>> edges(n + 1);
        for(int i=0;i<m;++i) {
            int a,b,w;
            cin >> a >> b >> w;
            edges[a].emplace_back(b,w);
            edges[b].emplace_back(a,w);
        }

        auto src = computeDijkstra(edges, 1);
        auto dest = computeDijkstra(edges, n);

        int ans = INF;
        for(int p1=1;p1<=n;p1++) {
            for(auto [p2, w] : edges[p1]) {
                ans = min(
                    ans,
                    max({src[p1], dest[p2], w})
                    +
                    w
                );
            }
        }
        cout << ans << endl;
    }
}