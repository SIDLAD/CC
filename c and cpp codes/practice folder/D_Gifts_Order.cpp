#include <bits/stdc++.h>
const long double EPS = 1e-10;
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


template <typename T = array<int,3>>
struct segtree
{
    int n;
    vector<T> tree;
    T zero; // Change according to QUERY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        tree.resize(2 * sz - 1, zero);
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        T c;
        c[2] = max(a[2],b[2]);
        c[1] = min(a[1],b[1]);
        c[0] = max({a[0],b[0],b[2] - a[1]});
        return c;
    }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = {0ll,v[segl], v[segl]};  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }


    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = {0ll, val, val}; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, id + 1, segl, mid);
        modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

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
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }
    auto query(int index) { return query(index, index); }
};


vector<int> ans;
vector<int> a;
int n, q;
vector<pair<int,int>> queries;

void solve1(){
    vector<int> working = a;
    for(int i = 0;i<n;i++)working[i] -= i;
    segtree st(working);
    ans[0] = max(ans[0], st.tree[0][0]);
    for(int i=0;i<q;i++){
        auto [idx, val] = queries[i];
        working[idx] = - idx + val;
        st.modify(working[idx],idx);
        ans[i + 1] = max(ans[i + 1], st.tree[0][0]);
    }
}

void solve2(){
    vector<int> working = a;
    reverse(all(working));
    for(int i = 0;i<n;i++)working[i] -= i;
    segtree st(working);
    ans[0] = max(ans[0], st.tree[0][0]);
    for(int i=0;i<q;i++){
        auto [idx, val] = queries[i];
        idx = n - idx - 1;
        working[idx] = - idx + val;
        st.modify(working[idx],idx);
        ans[i + 1] = max(ans[i + 1], st.tree[0][0]);
    }
}

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
        cin >> n >> q;
        a.assign(n, 0);
        arrPut(a);
        queries.assign(q,{0,0});

        range(i,0,q){
            int p, x;
            cin >> p >> x;
            --p;
            queries[i] = {p, x};
        }

        ans.assign(q + 1,0);
        solve1();
        solve2();
        for(auto ele: ans){
            cout << ele << endl;
        }
    }
}