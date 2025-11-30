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
// #define sz(x) (int)(x).size()
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

void printPre(int TT) {
    cout << "Case #" << TT << ": ";
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
        int n,m;
        cin >> n >> m;
        vi a(n), b(m);
        arrput(a) arrput(b);

        printPre(TT);

        sort(all(a)); reverse(all(a));
        sort(all(b));
        int curB = 0;
        int i;
        debug(a,b);
        for(i=0;i<n;++i) {
            int add;
            if(i && a[i] == a[i-1]) add = 1;
            else add = i + 1;
            debug(add);
            int curSum = 0;
            while(curSum < add && curB < m) {
                curSum += b[curB++];
            }
            debug(curB);
            if(curSum < add) break;
        }
        debug(i);
        while(i && a[i-1] == a[i]) --i;
        cout << i << endl;
    }
}