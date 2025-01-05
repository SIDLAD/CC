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


struct SegNode{
    long long freq = 0;
    int lazy = 0;
    int left = -1;
    int right = -1;
};
 
struct PersistentDynamicSegTree {
	vector<SegNode> tree;
	const int minl, maxr;
	int timer = 0;
    int lastroot = 0; // -
 
	long long comb(long long a, long long b) { return a + b; }
 
	void apply(int cur, int len, int val) {
        tree[cur].lazy += val;
        tree[cur].freq += (long long) len * val;
	}
    
    // .., int q = 0) .. if(q > 0) {tree.reserve(2 * q * __lg(r - l + 1));}..
	PersistentDynamicSegTree(int l, int r) : minl(l), maxr(r) {tree.push_back(SegNode());}

	void push_down(int cur, int l, int r) {
		if (tree[cur].left == -1) {
			tree[cur].left = ++timer;
			tree.push_back(SegNode());
		}
        else if (tree[cur].lazy != 0){              // -
            int newleft = ++timer;                  // -
            tree.push_back(tree[tree[cur].left]);   // -
            tree[cur].left = newleft;               // -
        }
		if (tree[cur].right == -1) {
			tree[cur].right = ++timer;
			tree.push_back(SegNode());
		}
        else if (tree[cur].lazy != 0){              // -
            int newright = ++timer;                 // -
            tree.push_back(tree[tree[cur].right]);  // -
            tree[cur].right = newright;             // -
        }
        if(tree[cur].lazy == 0) {return;}
		int m = l + (r - l >> 1);
		apply(tree[cur].left, m - l + 1, tree[cur].lazy);
		apply(tree[cur].right, r - m, tree[cur].lazy);
		tree[cur].lazy = 0;
	}
    
    //void modify .. , int cur = 0, ..
	int modify(int val, int index_l, int index_r, int cur = -1, int l = 1, int r = -1) {
        if(cur == -1) cur = lastroot;   // -
        if(l == 1 and r == -1) l = minl, r = maxr;
		if (index_r < l || index_l > r) { return cur; } // { return; }
 
        int newcur = cur;   // -                     
		if (index_l <= l && r <= index_r) {
            newcur = ++timer;           // -
            tree.push_back(tree[cur]);  // -
			apply(newcur, r - l + 1, val); // replace newcur with cur
		} else {
			push_down(cur, l, r);
			int m = l + (r - l >> 1);
            newcur = ++timer;           // -
            tree.push_back(tree[cur]);  // -
			tree[newcur].left = modify(val, index_l, index_r, tree[cur].left, l, m);        // remove lhs
			tree[newcur].right = modify(val, index_l, index_r, tree[cur].right, m + 1, r);  //remove lhs
			tree[newcur].freq = // replace newcur with cur
			    comb(tree[tree[newcur].left].freq, tree[tree[newcur].right].freq);  // replace newcur with cur
		}
        return lastroot = newcur;       // -
	}
    
    // .. int cur = 0, ..
	// long long query(int index_l, int index_r, int cur = -1, int l = 1, int r = -1) {
    //     if(cur == -1) cur = lastroot; // -
    //     if(l == 1 and r == -1) l = minl,r = maxr;
	// 	if (index_r < l || index_l > r) { return 0; }
	// 	if (index_l <= l && r <= index_r) { return tree[cur].freq; }
	// 	push_down(cur, l, r);
	// 	int m = l + (r - l >> 1);
	// 	return comb(query(index_l, index_r, tree[cur].left, l, m),
	// 	            query(index_l, index_r, tree[cur].right, m + 1, r));
	// }

    long long query(int k, int leftversioncur, int rightversioncur, int l = 1, int r = -1)
    {
        if(l == 1 and r == -1) l = minl, r = maxr;
        if(l == r) return l;
        push_down(leftversioncur, l, r);
        push_down(rightversioncur, l, r);
        // assert(tree[rightversioncur].freq - tree[leftversioncur].freq >= k);
        int leftsum = tree[tree[rightversioncur].left].freq - tree[tree[leftversioncur].left].freq;
        int m = l + (r - l >> 1);
        if(leftsum >= k)
        {
            return query(k,tree[leftversioncur].left, tree[rightversioncur].left, l ,m);
        }
        else return query(k - leftsum ,tree[leftversioncur].right, tree[rightversioncur].right, m + 1 ,r);
    }
    
    // remove function
    int load_root(int cur){
        lastroot = ++timer;
        tree.push_back(tree[cur]);
        return lastroot;
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
    vector<int> v(n);
    arrPut(v);
    auto vc = v;
    vector<pair<int,int>> vv(n);
    for(int i=0;i<n;i++)vv[i].first = v[i],vv[i].second = i;
    // map<int,int> mp;
    map<int,int>rmp;
    sort(all(vc));
    sort(all(vv));
    debug(vv);
    for(int i=0;i<n;i++)
    {
        rmp[i] = vc[i];
        vv[i].first = i;
    }
    debug(vv);
    sort(all(vv),[](auto a, auto b){return a.second < b.second;});
    for(int i=0;i<n;i++)v[i] = vv[i].first;
    debug(v);
    int mn = *min_element(all(v));
    int mx = *max_element(all(v));
    assert(mn == 0 and mx == n - 1);
    PersistentDynamicSegTree st(0,n-1);
    vector<int> versions(n + 1);
    versions[0] = st.lastroot;
    
    for (int i = 1; i <= n; i++) {
        versions[i] = st.modify(1, v[i - 1], v[i - 1]);
        assert(v[i-1] >= st.minl and v[i-1] <= st.maxr);
    }
    while(m--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        assert(1 <= i and i <= j and j <= n and 1<= k and k <=j - i + 1);
        assert(st.tree.size() > max(versions[i-1],versions[j]));
        assert(st.tree[versions[j]].freq - st.tree[versions[i-1]].freq == j - i + 1);
        cout<<rmp[st.query(k,versions[i - 1],versions[j])]<<endl;
    }
}