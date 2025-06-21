#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int x, y, n;
int calc(int mid, vector<pair<int, int>> &a) {
    vector<int> mx(x, -1), mn(x, n + 1);
    int ct = x - 1;
    for(int i = 0;i<n;i++) {
        mx[a[i].first] = max(mx[a[i].first], a[i].second);
        mn[a[i].first] = min(mn[a[i].first], a[i].second);
    }
    for(int i = 0;i<x;i++) {
        if(mid > mn[i]) ct += 2 * (mid - mn[i]);
        if(mid < mx[i]) ct += 2 * (mid - mx[i]);
    }
    return ct;

}

void solve() {
    cin  >> x >> y >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0;i<n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> mx(x, -1), mn(x, n + 1);
    for(int i = 0;i<n;i++) {
        mx[a[i].first] = max(mx[a[i].first], a[i].second);
        mn[a[i].first] = min(mn[a[i].first], a[i].second);
    }
    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());
    vector<int> pref(x), suff(x);
    pref[0] = mn[0];
    suff[x - 1] = mx[x - 1];
    for(int i = 1;i<x;i++) {
        pref[i] = pref[i - 1] + mn[i];
        suff[x - i - 1] = suff[x - i] + mx[x - i - 1];
    }
    int ans = INF;
    for(int i = 0;i<x;i++) {
        int ind1 = lower_bound(mn.begin(), mn.end(), i) - mn.begin();
        int ind2 = upper_bound(mx.begin(), mx.end(), i) - mx.begin();
        int curr = x - 1;
        if(ind1 > 0) curr += 2 * (ind1 * i - pref[ind1 - 1]);
        if(ind2 != x) curr += 2 * (suff[ind2] - (x - ind2) * i);
        ans = min(ans, curr);
    }
    cout << ans << "\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
    
}