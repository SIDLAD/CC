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
        int n,a,b;
        cin>>n>>a>>b;
        vector<vector<int>> edges(n+1);
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        int meetspot = -1;
        int distmeetspot = -1;
        int dist = 0;
        
        {
            queue<int> q;
            q.push(b),q.push(a);
            vector<int> visited(n + 1);
            vector<int> dist(n + 1);
            visited[b] |= 2;
            visited[a] |= 1;
            dist[b] = 0;
            while(q.size())
            {
                int ele = q.front();
                q.pop();
                if(visited[ele] == 3)
                {
                    meetspot = ele;
                    distmeetspot = dist[meetspot];
                    break;
                }
                for(auto nbr: edges[ele])
                {
                    if(visited[nbr] & visited[ele])continue;
                    visited[nbr] |= visited[ele];
                    if(visited[ele] & 2)
                    {
                        dist[nbr] = dist[ele] + 1;
                    }
                    if(visited[nbr] == 3)
                    {
                        meetspot = nbr;
                        distmeetspot = dist[meetspot];
                        break;
                    }
                    q.push(nbr);
                }
            }
        }
        
        debug(distmeetspot,meetspot);
        auto dfs = [&](auto self, int node, int p)->pair<int,int> // tot, maxdepth
        {
            int mxdepth = 0;
            int tot = 0;
            for(auto child:edges[node])if(child!=p)
            {
                auto [subtot,subdepth] = self(self,child,node);
                tot += 2 + subtot;
                mxdepth = max(mxdepth,1 + subdepth);
            }
            return {tot,mxdepth};
        };

        auto [tot,depth] = dfs(dfs,meetspot,-1);
        cout<<distmeetspot + (tot - depth)<<endl;
    }
}