#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int)1e9 + 7; // 998'244'353;
using namespace std;
// insert policy here

// insert mintcode here

// insert randnum here

#if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
void _exe() {}
template <typename T, typename... V>
const T &_exe(const T &t, const V &...v) { return t; }
template <typename T, typename... V>
T &_exe(T &t, V &...v) { return t; }
#define debug(x...) (_exe(x))

class CNothing
{
} cnothing;
template <typename T>
const CNothing &operator<<(const CNothing &proxy, const T &) { return proxy; }
const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &)) { return proxy; }
#define cerr cnothing
#else
#include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define endl '\n' // comment out for interactive problems
#define cout(x) (x ? cout << "YES" << endl : cout << "NO" << endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var)         \
    for (auto &inVar : var) \
    {                       \
        cin >> inVar;       \
    }
#define arrPrint(var)          \
    for (auto outVar : var)    \
    {                          \
        cout << outVar << ' '; \
    }                          \
    cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
    ;

int a[5001], b[5001];

set<pair<int, int>> a2b;
set<pair<int, int>> b2a;
set<pair<int, int>> a20;
set<pair<int, int>> b20;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n, s, t;
    cin >> n >> s >> t;

    if (s + t > n)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    int curAns = 0;

    for (int i = 1; i <= n; i++)
    {
        vector<int> v = {
            a[i] + (a20.size() == s ? a2b.rbegin()->first + (b20.size() == t ? b20.rbegin()->first : 0) : 0),
            a[i] + (a20.size() == s ? a20.rbegin()->first : 0),
            b[i] + (b20.size() == t ? b2a.rbegin()->first + (a20.size() == s ? a20.rbegin()->first : 0) : 0),
            b[i] + (b20.size() == t ? b20.rbegin()->first : 0),
            0};
        int mxInd = max_element(all(v)) - v.begin();
        curAns += v[mxInd];

        int remIndA, remIndB;

        switch (mxInd)
        {
        case 1:
            if (a20.size() == s)
            {
                remIndA = a20.rbegin()->second;
                a20.erase({-a[remIndA], remIndA});
                a2b.erase({b[remIndA] - a[remIndA], remIndA});
            }
            a20.emplace(-a[i], i);
            a2b.emplace(b[i] - a[i], i);
            break;

        case 0:
            if (a20.size() == s)
            {
                if (b20.size() == t)
                {
                    remIndB = b20.rbegin()->second;
                    b20.erase({-b[remIndB], remIndB});
                    b2a.erase({a[remIndB] - b[remIndB], remIndB});
                }
                remIndA = a2b.rbegin()->second;
                a20.erase({-a[remIndA], remIndA});
                a2b.erase({b[remIndA] - a[remIndA], remIndA});
                b20.emplace(-b[remIndA], remIndA);
                b2a.emplace(a[remIndA] - b[remIndA], remIndA);
            }
            a20.emplace(-a[i], i);
            a2b.emplace(b[i] - a[i], i);
            break;

        case 3:
            if (b20.size() == t)
            {
                remIndB = b20.rbegin()->second;
                b20.erase({-b[remIndB], remIndB});
                b2a.erase({a[remIndB] - b[remIndB], remIndB});
            }
            b20.emplace(-b[i], i);
            b2a.emplace(a[i] - b[i], i);
            break;

        case 2:
            if (b20.size() == t)
            {
                if (a20.size() == s)
                {
                    remIndA = a20.rbegin()->second;
                    a20.erase({-a[remIndA], remIndA});
                    a2b.erase({b[remIndA] - a[remIndA], remIndA});
                }
                remIndB = b2a.rbegin()->second;
                b20.erase({-b[remIndB], remIndB});
                b2a.erase({a[remIndB] - b[remIndB], remIndB});
                a20.emplace(-a[remIndB], remIndB);
                a2b.emplace(b[remIndB] - a[remIndB], remIndB);
            }
            b20.emplace(-b[i], i);
            b2a.emplace(a[i] - b[i], i);
            break;
        }
    }

    cout << curAns << endl;
    vector<string> ans(n + 1, "Rejected\n");
    for (auto [_, i] : a20)
        ans[i] = "CPG\n";
    for (auto [_, i] : b20)
        ans[i] = "MLG\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i];
}