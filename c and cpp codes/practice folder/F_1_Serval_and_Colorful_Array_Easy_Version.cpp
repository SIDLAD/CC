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
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        arrPut(v);
        int hfl = k/2;
        int hfr = k - hfl;
        int subtract = hfl * (hfl - 1) / 2 + (hfr) * (hfr - 1) / 2;
        int ans = INF;
        for(int bp=1;bp < n;bp++) {
            vector<int> ld(k + 1, 5e5);
            vector<int> rd(k + 1, 5e5);
            for(int i=0;i<bp;i++)ld[v[i]] = bp - i - 1;
            for(int i=bp;i<n;i++)if(rd[v[i]] == 5e5)rd[v[i]] = i - bp;
            int sum = 0;
            for(int i=1;i<=k;i++)sum += ld[i];
            vector<int> diff(k);
            for(int i=0;i<k;i++)diff[i] = rd[i + 1] - ld[i + 1];
            sort(all(diff));
            for(int i=0;i<hfr;i++)sum += diff[i];
            ans = min(ans, sum - subtract);
        }
        cout << ans << endl;
    }
}