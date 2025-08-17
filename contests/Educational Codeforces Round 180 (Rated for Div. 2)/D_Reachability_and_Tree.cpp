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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

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
        int n;
        cin >> n;
        vector<vector<int>> edges(n + 1);
        vector<pair<int,int>> edgelist;
        for(int i=0;i<n-1;i++) {
            int a,b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
            edgelist.emplace_back(a,b);
        }
        assert(edgelist.size() == n - 1);

        int mid = -1;

        for(int i=1;i<=n;++i) if(edges[i].size() == 2) mid = i;
        if(mid == -1) cout(0); else cout(1);
        if(mid == -1) continue;
        
        vector<int> bip(n + 1);

        auto dfs = [&] (auto self, int cur, int p, int col)-> void {
            if(cur == mid) bip[cur] = 2;
            else col ^= 1, bip[cur] = col;
            for(auto nbr: edges[cur]) if(nbr != p) {
                self(self,nbr, cur, col);
            }
        };
        int root = mid + 1;
        if(root > n) root -= n;
        dfs(dfs, root, root, 1);

        for(auto [x,y] : edgelist) {
            if(bip[x] > bip[y]) swap(x,y);
            if(bip[y] == 2 && bip[x] == 1) swap(x ,y);
            cout << x << " " << y << endl;
        }
    }
}