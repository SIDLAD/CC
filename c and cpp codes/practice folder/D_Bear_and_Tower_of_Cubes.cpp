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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cube(int x){return x*x*x;}
map<int,pair<int,int>> mp;

int solve(int x) {
    assert(x >= 0);
    if(x == 0) {mp[x] = {-1, -1}; return 0;}
    if(x == 1) {mp[x] = {1, 0}; return 1 + solve(0);}
    int ll = 0, ul = 1e5 + 1;
    while(ul - ll > 1) {
        int mid = ll + ul >> 1;
        if(cube(mid) <= x) ll = mid;
        else ul = mid;
    }
    int ans1 = 1 + solve(x - cube(ll));
    int ans2 = 1 + solve(cube(ll) - cube(ll - 1) - 1);
    if(ans1 >= ans2) {
        mp[x] = {ll, x - cube(ll)};
        return ans1;
    }
    else {
        mp[x] = {ll - 1, cube(ll) - cube(ll - 1) - 1};
        return ans2;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int m;
    cin >> m;
    int answer = solve(m);
    cout << answer << " ";
    vector<int> ans;
    while(mp[m].first != -1) {
        ans.push_back(mp[m].first);
        m = mp[m].second;
    }
    debug(ans);
    int tot = 0;
    for(auto e: ans) tot += cube(e);
    cout << tot << endl;
}