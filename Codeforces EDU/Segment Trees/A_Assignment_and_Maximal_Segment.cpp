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

template <typename T = array<int,4>>
struct segtree
{
    int n;
    vector<T> tree;
    vector<int> lazy;
    T zero = {0,0,0,0}; // Change according to QUERY operation
    int lazy_zero = INF; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(2 * sz - 1, zero);
        lazy.resize(2 * sz - 1, lazy_zero);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        debug(a,b);
        T ret = {max({a[0],b[0], a[2] + b[1]}),max(a[1],a[3] + b[1]), max(b[2],b[3] + a[2]),a[3] + b[3]};
        debug(ret);
        return ret;
    }

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id] == lazy_zero)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            array<int, 2> len = {mid - segl + 1, segr - mid}; 
            for(int i=0;i<2;i++)
            {
                auto child = children[i];
                if(lazy[id] < 0)tree[child] = {0,0,0,lazy[id] * len[i]};
                else tree[child] = {lazy[id]*len[i],lazy[id]*len[i],lazy[id]*len[i],lazy[id]*len[i]};
                lazy[child] = lazy[id];  // Change according to MODIFY operation
            }
        }
        lazy[id] = lazy_zero;
    }

    void modify(int val, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_r == -1)index_r = index_l;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        if (segl >= index_l && segr <= index_r)
        {
            int len = segr - segl + 1;
            if(val < 0)tree[id] = {0,0,0,val * len};
            else tree[id] = {val * len,val * len,val * len,val * len};
            lazy[id] = val; // Change according to MODIFY operation
            return;
        }
        propagate(id, segl, segr);
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
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
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
    segtree st(n);
    while(m--)
    {
        int l,r,v;
        cin>>l>>r>>v;
        st.modify(v,l,r-1);
        cout<<st.query(0,n-1)[0]<<endl;
    }
}