#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

template <typename T = array<int,3>, typename V = int>
struct segtree
{
    int n;
    vector<T> tree;
    vector<V> lazy;
    T zero = {0,-INF,INF}; // Change according to QUERY operation
    V lazy_zero = -INF; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(2 * sz - 1, zero);
        lazy.resize(2 * sz - 1, lazy_zero);
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return {a[0] + b[0], max(a[1],b[1]), min(a[2],b[2])};
    }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = {v[segl],v[segl],v[segl]};  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id] == lazy_zero)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            array<int, 2> lengths = {mid - segl + 1, segr - mid};
            array<pair<int,int>,2> segbounds;
            segbounds[0] = {segl,mid}, segbounds[1] = {mid + 1,segr};
            for(int i=0;i<2;i++)
            {
                auto [child, len] = tie(children[i],lengths[i]);
                assert(tree[child][1] == tree[child][2]);
                int val = lazy[id];
                tree[child] = {val * len, val, val};
                lazy[child] = lazy[id];
            }
        }
        lazy[id] = lazy_zero;
    }

    template <typename U>
    void set(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            assert(segr == segl);
            tree[id] = {val,val,val};
            return;
        }
        int mid = (segl + segr) / 2;
        set(val, index_l, index_r, id + 1, segl, mid);
        set(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    template <typename U>
    void modulo(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r || tree[id][1] < val)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r && tree[id][1] == tree[id][2])
        {
            int newval = tree[id][1] % val;
            tree[id] = {newval * (segr - segl + 1), newval,newval};
            lazy[id] = newval; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modulo(val, index_l, index_r, id + 1, segl, mid);
        modulo(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
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
    auto query(int index) { return query(index, index); }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    arrPut(v);
    segtree st(v);
    while(m--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l,r; cin>>l>>r;
            cout<<st.query(l-1,r-1)[0]<<endl;
        }
        else if(t == 2)
        {
            int l,r,x;
            cin>>l>>r>>x;
            st.modulo(x,l-1,r-1);
        }
        else
        {
            int k,x;
            cin>>k>>x;
            st.set(x,k-1,k-1);
        }
    }
}