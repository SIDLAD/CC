#include<bits/stdc++.h>
using namespace std;

int solve(string s) { 
    int n = s.length();
    map<char, int> mp;
    for(int i=0;i<s.length();i++)mp[s[i]]++;
    auto mpc = mp;
    for(int l = s.length(); l>0;l--) {
        mp[s[l-1]]--;
        if(mp[s[l-1]] * 2 >= mpc[s[l-1]]);
        else if(l * 2 <= n && s[l-1] == s[n - l]);
        else return l;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int i;
        for(i=0;i<n && s[i] == s[n-i-1];i++);

        s = s.substr(i, n - 2 * i);
        cout << solve(s) << endl;
    }
}