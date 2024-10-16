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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n+1);
    vector<vector<int>> redges(n+1);
    vector<int> indegree(n+1);
    vector<pair<int,int>> inp;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        redges[b].push_back(a);
        // indegree[b] ++;
        inp.push_back({a,b});
    }
    vector<int> reachable(n+1);
    auto dfs = [&](int node, auto self)-> void
    {
        for(auto& nbr: edges[node])
        {
            if(!reachable[nbr])
            reachable[nbr] = true,self(nbr,self);
        }
    };
    reachable[1] = 1;
    dfs(1,dfs);
    for(auto [a,b]:inp)
    {
        if(reachable[a])indegree[b]++;
    }
    vector<int> parent(n+1);
    vector<int> depth(n+1,-INF);
    depth[1] = 0;
    queue<int> q;
    q.push(1);
    debug(indegree);
    while(q.size())
    {
        int cur = q.front();
        debug(cur);
        q.pop();
        for(auto nbr: edges[cur])
        {
            indegree[nbr]--;
            if(indegree[nbr] == 0)q.push(nbr);
        }
        if(cur!=1)
        {
            for(auto pre:redges[cur])
            {
                if(depth[pre] + 1 > depth[cur])
                {
                    parent[cur] = pre;
                    depth[cur] = depth[pre] + 1;
                }
            }
        }
    }
    debug(redges);
    debug(edges);
    debug(indegree);
    debug(depth,parent);

    if(depth[n] == -INF)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        stack<int> answer;
        answer.push(n);
        while(answer.top() != 1)
        {
            answer.push(parent[answer.top()]);
        }
        cout<<answer.size()<<endl;
        while(answer.size())
        {
            cout<<answer.top()<<" ";
            answer.pop();
        }
    }
}