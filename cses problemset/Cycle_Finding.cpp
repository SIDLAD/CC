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
#define endl "\n" // comment out for interactive problems
#define cout(x) x ? cout << "Yes" << endl : cout << "No" << endl

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }
    vector<int> father(n + 1, INF);
    int inloopind = 0;
    vector<int> marked(n + 1);

    for (int k = 1; k <= n; k++)
        if (!marked[k])
        {
            marked[k] = 1;
            queue<int> q1, q2;
            vector<int> distances(n + 1, INF);
            father.assign(n + 1, INF);
            vector<bool> inq(n + 1);
            distances[k] = 0;
            q1.push(k);
            inq[k] = 1;
            for (int i = 1; i <= n; i++)
            {
                auto &qcur = i & 1 ? q1 : q2;
                auto &qnext = ~i & 1 ? q1 : q2;
                if(qcur.empty())break;
                while (qcur.size())
                {
                    int cur = qcur.front();
                    qcur.pop();
                    inq[cur] = 0;
                    for (auto [nbr, wt] : edges[cur])
                    {

                        marked[nbr] = true;
                        if ((distances[nbr]) > (distances[cur] + wt))
                        {

                            distances[nbr] = distances[cur] + wt;
                            father[nbr] = cur;
                            if (!inq[nbr])
                                inq[nbr] = true, qnext.push(nbr);
                        }
                    }
                    if (i == n and qnext.size())
                    {
                        inloopind = qnext.front();
                        goto outer;
                    }
                }
            }
        }
outer:
    if (inloopind)
    {
        cout << "YES" << endl;
        int cur = inloopind;
        vector<int> appeared(n + 1);
        vector<int> ans;
        while (!appeared[cur])
        {
            appeared[cur] = true;
            ans.push_back(cur);
            cur = father[cur];
        }
        ans.push_back(cur);
        reverse(all(ans));
        int start = 2;
        for (auto ele : ans)
        {
            if (start)
            {
                cout << ele << " ";
            }
            if (ele == cur)
                start--;
        }
    }
    else
        cout << "NO" << endl;
}
