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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
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
        int n;
        cin >> n;
        vi v(n); arrput(v);
        vi f(n + 1);
        for(auto e: v) ++f[e];
        int mex = n;
        for(int i=0;i<n;++i) if(f[i]); else {mex = i; break;}
        auto fc = f;
        partial_sum(fc.rbegin(), fc.rend(), fc.rbegin());

        vi acc(n + 1);
        acc[0] = max(0ll, f[0] - 1);
        for(int i=1;i<=n;++i) acc[i] = acc[i-1] + max(0ll, f[i] - 1);

        for(int i=1;i<=n;++i) fc[i] += acc[i-1];

        vector<pair<int,int>> pts;
        for(int i=0;i<=mex;++i) debug(i, f[i], fc[i] + 1), pts.emplace_back(f[i], -1), pts.emplace_back(fc[i] + 1, 1);
        sort(all(pts));
        int ptsptr = 0;
        int curs = 0;
        debug(pts);
        for(int k=0;k<=n;++k) {
            while(ptsptr < pts.size() && pts[ptsptr].first <=k) curs -= pts[ptsptr++].second;
            cout << curs << " ";
        } cout << endl;
    }
}