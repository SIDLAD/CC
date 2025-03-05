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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define sz(x) (int)x.size()
#define vi vector<int>

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

struct TwoSat
{
    int N;
    vector<vi> gr;
    vi values; // 0 = fa lse , 1 = true
    TwoSat(int n = 0) : N(n), gr(2 * n) {}
    int addVar()
    { // ( optional )
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }
    void either(int f, int j)
    {
        debug("either", f ,j);
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }
    void setValue(int x) { debug("setValue", x); either(x, x); }
    void atMostOne(const vi &li)
    { // ( optional )
        if (sz(li) <= 1)
            return;
        int cur = ~li[0];
        rep(i, 2, sz(li))
        {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }
    vi val, comp, z;
    int time = 0;
    int dfs(int i)
    {
        int low = val[i] = ++time, x;
        z.push_back(i);
        for (int e : gr[i])
            if (!comp[e])
                low = min(low, val[e] ?: dfs(e));
        if (low == val[i])
            do
            {
                x = z.back();
                z.pop_back();
                comp[x] = low;
                if (values[x >> 1] == -1)
                    values[x >> 1] = x & 1;
            } while (x != i);
        return val[i] = low;
    }
    bool solve()
    {
        values.assign(N, -1);
        val.assign(2 * N, 0);
        comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
    ;

int n;
vector<array<int, 4>> investigations;
set<char> mafia;

int solve(char i, char j, char k)
{
    mafia.clear();
    mafia.insert(i);
    mafia.insert(j);
    mafia.insert(k);
    TwoSat ts(128);
    for (auto [a, b, p, r] : investigations)
    {
        if(r == 0) {
            vector<int> v = {a,b};
            for(auto c : v) {
                if(mafia.count(c))continue;
                ts.setValue(p?~c:c);
            }
        }
        else if(r == 1) {
            if(mafia.count(a) and mafia.count(b))return 0;
            if(mafia.count(a))ts.setValue(p?b:~b);
            else if(mafia.count(b))ts.setValue(p?a:~a);
            else {
                ts.either(a,b);
                ts.either(~a, ~b);
            }
        }
        else {
            vector<int> v = {a,b};
            for(auto c : v) {
                if(mafia.count(c))return 0;
                ts.setValue(p?c : ~c);
            }
        }
    }
    return (ts.solve());
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int p, r;
        cin >> s >> p >> r;
        p--;
        char a = s[0], b = s[1];
        investigations.push_back({a, b, p, r});
    }
    int ans = 0;
    for (char i = 'A'; i <= 'Z'; i++)
        for (char j = i + 1; j <= 'Z'; j++)
            for (char k = j + 1; k <= 'Z'; k++)
            {
                ans += (solve(i, j, k));
            }

    cout << ans << endl;
}