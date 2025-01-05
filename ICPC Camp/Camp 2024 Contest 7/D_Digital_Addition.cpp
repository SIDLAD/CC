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

//  ---   0
//  |  |  1,2
//  ---   3
//  |  |  4,5
//  ---   6
//

map<int, int> conv;

int compute(vector<vector<int>> arr, int cur)
{

    int need = 0;
    need |= arr[0][cur] << 0;
    need |= arr[1][cur + 1] << 1;
    need |= arr[1][cur] << 2;
    need |= arr[2][cur] << 3;
    need |= arr[3][cur + 1] << 4;
    need |= arr[3][cur] << 5;
    need |= arr[4][cur] << 6;
    need |= arr[5][cur + 1] << 7;
    need |= arr[5][cur] << 8;
    need |= arr[6][cur] << 9;
    need |= arr[7][cur + 1] << 10;
    need |= arr[7][cur] << 11;
    need |= arr[8][cur] << 12;


    return need;
}

void solve()
{

    // freopen("digital.in","r",stdin);
    // freopen("digital.out","w",stdout);
    int w;
    cin >> w;
    conv[0] = 0b01110111;
    conv[1] = 0b00100100;
    conv[2] = 0b01011101;
    conv[3] = 0b01101101;
    conv[4] = 0b00101110;
    conv[5] = 0b01101011;
    conv[6] = 0b01111011;
    conv[7] = 0b00100101;
    conv[8] = 0b01111111;
    conv[9] = 0b01101111;

    vector<vector<int>> arr;
    forn(i, 9)
    {
        int ex = (i) % 2;
        arr.pb(vector<int>(w + ex));

        forn(j, w + ex)
        {
            cin >> arr[i][j];
        }
        reverse(all(arr[i]));
    }

    vector<vector<array<int, 4>>> dp(w, vector<array<int, 4>>(32, {-1, -1, -1, -1})); // carry, 4th, 3rd, 2nd, 1st

    int need = 0b00000000;

    int cur = 0;
    need = compute(arr, cur);
    for (int i = 0; i < 10; i++)
    {
        forn(j, 10)
        {
            bool carry = false;
            int k = i + j;
            if (k > 9)
            {
                carry = true;
                k -= 10;
            }
            vector<bool> needed(4, false);
            vector<bool> can_do(4, false);
            if (need & 1 << 1)
            {
                can_do[0] = true;
            }
            if (need & 1 << 4)
            {
                can_do[1] = true;
            }
            if (need & 1 << 7)
            {
                can_do[2] = true;
            }
            if (need & 1 << 10)
            {
                can_do[3] = true;
            }
            int tot = conv[i] | (conv[j] << 3) | (conv[k] << 6);
            bool correct = true;
            for (int ch = 0; ch < 13; ch++)
            {
                int checker = 1 << ch;
                if (need & checker)
                {
                    if (!(tot & checker))
                    {

                        if ((ch - 1) % 3 == 0)
                        {
                            needed[(ch - 1) / 3] = true;
                            can_do[(ch - 1) / 3] = false;
                        }
                        else
                        {
                            correct = false;
                            break;
                        }
                        // if(i==7 and j==4)dbg(needed[(ch-1)/3]);
                    }
                }
                if (tot & checker)
                {
                    if(!(need & checker)){
                        correct = false;
                        break;
                    }
                }
            }

            if (correct)
            {
                int mem = 0b00000;
                if (carry)
                {
                    mem |= 1 << 4;
                }
                for (int c = 0; c < 4; c++)
                {
                    
                    if (needed[c])
                    {
                        mem |= 1 << c;
                    }
                }
                vector<int> mems;
                mems.push_back(mem);
                for (int me = 0; me < 4; me++)
                {
                    if (can_do[me])
                    {
                        if ((mem & 1 << me))
                        {
                            continue;
                        }
                        int l = mems.size();
                        for (int mej = 0; mej < l; mej++)
                        {
                            mems.push_back(mems[mej] | 1 << me);
                        }
                    }
                }
                for (auto mem : mems)
                {
                    dp[0][mem] = {i, j, k, -1};
                }
            }
        }
    }

    

    for (cur = 1; cur < w; cur++)
    {
        int need_orig = compute(arr, cur);
        for (int dp_val = 0; dp_val < 32; dp_val++)
        {
            if (dp[cur - 1][dp_val][0] == -1 or dp[cur][dp_val][0] != -1)
            {
                continue;
            }
            int need = need_orig;
            bool carry_needed = dp_val & 1 << 4;
            for (int i = 0; i < 4; i++)
            {
                if (dp_val & 1 << i)
                {
                    need |= 1 << 3 * i + 2;
                }
            }
            for (int i = 0; i < 10; i++)
            {
                forn(j, 10)
                {
                    bool carry = false;
                    int k = i + j;
                    if (carry_needed)
                        k++;
                    if (k > 9)
                    {
                        carry = true;
                        k -= 10;
                    }
                    vector<bool> needed(4, false);
                    vector<bool> can_do(4, false);
                    if (need & 1 << 1){
                        can_do[0] = true;
                    }
                    if (need & 1 << 4)
                    {
                        can_do[1] = true;
                    }
                    if (need & 1 << 7)
                    {
                        can_do[2] = true;
                    }
                    if (need & 1 << 10)
                    {
                        can_do[3] = true;
                    }
                    int tot = conv[i] | (conv[j] << 3) | (conv[k] << 6);
                    bool correct = true;
                    for (int ch = 0; ch < 13; ch++)
                    {
                        int checker = 1 << ch;
                        if (need & checker)
                        {
                            if (!(tot & checker))
                            {

                                if ((ch - 1) % 3 == 0)
                                {
                                    needed[(ch - 1) / 3] = true;
                                    can_do[(ch - 1) / 3] = false;
                                }
                                else
                                {
                                    correct = false;
                                    break;
                                }
                            }
                        }
                        if (tot & checker)
                        {
                            if (!(need & checker))
                            {
                                correct = false;
                                break;
                            }
                        }
                    }
                    if (correct)
                    {
                        int mem = 0b00000;
                        if (carry)
                        {
                            mem |= 1 << 4;
                        }
                        for (int c = 0; c < 4; c++)
                        {
                            if (needed[c])
                            {
                                mem |= 1 << c;
                            }
                        }
                        vector<int> mems;
                        mems.push_back(mem);
                        for(int me = 0; me < 4; me++){
                            if(can_do[me]){
                                if((mem & 1<<me)){
                                    continue;
                                }
                                int l = mems.size();
                                for(int mej = 0; mej < l; mej++){
                                    mems.push_back(mems[mej] | 1 << me);
                                }
                            }
                        }
                        for(auto mem: mems){
                            dp[cur][mem] = {i,j,k,dp_val};
                        }
                    }
                }
            }
        }
    }
    // for (int i = 0; i < 32; i++)
    // {
    //     dbg(i);
    //     cerr << dp[1][i][0] << " " << dp[1][i][1] << " " << dp[1][i][2] << " " << dp[1][i][3] << endl;
    // }

    if (dp[w - 1][0][0] == -1)
    {
        cout << "No" << endl;
        return;
    }
    vector<char> a;
    vector<char> b;
    vector<char> c;

    int next = 0;
    for (int i = w - 1; i >= 0; i--)
    {
        array<int, 4> here = dp[i][next];
        next = here[3];
        a.push_back('0' + here[0]);
        b.push_back('0' + here[1]);
        c.push_back('0' + here[2]);
    }
    forn(i, a.size())
    {
        cout << a[i];
    }
    cout << ln;
    forn(i, b.size())
    {
        cout << b[i];
    }
    cout << ln;
    forn(i, c.size())
    {
        cout << c[i];
    }
    cout << ln;
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