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
int n,m;
vector<vector<int>> edges,redges;
vector<pair<int,int>> tout;

void dfs(int node, int &t, vector<int> &visited,vector<vector<int>> & edges)
{
    visited[node] = true;
    for(auto nbr :  edges[node])if(!visited[nbr])
    {
        dfs(nbr,t,visited,edges);
    }
    tout[node - 1] = {t++,node};
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    edges.resize(n + 1),redges.resize(n + 1);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        redges[b].push_back(a);
    }
    tout.resize(n);
    vector<int> visited(n + 1);
    int t = 0;
    for(int i=1;i<=n;i++)if(!visited[i])dfs(i,t,visited,edges);
    debug(tout);

    sort(all(tout),greater<pair<int,int>>());
    debug(tout);

    int start = tout.front().second;
    visited.assign(n + 1,0);
    dfs(start,t,visited,redges);
    if(accumulate(1 + all(visited),0ll) == n)
    cout(true);
    else
    {
        cout(false);
        int unr = -1;
        for(int i=1;i<=n;i++)if(!visited[i])
        {
            unr = i;
            break;
        }
        cout<<unr<<" "<<start<<endl;
    }
}