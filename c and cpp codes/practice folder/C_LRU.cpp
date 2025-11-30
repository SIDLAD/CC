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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int _n,_k;
    cin >> _n >> _k;
    vector<double> _vals(_n);
    arrput(_vals);
    vector<double> vals;
    for(int i=0;i<_n;++i) if(!(_vals[i] < EPS)) vals.push_back(_vals[i]);
    int n = vals.size();
    int k = min(_k, n);

    vector<double> prob(1<<n);
    prob[0] = 1;
    for(int kk=0;kk<k;++kk) {
        for(int bm = 0; bm < (1 << n); ++bm) {
            if(__builtin_popcountll(bm) != kk) continue;
            double tot = 0;
            for(int b=0;b < n;++b) if(~bm >> b & 1) tot += vals[b];
            for(int b=0;b < n; ++b) if(~bm >> b & 1) prob[bm^1<<b] += prob[bm] * vals[b] / tot;
        }
    }

    vector<double> ans(n);
    for(int bm=0;bm < (1 << n); ++ bm) if(__builtin_popcountll(bm) == k) {
        for(int b=0; b < n; ++b) if(bm >> b & 1) ans[b] += prob[bm];
    }

    for(int i=0,j=0;i<_n;++i) {
        if(_vals[i] < EPS) cout << 0 << " ";
        else cout << ans[j++] << " ";
    } cout << endl;
}