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

template <typename T = pair<int,int>, typename V = int>
struct segtree
{
    int n;
    vector<T> tree;
    vector<V> lazy;
    T zero = {0,INF}; // Change according to QUERY operation
    V lazy_zero = 0; // Change according to MODIFY operation

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
        if(a.first - a.second > b.first - b.second)return a;
        return b;
    }

    template <typename U>
    void build(vector<U> &v, vector<int>& pre, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = {segl == 0 ? 0 : pre[segl - 1] ,v[segl]};  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, pre,id + 1, segl, mid);
        build(v, pre,id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id] == lazy_zero)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            for(auto child : children)
            {
                tree[child].first += lazy[id];  // Change according to MODIFY operation
                lazy[child] += lazy[id];  // Change according to MODIFY operation
            }
        }
        lazy[id] = lazy_zero;
    }

    void modify1(int val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        assert(index_l == index_r);
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            assert(segl == segr);
            modify2(val - tree[id].second, index_l + 1, n-1);
            tree[id].second = val; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modify1(val, index_l, index_r, id + 1, segl, mid);
        modify1(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    void modify(int val, int index) { return modify1(val, index, index); }

    void modify2(int delta, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if(segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id].first += delta;
            lazy[id] += delta;
            return;
        }
        int mid = (segl + segr) / 2;
        modify2(delta, index_l, index_r, id + 1, segl, mid);
        modify2(delta, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            debug(segl,id);
            debug(tree[id]);
            return tree[id];
        }
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
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        arrPut(a);
        vector<int> pre(n);
        partial_sum(all(a),pre.begin());
        segtree st(n);
        st.build(a,pre);

        auto xx = st.query(0,n-1);
        cout<<max(0ll,xx.first - xx.second) + st.query(n-1).second<<endl;

        while(q--)
        {
            int id,val;
            cin>>id>>val;
            id--;
            st.modify(val,id);
            auto xx = st.query(0,n-1);
            cout<<max(0ll,xx.first - xx.second) + st.query(n-1).second<<endl;
        }
    }
}