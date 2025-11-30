#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 200000 + 1;
constexpr int MAXQ = 500000 + 1;
int n,q;
int p[MAXN]{};

int find(int x) {
    if(p[x] == x) return x;
    else return p[x] = find(p[x]);
}

void unite(int a, int b) {
    a = find(a), b = find(b);
    if(b != a) p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    iota(p + 1, p + 1 + n, 1);
    set<int> st;
    for(int i=1;i<=n;++i) st.insert(i);
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) unite(x,y);
        else if(t == 2) {
            auto it = st.upper_bound(x);
            stack<int> stk;
            while(it != st.end() and *it <= y) {
                stk.push(*it);
                unite(x, *it);
                it++;
            }
            while(stk.size()) st.erase(stk.top()), stk.pop();
            st.insert(x), st.insert(y);
        }
        else {
            cout << (find(x) == find(y) ? "YES" : "NO") << endl;
        }
    }
}