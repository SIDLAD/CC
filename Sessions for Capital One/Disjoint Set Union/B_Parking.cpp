#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300000 + 10;
int p[MAXN]{};
int n;

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void unite(int x) {
    x = find(x);
    int y = find(x%n + 1);
    p[x] = y;
}

int main () {
    cin >> n;
    iota(p + 1, p + 1 + n, 1);
    for(int i=n; i-->0;) {
        int x;
        cin >> x;
        cout << find(x) << " ";
        unite(x);
    }
}