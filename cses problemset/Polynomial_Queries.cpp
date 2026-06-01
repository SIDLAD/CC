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

struct segtree {
    int n;
    vector<int> st;
    segtree(int n):n(n) {
        st.assign(2 * n, 0);
    }

    void add(int x, int i) {
        assert(0 <= i and i < n);
        for(st[i += n] += x; i >>= 1;) {
            st[i] = st[i << 1] + st[(i << 1) + 1];
        }
    }

    int sum(int l, int r) { // r is inclusive
        r += 1; // now it is exclusive
        int sum = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) sum += st[l++];
            if(r&1) sum += st[--r];
        }
        return sum;
    }
};

int n, q;
int t[200001]{};
int qt, a, b;

void update(int i, int addV, segtree& nonj, segtree& onej, segtree& twoj)
{
    nonj.add(addV, i);
    onej.add(addV * i, i);
    twoj.add(addV * i * i, i);
}

int sum(int a, int b, segtree& nonj, segtree& onej, segtree& twoj) {
    --a;
    int sum1 = nonj.sum(1, b) * (b*b + 3 * b + 2)
        - onej.sum(1, b) * (2 * b + 3) + twoj.sum(1, b);
    int sum2 = nonj.sum(1, a) * (a*a + 3 * a + 2)
        - onej.sum(1, a) * (2 * a + 3) + twoj.sum(1, a);
    
    return sum1 - sum2 >> 1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin >> n >> q;
    for(int i=1;i<=n;++i) {
        cin >> t[i];
        t[i] += t[i-1];
    }

    segtree nonj(n + 5), onej(n + 5), twoj(n + 5);
    while(q--) {
        cin >> qt >> a >> b;
        if(qt == 1) {
            int dist = b - a + 1;
            update(a, 1, nonj, onej, twoj);
            update(b + 1, - dist - 1, nonj, onej, twoj);
            update(b + 2, dist, nonj, onej, twoj);
        }
        else {
            cout << sum(a, b, nonj, onej, twoj) + t[b] - t[a-1] << endl;
        }
    }
}