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
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<array<int,3>> aa(n);
        for(int i=0;i<n;++i) aa[i] = {a[i] == '1' ? 1 : -1, a[i] == '1', a[i] == '0'};
        for(int i=1;i<n;++i) aa[i][0] += aa[i-1][0], aa[i][1] += aa[i-1][1], aa[i][2] += aa[i-1][2];

        sort(all(aa));
        for(int i=1;i<n;++i) aa[i][1] += aa[i-1][1], aa[i][2] += aa[i-1][2];


        int ans = 0;

        int curb1 = 0, curb0 = 0;
        for(int i=0;i<n;++i) {
            if(b[i] == '1') curb1++;
            else curb0++;

            int delta = curb0 -  curb1;
            auto idx = lower_bound(all(aa), array<int,3>{delta , -INF, -INF}) - aa.begin();
            if(idx == n) {
                // all ones should be chosen
                ans += aa.back()[1] + n * curb1;
            }
            else {
                if(idx == 0) ans += aa.back()[2] + n * curb0;
                else ans += (aa.back()[2] - aa[idx - 1][2]) + (n - idx) * curb0 + aa[idx - 1][1] + idx * curb1; 
            }

        }
        cout << ans << endl;
    }
}