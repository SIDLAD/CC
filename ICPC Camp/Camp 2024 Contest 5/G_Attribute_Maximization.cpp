#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i<m;i++) {
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 1;i<n;i++) {
        ans += abs(a[i] - a[i - 1]);
    }
    for(int i = 1;i<m;i++) {
        ans += abs(b[i] - b[i - 1]);
    }
    cout << ans << "\n";
}