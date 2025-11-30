#include<bits/stdc++.h>
using namespace std;

struct distinctColors {
    mutable set<int> colors;

    void operator+=(distinctColors const& other) const {
        if(other.colors.size() > colors.size()) swap(colors, other.colors);
        for(auto& color: other.colors) colors.insert(color);
    }

    friend ostream& operator<<(ostream& os, distinctColors const& dc) {
        os << dc.colors.size();
        return os;
    }

    operator int() const {
        return colors.size();
    }
};

int main () {
    int n;
    cin >> n;
    vector<vector<int>> edges(n + 1);
    vector<int> colors(n + 1);
    for(int i=1;i<=n;++i) {
        cin >> colors[i];
    }
    for(int i=0;i<n-1;++i) {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> ans(n + 1);

    auto dfs = [&](auto self, int node, int p) -> distinctColors {
        distinctColors dc = {{colors[node]}};
        for(auto nbr: edges[node]) if(nbr != p) {
            dc += self(self, nbr, node);
        }
        ans[node] = dc;
        return dc;
    }; 
    cout << dfs(dfs, 1, 1) << " ";
    for(int i=2;i<=n;++i) cout << ans[i] << " ";
    cout << endl;
}