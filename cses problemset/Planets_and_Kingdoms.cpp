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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int n,m;
vector<vector<int>> edges,redges;
vector<pair<int,int>> tout;
vector<int> ans;

void dfs(int node, vector<int>& visited, vector<vector<int>>& edges, int& t, int label = -1)
{
    debug(node);
    if(visited[node])return;
    visited[node] = true;
    ans[node] = label;
    for(auto nbr: edges[node])if(!visited[nbr])
    {
        dfs(nbr,visited,edges,t,label);
    }
    if(tout[node-1] == make_pair(0ll,0ll))
    tout[node-1] = {t++,node};
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    cin>>n>>m;
    edges.resize(n + 1),redges.resize(n + 1),ans.resize(n + 1);
    tout.resize(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b),redges[b].push_back(a);
    }

    vector<int> visited(n + 1);
    int t=0;
    for(int i=1;i<=n;i++)dfs(i,visited,edges,t);
    sort(all(tout)),reverse(all(tout));
    debug(tout);
    visited.assign(n + 1, 0);
    int cnt = 0;
    for(int i=0;i<n;i++)if(!visited[tout[i].second])
    {
        dfs(tout[i].second,visited,redges,t,++cnt);
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}