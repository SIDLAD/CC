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

bool find(int j, vector<vector<int>> &g, vector<int> &btoa, vector<int> &vis) {
    if(btoa[j] == -1) return 1;
    vis[j] = 1;
    int di = btoa[j];
    for (int e : g[di]) {
        if(!vis[e] && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return 1;
        }
    }
    return 0;
}

int dfsMatching(vector<vector<int>> &g, vector<int> &btoa) {
    vector<int> vis;
    range(i,0,g.size()) {
        vis.assign(btoa.size(), 0);
        for (int j : g[i]) {
            if(find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
        }
    }
    return btoa.size() - (int)count(all(btoa), -1);
}

int n, m;

int dp[410][160][160];

bool calc(int i, int j, int k, vector<vector<int>> &a) {
    if(i < 0 || k < 0) {
        return true;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];
    bool ans = true;
    if(i >= j) ans &= calc(i - 1, j, k, a);
    if(j > 0) {
        ans &= (a[i][k] == 1 && calc(i - 1, j - 1, k - 1, a));
    }
    return dp[i][j][k] = ans;
}
bool comp(vector<int> &a, vector<int> &b) {
    vector<int> temp1, temp2;
    range(i,0,m) {
        if(a[i] == '1') {
            temp1.push_back(i);
        }
        if(b[i] == '1') {
            temp2.push_back(i);
        }
    }
    return (temp1 > temp2);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> m >> n;
    vector<set<int>> graph(n);
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> g(n);
    vector<int> btoa(m ,-1);
    range(i,0,m) {
        range(j,0,n) {
            cin >> a[j][i];
            if(a[j][i] == 0) g[j].push_back(i);
        }
    }
    debug(g);
    sort(all(a), comp);
    vector<vector<int>> b(n, vector<int>(m));
    bool ans = calc(n - 1, m, m - 1, a);
    int ansCt = dfsMatching(g, btoa);
    debug(btoa);
    debug(ansCt);
    if(ansCt != m) {
        cout << "1\n";
        return;
    }
    cout << "0\n";
    debug(btoa);
    // vector<int> seq;
    // int currI = n - 1, currJ = m, currK = m - 1;
    // while(seq.size() != m) {
    //     if(currI >= currJ && !calc(currI - 1, currJ, currK, a)) {
    //         currI--;
    //     }
    //     else {
    //         seq.push_back(currI + 1);
    //         currI--;
    //         currJ--;
    //         currK--;
    //     }
    // }
    // reverse(all(seq));
    // arrPrint(seq);
    // debug(seq);


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}