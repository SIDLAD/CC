#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for(int i=1;i<=n;i++)cin >> p [i];
        int curL = 0;
        set<int> st;
        vector<int> label(n + 1);
        int s;
        vector<int> Lsz(n + 1);
        for(int i=1;i <=n; i++) if(!label[i]) {
            s = i;
            curL++;
            do {
                label[s] = curL;
                s = p[s];
                Lsz[curL]++;
            } while(s != i);
            
        }
        int ans = 0;
        while(n--) {
            cin >> s;
            if(!st.count(label[s]))ans += Lsz[label[s]];
            st.insert(label[s]);
            cout << ans << " ";
        }cout<<endl;
    }
}