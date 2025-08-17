#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& e: v)  cin >> e;
    int ans = min(2 * v[0], v[0] + v[1]);
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
}