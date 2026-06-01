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

int n, q;
string state[1001];

struct F2{
    int n;
    vector<vector<int>> f;
    F2(int n) : n(n), f(n, vector<int>(n)) {
        for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            if(state[i][j] == '*') f[i][j] += 1;

        for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            if(int nj = j | j + 1; nj < n) f[i][nj] += f[i][j];
        
        for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            if(int ni = i | i + 1; ni < n) f[ni][j] += f[i][j];
    }

    int sum(int ei, int ej) {
        if(min(ei, ej) < 0) return 0;
        assert(max(ei, ej) < n);
        int s = 0;
        for(int i=ei + 1; i--; i &= i + 1) for(int j = ej + 1; j--; j &= j + 1)
            s += f[i][j];
        return s;
    }
    void add(int si, int sj, int x) {
        for(int i = si; i < n; i |= i + 1) for(int j = sj; j < n; j |= j + 1)
            f[i][j] += x;
    }

    int sum(int si, int sj, int ei, int ej) {
        return sum(ei, ej) - sum(ei, sj - 1) - sum(si - 1, ej) + sum(si - 1, sj - 1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t, x1, y1, x2, y2;
    cin >> n >> q;
    for(int i=0;i<n;++i) cin >> state[i];
    F2 f(n);
    while(q--) {
        cin >> t;
        if(t - 1) {
            cin >> y1 >> x1 >> y2 >> x2;
            y1 --, x1--, y2--, x2--;
            cout << f.sum(y1, x1, y2, x2) << endl;
        } else {
            cin >> y1 >> x1;
            y1 -- , x1 --;
            if(state[y1][x1] == '.') {
                state[y1][x1] = '*';
                f.add(y1, x1, 1);
            } else {
                assert(state[y1][x1] == '*');
                state[y1][x1] = '.';
                f.add(y1, x1, -1);
            }
        }
    }
}