#include<bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
#define int long long
#define MIDD int mid = ss + se >> 1
#define FC si + 1
#define SC si + 2 * (mid - ss)

struct segtree{
    int n;
    vector<int> tree, lazy;
    segtree(int n) : n(n) {
        assert(n > 0);
        tree.assign(2 * n - 1, 0); // initially assigned with zeros
        lazy.assign(2 * n - 1, 0); // add op identity
    }

    void pushDown(int si, int ss, int se) {
        if(lazy[si] == 0) return;
        tree[si] += lazy[si];
        int lz = lazy[si];
        lazy[si] = 0;
        if(se - ss == 1) return;
        MIDD;
        lazy[FC] += lz;
        lazy[SC] += lz;
    }

    int get(int si, int ss, int se) {
        assert(se > ss);
        pushDown(si, ss, se);
        return tree[si];
    }

    void add(int val, int l, int r, int si=-1, int ss=-1, int se=-1) {
        if(si == -1) si = 0, ss = 0, se = n;
        assert(si < 2*n- 1);
        assert(se > ss);
        assert(l < r);
        if(r <= ss or se <= l) return;
        if(l <= ss and se <= r) {
            lazy[si] += val;
            return;
        }
        pushDown(si, ss, se);
        MIDD;
        add(val, l, r, FC, ss, mid);
        add(val, l, r, SC, mid, se);
        tree[si] = min(get(FC, ss, mid), get(SC, mid, se));
    }

    int getMin(int l, int r, int si = -1, int ss = -1, int se = -1) {
        if(si == -1) si = 0, ss = 0, se = n;
        assert(si < 2*n- 1);
        assert(l < r);
        assert(se > ss);
        if(r <= ss or se <= l) return INF;
        pushDown(si, ss, se);
        if(l <= ss and se <= r) return tree[si];
        MIDD;
        return min(getMin(l, r, FC, ss, mid), getMin(l, r, SC, mid, se));
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    int x, l, r, v;
    segtree st(n);
    while(m--) {
        cin >> x;
        if(x - 1) {
            cin >> l >> r;
            cout << st.getMin(l, r) << endl;
        }
        else {
            cin >> l >> r >> v;
            st.add(v, l, r);
        }
    }
}