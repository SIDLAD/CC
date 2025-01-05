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

struct segtree
{
    using T = array<int,26>;
    using V = pair<int,T>;

    int n;
    vector<T> tree;
    vector<V> lazy;
    T zero = {}; // Change according to QUERY operation
    V lazy_zero = make_pair(-1,zero); // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(2 * sz - 1, zero);
        lazy.resize(2 * sz - 1, lazy_zero);
    }

    segtree(string &v) : segtree(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        for(int i=0;i<26;i++)a[i] += b[i];
        return a;
    }

    void build(string &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id][v[segl] - 'a'] = 1;  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    T getchars(V& seq, int reqlen)
    {
        T ans = zero;

        if(seq.first == 0)
        for(int i=0;i<26;i++)
        {
            int shift = min(seq.second[i],reqlen);
            ans[i] = shift;
            seq.second[i] -= shift;
            reqlen -= shift;
        }

        else
        for(int i=25;i>=0;i--)
        {
            int shift = min(seq.second[i],reqlen);
            ans[i] = shift;
            seq.second[i] -= shift;
            reqlen -= shift;
        }
        assert(reqlen == 0);
        return ans;
    }

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id] == lazy_zero)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            array<int, 2> lengths = {mid - segl + 1,segr - mid};
            for(int i=0;i<2;i++)
            {
                auto [child,len] = tie(children[i],lengths[i]);
                lazy[child] = {lazy[id].first,getchars(lazy[id],len)};
                tree[child] = lazy[child].second;
            }
        }
        lazy[id] = lazy_zero;
    }

    void _modify(V& seq, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            int len = segr - segl + 1;
            lazy[id] = {seq.first,getchars(seq,len)};
            tree[id] = lazy[id].second;
            return;
        }
        int mid = (segl + segr) / 2;
        _modify(seq, index_l, index_r, id + 1, segl, mid);
        _modify(seq, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
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
            return tree[id];
        }
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }
    auto query(int index) { return query(index, index); }

    void modify(int type, int index_l, int index_r) // 0 =>inc; 1=>dec
    {
        T seqs = query(index_l,index_r);
        V queryV = {type,seqs};
        _modify(queryV,index_l,index_r);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;

    segtree st(s);

    while(q--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        k^=1;
        i--,j--;
        st.modify(k,i,j);
    }
    string finans = "";
    for(int i=0;i<n;i++)
    {
        auto v = st.query(i);
        assert(accumulate(all(v),0ll) == 1 and *max_element(all(v)) == 1);
        finans += (char)(max_element(all(v)) - v.begin() + 'a');
    }
    cout<<finans<<endl;
}