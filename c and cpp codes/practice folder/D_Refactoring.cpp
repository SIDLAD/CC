#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()

string input() {
    string s;
    cin >> s;
    return s;
}

int markPos(string& s, string& a) {
    string cp = a + '$' + s;
    vector<int> zval(cp.size());
    int l = 0, r = 0;
    int n = cp.size();
    for(int i=1;i<n;++i) {
        if(i < r) zval[i] = min(zval[i-l], r - i);
        while(i + zval[i] < n && cp[i + zval[i]] == cp[zval[i]]) ++zval[i];
        if(i + zval[i] > r) l = i, r = i + zval[i];
    }
    int id = - 1;
    if(int mx = *max_element(all(zval)); mx == a.size()) {
        for(int i=0;i<n;++i) if(zval[i] == mx) {
            id = i - a.size() - 1;
            break;
        }
    }
    return id;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> ss,tt;
    for(int i=0;i<n;++i) ss.emplace_back(input());
    for(int i=0;i<n;++i) tt.emplace_back(input());
    string a,b;

    bool prelimCheck = true;
    vector<tuple<string,string,int,int>> consider;

    for(int i=0;i<n;++i) {
        int fDif = -1, lDif = -1;
        for(int j=0;j<ss[i].size();++j) if(ss[i][j] != tt[i][j]) {
            if(fDif == -1) fDif = j;
            lDif = j;
        }
        string aa, bb;
        if(lDif != -1) {
            consider.emplace_back(ss[i], tt[i], fDif, lDif);
            aa = ss[i].substr(fDif, lDif - fDif + 1);
            bb = tt[i].substr(fDif, lDif - fDif + 1);
            if(a.size()) {
                if(aa != a or bb != b) {
                    prelimCheck = false;
                    break;
                }
            }
            else a = aa, b = bb;
        }
    }
    if(!prelimCheck) {
        cout << "NO" << endl;
        return 0;
    }
    int nn = n;
    n = consider.size();
    while(true) {
        char ls{}, lt{};
        bool ch = true;
        for(int i=0;i<n;++i) {
            if(get<2>(consider[i]) == 0) {
                ch = false;
                break;
            }
            if(!ls) ls = get<0>(consider[i])[get<2>(consider[i]) - 1], lt = get<1>(consider[i])[get<2>(consider[i]) - 1];
            else if(get<0>(consider[i])[get<2>(consider[i]) - 1] == ls && get<1>(consider[i])[get<2>(consider[i]) - 1] == lt);
            else {
                ch = false;
                break;
            }
        }
        if(ch) {
            for(int i=0;i<n;++i) get<2>(consider[i])--;
        }
        else break;
    }

    while(true) {
        char rs{}, rt{};
        bool ch = true;
        for(int i=0;i<n;++i) {
            if(get<3>(consider[i]) == get<1>(consider[i]).size() - 1) {
                ch = false;
                break;
            }
            if(!rs) rs = get<0>(consider[i])[get<3>(consider[i]) + 1], rt = get<1>(consider[i])[get<3>(consider[i]) + 1];
            else if(get<0>(consider[i])[get<3>(consider[i]) + 1] == rs && get<1>(consider[i])[get<3>(consider[i]) + 1] == rt);
            else {
                ch = false;
                break;
            }
        }
        if(ch) {
            for(int i=0;i<n;++i) get<3>(consider[i])++;
        }
        else break;
    }
    a = get<0>(consider[0]).substr(get<2>(consider[0]), get<3>(consider[0]) - get<2>(consider[0]) + 1);
    b = get<1>(consider[0]).substr(get<2>(consider[0]), get<3>(consider[0]) - get<2>(consider[0]) + 1);

    for(int i=0;i<nn;++i) {
        string& s = ss[i];
        string& t = tt[i];
        int mp = markPos(s, a);
        string tgt;
        if(mp != -1) {
            tgt = s.substr(0,mp) + b + s.substr(mp + a.size());
        }
        else tgt = t;
        if(t == tgt);
        else {
            prelimCheck = false;
            break;
        }
    }
    if(prelimCheck) {
        cout << "YES" << endl;
        cout << a << endl;
        cout << b << endl;
    }
    else cout << "NO" << endl;
}