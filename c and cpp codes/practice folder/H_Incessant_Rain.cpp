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

/**
 * Author: Siddharth
 * Date: 2024-12-22
 * Description: Make the commented changes to remove persistence.
 * O(q) should be around 2e5 for persistent, seems like 1e6 gives memory problems
 */

struct Freq{
    int tot = 0;
    int mx = 0;
    int lsum = 0;
    int rsum = 0;
};

struct SegNode{
    Freq freq = Freq();
    int lazy = 0;
    int left = -1;
    int right = -1;
};
 
struct DynamicLazy {
	vector<SegNode> tree;
	
    int minl, maxr;
	int timer = 0;
 
	Freq comb(Freq a, Freq b) {
        Freq c;
        c.tot = a.tot + b.tot;
        c.mx = max({a.mx, b.mx, a.rsum + b.lsum});
        c.lsum = max(a.lsum, a.tot + b.lsum);
        c.rsum = max(b.rsum, b.tot + a.rsum);
        return c;
    }
 
	void apply(int cur, int len, int val) {
        tree[cur].lazy = val;
        auto tot = len * val;
        tree[cur].freq.tot = tot;
        tree[cur].freq.mx = tree[cur].freq.lsum = tree[cur].freq.rsum = max(0, tot);
	}
    
    // .., int q = 0) .. if(q > 0) {tree.reserve(2 * q * __lg(r - l + 1));}..
	DynamicLazy(int l, int r) : minl(l), maxr(r) {
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
        if(tree[cur].lazy == 0) {return;}
		int m = l + (r - l >> 1);
		apply(tree[cur].left, m - l + 1, tree[cur].lazy);
		apply(tree[cur].right, r - m, tree[cur].lazy);
		tree[cur].lazy = 0;
	}
    
    //void modify .. , int cur = 0, ..
	void modify(int val, int index_l, int index_r, int cur = 0, int l = 1, int r = -1) {
        if(l == 1 and r == -1) l = minl, r = maxr;
		if (index_r < l || index_l > r) { return ; } // { return; }
                     
		if (index_l <= l && r <= index_r) {
			apply(cur, r - l + 1, val); // replace newcur with cur
		} else {
			push_down(cur, l, r);
			int m = l + (r - l >> 1);
			modify(val, index_l, index_r, tree[cur].left, l, m);        // remove lhs
			modify(val, index_l, index_r, tree[cur].right, m + 1, r);  //remove lhs
			tree[cur].freq = // replace newcur with cur
			    comb(tree[tree[cur].left].freq, tree[tree[cur].right].freq);  // replace newcur with cur
		}
	}
    
    // .. int cur = 0, ..
	Freq query(int index_l, int index_r, int cur = 0, int l = 1, int r = -1) {
        if(l == 1 and r == -1) l = minl,r = maxr;
		if (index_r < l || index_l > r) { return Freq(); }
		if (index_l <= l && r <= index_r) { return tree[cur].freq; }
		push_down(cur, l, r);
		int m = l + (r - l >> 1);
		return comb(query(index_l, index_r, tree[cur].left, l, m),
		            query(index_l, index_r, tree[cur].right, m + 1, r));
	}
};

DynamicLazy createSeg(int n) {
    auto ret = DynamicLazy(0, n-1);
    ret.modify(-1, 0, n - 1);
    return ret;
}

void modifySeg(int x, DynamicLazy& t, int add=1) {
    t.modify(add, x, x);
}
int querySeg(DynamicLazy& t) { return t.query(t.minl, t.maxr).mx / 2;}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    auto getMax = [&](multiset<int>& st) {return *st.rbegin();};

    int T;
    cin>>T;
    for(;T--;)
    {
        int n,q;
        cin >> n >> q;
        vector<int> v(n);
        arrput(v);
        
        vector<int> qi(q), qval(q);
        auto workv = v;

        vector<vector<array<int,3>>> updates(n + 1);
        for(int i=0;i<n;++i) {
            updates[v[i]].push_back({i, 1, 0});
        }

        set<int> nums(all(v));

        for(int _=0; _<q; ++_) {
            int i, x;
            cin >> i >> x; --i;
            updates[workv[i]].push_back({i, -1, _});
            workv[i] = x;
            updates[workv[i]].push_back({i, 1, _});
            nums.insert(x);
        }

        
        vector<vector<pair<int,int>>> qChanges(q);
        for(auto e: nums) {
            DynamicLazy t = createSeg(n);
            for(auto [vi, add, qi] : updates[e]) {
                auto prev = querySeg(t);
                modifySeg(vi, t, add);
                auto nw = querySeg(t);
                qChanges[qi].emplace_back(prev, nw);
            }
        }
        
        multiset<int> st;
        for(int i=0;i<q;++i) {
            for(auto [prev, nw] : qChanges[i]) {
                if(st.count(prev))
                st.erase(st.find(prev));
                st.insert(nw);
            }

            cout << getMax(st) << " ";
        } cout << endl;
    }
}