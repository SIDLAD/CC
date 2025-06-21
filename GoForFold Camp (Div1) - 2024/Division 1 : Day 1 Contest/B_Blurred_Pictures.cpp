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
int n;

bool possible(int mid, vector<pair<int, int>> &a) {
    bool check = false;
    for(int i = 0;i<n;i++) {
        if(i + mid < n && a[i].second >= a[i].first + mid) {
            if(a[i + mid].first <= a[i].first && a[i + mid].second >= a[i].first + mid) {check = true;break;}
            if(a[i + mid].second >= a[i].second && a[i + mid].first <= a[i].second - mid) {check = true; break;}
        }
        if(i - mid >= 0 && a[i].first <= a[i].second - mid) {
            if(a[i - mid].first <= a[i].first && a[i - mid].second >= a[i].first + mid) {check = true; break;}
            if(a[i - mid].second >= a[i].second && a[i - mid].first <= a[i].second - mid) {check = true; break;}
        }
    }
    return check;
}

void solve() {
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0;i<n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    int lo = 0, hi = 1e7;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        if(possible(mid, a)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << ans + 1 << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}