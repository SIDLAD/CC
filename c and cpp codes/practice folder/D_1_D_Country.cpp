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
// #define endl '\n' //comment out for interactive problems
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
/*
struct SegNode{
    int freq = 0;
    int lazy = 0;
    int left = -1;
    int right = -1;
};

struct DynamicSegTree {
	vector<SegNode> tree;
	const int minl, maxr;
	int timer = 0;

	int comb(int a, int b) { return a + b; }

	void apply(int cur, int len, int val) {
        tree[cur].lazy += val;
        tree[cur].freq += len * val;
	}

	DynamicSegTree(int l, int r, int q = 0) : minl(l), maxr(r) {
		if (q > 0) { tree.reserve(2 * q * __lg(r - l + 1)); }
		tree.push_back(SegNode());
	}

	void push_down(int cur, int l, int r) {
		if (tree[cur].left == -1) {
			tree[cur].left = ++timer;
			tree.push_back(SegNode());
		}
		if (tree[cur].right == -1) {
			tree[cur].right = ++timer;
			tree.push_back(SegNode());
		}
        if (tree[cur].lazy == 0) { return; }
		int m = (l + r) / 2;
		apply(tree[cur].left, m - l + 1, tree[cur].lazy);
		apply(tree[cur].right, r - m, tree[cur].lazy);
		tree[cur].lazy = 0;
	}

	void modify(int val, int index_l, int index_r, int cur = 0, int l = 1, int r = -1) {
        if(l == 1 and r == -1) l = minl, r = maxr;
		if (index_r < l || index_l > r) { return; }
		if (index_l <= l && r <= index_r) {
			apply(cur, r - l + 1, val);
		} else {
			push_down(cur, l, r);
			int m = l + (r - l >> 1);
			modify(val, index_l, index_r, tree[cur].left, l, m);
			modify(val, index_l, index_r, tree[cur].right, m + 1, r);
			tree[cur].freq =
			    comb(tree[tree[cur].left].freq, tree[tree[cur].right].freq);
		}
	}

	int query(int index_l, int index_r, int cur = 0, int l = 1, int r = -1) {
        if(l == 1 and r == -1) l = minl,r = maxr;
		if (index_r < l || index_l > r) { return 0; }
		if (index_l <= l && r <= index_r) { return tree[cur].freq; }
		push_down(cur, l, r);
		int m = l + (r - l >> 1);
		return comb(query(index_l, index_r, tree[cur].left, l, m),
		            query(index_l, index_r, tree[cur].right, m + 1, r));
	}
};*/

struct SegNode{
    long long freq = 0;
    int lazy = 0;
    int left = -1;
    int right = -1;
};
 
struct DynamicSegTree {
	vector<SegNode> tree;
	const int minl, maxr;
	int timer = 0;
    // int lastroot = 0; // -
 
	long long comb(long long a, long long b) { return a + b; }
 
	void apply(int cur, int len, int val) {
        tree[cur].lazy += val;
        tree[cur].freq += (long long) len * val;
	}
    
    // .., int q = 0) .. if(q > 0) {tree.reserve(2 * q * __lg(r - l + 1));}..
	DynamicSegTree(int l, int r, int q = 0) : minl(l), maxr(r) {if(q > 0) {tree.reserve(2 * q * __lg(r - l + 1));}tree.push_back(SegNode());}

	void push_down(int cur, int l, int r) {
		if (tree[cur].left == -1) {
			tree[cur].left = ++timer;
			tree.push_back(SegNode());
		}
        // else if (tree[cur].lazy != 0){              // -
        //     int newleft = ++timer;                  // -
        //     tree.push_back(tree[tree[cur].left]);   // -
        //     tree[cur].left = newleft;               // -
        // }
		if (tree[cur].right == -1) {
			tree[cur].right = ++timer;
			tree.push_back(SegNode());
		}
        // else if (tree[cur].lazy != 0){              // -
        //     int newright = ++timer;                 // -
        //     tree.push_back(tree[tree[cur].right]);  // -
        //     tree[cur].right = newright;             // -
        // }
        if(tree[cur].lazy == 0) {return;}
		int m = l + (r - l >> 1);
		apply(tree[cur].left, m - l + 1, tree[cur].lazy);
		apply(tree[cur].right, r - m, tree[cur].lazy);
		tree[cur].lazy = 0;
	}
    
    //void modify .. , int cur = 0, ..
	void modify(int val, int index_l, int index_r, int cur = 0, int l = 1, int r = -1) {
        // if(cur == -1) cur = lastroot;   // -
        if(l == 1 and r == -1) l = minl, r = maxr;
		if (index_r < l || index_l > r) { return; } // { return; }
 
        // int newcur = cur;   // -                     
		if (index_l <= l && r <= index_r) {
            // newcur = ++timer;           // -
            // tree.push_back(tree[cur]);  // -
			apply(cur, r - l + 1, val); // replace newcur with cur
		} else {
			push_down(cur, l, r);
			int m = l + (r - l >> 1);
            // newcur = ++timer;           // -
            // tree.push_back(tree[cur]);  // -
			modify(val, index_l, index_r, tree[cur].left, l, m);        // remove lhs
			modify(val, index_l, index_r, tree[cur].right, m + 1, r);  //remove lhs
			tree[cur].freq =
			    comb(tree[tree[cur].left].freq, tree[tree[cur].right].freq);
		}
        // return lastroot = newcur;       // -
	}
 
	long long query(int index_l, int index_r, int cur = 0, int l = 1, int r = -1) {
        // if(cur == -1) cur = lastroot; // -
        if(l == 1 and r == -1) l = minl,r = maxr;
		if (index_r < l || index_l > r) { return 0; }
		if (index_l <= l && r <= index_r) { return tree[cur].freq; }
		push_down(cur, l, r);
		int m = l + (r - l >> 1);
		return comb(query(index_l, index_r, tree[cur].left, l, m),
		            query(index_l, index_r, tree[cur].right, m + 1, r));
	}
    
    // remove function
    // int load_root(int cur){
    //     lastroot = ++timer;
    //     tree.push_back(tree[cur]);
    //     return lastroot;
    // }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin>>v[i].first;
    for(int i=0;i<n;i++)cin>>v[i].second;

    int q;
    cin>>q;
    DynamicSegTree st(-(int)1e9 - 10, (int)1e9 + 10);
    for(auto node: st.tree)debug(node.freq,node.lazy,node.left,node.right);

    for(int i=0;i<n;i++){st.modify(v[i].second,v[i].first,v[i].first);}
    debug(st.minl,st.maxr);
    // debug(st.query(0,10));
    debug();
    for(auto node: st.tree)debug(node.freq,node.lazy,node.left,node.right);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        debug(l,r);
        cout<<st.query(l,r)<<endl;
    }
}