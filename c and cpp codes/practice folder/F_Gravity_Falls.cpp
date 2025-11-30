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

bool compare(vi& a, vi& b, int ind) {
    if(a[0] == INF) return false;
    assert(ind < a.size() && ind < b.size());
    for(int i=ind;i<min(a.size(),b.size());++i) if(a[i] != b[i]) {
        return a[i] < b[i];
    }
    return a.size() < b.size();
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
        int mxl = -1;
        vector<vi> ss;
        for(int i=0;i<n;++i) {
            int k;
            cin >> k;
            mxl = max(mxl, k);
            vi s(k);
            arrput(s);
            ss.push_back(s);
        }
        sort(all(ss), [&](auto& a, auto& b){return a.size() > b.size();});
        vi ans;
        vi tmp = {INF};
        while(ans.size() < mxl) {
            vi* mn = &tmp;
            for(int i=0;i<n && ss[i].size() > ans.size(); ++i) {
                if(!compare(*mn, ss[i], ans.size())) mn = &ss[i];
            }
            debug(*mn);
            for(int i=ans.size(); i < mn->size(); ++i)
            ans.push_back((*mn)[i]);
        }
        arrprint(ans);
    }
}