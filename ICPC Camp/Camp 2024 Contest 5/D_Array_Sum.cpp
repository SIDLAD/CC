#include<bits/stdc++.h>
using namespace std;

#define int long long

struct segtree {
    int size, n;
    vector<int> mins, inds;

    segtree(int n) : n(n) {
        size = 1;
        while(size < n) size *= 2;
        mins.assign(2*size, INT_MAX);
        inds.assign(2*size, -1);
    }

    void set(int ind, int val, int x, int lx, int rx) {
        if(rx - lx == 1) {
            mins[x] = val;
            inds[x] = lx;
            return;
        }
        int mid = (lx + rx)/2;
        if(ind < mid) set(ind, val, 2*x + 1, lx, mid);
        else set(ind, val, 2*x + 2, mid, rx);
        if(mins[2*x + 1] <= mins[2*x + 2]) {
            mins[x] = mins[2*x + 1];
            inds[x] = inds[2*x + 1];
        }
        else {
            mins[x] = mins[2*x + 2];
            inds[x] = inds[2*x + 2];
        }
    }

    void set(int ind, int val) {
        set(ind, val, 0, 0, n);
    }

    pair<int, int> find(int l, int r, int x, int lx, int rx) {
        if(lx >= r || rx <= l) return {INT_MAX, -1};
        if(lx >= l && rx <= r) {
            return {mins[x], inds[x]};
        }
        int mid = (lx + rx)/2;
        auto ans1 = find(l, r, 2*x + 1, lx, mid), ans2 = find(l, r, 2*x + 2, mid, rx);
        if(ans1.first <= ans2.first) {
            return ans1;
        }
        else {
            return ans2;
        }
    }

    pair<int, int> find(int l, int r) {
        return find(l, r, 0, 0, n);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    segtree st(n);
    for(int i = 0;i<n;i++) {
        cin >> a[i];
        st.set(i, a[i]);
    }
    vector<pair<int, int>> b;
    for(int i = 0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        b.push_back({x, y});
    }
    sort(b.begin(), b.end());
    for(int i = 0;i<m;i++) {
        int x = b[i].first, y = b[i].second;
        auto temp = st.find(0, x);
        st.set(temp.second, temp.first - y);
        a[temp.second] = temp.first - y;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i = 0;i<n;i++) {
        sum += a[i];
        cout << sum << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
}