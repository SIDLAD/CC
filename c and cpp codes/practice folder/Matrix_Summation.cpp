#include<bits/stdc++.h>
using namespace std;
#define int long long

struct F2 {
    int n;
    vector<vector<int>> f;
    F2(int n): n(n), f(n, vector<int>(n, 0ll)) {}
    void add(int si, int sj, int x) {
        assert(max(si, sj) < n);
        assert(min(si, sj) >= 0);
        for(int i=si; i<n; i |= i + 1) for(int j = sj; j < n; j |= j + 1)
            f[i][j] += x;
    }
    void reset(int n) {
        this->n = n;
        f.assign(n, vector<int>(n, 0));
    }
    int sum(int ei, int ej) {
        if(min(ei, ej) < 0) return 0;
        assert(max(ei, ej) < n);
        int s = 0;
        for(int i = ei+1; i--; i &= i + 1) for(int j=ej + 1; j--; j &= j + 1)
            s += f[i][j];
        return s;
    }
    int rngSum(int si, int sj, int ei, int ej) {
        return sum(ei, ej) - sum(ei, sj - 1) - sum(si - 1, ej) + sum(si - 1, sj - 1);
    }
    int get(int si, int sj) {
        return sum(si, sj) - sum(si - 1, sj) - sum(si, sj - 1) + sum (si - 1, sj - 1);
    }
    void set(int si, int sj, int& prev, int nw) {
        int d = nw - prev;
        add(si, sj, d);
        prev = nw;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<vector<int>> mat;
    int t;
    cin >> t;
    F2 f(0);
    while(t--) {
        int n;
        cin >> n;
        mat.assign(n, vector<int>(n, 0));
        string s;
        f.reset(n);
        while(true) {
            cin >> s;
            if(s == "END") break;
            if(s == "SET") {
                int x, y, num;
                cin >> x >> y >> num;
                f.set(x, y, mat[x][y], num);
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << f.rngSum(x1, y1, x2, y2) << '\n';
            }
        }
    }
}