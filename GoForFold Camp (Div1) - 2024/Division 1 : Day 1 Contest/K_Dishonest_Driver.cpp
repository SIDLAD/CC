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

int givelen(string s)
{
    int n  = s.length();
    vector<int> z(n);
    int l = 0,r = 0;
    int mn = n;
    for(int i=1;i<n;i++)
    {
        if(i + z[i] < r) z[i] = min(r -i, z[i-l]);
        while(i + z[i] < n and s[i + z[i]] == s[z[i]])z[i]++;
        if(z[i] + i > r)l = i,r = i + z[i];

        if(n%(i) == 0 )
        {
            if(i + z[i] == n)
            {
                mn = i;
                break;
            }
        }
    }
    return mn;

}

int dp[705][705];

int calc(int l, int r, string &s) {
    if(r - l == 1) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = INF;
    for(int i = l + 1;i<r;i++) {
        ans = min(ans, calc(l, i, s) + calc(i, r, s));
    }
    int ct = givelen(s.substr(l, r - l));
    if(ct < r - l) ans = min(ans, calc(l, l + ct, s));
    return dp[l][r] = ans;

}

void solve() {
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0;i<n + 1;i++) {
        for(int j = 0;j<n + 1;j++) dp[i][j] = -1;
    }
    cout << calc(0, n, s) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}