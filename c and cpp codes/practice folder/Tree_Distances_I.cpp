#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX / 2;
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
#define cout(x) x ? cout << "Yes" << endl : cout << "No" << endl
#define endl "\n" // comment out for interactive problems

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(0));

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> firstans(n);
    vector<int> firstchild(n);
    // memset(firstchild, -1, sizeof(firstchild));
    vector<int> secondans(n);

    function<void(int, int)> dfs1 = [&](int x, int p) -> void
    {
        for (int v : edges[x])
            if (v != p)
            {
                dfs1(v, x);
                if (firstans[x] < firstans[v] + 1)
                {
                    secondans[x] = firstans[x];
                    firstans[x] = firstans[v] + 1;
                    firstchild[x] = v;
                }
                else if (secondans[x] < firstans[v] + 1)
                    secondans[x] = firstans[v] + 1;
            }
    };

    dfs1(0, -1);
    // debug(firstans, secondans, firstchild);

    function<void(int, int)> dfs2 = [&](int x, int p) -> void
    {

        if (x == firstchild[p])
        {
            if (secondans[p] + 1 > firstans[x])
            {
                secondans[x] = firstans[x];
                firstans[x] = secondans[p] + 1;
                firstchild[x] = -1;
            }
            else
                secondans[x] = max(secondans[x], secondans[p] + 1);
        }
        else if(p >=0)
        {
            if (firstans[p] + 1 > firstans[x])
            {
                secondans[x] = firstans[x];
                firstans[x] = firstans[p] + 1;
                firstchild[x] = -1;
            }
            else
                secondans[x] = max(secondans[x], firstans[p] + 1);
        }

        for (int v : edges[x])
            if (v != p)
            {
                dfs2(v, x);
            }
    };
    dfs2(0, -1);

    // debug(firstans, secondans, firstchild);
    for (int i = 0; i < n; i++)
    {
        cout << firstans[i] << " ";
    }
}