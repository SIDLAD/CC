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
    int T;
    cin >> T;
    for (; T--;)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int minright = INF;
        int maxleft = -INF;
        for (int i = 0; i < n; i++)
        {
            minright = min(minright, v[i] - 1 + i);
            maxleft = max(maxleft, i - v[i] + 1);
        }
        debug(minright, maxleft);
        if (minright < maxleft)
            cout << 0 << endl;
        else
        {
            int cur = minright;
            int ans = minright - maxleft + 1;
            // only have to check if this satisfies or not.
            stack<pair<int, int>> s1, s2;
            for (int i = 0; i < cur; i++)
            {
                if (s1.empty() or v[i] - 1 + i < s1.top().first + s1.top().second)
                    s1.push({i, v[i] - 1});
            }
            for (int i = n - 1; i > cur; i--)
            {
                if (s2.empty() or i - v[i] + 1 > s2.top().first - s2.top().second)
                    s2.push({i, v[i] - 1});
            }
            int l = cur,r = cur;
            for(int i=0;i<n;i++)
            {
                if(s1.size() and s1.top().first == l)s1.pop();
                if(s2.size() and s2.top().first == r)s2.pop();
                int leftspace = s1.empty()?INF:s1.top().first + s1.top().second - i - l;
                int rightspace = s2.empty()?INF:r - (s2.top().first - s2.top().second + i);
                debug(i,leftspace,rightspace);
                if(s1.size())debug(s1.top());if(s2.size())debug(s2.top());
                if(leftspace < 0 or rightspace < 0)
                {
                    ans = 0;break;
                }
                else if (leftspace < rightspace) l--;
                else r++;
            }
            cout<<ans<<endl;
        }
    }
}