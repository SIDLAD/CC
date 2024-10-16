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

int n,m;
vector<vector<int>> edges;
vector<int> p;
vector<int> v;

int dfs(int node)
{
    if(v[node] == 1)
    {
        return node;
    }
    else if(v[node] == 2)
    {
        return -1;
    }
    v[node] = 1;
    for(auto nbr: edges[node])
    {
        int x;
        if(v[nbr]!=2)p[nbr] = node;
        if((x=dfs(nbr)) != -1)return x;
    }
    v[node] = 2;
    return -1;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin>>n>>m;
    edges.resize(n+1);
    v.resize(n+1);
    p.resize(n+1,INF);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
    }
    int ans = -1;
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        {
            ans = dfs(i);
            if(ans != -1)
            {
                break;
            }
        }
    }
    if(ans == -1)cout<<"IMPOSSIBLE";    
    else
    {
        vector<int> stk;
        int cur = ans;
        stk.push_back(cur);
        do
        {
            cur = p[cur];
            stk.push_back(cur);
        } while (cur!=ans);
        cout<<stk.size()<<endl;
        while(stk.size())
        {
            cout<<stk.back()<<" ";
            stk.pop_back();
        }
        
    }
}