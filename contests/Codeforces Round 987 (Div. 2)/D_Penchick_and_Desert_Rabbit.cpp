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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;


template <typename T = int, typename V = T>
struct segtree
{
    int n;
    vector<T> tree;
    // vector<V> lazy;
    T zero = -INF; // Change according to QUERY operation
    // V lazy_zero; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(2 * sz - 1, zero);
        // lazy.resize(2 * sz - 1, lazy_zero);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return max(a,b);
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
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    // void propagate(int id, int segl, int segr)
    // {
        // if(lazy[id] == lazy_zero)return;
        // if(segl != segr)
        // {
            // int mid = (segl + segr) / 2;
            // array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            // for(auto child : children)
            // {
                // tree[child] = lazy[id];  // Change according to MODIFY operation
                // lazy[child] = lazy[id];  // Change according to MODIFY operation
            // }
        // }
        // lazy[id] = lazy_zero;
    // }

    void modify(T val, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = max(val,tree[id]); // Change according to MODIFY operation
            // lazy[id] = val; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, id + 1, segl, mid);
        modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    T query(int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }
};

vector<int> v;

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
        v.assign(n,0);
        arrPut(v);

        vector<int> dp(n);

        dp[n-1] = *max_element(all(v));

        segtree st(n + 1);

        st.modify(dp[n-1],v[n-1]);

        vector<int> prevmax(n);
        prevmax[0] = v[0];
        for(int i=1;i<n;i++)
        {
            prevmax[i] = max(prevmax[i-1],v[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            dp[i] = prevmax[i];
            auto alternateans = st.query(0,prevmax[i]-1);
            dp[i] = max(dp[i],alternateans);
            st.modify(dp[i],v[i]);
        }

        arrPrint(dp);
    }
}