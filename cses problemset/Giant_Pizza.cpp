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

void tarjan(int node, vector<vector<int>>& edges, vector<int>& stack, vector<int>& instack, vector<int>& component, int& componentcount, vector<int>& tin, vector<int>& lo, int& curt)
{
    tin[node] = lo[node] = ++curt;
    stack.push_back(node),instack[node] = 1;
    for(auto nbr:edges[node])
    {
        if(!tin[nbr])tarjan(nbr,edges,stack,instack,component,componentcount,tin,lo,curt);
        if(instack[nbr])lo[node] = min(lo[node],lo[nbr]);
    }
    if(lo[node] == tin[node])
    {
        while(1)
        {
            int top = stack.back();stack.pop_back();
            instack[top] = false;
            component[top] = componentcount;
            if(top == node)break;
        }
        componentcount++;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>m>>n;
    vector<vector<int>> edges(2 * n + 1);
    for(int i=0;i<m;i++)
    {
        char a,b;
        int na,nb;
        cin>>a>>na>>b>>nb;
        int sgna = 0,sgnb = 0;
        if(a == '+')sgna = 1;
        if(b == '+')sgnb = 1;
        edges[na + n*(sgna)].push_back(nb + n*(1^sgnb));
        edges[nb + n*(sgnb)].push_back(na + n*(1^sgna));
    }
    vector<int> tmpstk;
    vector<int> instack(2*n + 1);
    vector<int> component(2*n + 1);
    int componentcount = 0;
    vector<int> tin(2*n + 1),lo(2*n + 1);
    int cur_t = 0;

    for(int i=1;i<=2*n;i++)if(!tin[i])
    {
        tarjan(i,edges,tmpstk,instack,component,componentcount,tin,lo,cur_t);
    }
    debug(component);
    bool check = true;
    for(int i=1;i<=n;i++)if(component[i] == component[i+n]){check = false;break;}
    if(!check)cout<<"IMPOSSIBLE"<<endl;
    else for(int i=1;i<=n;i++)
    {
        if(component[i] < component[i + n])cout<<"+ ";
        else cout<<"- ";
    }
}