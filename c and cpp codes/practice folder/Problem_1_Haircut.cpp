#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

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

template <typename T>
struct segtree
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero; // Change according to QUERY operation
    // T lazy_zero; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, lazy_zero);
    }

    T combine(T a, T b)
    {
        return a + b; // Change according to QUERY operation
    }

    void build(vector<T> &v, int id = 0, int segl = 0, int segr = -1)
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

    void modify(T val, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > segr || segl > index_r)
        {
            return;
        }
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = val; // Change according to MODIFY operation
            // lazy[id] += val; // Change according to MODIFY operation
            return;
        }
        // propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, 2 * id + 1, segl, mid);
        modify(val, index_l, index_r, 2 * id + 2, mid + 1, segr);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    T query(int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
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
        T leftVal = query(index_l, index_r, 2 * id + 1, segl, mid);
        T rightVal = query(index_l, index_r, 2 * id + 2, mid + 1, segr);
        return combine(leftVal, rightVal);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int N = n + 1;
    vector<int> fenwick(N + 1);
    auto update = [&](int index)
    {
        index++;
        int inc = 1;
        for(int i = index; i <= N; i += (i & -i))fenwick[i] += inc;
    }
    ;

    auto query = [&](int l)
    {
        l ++;
        int r = N;
        int lsum = 0;
        for(int i = l;i >= 1; i -= (i & -i))lsum += fenwick[i];
        int rsum = 0;
        for(int i = r; i >= 1;i -= (i &- i))rsum += fenwick[i];
        return rsum - lsum;
    }
    ;
    vector<int> ans(n);
    for(int i = 0;i < n;i++)
    {
        update(v[i]);
        if(v[i] >= n-1)continue;
        ans[v[i] + 1] += query(v[i]);
    }
    partial_sum(all(ans),ans.begin());
    for(auto ele:ans)cout<<ele<<endl;
    
}