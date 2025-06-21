#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n,vector<int>(m));
        set<int> st;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> a[i][j], st.insert(a[i][j]);
        set<int> st2;
        for(int i=0;i<n;i++)for(int j=0;j<m-1;j++){
            if(a[i][j] == a[i][j+1])st2.insert(a[i][j]);
        }
        for(int i=0;i<n-1;i++)for(int j=0;j<m;j++)if(a[i][j] == a[i+1][j])st2.insert(a[i][j]);
        if(st2.size() == 0)cout << st.size() - 1 << endl;
        else cout <<st.size() - 1 + st2.size()  -1 << endl;
    }
}