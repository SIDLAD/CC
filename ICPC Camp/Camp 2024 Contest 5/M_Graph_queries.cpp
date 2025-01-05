#include<bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;

void calc(int v, int ct, vector<int> &dist, vector<set<int>> &graph, vector<bool> &visited, vector<int> &ans) {
    visited[v] = true;
    dist[v] = ct;
    for(auto &val : graph[v]) {
        if(visited[val] && ct - dist[val] > 1) {
            ans.push_back(ct - dist[val] + 1);
            continue;
        }
        if(visited[val]) continue;
        calc(val, ct + 1, dist, graph, visited, ans);
    }
}

void solve() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >>n ;
    vector<set<int>> graph(2*n);
    for(int i = 0;i<n - 1;i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].insert(v - 1);
        graph[v - 1].insert(u - 1);
    }
    vector<bool> pres(n, false);
    for(int i = 0;i<n - 1;i++) {
        int q;
        cin >> q;
        q--;
        pres[q] = true;
        for(auto &val : graph[q]) {
            if(val >= n) break;
            if(pres[val]) {
                graph[q + n].insert(val + n);
                graph[val + n].insert(q + n);
                graph[q].erase(graph[q].find(val + n));
                graph[val + n].erase(graph[val + n].find(q));
            }
            else {
                graph[q + n].insert(val);
                graph[val].insert(q + n);
            }
        }

        vector<int> dist(2*n, 0), ans;
        vector<bool> visited(2*n, false);
        calc(0, 0, dist, graph, visited, ans);
        int finalAns =1;
        for(auto &val : ans) {
            finalAns  = (finalAns * val) % M;
            cerr << val << " ";
        }
        cerr << "\n";
        cout << finalAns << "\n";
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    
}