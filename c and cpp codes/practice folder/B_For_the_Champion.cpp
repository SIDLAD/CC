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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int k = 1e9;
int xx;
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
        int mxs = -INF, mxd = -INF;
        rep(i,0,n) {
            int x,y;
            cin >> x >> y;
            mxs = max(mxs, x + y), mxd = max(mxd, y - x);
        }
        cout << "? U " << k << endl; cin >> xx;
        cout << "? U " << k << endl; cin >> xx;
        cout << "? R " << k << endl; cin >> xx;
        cout << "? R " << k << endl; cin >> xx;
        //X + Y = xx + mxs - 4k
        int sum = xx + mxs - 4*k;

        cout << "? L " << k << endl; cin >> xx;
        cout << "? L " << k << endl; cin >> xx;
        cout << "? L " << k << endl; cin >> xx;
        cout << "? L " << k << endl; cin >> xx;

        //Y - X  = xx + mxd - 4K
        int diff = xx + mxd - 4*k;

        int Y = sum + diff >> 1;
        int X = sum - diff >> 1;
        cout << "! " << X << " " << Y << endl;
    }
}