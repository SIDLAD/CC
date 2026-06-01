#include<bits/stdc++.h>
using namespace std;

struct F2 {
    int n;
    vector<vector<int>> f;
    vector<vector<bool>> one;
    F2(int n) : n(n), f(n,vector<int>(n)), one(n, vector<bool>(n)) {}
    void reset() {
        for(int i=0;i<n;++i) for(int j=0;j<n;++j)
                one[i][j] = f[i][j] = 0;
    }
    void set(int si, int sj) {
        if(one[si][sj]) return;
        assert(max(si, sj) < n);
        assert(min(si, sj) >= 0);
        for(int i=si; i < n; i|= i + 1)
            for(int j=sj; j < n; j|= j + 1)
                f[i][j] += 1;
        one[si][sj] = 1;
    }
    int sum(int ei, int ej) {
        if(min(ei, ej) < 0) return 0;
        assert(max(ei, ej) < n);
        int s = 0;
        for(int i=ei + 1; i--; i &= i + 1)
            for(int j=ej + 1; j--; j &= j + 1)
                s += f[i][j];
        return s;
    }
    int sum(int si, int sj, int ei, int ej) {
        return
            sum(ei, ej)
            - sum(ei, sj - 1)
            - sum(si - 1, ej)
            + sum(si - 1, sj - 1);
    }
};

F2 f(1001);

int main() {
    int t;
    cin >> t;
    int TT = 1;
    while(t--) {
        cout << "Case " << TT << ":" << endl;
        TT++;
        int q;
        cin >> q;
        f.reset();
        while(q--) {
            int ct, x1, y1, x2, y2;
            cin >> ct >> x1 >> y1;
            if(ct == 1) {
                cin >> x2 >> y2;
                cout << f.sum(x1, y1, x2, y2) << endl;
            } else {
                f.set(x1, y1);
            }
        }
    }
}
