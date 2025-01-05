#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    
    #define debug(x...) (_exe(x))
    
    class CNothing {};

    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&)
    {
        return proxy;
    }

    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
    {
        return proxy;
    }
    CNothing cnothing;
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

class DSU {
public:
    int n;
    vector<int> p,sz,rank;
    int start, count = 0;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
            count++;
        }
    }

    DSU(int n):DSU(0,n-1){}
 
    int find(int x) {
        if(x == p[x]) return x;
        return find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[find(p[x])];
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);
            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
            count--;
            return true;
        }
        return false;
    }
};

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
        cin>>n>>m;
        vector<set<int>> edges(n + 1);
        vector<array<int,3>> ans;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a].insert(b);
            edges[b].insert(a);
        }
        priority_queue<pair<int,int>> deg;
        for(int i=1;i<=n;i++)deg.push({edges[i].size(),i});
        debug(edges);
        while(deg.top().first > 1)
        {
            auto [_,node] = deg.top();
            debug(_,node);
            deg.pop();
            if(_ != edges[node].size())continue;
            
            int x = *edges[node].begin();
            edges[node].erase(x);
            edges[x].erase(node);
            int y = *edges[node].begin();
            edges[node].erase(y);
            edges[y].erase(node);
            ans.push_back({node,x,y});

            if(edges[x].count(y))edges[x].erase(y),edges[y].erase(x);
            else edges[x].insert(y),edges[y].insert(x);

            deg.push({edges[node].size(),node});
            deg.push({edges[x].size(),x});
            deg.push({edges[y].size(),y});
            debug(ans.back(),edges);
        }

        DSU dsu(1,n);
        pair<int,int> somedge;
        for(int i=1;i<=n;i++)
        {
            assert(edges[i].size() <= 1);
            for(auto nbr: edges[i])
            {
                //if exists loop should exe only once
                dsu.unite(i,nbr);
                somedge = {i,nbr};
            }
        }
        for(int i=1;i<=n;i++)debug(dsu.find(i));
        debug(somedge,ans);
        if(dsu.count != n)
        {
            for(int i=1;i<=n;i++)
            {
                if(dsu.find(i) == dsu.find(somedge.first))continue;
                ans.push_back({somedge.first,somedge.second,i});
                dsu.unite(i,somedge.first);
                somedge = {i,somedge.first};
            }
        }

        cout<<ans.size()<<endl;
        for(auto [a,b,c]:ans)
        {
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
}