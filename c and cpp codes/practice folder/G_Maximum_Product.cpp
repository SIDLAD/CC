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

string a,b;

pair<double,int> cache[20][2][2][2];

int getTenPow(int x) {
    int a = 1;
    while(x--) a *= 10;
    return a;
}

pair<double,int> solve(int curI=0, int over=0, int under=0, int started=0) {
    auto& curstate = cache[curI][over][under][started];
    if(curstate.second != -1) return curstate;
    if(curI == sz(a)) return curstate = {0.0, 0};

    int startD = 0; if(!over) startD = a[curI] - '0';
    int endD = 9; if(!under) endD = b[curI] - '0';
    for(int i=startD;i<=endD;++i) {
        bool nunder = under | i != b[curI] - '0';
        bool nover = over | i != a[curI] - '0';
        bool nstarted = started | i!=0;
        auto sret = solve(curI + 1, nover, nunder, nstarted);
        int curNum = sret.second + i * getTenPow(sz(a) - curI - 1);
        double logSum = i == 0 && started ? -1 : i == 0 ? sret.first : sret.first + log2(i);
        curstate = max(curstate, {logSum, curNum});
    }
    return curstate;
}

string getP(int x){string s; while(x--) s += '0'; return s;}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> a >> b;
    a = getP(19 - sz(a)) + a; b = getP(19 - sz(b)) + b;
    debug(a,b);
    rep(i,0,20) rep(j,0,2) rep(k,0,2) rep(l,0,2) cache[i][j][k][l] = {-3.0, -1};
    cout << solve().second << endl;
}