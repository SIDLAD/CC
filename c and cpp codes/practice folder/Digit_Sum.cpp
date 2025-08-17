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
#define cout(x) cout << ((x) ? "Yes" : "No") << endl
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

string getP(int x) {
    string s = "";
    while(x--) s += '0';
    return s;
}

string a,b;

typedef array<int,3> cache_k;
typedef pair<int,int> cache_v;
typedef map<cache_k,cache_v> cache_t;

cache_t cache;
int n = 16;

cache_v solve(string& a, string& b, int curI=0, bool over=0, bool under=0) {
    assert(sz(a) == n && sz(b) == n);
    cache_k x = {curI, over, under};
    if(cache.count(x)) return cache[x];
    if(curI == n) return cache[x] = {0,1};
    int startD = 0; if(!over) startD = a[curI] - '0';
    int endD = 9; if(!under) endD = b[curI] - '0';
    int ans1 = 0;
    int ans2 = 0;
    for(int i=startD; i<=endD; ++i ){
        bool nover = over | a[curI] - '0' != i;
        bool nunder = under |  b[curI]  - '0'!= i;
        auto uret = solve(a,b, curI + 1, nover, nunder);
        ans1 += uret.first + i * uret.second;
        ans2 += uret.second;
    }
    return cache[x] = {ans1,ans2};
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        cache.clear();
        cin >> a >> b;
        a = getP(16 - sz(a)) + a;
        b = getP(16 - sz(b)) + b;
        assert(sz(a) == sz(b));
        cout << solve(a,b).first << endl;
    }
}