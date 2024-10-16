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
vector<int> v;
int c;
pair<int,int> solve(int node, int p, vector<vector<int>> &edges)
{
    int selected = v[node],unselected = 0;
    for(auto nbr: edges[node]) if(nbr!=p)
    {
        auto [chs,chns] = solve(nbr,node,edges);
        selected += max(chs - 2*c,chns);
        unselected += max(chs,chns);
    }
    return {selected,unselected};
}

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
        int n;
        cin>>n>>c;
        v.assign(n,0);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<vector<int>> edges(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        
        }
        auto [a,b] = solve(0,0,edges);
        cout<<max(a,b)<<endl;
    }
}