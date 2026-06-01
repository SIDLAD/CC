#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;

#define midDef int mid = ss + se >> 1
#define firstC (id + 1)
#define secondC (id + 2 * (mid - ss))

struct segtree {
    int n;
    vector<int> st;
    vector<int> lazy;
    segtree(int n): n(n) {
        st.assign(2 * n - 1, 0);
        lazy.assign(2 * n - 1, 0);
    }

    void pushDown(int id, int ss, int se) {
        if(lazy[id] == 0) return;
        st[id] += lazy[id] * (se - ss);
        int lz = lazy[id];
        lazy[id] = 0;
        if(se - ss == 1) {return;}
        midDef;
        lazy[firstC] += lz;
        lazy[secondC] += lz;
    }

    void add(int val, int l, int r, int id = -1, int ss = -1, int se = -1) { // l inclusive, r exclusive
        if(id == -1) {
            id = 0;
            ss = 0;
            se = n;
        }
        assert(l < r);
        assert(se > ss);
        if(r <= ss or se <= l) return;
        if(l <= ss and se <= r) {
            lazy[id] += val;
            return;
        }
        pushDown(id, ss, se);
        midDef;
        add(val, l, r, firstC, ss, mid);
        add(val, l, r, secondC, mid, se);
        pushDown(firstC, ss, mid);
        pushDown(secondC, mid, se);
        st[id] = st[firstC] + st[secondC];
    }

    int getVal(int ind, int id = -1, int ss = -1, int se = -1) {
        if(id == -1) {
            id = 0;
            ss = 0;
            se = n;
        }
        assert(se > ss);
        pushDown(id, ss, se);
        if(ind < ss or ind >= se) return 0;
        if(se - ss == 1) return st[id];
        midDef;
        return getVal(ind, firstC, ss, mid) + getVal (ind, secondC, mid, se);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    segtree st(n);
    while(m--) {
        int x;
        cin >> x;
        if(x - 1) {
            int i;
            cin >> i;
            cout << st.getVal(i) << endl;
        } else {
            int l, r, v;
            cin >> l >> r >> v;
            st.add(v, l, r);
        }
    }
}