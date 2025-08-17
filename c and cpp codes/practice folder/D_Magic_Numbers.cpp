#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

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
int m, d;
string a,b;

// typedef tuple<int,int,bool, bool> cache_k;
// typedef int cache_v;
// typedef map<cache_k, cache_v> cache_t;

int cache[2001][2000][2][2];
int solve(int curI = 0, int curRem = 0, bool over=0, bool under=0) {
    if(cache[curI][curRem][over][under] != -1) return cache[curI][curRem][over][under];
    if(curI == sz(a)) return cache[curI][curRem][over][under] = curRem == 0;
    int l = a[curI] - '0', r = b[curI] - '0';
    int startD = 0; if(!over) startD = l;
    int endD = 9; if(!under) endD = r;

    int ans = 0;
    for(int i=startD; i<= endD; ++i) {
        if(curI&1 && i != d) continue;
        if(~curI&1 && i == d) continue;
        bool nover = over | i != l;
        bool nunder = under | i != r;
        int newRem = curRem * 10 + i;
        newRem %= m;
        ans += solve(curI + 1, newRem, nover, nunder);
        ans %= M;
    }
    return cache[curI][curRem][over][under] = ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    memset(cache, -1, sizeof(cache));
    cin >> m >> d >> a >> b;
    cout << solve() << endl;
}