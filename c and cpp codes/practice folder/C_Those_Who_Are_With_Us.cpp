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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m));
        int mx = -1;
        for(auto& e: v) for(auto& e2:e) cin >> e2, mx = max(mx , e2);
        vector<pair<int,int>> p;
        rep(i,0,n) rep(j,0,m) if(v[i][j] == mx) p.emplace_back(i,j);
        
        if(p.size() < 3) {
            cout << mx - 1 << endl;
            continue;
        }

        bool ch1 = true, ch2 = true;
        int r0 = p.front().first, c0 = p.front().second;
        int r1 = -1, c1 = -1;

        for(auto [r,c] : p) {
            if(r != r0) if(c1 == -1) c1 = c;
            else if(c1 != c) ch1 = false;
        }
        for(auto [r,c]:p) {
            if(c!=c0) if(r1 == -1) r1 = r;
            else if(r1 != r) ch2 = false;
        }
        if(ch1 || ch2) cout << mx - 1 << endl;
        else cout << mx << endl;
    }
}