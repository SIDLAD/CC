#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
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
vector<vector<int>> edges;
#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
queue<int> q;
class DSU {
public:
    int n;
    vector<int> p,sz,rank;
    int start;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }
 
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[p[x] = find(p[x])];
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(c==d)return false;
        if(sz[d] > sz[c])swap(c,d);
        p[d] = c;
        sz[c] += sz[d];
        edges[c].insert(edges[c].end(),all(edges[d]));
        if(edges[c].size() > 1)q.push(c);
        return true;
    }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("fcolor.in","r",stdin);
    // freopen("fcolor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    edges.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
    }


    DSU dsu(1,n);
    for(int i=1;i<=n;i++)
    {
        if(edges[i].size() > 1)q.push(i);
    }
    while(q.size())
    {
        int top = dsu.find(q.front());
        q.pop();
        while(edges[top].size() > 1)
        {
            int x = edges[top].back();
            edges[top].pop_back();
            dsu.unite(x,edges[top].back());
        }
    }
    map<int,int> appeared;int x = 1;
    for(int i=1;i<=n;i++)
    {
        if(appeared.count(dsu.find(i)) == 0)appeared[dsu.find(i)] = x++;
        cout<<appeared[dsu.find(i)]<<endl;
    }
}