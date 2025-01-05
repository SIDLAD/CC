#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

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
    vector<pair<int&,int>> changes;
    int savemem;
 
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
        return find(p[x]);
    }
    int size(int x)
    {
        if(x == p[x]) return sz[x];
        else return sz[find(p[x])];
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);

            changes.push_back({rank[c],rank[c]});
            changes.push_back({p[d],p[d]});
            changes.push_back({sz[c],sz[c]});
            changes.push_back({count,count});

            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
            count--;
            return true;
        }
        return false;
    }

    void save()
    {
        changes.push_back({savemem,savemem});
    }

    void rollback()
    {
        while(&(changes.back().first) != &savemem)
        {
            changes.back().first = changes.back().second;
            changes.pop_back();
        }
        changes.pop_back();
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
    DSU dsu(1,n);
    while(m--)
    {
        string s;
        cin>>s;
        if(s == "persist"){dsu.save();continue;}
        if(s == "union")
        {
            int a,b;
            cin>>a>>b;
            dsu.unite(a,b);
        }
        if(s == "rollback")dsu.rollback();
        cout<<dsu.count<<endl;
    }
}