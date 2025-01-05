#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,q,s;
    cin>>n>>q>>s;
    s--;
    int totnodes = 5*n - 1;
    vector<vector<pair<int,int>>> edges(5*n - 1);

    auto preprocess = [&](auto self, int si = 0, int ss = 0, int se = -1)->void
    {
        if(se == -1)se += n;
        if(ss == se)
        {
            edges[ss].push_back({n + si,0});
            edges[3 * n - 1 + si].push_back({ss,0});
            return;
        }
        int mid = ss + se >> 1;
        self(self,si + 1, ss, mid);
        self(self,si + 2*(mid - ss + 1), mid + 1, se);
        
        edges[n + si + 1].push_back({n + si, 0});
        edges[n + si + 2*(mid - ss + 1)].push_back({n + si,0});

        edges[3 * n - 1 + si].push_back({3 * n - 1 + si + 1, 0});
        edges[3 * n - 1 + si].push_back({3 * n - 1 + si + 2*(mid - ss + 1),0});
    };
    preprocess(preprocess);
    
    auto getnodeidlistsource = [&](auto self, vector<int>& v, int l, int r, int si = 0, int ss = 0, int se = -1)->void
    {
        if(se == -1)se += n;
        if(l > r || se < l || ss > r)return;
        if(ss >= l and se <= r)
        {
            v.push_back(si + n);
            return;
        }

        int mid = ss + se >> 1;
        self(self,v,l,r,si + 1, ss, mid);
        self(self,v,l,r,si + 2*(mid - ss + 1), mid + 1, se);
    };

    auto getnodeidlistdest = [&](auto self, vector<int>& v, int l, int r, int si = 0, int ss = 0, int se = -1)->void
    {
        if(se == -1)se += n;
        if(l > r || se < l || ss > r)return;
        if(ss >= l and se <= r)
        {
            v.push_back(si + 3*n - 1);
            return;
        }

        int mid = ss + se >> 1;
        self(self,v,l,r,si + 1, ss, mid);
        self(self,v,l,r,si + 2*(mid - ss + 1), mid + 1, se);
    };

    auto addedges = [&](vector<int>& vs,vector<int>& vd, int wt)
    {
        for(auto s:vs)for(auto d:vd)edges[s].push_back({d,wt});
    };

    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        int ls,rs,ld,rd,wt;
        if(t == 1)
        {
            cin>>ls>>ld>>wt;
            rs = --ls,rd = --ld;
        }
        else if(t == 2)
        {
            cin>>ls>>ld>>rd>>wt;
            rs = --ls,--ld,--rd;
        }
        else
        {
            cin>>ld>>ls>>rs>>wt;
            rd = -- ld,--ls,--rs;
        }
        vector<int> vs,vd;
        getnodeidlistsource(getnodeidlistsource,vs,ls,rs);
        getnodeidlistdest(getnodeidlistdest,vd,ld,rd);
        addedges(vs,vd,wt);
    }

    vector<int> dijkstra(5*n - 1,INF);
    dijkstra[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(pq.size())
    {
        auto [dist,nodeid] = pq.top();pq.pop();
        if(dist != dijkstra[nodeid])continue;
        for(auto [nbr,wt]:edges[nodeid])
        {
            if(dijkstra[nbr] > dist + wt)
            {
                dijkstra[nbr] = dist + wt;
                pq.push({dijkstra[nbr],nbr});
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        auto val = dijkstra[i];
        if(val == INF)val = -1;
        cout<<val<<" ";
    }
}