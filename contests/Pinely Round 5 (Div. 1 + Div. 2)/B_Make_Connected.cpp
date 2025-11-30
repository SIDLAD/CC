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

bool ch4(vector<pii>& v) {
    int mini = INF, maxi = -INF, minj = INF, maxj = -INF;
    for(auto [i,j] : v) {
        mini = min(i, mini);
        maxi = max(i, maxi);
        minj = min(j, minj);
        maxj = max(j, maxj);
    }
    if(maxi - mini == 1 and maxj - minj == 1) return true;
    return false;
}

bool chd1(vector<pii>& v) {
    set<int> st;
    for(auto [i,j]: v) st.insert(i + j);
    if(st.size() < 2) return true;
    if(st.size() == 2) {
        vi vv(all(st));
        if(vv[1] - vv[0] == 1) return true;
    }
    return false;
}

bool chd2(vector<pii>& v) {
    set<int> st;
    for(auto [i,j]: v) st.insert(i - j);
    if(st.size() < 2) return true;
    if(st.size() == 2) {
        vi vv(all(st));
        if(vv[1] - vv[0] == 1) return true;
    }
    return false;
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
        vector<pii> v;
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) {
            char x;
            cin >> x;
            if(x == '#') v.emplace_back(i,j);
        }
        char ch = false;
        if(sz(v) == 4) {
            ch = ch4(v);
        }
        if(!ch) ch = chd1(v);
        if(!ch) ch = chd2(v);
        cout(ch);
    }
}