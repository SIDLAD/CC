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

vector<pair<int, int>> moves1 = {
    {0, 1},
    {0, -1},
};
vector<pair<int, int>> moves2 = {
    {1, 0},
    {-1, 0},
};

int n, m;
bool isValid(int i, int j) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void solve() {
    cin >> n >> m;
    vector<string> a(n);
    range(i,0,n) {
        cin >> a[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q1, q2;

    range(i,0,n) {
        if(a[i][0] == '.' && !visited[i][0]) {
            q1.push({i, 0});
            visited[i][0] = true;
        }
        if(a[i][m - 1] == '.' && !visited[i][m - 1]) {
            q1.push({i, m - 1});
            visited[i][m - 1] = true;
        }
    }
    int ans = 0;
    vector<vector<bool>> finalAns(n, vector<bool>(m, false));
    while(!q1.empty()) {
        auto start = q1.front();
        q1.pop();
        finalAns[start.first][start.second] = true;
        for(auto &val : moves1) {
            int newI = val.first + start.first, newJ = val.second + start.second;
            if(!isValid(newI, newJ) || visited[newI][newJ] || a[newI][newJ] == 'o') continue;
            visited[newI][newJ] = true;
            q1.push({newI, newJ});
        }
    }
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    range(i,0,m) {
        if(a[0][i] == '.' && !visited[0][i]) {
            q2.push({0, i});
            visited[0][i] = true;
        }
        if(a[n - 1][i] == '.' && !visited[n - 1][i]) {
            q2.push({n - 1, i});
            visited[n - 1][i] = true;
        }
    }
    while(!q2.empty()) {
        auto start = q2.front();
        q2.pop();
        finalAns[start.first][start.second] = true;
        for(auto &val : moves2) {
            int newI = val.first + start.first, newJ = val.second + start.second;
            if(!isValid(newI, newJ) || visited[newI][newJ] || a[newI][newJ] == 'o') continue;
            visited[newI][newJ] = true;
            q2.push({newI, newJ});
        }
    }
    range(i,0,n) {
        range(j,0,m) {
            ans += (finalAns[i][j]);
        }
    }
    cout  << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}