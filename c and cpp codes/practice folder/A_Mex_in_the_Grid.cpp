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

pii z = {-1,-1};

bool isValid(pii coord, vector<vi>& v) {
    if(min(coord.first, coord.second) < 0 || max(coord.first, coord.second) >= sz(v)) return false;
    if(v[coord.first][coord.second] != -1) return false;
    return true;
}

pii sum(pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}

pii nxt(pii cur, pii prev, vector<vi>& v, int n) {
    pii ans = z;
    pii curd = {cur.first - prev.first, cur.second - prev.second};
    pii nextd = curd.first == 1 ? make_pair(0, -1) :
                curd.first == -1 ? make_pair(0, 1) :
                curd.second == 1 ? make_pair(1, 0) : 
                                    make_pair(-1, 0);
    
    if(isValid(sum(cur, nextd), v)) return sum(cur, nextd);
    if(isValid(sum(cur, curd), v)) return sum(cur, curd);
    return ans;
}

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
        vector<vi> v(n, vi(n, -1));
        int x = n/2, y = n/2;
        int cur =0;
        pii prev = {x - 1, y};
        pii tmp = {x,y};
        while(1)  {
            v[tmp.first][tmp.second] = cur++;
            auto tmp2 = nxt(tmp, prev, v, n);
            if(tmp2 == z) break;
            prev = tmp;
            tmp = tmp2;

        };
        for(auto vv : v) {arrprint(vv);}
    }
}