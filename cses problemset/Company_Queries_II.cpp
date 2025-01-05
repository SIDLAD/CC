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
int n,q;
vector<int> parent;
vector<int> tin,tout;
vector<vector<int>> binlift;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>q;
    parent.resize(n + 1);
    vector<vector<int>> redges(n + 1);
    tin.resize(n + 1,-1),tout.resize(n + 1,-1);
    int lgn = log2l(n) + 1;
    binlift.resize(lgn,vector<int>(n + 1));

    binlift[0][1] = parent[1] = 1;
    for(int i=2;i<=n;i++)cin>>parent[i],binlift[0][i]= parent[i];
    for(int j=1;j<lgn;j++)for(int i=1;i<=n;i++)binlift[j][i] = binlift[j-1][binlift[j-1][i]];
    debug(binlift);
    
    for(int i=2;i<=n;i++)redges[parent[i]].push_back(i);
    int timer = 1;
    auto dfs = [&](auto self, int node)->void
    {
        tin[node] = timer++;
        for(auto c: redges[node])
        {
            self(self,c);
        }
        tout[node] = timer++;
    };

    dfs(dfs,1);

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        
        int l = a;
        for(int i=lgn - 1;i>=0;i--)
        {
            if(tin[binlift[i][l]] <= tin[b] and tout[binlift[i][l]] >= tout[b]);
            else l = binlift[i][l];
        }
        if(tin[l] <= tin[b] and tout[l] >= tout[b])cout<<l<<endl;
        else cout<<parent[l]<<endl;
    }
}