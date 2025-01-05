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

constexpr int batchsize = 1024;

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

constexpr int maxN = 5e4 + 1;

int n,m;
vector<vector<int>> edges;
vector<int> ind;
bitset<batchsize> reach[maxN + 1];
int ans[maxN + 1];
int topo[maxN + 1];
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    edges.resize(n + 1);
    ind.resize(n + 1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        ind[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)if(ind[i] == 0)q.push(i);
    int curidx = n - 1;
    while(q.size())
    {
        int cur = q.front();q.pop();
        topo[curidx--] = cur;
 
        for(auto nbr:edges[cur])
        {
            ind[nbr]--;
            if(ind[nbr] == 0)q.push(nbr);
        }
    }
    
    for(int i=1;i<=n;i += batchsize)for(int j=0;j<n;j++)
    {
        int cur = topo[j];
        reach[cur] = 0;
        for(auto nbr:edges[cur])
        {
            reach[cur] |= reach[nbr];
        }
        if(i <= cur and cur < i + batchsize)
        reach[cur].set(cur - i);
        ans[cur] += reach[cur].count();
    }
    
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    cout<<endl;
}