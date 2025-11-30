#include<bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e6 +  10;
int n,m;
int dsu[MAXN]{};
int sz[MAXN]{};
int rightmost[MAXN]{};

int find(int x) {
    if(dsu[x] == x) return x;
    return find(dsu[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    // Now size of the set corr. x is greater than or equal to size of the set corr. y
    dsu[y] = x;
    sz[x] += sz[y];
    rightmost[x] = max(rightmost[x],rightmost[y]);
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    iota(dsu + 1, dsu + n + 2, 1); // This sets dsu[1] = 1, dsu[2] = 2 ... dsu[n] = n;
    iota(rightmost + 1, rightmost + n + 2, 1); // This sets dsu[1] = 1, dsu[2] = 2 ... dsu[n] = n;
    fill(sz + 1, sz + n + 2, 1); // This sets sz[i] = 1 for all i

    for(int i=0;i<m;++i) {
        char c;
        int x;
        cin >> c >> x;
        if(c == '-') {
            unite(x, x + 1);
        } else {
            int ans = rightmost[find(x)];
            if(ans == n + 1) ans = -1;
            cout << ans << endl;
        }
    }
}