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
#define cout(x) (x ? cout << "Alice can win." << endl : cout << "Bob will win." << endl)
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

int p, k;
vector<int> pile;
int n;

int getGrundy()
{
    vector<int> grundyVals(n + 1);
    grundyVals[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        set<int> st;
        for (int j = 0; j <= k and i - j > 0; j++)
        {
            int remove = pile[i - j - 1];
            if (i - j - remove >= 0)
                st.insert(grundyVals[i - j - remove]);
        }
        for (int j = 0; j <= st.size(); j++)
        {
            if (st.count(j))
                continue;
            grundyVals[i] = j;
            break;
        }
    }
    return grundyVals[n];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> p >> k;
    int grundy = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> n;
        pile.resize(n);
        for (auto &card : pile)
            cin >> card;
        grundy ^= getGrundy();
    }
    cout(grundy != 0);
}