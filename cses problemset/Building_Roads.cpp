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
    int start;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int n):DSU(0,n-1){}

    int count()
    {
        std::set<int> st;
        for(int i=start;i<=n;i++)
        {
            st.insert(p[i] = find(p[i]));
        }
        return st.size();
    }
    set<int> heads()
    {
        std::set<int> st;
        for(int i=start;i<=n;i++)
        {
            st.insert(p[i] = find(p[i]));
        }
        return st;
    }
 
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[p[x] = find(p[x])];
    }
 
    void unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);
            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
        }
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    // debug(n,m);
    DSU dsu(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        dsu.unite(a-1,b-1);
    }
    set<int> rem = dsu.heads();
    cout<<rem.size() - 1<<endl;
    for(auto it = rem.begin();it!= --rem.end();it++)
    {
        auto itc = it;
        itc++;
        cout<<*it + 1<<" "<<*itc + 1<<endl;
    }
}