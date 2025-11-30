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

// #define int long long
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = (int)2e5 + 1;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    vector<vi> divsi(MAXN);
    for(int i=1;i<MAXN;++i) for(int j=i;j<MAXN;j += i) divsi[j].push_back(i);

    int T = 1;
    cin >> T;

    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        vector<int> cntr(n + 1);
        int ans = 0;
        vi consider;
        vector<bool> inC(n + 1);
        for(int i=0;i<n;++i) {
            int x;
            cin >> x;
            vi nxt;
            auto& divs = divsi[x];
            for(auto div: divs) {
                ++cntr[div];
                if(cntr[div] != i + 1) ans = max(ans, cntr[div]);
                else nxt.push_back(div), inC[div] = 1;
            }

            for(auto e: consider)
            if(cntr[e] != i + 1) ans = max(ans, cntr[e]), inC[e] = 0;
            else if(!inC[e]) inC[e] = 1, nxt.push_back(e);
            cout << ans << " ";
            consider = nxt;
        }
        cout << endl;
    }
}