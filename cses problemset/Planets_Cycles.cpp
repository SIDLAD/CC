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
int n;
vector<int> a;
vector<int> cycleindex;
vector<int> cyclelength;
map<int,int> totcyclelen;
vector<int> root;
// vector<vector<int>> binlift;

int dfs(int node, int cind = -1, int clen = 0)
{
    if(cycleindex[node] >= 0)
    {
        if(clen != 0)
        {
            totcyclelen[cycleindex[node]] = clen;
        }
        return node;
    }

    if(root[node] >= 0)
    {
        return root[node];
    }

    if(cycleindex[node] == -1)
    {
        cycleindex[node] = cind;
        cyclelength[node] = clen;
        return dfs(a[node], cind, clen + 1);
    }

    cycleindex[node] = -1;
    root[node] = dfs(a[node], node,0);
    if(cycleindex[node] == -1)cycleindex[node] = -2;

    return root[node];
}

vector<pair<int,int>> stamp;
vector<vector<int>> redges;
vector<int> depths;

void dfs2(int node, int & t, int depth = 0)
{
    if(depth == 0  and cycleindex[node] < 0)return;
    depths[node] = depth;
    stamp[node].first = t++;
    for(auto nbr: redges[node])if(cycleindex[nbr] < 0)
    {
        dfs2(nbr,t,depth + 1);
    }
    stamp[node].second = t++;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    a.assign(n,0),cycleindex.assign(n,-2),cyclelength.assign(n,-1),root.assign(n,-1);
    stamp.resize(n),redges.resize(n),depths.resize(n);

    for(int i=0;i<n;i++)cin>>a[i],a[i]--,redges[a[i]].push_back(i);

    for(int i=0;i<n;i++)dfs(i);
    for(int i=0;i<n;i++){int _ = 0;dfs2(i,_);}

    debug(cycleindex,cyclelength,totcyclelen,root);
    debug(stamp,redges,depths);
    for(int i=0;i<n;i++)
    {
        if(cycleindex[i] >= 0)cout<<cyclelength[cycleindex[i]] + 1<<" ";
        else cout<<depths[i] + cyclelength[cycleindex[root[i]]] + 1<<" ";
    }
}