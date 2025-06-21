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

double calcDist(pair<double, double> &a, pair<double, double> &b) {
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int n;

double dp[310][310][2];

double calc(int l, int r, bool clockwise, vector<pair<double, double>> &a, vector<vector<int>> &adj) { // l -> currently at, r-> max you can go
    if(l == r) return 0.0;
    if(dp[l][r][clockwise] != -1.0) return dp[l][r][clockwise];
    double ans = 0.0;
    if(clockwise) {
        if(r < l) {
            range(i,l + 1, n) {
                if(adj[l][i] == 0) continue;
                double dist = calcDist(a[l], a[i]);
                ans = max(ans, calc(i, (l == n - 1 ? 0 : l + 1), false, a, adj) + dist);
                ans = max(ans, calc(i, r, true, a, adj) + dist);
            }
            range(i,0,r + 1) {
                if(adj[l][i] == 0) continue;
                double dist = calcDist(a[l], a[i]);
                ans = max(ans, calc(i, (l == n - 1 ? 0 : l + 1), false, a, adj) + dist);
                ans = max(ans, calc(i, r, true, a, adj) + dist);
            }
        }
        else {
            range(i,l + 1, r + 1) {
                if(adj[l][i] == 0) continue;
                double dist = calcDist(a[l], a[i]);
                ans = max(ans, calc(i, (l == n - 1 ? 0 : l + 1), false, a, adj) + dist);
                ans = max(ans, calc(i, r, true, a, adj) + dist);
            }
        }
    }
    else {
        if(r < l) {
            for(int i = l - 1;i>=r;i--) {
                if(adj[l][i] == 0) continue;
                double dist = calcDist(a[l], a[i]);
                ans = max(ans, calc(i, (l == 0 ? n - 1 : l - 1), true, a, adj) + dist);
                ans = max(ans, calc(i, r, false, a, adj) + dist);
            }
        }
        else {
            for(int i = l - 1;i>=0;i--) {
                if(adj[l][i] == 0) continue;
                double dist = calcDist(a[l], a[i]);
                ans = max(ans, calc(i, (l == 0 ? n - 1 : l - 1), true, a, adj) + dist);
                ans = max(ans, calc(i, r, false, a, adj) + dist);
            }
            for(int i = n - 1;i>=r;i--) {
                if(adj[l][i] == 0) continue;
                double dist = calcDist(a[l], a[i]);
                ans = max(ans, calc(i, (l == 0 ? n - 1 : l - 1), true, a, adj) + dist);
                ans = max(ans, calc(i, r, false, a, adj) + dist);
            }
        }
    }
    return dp[l][r][clockwise] = ans;
}

void solve() {
    cin >> n;
    vector<pair<double, double>> a(n);
    range(i,0,n) {
        cin >> a[i].first >> a[i].second;
    }
    range(i,0,n) {
        range(j,0,n) {
            range(h,0,2) {
                dp[i][j][h] = -1.0;
            }
        }
    }
    vector<vector<int>> adj(n, vector<int>(n));
    int m;
    cin >> m;
    range(i,0,m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    double ans = calc(0, n - 1, true, a, adj);
    range(i,1,n) {
        ans = max(ans, calc(i, i - 1, true, a, adj));
    }
    cout << ans << "\n";
    // range(i,0,n) {
    //     ans = max(ans, calc(i, ))
    // }


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(20);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}