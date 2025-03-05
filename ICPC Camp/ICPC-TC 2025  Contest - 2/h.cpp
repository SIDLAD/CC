#include<bits/stdc++.h>
using namespace std;
#define int long long

int check(int n, int m, int len, int x) {
    if(m == 0)return n == len and ((1ll << len) - 1) <= x;
    if(len % (n + m) != 0 and len % (n + m) != n) return 0;
    int num = 0;
    for(int i=0;i<len;i++) {
        //n eles, m eles, n eles, m eles ..
        if(i%(n + m) < n) num += (1ll << len - i - 1);
    }
    // cerr << "num: " << num << "|" << len << " " << n << " " << m << " "<< endl;
    return num <= x;
}
int solve(int x) {
    if(x <= 0)return 0;
    int maxLen = bit_width((unsigned long long) x);
    int ans = 0;
    for(int len = 1; len <= maxLen;len ++ )for(int n = 1;n <= 63;n++)for(int m = 0; m <= 63; m++) if(n + m <= len){
        ans += check(n,m,len,x);
    }
    return ans;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int l, r;
    cin >> l >> r;
    cout<<solve(r) - solve(l - 1) << endl;
}