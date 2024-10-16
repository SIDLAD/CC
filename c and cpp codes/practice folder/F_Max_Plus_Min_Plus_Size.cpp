#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order

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
    
    vector<int> active;
    vector<int> oddmx;
    vector<int> evenmx;
    int mxcnt=0;
    int counter = 0;

    DSU(int start,int n) : n(n),start(start) {
        rank.resize(n+1,1);
        p.resize(n+1);
        sz.resize(n+1);
        oddmx.resize(n+1),evenmx.resize(n+1),active.resize(n+1);
        for(int i=start;i<=n;i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int n):DSU(0,n-1){}

    bool notmxchecker()
    {
        assert(mxcnt>=0);
        return mxcnt == 0;
    }

    int elecnt()
    {
        return counter - notmxchecker();
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
        assert(c!=d);

        int pmxcntsum = 0;
        if(sz[c]&1)pmxcntsum += oddmx[c];
        else pmxcntsum += max(oddmx[c],evenmx[c]);

        if(sz[d]&1)pmxcntsum += oddmx[d];
        else pmxcntsum += max(oddmx[d],evenmx[d]);

        int newoddmx=0,newevenmx=0;
        int nmxcntsum = 0;

        if(sz[c]&1)
        {
            newoddmx = oddmx[c] + evenmx[d];
            newevenmx = evenmx[c] + oddmx[d];
        }
        else
        {
            newoddmx = oddmx[c] + oddmx[d];
            newevenmx = evenmx[c] + evenmx[d];
        }

        if((sz[c] + sz[d]) & 1) nmxcntsum = newoddmx;
        else nmxcntsum = max(newoddmx,newevenmx);

        mxcnt += nmxcntsum - pmxcntsum;
        counter += (sz[c] + sz[d] + 1)/2 - (sz[c] + 1)/2 - (sz[d] + 1)/2;

        if(d != c) {
            if(rank[c] < rank[d]) swap(c,d);
            if(rank[c] == rank[d]) rank[c]++;
            p[d] = c;
            sz[c] += sz[d];
        }
        
        oddmx[c] = newoddmx;
        evenmx[c] = newevenmx;
    }
    
    void insert(int a, bool ismax)
    {
        active[a] = 1;
        oddmx[a] = ismax;
        mxcnt+=ismax;
        counter++;
        if(a!=0 and active[a-1])
        {
            unite(a-1,a);
            
        }
        if(a!=n and active[a+1])
        {
            unite(a,a+1);
        }
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
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        umap<int,vector<int>> mp;
        DSU dsu(n);
        for(int i=0;i<n;i++)
        {
            mp[v[i]].push_back(i);
        }

        int mx = *max_element(all(v));
        set<int> st;
        for(auto ele: v)st.insert(ele);

        int mxans = -INF;
        for(auto it = st.rbegin();it!=st.rend();it++)
        {
            int ele = *it;
            for(auto ind: mp[ele])
            {
                dsu.insert(ind,ele==mx);
            }

            int curans = mx + ele + dsu.elecnt();
            mxans = max(mxans,curans);
        }
        cout<<mxans<<endl;
    }
}