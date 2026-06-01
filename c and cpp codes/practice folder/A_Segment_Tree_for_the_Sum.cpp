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
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

template<typename T=int>
T input() {
    T x;
    cin >> x;
    return x;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct fenwick0 {
    int n;
    vi f;
    fenwick0(const vi& v): n(sz(v)), f(v) {
        for(int i=0;i<n;++i) if(int nxt = i | i + 1; nxt < n) f[nxt] += f[i];
    }
    void add(int x, int i) {
        for(; i < n; i |= i + 1) f[i] += x;
    }
    int sum(int i) {
        if (i < 0) return 0;
        int s = 0;
        for(++i; i--; i &= i + 1) s += f[i];
        return s;
    }
    int sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
    int get(int i) {
        return sum(i) - sum(i - 1);
    }
    void set(int x, int i) {
        auto o = get(i);
        auto d = x - o;
        add(d, i);
    }
};

struct fenwick1 {
    int n;
    vi f;
    fenwick1(const vi& v): n(sz(v)), f(n + 1) {
        for(int i=1;i<=n;++i) f[i] = v[i-1];
        // for(int i=0;i<n;++i) if((i | i + 1) < n) f[i | i + 1] += f[i];
        for(int i=1;i<=n;++i) if(int nxt = i + (i & -i); nxt <= n) f[nxt] += f[i];
    }
    void add(int x, int i) {
        for(++i; i <= n; i += i & -i) f[i] += x;
    }
    int sum(int i) {
        if (i < 0) return 0;
        int s = 0;
        for(++i; i; i -= i & -i) s += f[i];
        return s;
    }
    int sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
    int get(int i) {
        return sum(i) - sum(i - 1);
    }
    void set(int x, int i) {
        auto o = get(i);
        auto d = x - o;
        add(d, i);
    }

};

int i, vv, l, r, t;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int n = input(), m = input();
    vi v(n);
    arrput(v);
    fenwick0 f(v);
    while(m--) {
        cin >> t;
        if(t - 1){
            cin >> l >> r;
            cout << f.sum(l, r) << endl;
        } else {
            cin >> i >> vv;
            f.set(vv, i);
        }
    }
}