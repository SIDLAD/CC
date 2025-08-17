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
#define cout(x) cout << ((x) ? "YES" : "NO") << endl
#define rep(it, start, end) for (auto it = start; it != end; ++it)
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
 
	long long comb(long long a, long long b) { return min(a,b); }
 
	void apply(int cur, int len, int val) {
        tree[cur].lazy += val;
        tree[cur].freq += len * val;
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
	int query(int val, int index_l, int index_r, int cur = -1, int l = 1, int r = -1) {
        if(cur == -1) cur = lastroot; // -
        if(l == 1 and r == -1) l = minl,r = maxr;
		if (index_r < l || index_l > r) { return maxr + 1; }
		if (val < tree[cur].freq) { return maxr + 1; }
        if(tree[cur].left == tree[cur].right) { return tree[cur].left; }
		push_down(cur, l, r);
		int m = l + (r - l >> 1);
		auto ll = query( val, index_l, index_r, tree[cur].left, l, m);
        if(ll != maxr + 1) return ll;
		return query( val, index_l, index_r, tree[cur].right, m + 1, r);
	}

    long long getVal(int index_l, int index_r, int cur = -1, int l = 1, int r = -1) {
        if(cur == -1) cur = lastroot; // -
        if(l == 1 and r == -1) l = minl,r = maxr;
		if (index_r < l || index_l > r) { return INF; }
		if (index_l <= l && r <= index_r) { return tree[cur].freq; }
		push_down(cur, l, r);
		int m = l + (r - l >> 1);
		return comb(getVal(index_l, index_r, tree[cur].left, l, m),
		            getVal(index_l, index_r, tree[cur].right, m + 1, r));
	}
    
    // remove function
    int load_root(int cur){
        lastroot = ++timer;
        tree.push_back(tree[cur]);
        return lastroot;
    }
};


struct SparseTable
{
    vector<int>& a;
    vector<vector<int>> table;
    int n;

    bool _compare(auto a, auto b) { return a < b; } // Change according to QUERY operation
    int identity = INF; // Change according to QUERY operation

    SparseTable(vector<int>& a) : a(a), n(a.size())
    {
        int lgN = (int)bit_width((unsigned int)n) - 1;
        table.resize(lgN + 1,vector<int>(n));
        rep(i,0,lgN + 1)rep(j,0,n - (1<<i) + 1)
        {
            if(i == 0)
                table[i][j] = j;
            else if(_compare (a[table[i-1][j]] , a[table[i-1][j + (1<<i-1)]]) )
                table[i][j] = table[i-1][j];
            else
                table[i][j] =  table[i-1][j + (1<<i-1)];
        }
    }

    int query_i(int l, int r)
    {
        assert(l <= r and l < n and r >= 0);
        l = max(l, (int)0), r = min(r, n - 1);

        int lgN = (int)bit_width((unsigned int)(r - l + 1)) - 1;
        if(_compare (a[table[lgN][l]] , a[table[lgN][r - (1<<lgN) + 1]]) )
            return table[lgN][l];
        else
            return table[lgN][r - (1<<lgN) + 1];
    }

    int query_val(int l, int r) { return (l > r || l >= n || r < 0) ? identity : a[query_i(l,r)]; }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        vi v(n);
        arrput(v);
        SparseTable st(v);
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;++i) a[i] = {v[i],i};
        sort(all(a));
        PersistentDynamicSegTree pst(0, n-1);
        for(int i=0;i<n;++i) pst.modify(-1, i, INF);

        vi timestamps(n);
        debug(a);
        for(auto [_,i]: a) {
            auto t = pst.modify(2, i, INF);
            timestamps[i] = t;
            debug(i, pst.getVal(i,i, timestamps[i]));
        }
        int ans = -INF;
        for(int i=0;i<n;++i) {
            auto bv = pst.getVal(i,i, timestamps[i]);
            debug(i, v[i], bv);
            int xInd;
            if(bv >= 0) xInd = 0;
            else xInd = pst.query(bv, 0, i - 1) + 1;
            debug(xInd);

            if(xInd >= n) continue;
            ans = max(ans, debug(v[i] - debug(st.query_val(xInd, i), i)));
        }
        debug();
        cout << ans << endl;
    }
}