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
vector<int> profit;
vector<vector<int>> edges;

void tarjan(int node, vector<int>& stk, vector<int>& instk, vector<vector<int>>& edges,vector<int>& component, vector<int>& tin,vector<int>& lo, int& componentcount, int& t)
{
    instk[node] = true;
    stk.push_back(node);
    tin[node] = lo[node] = ++t;
    for(auto nbr:edges[node])
    {
        if(!tin[nbr])tarjan(nbr,stk,instk,edges,component,tin,lo,componentcount,t);
        if(instk[nbr])lo[node] = min(lo[node],lo[nbr]);
    }
    if(lo[node] == tin[node])
    {
        componentcount++;
        while(1)
        {
            int top = stk.back();
            stk.pop_back();
            instk[top] = false;
            component[top] = componentcount;
            if(top == node)break;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    profit.assign(n + 1,0);
    edges.assign(n + 1,vector<int>());
    for(int i=1;i<=n;i++)cin>>profit[i];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
    }
    vector<int> stk,instk(n + 1),component(n + 1),tin(n + 1),lo(n + 1);
    int componentcount = 0,t = 0;

    for(int i=1;i<=n;i++)if(!tin[i])tarjan(i,stk,instk,edges,component,tin,lo,componentcount,t);
    debug(component);
    vector<vector<int>> condensed(componentcount + 1);
    vector<int> newwt(componentcount + 1);
    for(int i=1;i<=n;i++)
    {
        newwt[component[i]] += profit[i];
        for(auto nbr:edges[i])if(component[i] != component[nbr])condensed[component[i]].push_back(component[nbr]);
    }
    vector<int> dp = newwt;
    queue<int> q;
    for(int i = componentcount; i>=1; i--)
    {
        for(auto nbr: condensed[i])
        {
            dp[nbr] = max(dp[nbr],dp[i] + newwt[nbr]);
        }
    }
    cout<<*max_element(all(dp))<<endl;
}