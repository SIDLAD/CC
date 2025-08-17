#include<bits/stdc++.h>
using namespace std;

map<array<int,3>, int> cache;
int n;

int ask(int a, int b, int c) {
    array<int,3> ar = {a,b,c};
    sort(ar.begin(), ar.end());
    if(cache.contains(ar)) return cache[ar];
    if(cache.size() + 1 > n + 6) {cout << "ThisShouldn'tHappen" << endl; exit(0);}
    cout << "? " << ar[0] << " " << ar[1] << " " << ar[2] << endl;
    cin >> cache[ar];
    if(cache[ar] == -1) exit(0);
    cache[ar] ^= 1;
    return cache[ar];
}

void answer(vector<int> ans) {
    cout << "! " << accumulate(ans.begin() + 1, ans.end(), 0)<< " ";
    for(int i=1;i<=n;++i) if(ans[i]) cout << i << " ";
    cout << endl;
}

void solve() {
    cache.clear();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int nb3 = n / 3;
    
    int zeroInd = -1, oneInd = -1;
    for(int i=0;i<nb3;++i) {
        if(ask(3*i + 1, 3*i + 2, 3*i + 3)) oneInd = i;
        else zeroInd = i;
    }
    if(zeroInd == -1 || oneInd == -1) exit(0);
    vector<int> ans(n + 1, -1);

    
    int w = -1, b = -1;
    if(ask(3*zeroInd + 1, 3* zeroInd + 2, 3 * oneInd + 1)) {
        w = 3 * oneInd + 1;
        b = 3 * zeroInd + 3;
        ans[w] = 1;
        ans[b] = 0;
        ans[3*zeroInd + 1] = ask(w,b,3*zeroInd + 1);
        ans[3*zeroInd + 2] = ans[3*zeroInd + 1] ^ 1;
        ans[3 * zeroInd + 3] = 0;
    }
    else if(ask(3*zeroInd + 1, 3* zeroInd + 2, 3 * oneInd + 2)){
        w = 3 * oneInd + 2;
        b = 3 * zeroInd + 3;
        ans[w] = 1;
        ans[w - 1] = ans[b] = 0;
        ans[3*zeroInd + 1] = ask(w,b,3*zeroInd + 1);
        ans[3*zeroInd + 2] = ans[3*zeroInd + 1] ^ 1;
        ans[3 * zeroInd + 3] = 0;
    }
    else if(ask(3*zeroInd + 1, 3* zeroInd + 2, 3 * oneInd + 3)){
        w = 3 * oneInd + 3;
        b = 3 * zeroInd + 3;
        ans[w] = 1;
        ans[w - 1] = ans[w - 2] = ans[b] = 0;
        ans[3 * zeroInd + 1] = ask(w,b,3*zeroInd + 1);
        ans[3 * zeroInd + 2] = ans[3 * zeroInd + 1]^ 1;

        ans[3 * zeroInd + 3] = 0;
    }
    else {
        b = 3*zeroInd + 1;
        ans[b] = ans[3 * zeroInd + 2] = 0;
        int x = ask(3 * oneInd + 1, 3 * oneInd + 2, b);
        int y = ask(3 * oneInd + 3, 3 * oneInd + 2, b);
        if(x && y) {
            w = 3 * oneInd + 1;
            ans[3 * oneInd + 3] = ans[3 * oneInd + 1] = ans[3 * oneInd + 2] = 1;
        }
        else if(x) {
            w = 3 * oneInd + 1;
            ans[3 * oneInd + 3] = 0;
            ans[3 * oneInd + 1] = ans[3 * oneInd + 2] = 1;
        }
        else if(y){
            w = 3 * oneInd + 3;
            ans[3 * oneInd + 1] = 0;
            ans[3 * oneInd + 3] = ans[3 * oneInd + 2] = 1;
        }
        else {
            w = 3 * oneInd + 1;
            ans[3 * oneInd + 1] = ans[3 * oneInd + 3] = 1;
            ans[3 * oneInd + 2] = 0;
        }
    }
    if(w == -1 || b == -1) exit(0);
    for(int i=1;i<=3;++i) if(ans[3 * oneInd + i] == -1) ans[3 * oneInd + i] = ask(w,b, 3 * oneInd + i);
    for(int i=1;i<=3;++i) if(ans[3 * zeroInd + i] == -1) ans[3 * zeroInd + i] = ask(w,b, 3 * zeroInd + i);

    for(int i=0;i<nb3;++i) if(i != oneInd && i != zeroInd) {
        if(ask(3 * i + 1, 3 * i + 2, 3 * i + 3)) {
            int x = ask(b, 3 *i + 1, 3 * i + 2);
            int y = ask(b, 3 *i + 2, 3 * i + 3);
            if(x && y) {
                ans[3 *i + 1] = ans[3 * i + 2] = ans[3 * i + 3 ] = 1;
            }
            else if(x) {
                ans[3 * i + 1] = ans[3 * i + 2] = 1;
                ans[3 * i + 3] = 0;
            }
            else if(y){
                ans[3 * i + 2] = ans[3 * i + 3] = 1;
                ans[3 * i + 1] = 0;
            }
            else {
                ans[3 * i + 1] = ans[3 * i + 3] = 1;
                ans[3 * i + 2] = 0;
            }
        }
        else {
            int x = ask(w, 3 *i + 1, 3 * i + 2);
            int y = ask(w, 3 *i + 2, 3 * i + 3);
            x ^= 1, y^= 1;
            if(x && y) {
                ans[3 *i + 1] = ans[3 * i + 2] = ans[3 * i + 3] = 0;
            }
            else if(x) {
                ans[3 * i + 1] = ans[3 * i + 2] = 0;
                ans[3 * i + 3] = 1;
            }
            else if(y){
                ans[3 * i + 2] = ans[3 * i + 3] = 0;
                ans[3 * i + 1] = 1;
            }
            else {
                ans[3 * i + 1] = ans[3 * i + 3] = 0;
                ans[3 * i + 2] = 1;
            }
        }
    }
    if(*min_element(ans.begin() + 1, ans.end()) == -1) cout <<"unexpected", exit(0);
    answer(ans);
}

int main() {
    int t;
    cin >> t;
    while(t--)solve();
}