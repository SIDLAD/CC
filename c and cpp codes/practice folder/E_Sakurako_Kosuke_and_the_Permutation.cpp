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


class DSU {
public:
    int n;
    vector<int> p,sz,rank;
    int start, count = 0;
 
    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
            count++;
        }
    }

    DSU(int n):DSU(0,n-1){}
 
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[p[x] = find(p[x])];
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);
            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
            count--;
            return true;
        }
        return false;
    }

    int solve()
    {
        set<int> st;
        int ans = 0;
        for(int i=start;i<=n;i++)
        {
            if(st.count(find(i)))continue;
            st.insert(find(i));
            ans += sz[find(i)] + 1 >>1;
            ans--;
        }
        return ans ;
    }
};


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
        cin>>n;
        vector<int> v(n + 1);
        for(int i=1;i<=n;i++)cin>>v[i];
        DSU dsu(1, n + 1);
        for(int i=1;i<=n;i++)dsu.unite(i,v[i]);
        cout<<dsu.solve()<<endl;
    }
}