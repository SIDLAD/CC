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

int n;
vector<array<int,3>>edgeinp; // third index is the weight of the edge

template <typename T = pair<int,int>>
struct segtree
{
    int n;
    vector<T> tree;
    vector<int> lazy;
    vector<int> first_occ,last_occ;
    T zero = {INF,INF}; // Change according to QUERY operation
    int lazy_zero = 0; // Change according to MODIFY operation

    segtree(int sz, vector<int>& first_occ, vector<int>& last_occ):first_occ(first_occ),last_occ(last_occ)
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
        if(a.second < b.second)return a;
        else return b;
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

    void propagate(int id, int segl, int segr)
    {
        if(lazy[id] == lazy_zero)return;
        if(segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            for(auto child : children)
            {
                tree[child].second += lazy[id];  // Change according to MODIFY operation
                lazy[child] += lazy[id];  // Change according to MODIFY operation
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
            tree[id].second += val; // Change according to MODIFY operation
            lazy[id] += val; // Change according to MODIFY operation
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

    inline int getdepth(int node)
    {
        return query(first_occ[node]).second;
    }

    void update_edge(int edgeindex, int newwt)
    {
        int prevwt = edgeinp[edgeindex][2];
        int delta = newwt - prevwt;
        modify(delta,first_occ[edgeinp[edgeindex][1]],last_occ[edgeinp[edgeindex][1]]);
        edgeinp[edgeindex][2] = newwt;
    }

    int calculatedist(int anode, int bnode)
    {
        int l = first_occ[anode];
        int r = first_occ[bnode];
        if(l > r)swap(l,r);
        int lcadepth = query(l,r).second;
        debug(getdepth(anode),getdepth(bnode),lcadepth);
        return getdepth(anode) + getdepth(bnode) - 2*lcadepth;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    vector<vector<pair<int,int>>> edges(n + 1);
    for(int i=0;i<n-1;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[a].push_back({b,w});
        edges[b].push_back({a,w});
        edgeinp.push_back({a,b,w});
    }

    vector<pair<int,int>> euler;
    vector<int> first_occ(n + 1),last_occ(n + 1);
    vector<int> parent(n + 1);
    auto dfs = [&](auto self, int node = 1, int depth = 0, int p = -1)->void
    {
        parent[node] = p;
        euler.push_back({node,depth});
        first_occ[node] = euler.size() - 1;
        for(auto [nbr,wt]:edges[node])if(nbr != p)
        {
            self(self,nbr,depth + wt,node);
            euler.push_back({node,depth});
        }
        last_occ[node] = euler.size() - 1;
    };
    dfs(dfs);
    for(auto& [a,b,_]:edgeinp)
    {
        if(parent[a] == b)swap(a,b);
    }

    // debug(edgeinp);
    segtree st(euler.size(),first_occ,last_occ);
    st.build(euler);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x == 1)
        {
            st.update_edge(y-1,z);
        }
        else
        {
            cout<<st.calculatedist(y,z)<<endl;
        }
    }
}