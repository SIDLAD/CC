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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

template <typename T = int>
struct segtree
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero = -INF; // Change according to QUERY operation
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
        return max(a,b); // Change according to QUERY operation
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

    T query(int lim, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        int mid = (segl + segr) / 2;

        if(index_l > segl)
        {
            if(mid < index_l) return query(lim, index_l, index_r, 2 * id + 2, mid + 1, segr);
            auto r1 = query(lim, index_l, index_r, 2 * id + 1, segl, mid);
            if(r1 == -1)return query(lim, index_l, index_r, 2 * id + 2, mid + 1, segr);
            else return r1;
        }
        if(tree[id] <= lim)return -1;
        // propagate(id, segl, segr);
        if(segl == segr)return segl;
        if(tree[2*id + 1] > lim) return query(lim, index_l, index_r, 2 * id + 1, segl, mid);
        else if(tree[2*id + 2] > lim)return query(lim, index_l, index_r, 2 * id + 2, mid + 1, segr);
        else debug(tree[id],segl,segr,tree[2*id +1],tree[2*id+2]),assert(false);
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
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> diff(n);
    for(int i=1;i<n;i++)diff[i] = abs(a[i] - a[i-1]);
    segtree st(n);
    st.build(diff);
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x == 1)
        {
            int i,p;
            cin>>i>>p;
            --i;
            a[i] = p;
            if(i != 0)
            {
                st.modify(abs(a[i] - a[i-1]),i);
            }
            if(i != n - 1)
            {
                st.modify(abs(a[i + 1] - a[i]), i + 1);
            }
        }
        else
        {
            int i,t;
            cin>>i>>t;
            --i;
            auto ans = st.query(t,i + 1);
            if(ans == -1)cout<<n<<endl;
            else cout<<ans<<endl;
        }
    }
}