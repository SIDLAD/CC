#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
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

using T = pair<int,int>;
struct segtree
{
    int n;
    vector<T> tree;
    vector<T> lazy;
    T zero = {INF,INF}; // Change according to QUERY operation
    T no_change = {INF,INF}; // Change according to PROPAGATE operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(4 * sz + 1, zero);
        lazy.resize(4 * sz + 1, no_change); // Change according to MODIFY operation
    }

    T combine(T a, T b)
    {
        if(a == zero)return b;
        if(b == zero)return a;
        if(a.second > b.second)return b;
        else return a;
    }

    void propagate(int id, int segl, int segr)
    { // Change according to MODIFY operation
        int mid = (segl + segr) / 2;
        tree[2 * id + 1] = combine(tree[2 * id + 1], lazy[id]);
        lazy[2 * id + 1] = combine(lazy[2 * id + 1], lazy[id]);
        tree[2 * id + 2] = combine(tree[2 * id + 2], lazy[id]);
        lazy[2 * id + 2] = combine(lazy[2 * id + 2], lazy[id]);
        lazy[id] = no_change;
    }

    void modify(int l, int r, T val, int id, int segl, int segr)
    {
        if (l > segr || segl > r)
        {
            return;
        }
        if (segl >= l && segr <= r)
        {
            tree[id] = combine(tree[id],val);
            lazy[id] = combine(tree[id],val); // Change according to MODIFY operation
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(l, r, val, 2 * id + 1, segl, mid);
        modify(l, r, val, 2 * id + 2, mid + 1, segr);
    }

    void modify(int l, int r, T val)
    {
        modify(l, r, val, 0, 0, n - 1);
    }

    void modify(int index, T val)
    {
        modify(index, index, val);
    }

    T query(int l, int r, int id, int segl, int segr)
    {
        if (l > segr || segl > r)
        {
            return zero;
        }
        if (segl >= l && segr <= r)
        {
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(l, r, 2 * id + 1, segl, mid);
        T rightVal = query(l, r, 2 * id + 2, mid + 1, segr);
        if(leftVal == zero) return rightVal;
        return leftVal;
    }

    T query(int l, int r)
    {
        return query(l, r, 0, 0, n - 1);
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
    for(int i=0;i<m;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--,x--;
        if(l != x)st.modify(l,x-1,{x+1,i});
        if(r != x)st.modify(x+1,r,{x+1,i});
    }
    for(int i=0;i<n;i++)
    {
        auto ans = st.query(i,i);
        if(ans == st.zero)cout<<0<<" ";
        else cout<<ans.first<<" ";
    }
}