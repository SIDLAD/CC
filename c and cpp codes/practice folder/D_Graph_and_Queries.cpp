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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template <typename T = pair<int,int>, typename V = T>
struct segtree
{
    int n;
    vector<pair<int,int>> tree;
    // vector<V> lazy;
    pair<int,int> zero = {0,0}; // Change according to QUERY operation
    // V lazy_zero = 0; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(2 * sz - 1, zero);
        // lazy.resize(2 * sz - 1, lazy_zero);
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return max(a,b);
    }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = {v[segl], segl};  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    // void propagate(int id, int segl, int segr)
    // {
        // if(lazy[id] == lazy_zero)return;
        // if(segl != segr)
        // {
            // int mid = (segl + segr) / 2;
            // array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            // for(auto child : children)
            // {
                // tree[child] = lazy[id];  // Change according to MODIFY operation
                // lazy[child] = lazy[id];  // Change according to MODIFY operation
            // }
        // }
        // lazy[id] = lazy_zero;
    // }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = {val, segl}; // Change according to MODIFY operation
            // lazy[id] = val; // Change according to MODIFY operation
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
        // propagate(id, segl, segr);
        
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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void travTimes(vector<pair<int,int>>& inOut, vector<vector<int>>& edges, int cur, int& timer) { // timer = -1
    inOut[cur].first = ++timer;
    for(auto nbr: edges[cur]) travTimes(inOut, edges, nbr, timer);
    inOut[cur].second = timer;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> p(n);
    arrput(p);
    vector<pair<int,int>> edges(m);
    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        edges[i] = {a,b};
    }
    vector<int> nodeHead(q, -1);
    vector<pair<int,int>> qs;
    rep(_,0,q) {int a,b; cin >> a >> b; qs.emplace_back(a,b);}
    UF dsu(n + m + 1);
    vector<vector<int>> reachForest(n + 1);


    vector<int> undeletedEdges;
    set<int> delE;
    for(int i=0;i<q;++i) if(qs[i].first == 2) delE.insert(qs[i].second - 1);
    rep(nd,0,m) if(delE.count(nd));
    else {
        if(dsu.find(edges[nd].first) == dsu.find(edges[nd].second)) continue;
        auto newNode = reachForest.size(); reachForest.emplace_back();
        reachForest[newNode].push_back(dsu.find(edges[nd].first)),
        reachForest[newNode].push_back(dsu.find(edges[nd].second));
        dsu.join(newNode, edges[nd].first),
        dsu.join(newNode, edges[nd].second);
    }


    for(int i=q-1; i>=0; --i) {
        auto [qt, nd] = qs[i];
        switch(qt) {
            case 1:
                nodeHead[i] = dsu.find(nd);
                break;
            case 2:
                if(dsu.find(edges[--nd].first) == dsu.find(edges[nd].second)) continue;
                auto newNode = reachForest.size(); reachForest.emplace_back();
                reachForest[newNode].push_back(dsu.find(edges[nd].first)),
                reachForest[newNode].push_back(dsu.find(edges[nd].second));
                dsu.join(newNode, edges[nd].first),
                dsu.join(newNode, edges[nd].second);
                break;
        }
    }

    set<int> roots; for(int i=1;i<=n;++i) roots.insert(dsu.find(i));
    int timer = -1;
    vector<pair<int,int>> inOut(reachForest.size());

    debug(roots);
    for(auto r: roots) {
        travTimes(inOut, reachForest, r, timer);
    }
    
    debug(reachForest);
    debug(inOut);
    debug(nodeHead);
    vector<int> init(reachForest.size());
    for(int i=0;i<init.size();++i) init[inOut[i].first] = i <= n && i != 0 ? p[i - 1] : 0;
    debug(init);
    segtree st(init);

    for(int i=0;i<q;++i) {
        auto [qt, nd] = qs[i];
        if(qt == 2) continue;
        auto nH = nodeHead[i];
        debug(nH, inOut[nH]);

        auto qr = st.query(inOut[nH].first, inOut[nH].second);
        cout << qr.first << endl;
        st.modify(0, qr.second);
    }
}