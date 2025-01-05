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

inline int getchar(int num, int k)
{
    num %= k;
    return 'a' + num;
}

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
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> v(n, vector<char>(n));

        int charnum = 0;
        for (int i = 0; i <= (n - 1) / 2; i++)
        {
            for (int j = 0; j <= (n - 1) / 2; j++)
            {
                v[i][j] = v[n - i - 1][j] = v[i][n - j - 1] = v[n - i - 1][n - j - 1] = getchar(charnum, k);
                charnum++;
            }
        }

        if (charnum < k)
            cout << -1 << endl;
        else
        {
            range(i, 0, n)
            {
                range(j, 0, n) cout << v[i][j];
                cout << endl;
            }
        }
    }
}