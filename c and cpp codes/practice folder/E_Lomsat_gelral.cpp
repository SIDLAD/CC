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

struct info
{
    int sum;
    int mxcnt;
    map<int,int> clrcnt;
};

info& merge(info& a,info& b)
{
    if(a.clrcnt.size() < b.clrcnt.size())swap(a,b);
    for(auto [clr,cnt]:b.clrcnt)
    {
        a.clrcnt[clr] += cnt;
        if(a.clrcnt[clr] > a.mxcnt)
        {
            a.sum = clr;
            a.mxcnt = a.clrcnt[clr];
        }
        else if(a.clrcnt[clr] == a.mxcnt)
        {
            a.sum += clr;
        }
    }

    delete &b;
    return a;
}

info& create(int clr)
{
    info& node = *new info;
    node.clrcnt[clr]++;
    node.mxcnt = 1;
    node.sum = clr;
    return node;
}

info& dfs(int node, int p, vector<int>& ans, vector<int>& ori_colors,vector<vector<int>>& edges)
{
    info& cur = create(ori_colors[node]);
    for(auto child: edges[node])if(child!=p)
    {
        cur = merge(cur, dfs(child,node, ans, ori_colors, edges));
    }
    ans[node] = cur.sum;
    return cur;
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    vector<vector<int>> edges(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[--a].push_back(--b);
        edges[b].push_back(a);
    }
    vector<int> ans(n);
    delete& dfs(0,-1,ans,c,edges);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}