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
    
    int n;
    cin >> n;
    vi a(n), b(n);
    arrput(a) arrput(b);
    vector<array<int, 31>> apre(n), bpre(n);
    for(int i=0;i<n;++i) {
        for(int bit=0;bit<31;++bit) {
            if(i)
            apre[i][bit] = apre[i-1][bit],
            bpre[i][bit] = bpre[i-1][bit];
            if(a[i] & (1 << bit)) apre[i][bit]++;
            if(b[i] & (1 << bit)) bpre[i][bit]++;
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = 0;
        for(int bit=0;bit<31;bit++) {
            int oca = apre[r1][bit];
            if(l1) oca -= apre[l1-1][bit];
            int zca = r1 - l1 + 1 - oca;

            int ocb = bpre[r2][bit];
            if(l2) ocb -= bpre[l2-1][bit];
            int zcb = r2 - l2 + 1 - ocb;

            ans += (1ll << bit) * (oca * zcb + ocb * zca);
        }
        cout << ans << endl;
    }
}