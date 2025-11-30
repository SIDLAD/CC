#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1 << 17;
pair<int,int> tree[MAXN << 1];

int n,m;
int a[MAXN];

pair<int,int> join(pair<int,int> a, pair<int,int> b) {
    if(a.second == 0) return {a.first | b.first, 1};
    else return {a.first ^ b.first , 0};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    n = 1 << n;
    for(int i=0;i<n;++i)
        cin >> a[i];
    for(int i=0;i<n;++i) 
        tree[i + n] = {a[i], 0};
    for(int p = n; --p;)
        tree[p] = join(tree[p << 1],  tree[p << 1 | 1]);
    while(m--) {
        int p, b;
        cin >> p >> b;
        for(tree[p += n-1].first = b; p>>=1;)
            tree[p] = join(tree[p << 1], tree[p << 1 | 1]);
        cout << tree[1].first << endl; // since perfect power of 2
    }
}