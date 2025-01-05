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
    tree<pair<int, int>, null_type, left<pair<int, int>>, \
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

int get_bit(string s){
    int cur = 0;
    for(auto ch: s){
        cur |= 1 << (ch - 'a');
    }
    return cur;
}


void solve()
{
    
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> dp(1 << 21, -1);
    queue<int> q;
    forn(i,k){
        string m;
        cin >> m;
        int cur = get_bit(m);
        dp[cur] = i;
        q.push(cur);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        forn(i,20){
            if(cur & (1 << i)){
                int next = cur ^ (1 << i);
                if(dp[next] == -1){
                    dp[next] = dp[cur];
                    q.push(next);
                }
            }
        }
    }

    int till = 0;
    int times = 0;
    int i = 0;
    vector<int> ans;
    while(i < n){
        till |= 1<<(s[i]-'a');
        times += 1;
        while (i < n - 1 and dp[till | (1 << (s[i+1] - 'a'))] != -1){
            i += 1;
            times += 1;
            till |= 1 << (s[i]-'a');
        }
        forn(j,times){
            ans.push_back(dp[till]);
        }
        till = 0;
        times = 0;
        i += 1;
    }
    forn(j, times)
    {
        ans.push_back(dp[till]);
    }

    for(auto ele : ans){
        cout << ele  + 1 << " ";
    }
    cout << endl;

    
}

int32_t main()
{
    // fast_cin();
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}