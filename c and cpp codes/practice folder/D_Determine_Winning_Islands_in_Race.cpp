#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int)1e9 + 7; // 998'244'353;
using namespace std;
// insert policy here

// insert mintcode here

#if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
void _exe() {}
template <typename T, typename... V>
const T &_exe(const T &t, const V &...v) { return t; }
template <typename T, typename... V>
T &_exe(T &t, V &...v) { return t; }

#define debug(x...) (_exe(x))

class CNothing
{
};

template <typename T>
const CNothing &operator<<(const CNothing &proxy, const T &)
{
    return proxy;
}

const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &))
{
    return proxy;
}
CNothing cnothing;
#define cerr cnothing
#else
#include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define endl "\n" // comment out for interactive problems
#define cout(x) x ? cout << "Yes" << endl : cout << "No" << endl

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
    ;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n + 1), redges(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            redges[v].push_back(u);
        }
        cout << 1;
        vector<int> dp(n + 1, 0);
        int curmx = -1;
        for (int i = 2; i < n; i++)
        {
            for (auto edge : edges[i - 1])
            {
                dp[edge] = max(dp[edge],dp[i-1] + (edge - (i-1) - 1));
                curmx = max(curmx,dp[edge]);
                debug(i-1,edge,dp[edge]);
            }
            dp[i] = max(dp[i-1],dp[i]);
            if(curmx >= i)cout<<0;
            else cout<<1;
        }
        debug(dp);
        cout<<endl;
    }
}