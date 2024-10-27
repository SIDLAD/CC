#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds                                              \
    tree<pair<int, int>, null_type, less<pair<int, int>>, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forsn(i, s, n) for (ll i = s; i < n; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define dbg(x) cerr << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define ln "\n"
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long

int bs_ind_less(vector<array<int, 3>> &a, int x)
{
    int l = 0;
    int r = a.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid][0] > x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> a;
    forn(i, n)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a.pb({z, x, y});
    }

    sort(all(a));
    reverse(all(a));
    int max_b = 1e4 + 5;

    vector<vector<pair<int,int>>> ind_to_bal(n);
    vector<int> answer(q);

    forn(i, q)
    {
        int m, b;
        cin >> m >> b;
        int ind = bs_ind_less(a, m);
        if(ind!=-1){
            ind_to_bal[ind].pb({b,i});
        }
        if (ind == -1)
        {
            answer[i] = 0;
        }
    }

    vector<int> dp0(max_b + 1, 0);
    vector<int> dp1(max_b + 1, 0);

    int mon_o = a[0][2];
    int coins_o = a[0][1];

    for (int i = 0; i < max_b; i++)
    {
        vector<int> &prev = dp0;
        if (i < mon_o)
        {
            prev[i] = 0;
        }else
        {
            prev[i] = coins_o;
        }
        for (auto [x,y] : ind_to_bal[0])
        {
            answer[y] = prev[x];
        }
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> &cur = (i & 1) ? dp1 : dp0;
        vector<int> &prev = (i & 1) ? dp0 : dp1;
        int mon = a[i][2];
        int coins = a[i][1];
        for (int j = 0; j < max_b; j++)
        {
            cur[j] = prev[j];
            if (j < mon)
            {
                continue;
            }
            cur[j] = max(cur[j], prev[j - mon] + coins);
        }

        for (auto [x,y] : ind_to_bal[i])
        {
            answer[y] = cur[x];
        }

    }

    forn(i,q)
    {
        cout << answer[i] << ln;
    }
}

int32_t main()
{
    fast_cin();
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}