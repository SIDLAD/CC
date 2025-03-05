#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = 998'244'353;
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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

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
	T query(int b, int e) {// query [b, e]
        if(b < 0)b = 0;
        e++; 
        if(e > n)e = n;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct TreeAdd {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	TreeAdd(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {// query [b, e]
        if(b < 0)b = 0;
        e++; 
        if(e > n)e = n;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int fact[(int)2e5 + 50];

void calcFact() {
    fact[0] = fact[1] = 1;
    rep(i,2,2e5 + 40) {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

int cntInrange(int l, int r, TreeAdd& t) {
    if(r < l)return 0;
    return t.query(l,r);
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n),c(n);
    Tree st(n); 
    TreeAdd t(n);
    arrPut(p) arrPut(c)

    for(int i=0;i<n;i++)st.update(i,p[i]);

    map<int,vector<int>> mp;
    for(int i=0;i<n;i++)mp[c[i]].push_back(i);
    int ans = 1;
    vector<pair<int,int>> ranges(n);
    for(auto [color, indices] : mp) {
        sort(all(indices),[&](auto a, auto b){return p[a] < p[b];});
        for(auto i : indices)st.update(i,0), t.update(i,1);

        for(int j=0;j<indices.size();j++) {
            int i = indices[j];
            //find left index using binsearch
            int rr = i; // satisfies
            int l = -1; //doesnt
            int val = p[i];
            while(rr - l > 1) {
                int mid = l + rr >> 1;
                if(st.query(mid, i) < val)rr = mid;
                else l = mid;
            }

            //find right index using binsearch
            int ll = i; //satisfies
            int r = n; // doesnt
            while(r - ll > 1) {
                int mid = ll + r >> 1;
                if(st.query(i, mid) < val) ll = mid;
                else r = mid;
            }
            ans = (ans * cntInrange(rr, ll, t))%M;
            t.update(i,0);
        }
        for(auto i: indices)st.update(i,p[i]);
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    calcFact();
    cin>>T;
    for(;T--;)
    {
        solve();
    }
}