#include<bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;

int n, m, u, v;
vector<pair<int,int>> adj[20];
int ways[20][1<<20]{};

signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj[--u].emplace_back(--v, 1);
    }

    for(auto& v: adj) {
        sort(v.begin(), v.end());
        vector<pair<int,int>> cntV;
        for(auto [v1,_]: v) {
            if(!cntV.size() or cntV.back().first != v1) cntV.emplace_back(v1, 1);
            else cntV.back().second ++;
        }
        v = cntV;
    }

    ways[0][1] = 1;
    
    for(int i=1;i<(1<<n); i += 2) for(int from=0; from < n; ++from) if((1<<from) & i)
    {
        for(auto [to, mult]: adj[from]) if(!((1<<to) & i))
        {
            (ways[to][i ^ (1<<to)] += 1ll * ways[from][i] * mult % MOD) %= MOD; 
        }
    }

    cout << ways[n-1][(1<<n) - 1] << '\n';
}