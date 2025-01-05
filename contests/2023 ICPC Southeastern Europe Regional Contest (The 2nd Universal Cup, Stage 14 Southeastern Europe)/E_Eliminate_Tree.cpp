#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> edges(n + 1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<pair<int,int>> v(n + 1);

    auto dfs = [&](auto self, int node = 1, int p = 1)->void
    {
        int childsum = 0;
        int maxdelta = -1;
        for(auto child: edges[node])if(child != p)
        {
            self(self,child,node);
            childsum += v[child].first;
            maxdelta = max(maxdelta,v[child].second);
        }

        int x = min(2 + childsum, 1 + childsum - maxdelta);
        int y = x - childsum;
        v[node] = {x,y};
    };
    dfs(dfs);

    cout<<v[1].first<<endl;
}