#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order

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

struct delta
{
    pair<int,int> rangedelta;
    int curdelta;
};

struct segtree
{
    using T = delta;
    using V = T;
    int n;
    vector<T> tree;
    vector<V> lazy;
    T zero = {{0,0},-INF}; // Change according to QUERY operation
    V lazy_zero = {{0,0},0}; // Change according to MODIFY operation

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
        if(a.curdelta == -INF)return b;
        if(b.curdelta == -INF)return a;
        assert(false);
        return a;//this will not matter
    }

    
    delta readjustrangedelta(delta d)
    {
        if(d.curdelta < d.rangedelta.first)d.rangedelta.first = d.curdelta;
        if(d.curdelta > d.rangedelta.second)d.rangedelta.second = d.curdelta;
        return d;
    }

    T lazycombine(T child, T parent)
    {
        child.rangedelta.first = min(child.rangedelta.first, child.curdelta + parent.rangedelta.first);
        child.rangedelta.second = max(child.rangedelta.second, child.curdelta + parent.rangedelta.second);
        child.curdelta += parent.curdelta;
        return child;
    }

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id].rangedelta == lazy_zero.rangedelta)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            for(auto child : children)
            {
                lazy[child] = lazycombine(lazy[child],lazy[id]);
                tree[child] = lazycombine(tree[child],lazy[id]);
            }
        }
        lazy[id] = lazy_zero;
    }


    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id].curdelta += val; // Change according to MODIFY operation
            lazy[id].curdelta += val; // Change according to MODIFY operation
            tree[id] = readjustrangedelta(tree[id]);
            lazy[id] = readjustrangedelta(lazy[id]);
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, id + 1, segl, mid);
        modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        // tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    template <typename U>
    void set(U val, int index, int id = 0, int segl = 0, int segr = -1)
    {
        assert(val >= 1);
        if (segr == -1)segr = n - 1;
        if (index > segr || segl > index)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index && segr <= index)
        {
            assert(segl == segr);
            tree[id].curdelta = val; // Change according to MODIFY operation
            lazy[id].curdelta = val; // Change according to MODIFY operation
            lazy[id].rangedelta = tree[id].rangedelta = {val,val};
            return;
        }
        int mid = (segl + segr) / 2;
        set(val, index, id + 1, segl, mid);
        set(val, index, id + 2 * (mid - segl + 1), mid + 1, segr);
        // tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
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
            // assert(tree[id].rangedelta.first >= 1);
            return tree[id];
        }
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }
    auto query(int index) { return query(index, index).rangedelta.first; }
};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin>>v[i].first,v[i].second = i,v[i].first *= -1;

    vector<int> nextunequalpos(n);
    for(int i=n-1;i>=0;i--)
    {
        if(i == n-1)nextunequalpos[i] = INF;
        else if(v[i].first == v[i + 1].first) nextunequalpos[i] = nextunequalpos[i + 1];
        else nextunequalpos[i] = i + 1;
    }
    sort(all(v));
    debug(v);
    map<int,int> segtreemapping;
    for(int i=0;i<n;i++)
    {
        segtreemapping[v[i].second] = i;
    }
    debug(segtreemapping);

    debug(nextunequalpos);
    map<int,int> nextunequalposmapping;
    for(int i=0;i<n;i++)
    {
        if(nextunequalpos[i] == INF)nextunequalposmapping[v[i].second] = INF;
        else
        {
            nextunequalposmapping[v[i].second] = nextunequalpos[i];
        }
    }

    debug(nextunequalposmapping);

    sort(all(v),[&](auto a, auto b){
        return a.second < b.second;
    });

    debug(v);


    ordered_set<pair<int,int>> os;
    segtree st(n);

    // map<int,int> rankstoset;

    for(int i=0;i<k;i++)
    {
        auto [vv, ind] = v[i];
        os.insert({vv,i});
        // int rank = os.order_of_key({vv,-INF}) + 1;
        // st.set(rank,segtreemapping[ind]);
        // st.modify(1,nextunequalposmapping[ind],INF);
        // rankstoset[segtreemapping[ind]] = rank;
    }

    for(int i=0;i<k;i++)
    {
        auto [vv,ind] = v[i];
        int rank = os.order_of_key({vv,-INF}) + 1;
        debug(i,rank);
        st.set(rank,segtreemapping[ind]);
    }
    debug(segtreemapping);

    vector<int> ans(n);
    debug();
    for(int i=0;i<n-k;i++)//ith will be removed, i + k th will be added
    {
        debug(i);
        auto [vvrem,indrem] = v[i];
        auto [vvadd,indadd] = v[i + k];
        debug(segtreemapping[indrem]);

        ans[i] = st.query(segtreemapping[indrem]);
        debug(st.query(segtreemapping[indrem],segtreemapping[indrem]).rangedelta,st.query(segtreemapping[indrem],segtreemapping[indrem]));
        st.modify(1,nextunequalposmapping[indadd],INF);
        os.insert({vvadd,indadd});

        st.modify(-1,nextunequalposmapping[indrem],INF);
        os.erase({vvrem,indrem});
        
        int rank = os.order_of_key({vvadd,-INF}) + 1;
        st.set(rank,segtreemapping[indadd]);


        // #ifndef cerr
        // debug();
        // for(int i=0;i<n;i++)
        // {
        //     debug(i,st.query(i,i).curdelta,st.query(i,i).rangedelta);
        // }
        // debug();
        // #endif
        // debug(segtreemapping[indadd]);
        // #ifndef cerr
        // debug();
        // for(int i=0;i<n;i++)
        // {
        //     debug(i,st.query(i,i).curdelta,st.query(i,i).rangedelta);
        // }
        // debug();
        // #endif
        
    }

    for(int i=n-k;i<n;i++)
    {
        auto [vv,ind] = v[i];
        assert(ind == i);
        ans[i] = st.query(segtreemapping[ind]);
        #ifndef cerr
        debug();
        for(int i=0;i<n;i++)
        {
            debug(i,st.query(i,i).curdelta);
        }
        debug();
        #endif
    }

    arrPrint(ans);
}