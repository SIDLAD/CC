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

int savemem;


class DSU {
public:
    int n;
    vector<int> p,sz,rank;
    vector<pair<int&,int>> history;
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

            history.emplace_back(rank[c],rank[c]);
            history.emplace_back(sz[c],sz[c]); 
            history.emplace_back(p[d],p[d]); 
            history.emplace_back(count,count); 

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
        history.emplace_back(savemem,savemem);
    }
    void rollback()
    {
        while(&(history.back().first) != &savemem){
            history.back().first = history.back().second;
            history.pop_back();
        }
        history.pop_back();
    }
};

constexpr int len = 224;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
    range(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        edges[i] = {a,b};
    }

    vector<vector<array<int,3>>> querybuckets(len);
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        querybuckets[a/len].push_back({a,b,i});
    }
    vector<int> answers(k);
    DSU dsu(1,n);
    for(int i=0;i<len;i++){
        sort(all(querybuckets[i]),[](auto a, auto b){return a[1] < b[1];});
        assert(dsu.count == n);
        auto& queries = querybuckets[i];
        int qi = 0;
        for(;qi < queries.size() and queries[qi][1] < (i + 1) * len;qi++)
        {
            assert(dsu.count == n);
            for(int ptr = queries[qi][0];ptr<=queries[qi][1];ptr++)
            {
                dsu.unite(edges[ptr].first,edges[ptr].second);
            }
            answers[queries[qi][2]] = dsu.count;
            while(dsu.history.size())
            {
                dsu.history.back().first = dsu.history.back().second;
                dsu.history.pop_back();
            }
        }
        assert(dsu.count == n);
        int curl = (i + 1) * len;
        int curr = (i + 1) * len - 1;
        for(;qi < queries.size();qi++)
        {
            auto [l,r,ansi] = queries[qi];
            while(curr < r)
            {
                curr++;
                dsu.unite(edges[curr].first,edges[curr].second);
            }

            dsu.save();
            while(curl > l)
            {
                curl--;
                dsu.unite(edges[curl].first,edges[curl].second);
            }
            answers[ansi] = dsu.count;
            dsu.rollback();
            curl = (i + 1) * len;
        }
        while(dsu.history.size())
        {
            dsu.history.back().first = dsu.history.back().second;
            dsu.history.pop_back();
        }
    }
    for(int i=0;i<k;i++)cout<<answers[i]<<endl;
}