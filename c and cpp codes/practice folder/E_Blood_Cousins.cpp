#include<bits/stdc++.h>
using namespace std;

int n,m;
int v,p;
int rng[(int)1e5 + 1][2];
int anc[21][(int)1e5 + 1];
int nodeHt[(int)1e5 + 1];
vector<int> edges[(int)1e5 + 1];
vector<int> euler;
vector<int> height[(int)2e5 + 1];

void traverse(int node, int ht) {
    rng[node][0] = euler.size();
    euler.push_back(node);
    height[nodeHt[node] = ht].push_back(euler.size());
    for(auto ch: edges[node]) traverse(ch, ht + 1);
    rng[node][1] = euler.size();
}

int main() {
    cin >> n;
    for(int i=1;i<=n;++i)  cin >> anc[0][i], edges[anc[0][i]].push_back(i);
    for(int i=1;i<=20;++i) for(int j=1;j<=n;++j) anc[i][j] = anc[i-1][anc[i-1][j]];
    for(int i=1;i<=n;++i) if(!anc[0][i]) traverse(i, 0);
    cin >> m;
    for(int i=0;i<m;++i) {
        cin >> v >> p;
        int htup = p;
        for(int i=20;i>=0;--i) if(htup >> i >= 1) v = anc[i][v], htup -= 1<<i;
        cout << max((int)(upper_bound(height[nodeHt[v] + p].begin(), height[nodeHt[v] + p].end(), rng[v][1])
            -   upper_bound(height[nodeHt[v] + p].begin(), height[nodeHt[v] + p].end(), rng[v][0])) - 1, 0)<< ' ';
    }

}