#include <bits/stdc++.h>
using namespace std;
int n, q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    cerr << t << endl;
    while (t--)
    {
        
        cin >> n >> q;
        vector<int> b(n);
        for (auto &e : b)
            cin >> e;
        vector<array<int, 3>> v(q);
        for (int i = 0; i < q; ++i)
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        reverse(v.begin(), v.end());

        auto a = b;
        for (auto [x1, y1, z1] : v)
        {
            x1--, y1--, z1--;
            auto [bx, by, bz] = array<int, 3>{a[x1], a[y1], a[z1]};
            a[z1] = 0;
            a[y1] = max(bz, by);
            a[x1] = max(bz, bx);
        }
        reverse(v.begin(), v.end());
        auto ans = a;
        for (auto [x1, y1, z1] : v)
        {
            x1--, y1--, z1--;
            a[z1] = min(a[x1], a[y1]);
        }
        if (a == b)
        {
            for (auto e : ans)
                cout << e << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}