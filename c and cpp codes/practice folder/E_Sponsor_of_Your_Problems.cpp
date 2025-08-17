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

typedef array<int,3> cache_k;
typedef map<cache_k, int> cache_t;

vector<int> getV(int num) {
    vector<int> ans;
    while(num) ans.push_back(num%10), num/=10;
    reverse(all(ans));
    return ans;
}

cache_t cache;

int solve(vector<int>& l, vector<int>& r, int curI = -1, bool over=0, bool under=0) {
    assert(l.size() == r.size());
    auto n = sz(l);
    assert(n < 10);
    assert(curI <= n);
    cache_k x = {curI, over, under};
    if(cache.contains(x)) return cache[x];
    ++curI;
    if(curI == n) {return cache[x] = 0;}

    assert(curI != -1);
    int startD = 0; if(!over && curI < n) startD = l[curI];
    int endD = 9;  if(!under && curI < n) endD = r[curI];
    if(curI < n && !over && !under) assert(l[curI] <= r[curI]);
    int ans = INF;
    for(int i=startD; i<=endD;++i) {
        bool nover = over | i != startD;
        bool nunder = under | i != endD;
        int add = 0;
        if(curI != n) add = (int)(l[curI] == i) + (int)(r[curI] == i);
        ans = min(ans, add + solve(l, r, curI, nover, nunder));
    }
    return cache[x] = ans;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
        int l,r;
        cin >> l >> r;
        auto ll = getV(l), rr = getV(r);
        cout << solve(ll, rr) << endl;
    }
}