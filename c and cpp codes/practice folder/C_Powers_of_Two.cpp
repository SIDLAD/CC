#include<bits/stdc++.h>
using namespace std;

using trygub = map<int,int>;

void addTo(trygub& t, int val, int ind) {
    while(true) {
        t[ind] += val;
        if(t[ind] == 0) t.erase(ind);
        else if(abs(t[ind]) == 2) {t.erase(ind++);continue;}
        break;
    }
}

bool checkZero(trygub& t){ return t.size() == 0; }
string input() {
    string x; cin >> x;
    return x;
}
int main() {
    int n;
    cin >> n;
    trygub ans;
    while(n--) {
        string a = input(), b = input();
        addTo(ans, (a == "+") * 2 - 1, stoi(b));
        cout << (checkZero(ans) ? "YES" : "NO") << endl;
    }
}