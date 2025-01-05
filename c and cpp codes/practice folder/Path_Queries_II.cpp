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
#define sz(x) (int)(x).size()
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

/**
 * Author: Benjamin Qi, Oleksandr Kulkov, chilli
 * Date: 2020-01-12
 * License: CC0
 * Source: https://codeforces.com/blog/entry/53170, https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Trees%20(10)/HLD%20(10.3).h
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 * edges such that the path from any leaf to the root contains at most log(n)
 * light edges. Code does additive modifications and max queries, but can
 * support commutative segtree modifications/queries on paths and subtrees.
 * Takes as input the full adjacency list. VALS\_EDGES being true means that
 * values are stored in the edges, as opposed to the nodes. All values
 * initialized to the segtree default. Root must be 0.
 * Time: O((\log N)^2)
 * Status: stress-tested against old HLD
 */

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Siddharth
 * Date: 2024-12-22
 * Description: Uncomment for lazy.
 */
#pragma once

// template <typename T = int, typename V = T>
// struct segtree{
//     int n;
//     vector<T> tree;
//     // vector<V> lazy;
//     T zero = -INF; // Change according to QUERY operation
//     // V lazy_zero = 0; // Change according to MODIFY operation
//     segtree(int sz){
//         n = sz;
//         tree.clear(),tree.resize(2 * sz - 1, zero);;
//         // lazy.clear(), lazy.resize(2 * sz - 1, lazy_zero);
//     }

//     template <typename U>
//     segtree(vector<U> &v) : segtree(v.size()){build(v);}
//     T combine(T a, T b){ return max(a,b); }// Change according to QUERY operation

//     template <typename U>
//     void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1){
//         if (segr == -1)segr = n - 1;
//         if (segl == segr){
//             tree[id] = v[segl];  // Change according to MODIFY operation
//             return;
//         }
//         int mid = (segl + segr) / 2;
//         build(v, id + 1, segl, mid);
//         build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
//         tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
//     }
//     /* void propagate(int id, int segl, int segr){
//         if(lazy[id] == lazy_zero)return;
//         if(segl != segr){
//             int mid = (segl + segr) / 2;
//             array<int, 2> children= {id + 1, id + 2 * (mid - segl + 1)};
//             for(auto child : children){
//                 tree[child] = lazy[id];  // Change according to MODIFY operation
//                 lazy[child] = lazy[id];  // Change according to MODIFY operation
//             }
//         }
//         lazy[id] = lazy_zero;
//     } */

//     template <typename U>
//     void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1){
//         if (segr == -1)segr = n - 1;
//         if (index_l > index_r || index_l > segr || segl > index_r){return;}
//         // propagate(id, segl, segr);
//         if (segl >= index_l && segr <= index_r){
//             tree[id] = val; // Change according to MODIFY operation
//             // lazy[id] = val; // Change according to MODIFY operation
//             return;
//         }
//         int mid = (segl + segr) / 2;
//         modify(val, index_l, index_r, id + 1, segl, mid);
//         modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
//         tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
//     }

//     T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1){
//         if (segr == -1)segr = n - 1;
//         if (index_l > index_r || index_l > segr || segl > index_r){return zero;}
//         // propagate(id, segl, segr);
//         if (segl >= index_l && segr <= index_r){return tree[id];}
//         int mid = (segl + segr) / 2;
//         T leftVal = query(index_l, index_r, id + 1, segl, mid);
//         T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
//         return combine(leftVal, rightVal);
//     }
// };

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, rt, pos;
	Tree tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1),
		  rt(N), pos(N), tree(N){ dfsSz(1); dfsHld(1); }
	void dfsSz(int v) {
		for (int& u : adj[v]) {
			adj[u].erase(find(all(adj[u]), v));
			par[u] = v;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (;; v = par[rt[v]]) {
			if (pos[u] > pos[v]) swap(u, v);
			if (rt[u] == rt[v]) break;
			op(pos[rt[v]], pos[v]);
		}
		op(pos[u] + VALS_EDGES, pos[v]);
	}
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) {assert(l == r); tree.update(l, val);});
	}
	int queryPath(int u, int v) { // Modify depending on problem
		int res = -1e9;
		process(u, v, [&](int l, int r) {
				res = max(res, tree.query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v] - 1);
	}
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n, q;
    cin >> n >> q;
    vector<int> init(n);
    arrPut(init);
    vector<vector<int>> edges(n + 1);
    for(int i=0;i<n - 1;i++){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    HLD<0> hld(edges);
    for(int i=0;i<n;i++){
        hld.modifyPath(i + 1, i + 1, init[i]);
    }
    while(q--){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            hld.modifyPath(a, a, b);
        }
        else{
            cout<< hld.queryPath(a, b) << " ";
        }
    }    
}