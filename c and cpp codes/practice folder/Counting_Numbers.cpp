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

int dp[20][11][2][2][2];
string a,b;

int solve(int curI=0, int prevD=10, bool over=0, bool under=0, bool started=0) {
    int& curstate = dp[curI][prevD][over][under][started];
    if(curstate != -1) return curstate;
    if(curI == sz(a)) return curstate = 1;
    curstate = 0;
    int startD = 0; if(!over) startD = a[curI] - '0';
    int endD = 9; if(!under) endD = b[curI] -'0';
    for(int i=startD;i<=endD;++i) {
        if(started && i == prevD) continue;
        bool nover = over | i != a[curI] - '0';
        bool nunder = under | i != b[curI] - '0';
        bool nstarted = started | i!= 0;
        curstate += solve(curI + 1, i, nover, nunder, nstarted);
    }
    debug(curI, prevD, over, under, startD, endD, started, curstate);
    return curstate;
}
string getP(int x) {
    string s;
    while(x--) s += '0';
    return s;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    a = getP(19 - sz(a)) + a, b = getP(19 - sz(b)) + b;
    cout << solve() << endl;
}