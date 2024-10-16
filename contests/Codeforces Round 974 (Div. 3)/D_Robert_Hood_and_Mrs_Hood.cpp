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

using T = int;
struct segtree
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero = -INF; // Change according to QUERY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, 0);
        // lazy.resize(4 * sz + 1, 0); // Change according to MODIFY operation
    }

    void resize(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, 0);
        // lazy.resize(4 * sz + 1, 0);
    }

    T combine(T a, T b)
    {
        return max(a,b); // Change according to QUERY operation
    }

    void build(int id, int segl, int segr, vector<T> &v)
    {
        if (segl == segr)
        {
            tree[id] = v[segl];
            return;
        }
        int mid = (segl + segr) / 2;
        build(2 * id + 1, segl, mid, v);
        build(2 * id + 2, mid + 1, segr, v);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void build(vector<T> &v)
    {
        build(0, 0, n - 1, v);
    }

    void propagate(int id, int segl, int segr)
    { // Change according to MODIFY operation
        // int mid = (segl + segr) / 2;
        // tree[2 * id + 1] += lazy[id];
        // lazy[2 * id + 1] += lazy[id];
        // tree[2 * id + 2] += lazy[id];
        // lazy[2 * id + 2] += lazy[id];
        // lazy[id] = 0;
    }

    void modify(int l, int r, T val, int id, int segl, int segr)
    {
        if (l > segr || segl > r)
        {
            return;
        }
        if (segl >= l && segr <= r)
        {
            tree[id] += val;
            // lazy[id] += val; // Change according to MODIFY operation
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(l, r, val, 2 * id + 1, segl, mid);
        modify(l, r, val, 2 * id + 2, mid + 1, segr);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
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
        return combine(leftVal, rightVal);
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
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,d,k;
        cin>>n>>d>>k;
        vector<pair<int,int>> v(k);
        for(int i=0;i<k;i++)cin>>v[i].first>>v[i].second;
        vector<int> pre(n+2);
        for(int i=0;i<k;i++)
        {
            pre[max(0ll,v[i].first - d + 1)]++;
            pre[min(n+1,v[i].second + 1)]--;
        }

        partial_sum(all(pre),pre.begin());
        int mn = INF,mx= -INF;
        int a1,a2;
        for(int i=1;i<=n-d+1;i++)
        {
            int x = pre[i];
            if(mn > x)
            {
                a1 = i,mn = x;
            }
            if(mx < x)
            {
                a2 = i,mx = x;
            }
        }
        debug(mn,mx,a1,a2);
        cout<<a2<<" "<<a1<<endl;
    }
}