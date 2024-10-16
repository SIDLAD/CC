#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = INT_MAX/2;
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

#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

using T = int;
int segmenttree[2 * (int)(4e5 + 1) - 1];
int diff[(int)4e5];
struct segtree
{
    int n;
    // vector<T> lazy;
    T zero = INF; // Change according to QUERY operation
    segtree(int sz)
    {
        n = sz;
    }

    T combine(T a, T b)
    {
        if(max(a,b) == INF) return min(a,b);
        return gcd(a,b); // Change according to QUERY operation
    }

    void build(int id = 0, int segl = 0, int segr = INF)
    {
        if (segr == INF)segr = n - 1;
        if (segl == segr)
        {
            if(diff[segl] == 0)diff[segl] = INF;
            segmenttree[id] = diff[segl];
            return;
        }
        int mid = (segl + segr) / 2;
        build(id + 1, segl, mid);
        build(id + 2 * (mid - segl + 1), mid + 1, segr);
        segmenttree[id] = combine(segmenttree[id + 1], segmenttree[id + 2 * (mid - segl + 1)]);
    }

    void propagate(int id, int segl, int segr)
    { // Change according to MODIFY operation
        // int mid = (segl + segr) / 2;
        // segmenttree[id + 1] += lazy[id];
        // lazy[id + 1] += lazy[id];
        // segmenttree[id + 2 * (mid - segl + 1)] += lazy[id];
        // lazy[id + 2 * (mid - segl + 1)] += lazy[id];
        // lazy[id] = lazy_zero;
    }

    T query(int l, int r, int id, int segl = 0, int segr = INF)
    {
        if (segr == INF)segr = n - 1;
        if (l > segr || segl > r)
        {
            return zero;
        }
        if (segl >= l && segr <= r)
        {
            return segmenttree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(l, r, id + 1, segl, mid);
        T rightVal = query(l, r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }

    T query(int l, int r)
    {
        return query(l,r,0);
    }
};

bool check2pow(int a)
{
    // if(a == INF)return true;
    if(__builtin_popcountll(a) == 1)return true;
    return false;
}
// 0 3 1 4 3
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    segtree st(4e5 + 1);
    for(;T--;)
    {
        long long n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }
        for(int i=0;i<n-1;i++)diff[i] = abs(v[i+1] - v[i]);

        // segtree st(diff.size());
        st.n = n-1;
        st.build();
        long long ans=  0;

        int lastnoninfindx = -1;
        for(int i=0;i<n-1;i++)
        {
            int ll = 0;
            int ul = i + 1;
            if(lastnoninfindx == -1 and diff[i] == INF)continue;
            
            // while(ul - ll > 1)
            // {
            //     int mid = ll + ul >> 1;
            //     if(st.query(mid,i) == INF)ul = mid;
            //     else ll = mid;
            // }
            int prevul = ul;

            if(diff[i] == INF)
            {
                prevul = lastnoninfindx + 1;
            }
            else
            {
                lastnoninfindx = i;
            }

            ll = 0;
            if(!check2pow(st.query(ll,i)))
            {
                ans += prevul;
                continue;
            }
            while(ul - ll > 1)
            {
                int mid = ll + ul >> 1;
                if(!check2pow(st.query(mid,i)))ul = mid;
                else ll = mid;
            }
            ans += prevul - ul;
        }
        cout<<n * (n+1) / 2 - ans<<endl;
    }
}