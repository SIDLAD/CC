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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    range(i,0,n) cin >> a[i];
    range(i,0,n) cin >> b[i];
    vector<vector<int>> ans;
    ans.push_back({1, n, 'I'});
    sort(a.begin(), a.end());
    range(i,0,n - 1) {
        int curr = b[i];
        int ind = -1;
        int mn = INT_MAX, mx = INT_MIN;
        range(j,i, n) {
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            if(a[j] == b[i]) {
                ind = j;
                break;
            }
        }
        if(a[ind] == mn) {
            ans.push_back({i + 1, ind + 1, 'I'});
            sort(a.begin() + i, a.begin() + ind + 1);
        }
        else {
            ans.push_back({i + 1, ind + 1, 'D'});
            sort(a.begin() + i, a.begin() + ind + 1);
            reverse(a.begin() + i, a.begin() + ind + 1);
        }
        debug(i);
        debug(ind);
        debug(a);
    }
    debug(a);
    cout << ans.size() << "\n";
    for(auto &val : ans) {
        cout << val[0] << " " << val[1] << " " <<  (char)(val[2]) << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}