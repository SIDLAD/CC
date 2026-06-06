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
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

template<typename T=int>
T input() {
    T x;
    cin >> x;
    return x;
}

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
        string s;
        cin >> s;
        for(auto& c: s) c-= '0';
        debug(s);
        vi a(n), c(n);
        arrput(a) arrput(c);
        debug(a);
        debug(c);
        vector<pii> preD(n); // second value if 0 represents known, 1 represents less or equal
        bool ch = true;
        for(int i=1;i<n;++i) if(c[i] < c[i-1]) ch = false;
        preD[0].first = c[0];
        if(ch and s[0] and a[0] != c[0]) ch = false;
        else
        for(int i=1;i<n;++i) {
            preD[i] = preD[i-1];
            if(s[i]) preD[i].first += a[i];
            else preD[i].first = INF, preD[i].second = 1;
            if(preD[i].second) preD[i].first = min(preD[i].first, c[i]);
            if(c[i] != c[i-1] and preD[i].second) {
                if(preD[i].first < c[i]) {
                    ch = false; break;
                }
                else preD[i].first = c[i], preD[i].second = 0;
            }
            if(not preD[i].second and preD[i].first > c[i]) {
                ch = false; break;
            }
            if(c[i] != c[i-1] and not preD[i].second and preD[i].first != c[i]) {
                ch = false; break;
            }
        }
        if(!ch) {cout(false); continue;}
        for(int i=n; i --> 1;) {
            if(preD[i - 1].second and s[i]) {
                preD[i - 1].first = preD[i].first - a[i];
                if(not preD[i].second) preD[i - 1].second = 0;
            }
        }
        cout(true);
        for(int i=0;i<n;++i) cout << preD[i].first - (i == 0 ? 0 : preD[i - 1].first) << " ";
        cout << endl;
    }
}