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

#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

using T2 = int;
struct segtree
{
    int n;
    vector<T2> tree;
    // vector<T2> lazy;
    T2 zero = INF; // Change according to QUERY operation
    // T2 lazy_zero; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, lazy_zero);
    }

    T2 combine(T2 a, T2 b)
    {
        if(a == INF)return b;
        if(b == INF)return a;
        return gcd(a,b); // Change according to QUERY operation
    }

    void build(vector<T2> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = v[segl];
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, 2 * id + 1, segl, mid);
        build(v, 2 * id + 2, mid + 1, segr);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    // void propagate(int id, int segl, int segr)
    // {
        // if(segl == segr)lazy[id] = lazy_zero;
        // if(lazy[id] == lazy_zero)return;
        // int mid = (segl + segr) / 2;
        // array<int , 2> children= {2 * id + 1, 2 * id + 2};
        // for(auto child : children)
        // {
            // tree[child] += lazy[id];  // Change according to MODIFY operation
            // lazy[child] += lazy[id];  // Change according to MODIFY operation
        // }
        // lazy[id] = lazy_zero;
    // }

    T2 query(int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > segr || segl > index_r)
        {
            return zero;
        }
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        // propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T2 leftVal = query(index_l, index_r, 2 * id + 1, segl, mid);
        T2 rightVal = query(index_l, index_r, 2 * id + 2, mid + 1, segr);
        return combine(leftVal, rightVal);
    }
};

using T = map<int,int>;
struct segtree_counter
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero; // Change according to QUERY operation
    // T lazy_zero; // Change according to MODIFY operation

    segtree_counter(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, lazy_zero);
    }

    T combine(T a, T b)
    {
        for(auto [ele,freq]:b)
        a[ele] += freq;
        return a;
    }

    void build(vector<int> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id].clear();
            tree[id][v[segl]] = 1;
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, 2 * id + 1, segl, mid);
        build(v, 2 * id + 2, mid + 1, segr);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    // void propagate(int id, int segl, int segr)
    // {
        // if(segl == segr)lazy[id] = lazy_zero;
        // if(lazy[id] == lazy_zero)return;
        // int mid = (segl + segr) / 2;
        // array<int , 2> children= {2 * id + 1, 2 * id + 2};
        // for(auto child : children)
        // {
            // tree[child] += lazy[id];  // Change according to MODIFY operation
            // lazy[child] += lazy[id];  // Change according to MODIFY operation
        // }
        // lazy[id] = lazy_zero;
    // }

    int query(int val, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > segr || segl > index_r)
        {
            return 0;
        }
        if (segl >= index_l && segr <= index_r)
        {
            if(tree[id].count(val))return tree[id][val];
            return 0;
        }
        // propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        int leftVal = query(val, index_l, index_r, 2 * id + 1, segl, mid);
        int rightVal = query(val, index_l, index_r, 2 * id + 2, mid + 1, segr);
        return leftVal + rightVal;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n + 1);
    v[0] = INF;
    for(int i=1;i<=n;i++)cin>>v[i];
    segtree st(v.size());
    segtree_counter cnt(v.size());
    cnt.build(v);
    st.build(v);
    int t;
    cin>>t;

    while(t--)
    {
        int l,r;
        cin>>l>>r;
        auto g = st.query(l,r);
        auto minus = cnt.query(g,l,r);
        cout<< r - l + 1 - minus <<endl;
        debug(g,minus);
    }
}