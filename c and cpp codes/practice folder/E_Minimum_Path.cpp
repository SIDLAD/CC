#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int v,u,w;
vector<tuple<int,int,int>> edges[5][(int)2e5 + 1];
int dijkstra[4][(int)2e5 + 1];


signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dijkstra, 0x3f, sizeof(dijkstra));
    cin >> n >> m;
    for(int i=0;i<m;++i) {
        cin >> v >> u >> w;
        edges[0][v].emplace_back(0,u,w);
        edges[0][u].emplace_back(0,v,w);
        edges[1][v].emplace_back(1,u,w);
        edges[1][u].emplace_back(1,v,w);
        edges[2][v].emplace_back(2,u,w);
        edges[2][u].emplace_back(2,v,w);
        edges[3][v].emplace_back(3,u,w);
        edges[3][u].emplace_back(3,v,w);

        edges[0][v].emplace_back(1,u,2*w);
        edges[0][u].emplace_back(1,v,2*w);

        edges[1][v].emplace_back(2,u,0);
        edges[1][u].emplace_back(2,v,0);

        edges[0][v].emplace_back(3,u,0);
        edges[0][u].emplace_back(3,v,0);

        edges[3][v].emplace_back(2,u,2*w);
        edges[3][u].emplace_back(2,v,2*w);
    }

    dijkstra[0][1] = 0;

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.emplace(0,0,1);
    while(pq.size()) {
        auto [d, l , u] = pq.top();
        pq.pop();
        if(dijkstra[l][u] != d) continue;
        for(auto [nxtl, nxtu, nxtw] : edges[l][u]) if(d + nxtw < dijkstra[nxtl][nxtu]){
            dijkstra[nxtl][nxtu] = d + nxtw;
            pq.emplace(d + nxtw, nxtl, nxtu);
        }
    }

    for(int i=2;i<=n;++i) cout << min(dijkstra[0][i], dijkstra[2][i]) << " "; cout << endl;
}