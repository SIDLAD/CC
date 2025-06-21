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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    range(i,0,n) {
        cin >> a[i];
    }
    vector<vector<int>> ans(n, vector<int>(m));
    range(i,0,m) {
        if(a[0][i] == 'B') ans[0][i] = 1;
    }
    int finalAns = 0;
    range(i,1,n) {
        range(j,0,m) {
            if(a[i][j] == '.') {
                if(j > 0) ans[i][j] = max(ans[i][j], ans[i - 1][j - 1]);
                if(j < m - 1) ans[i][j] = max(ans[i][j], ans[i - 1][j + 1]);
                ans[i][j] = max(ans[i][j], ans[i - 1][j]);
            }
            else if(a[i][j] == 'W') {
                int temp = 0;
                if(j > 0) temp = max(temp, ans[i - 1][j - 1]);
                if(j < m - 1) temp = max(temp, ans[i - 1][j + 1]);
                temp = max(temp, ans[i - 1][j]);
                finalAns = max(finalAns, temp);
            }
            else {
                if(j > 0) ans[i][j] = max(ans[i][j], ans[i - 1][j - 1] + 1);
                if(j < m - 1) ans[i][j] = max(ans[i][j], ans[i - 1][j + 1] + 1);
                ans[i][j] = max(ans[i][j], ans[i - 1][j] + 1);
                // if(j > 0) ans[i][j] += ans[i - 1][j - 1];
                // if(j < m - 1) ans[i][j] += ans[i - 1][j + 1];
                // ans[i][j] += ans[i - 1][j] + 1;
            }
        }
    }
    debug(ans);
    cout  << finalAns << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}