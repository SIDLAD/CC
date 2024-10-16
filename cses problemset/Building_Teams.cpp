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

class DSU {
public:
    int n;
    vector<int> p,sz,rank;
    vector<int> len;
    int start;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        len.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
            len[i] = 0;
        }
    }

    DSU(int n):DSU(0,n-1){}
 
    pair<int,int> find(int x) {
        if(x == p[x]) return {x,0};
        auto ret = find(p[x]);
        ret.second += len[x];
        return ret;
    }
 
    bool unite(int a, int b) {
        auto pr1 = find(a);auto pr2 = find(b);
        if(pr1.first == pr2.first)
        {
            return ((pr1.second^pr2.second)&1);
        }

        if(rank[pr1.first] < rank[pr2.first])swap(pr1,pr2);
        if(rank[pr1.first] == rank[pr2.first])rank[pr1.first]++;
        p[pr2.first] = pr1.first;
        len[pr2.first] = 1 + pr1.second + pr2.second;
        return true;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(!dsu.unite(--a,--b)){cout<<"IMPOSSIBLE"<<endl;return 0;}
    }
    for(int i=0;i<n;i++)
    {
        cout<<((dsu.find(i).second&1 )+ 1)<<" ";
    }
}