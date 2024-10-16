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

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

int visited[(int)1e5 + 1]; //0 white 1 grey 2 black

int parent[(int)1e5 + 1];

int dfs(int node, vector<vector<int>>& edges, int p) // -1 => no cycle
{
    debug(node);
    visited[node] = 1;
    for(auto nbr: edges[node])if(nbr!=p)
    {
        if(!visited[nbr]){parent[nbr] = node;auto x = dfs(nbr,edges,node);if(x!= -1)return x;}
        else if(visited[nbr] == 1)
        {
            parent[nbr] = node;
            return nbr;
        }
    }
    visited[node] = 2;
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    memset(visited,0,sizeof(int)*(n + 1));
    memset(parent,-1,sizeof(int) * (n + 1));
    vector<vector<int>> edges(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b),edges[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        debug(i);
        if(!visited[i])
        {
            int ret = dfs(i,edges,-1);
            if(ret != -1)
            {
                int cur = ret;
                vector<int> ans = {cur};
                while(parent[cur]!=ret)
                {
                    ans.push_back(parent[cur]);
                    cur = parent[cur];
                }
                ans.push_back(ret);
                cout<<ans.size()<<endl;
                while(ans.size())
                {
                    cout<<ans.back()<<" ";
                    ans.pop_back();
                }
                for(int i=1;i<=n;i++)
                {
                    debug(i,parent[i]);
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}