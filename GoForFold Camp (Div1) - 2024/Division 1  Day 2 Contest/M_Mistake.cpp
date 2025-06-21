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

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<set<pair<int, int>>> avail(k);
    vector<int> indegs(n);
    vector<vector<int>> graph(n);
    range(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        indegs[b]++;
        graph[a].push_back(b);
    }
    map<int, set<int>> inds;
    vector<int> aVec(n*k);
    for(int i = 0;i<n*k;i++) {
        cin >> aVec[i];
        aVec[i]--;
        inds[aVec[i]].insert(i);
    }
    vector<int> ans(n*k);
    range(i,0,k) {
        vector<int> indegcpy = indegs;
        set<pair<int, int>> avail;
        for(int j = 0;j<n;j++) {
            if(indegcpy[j] == 0) {
                avail.insert({*inds[j].begin(), j});
                inds[j].erase(inds[j].begin());
            }
        }
        while(!avail.empty()) {
            auto start = *avail.begin();
            avail.erase(avail.begin());
            ans[start.first] = i;
            for(auto &val : graph[start.second]) {
                indegcpy[val]--;
                if(indegcpy[val] == 0) {
                    avail.insert({*inds[val].begin(), val});
                    inds[val].erase(inds[val].begin());
                }
            }
        }
    }
    for(auto &val : ans) {
        cout << val + 1 << " ";
    }
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}