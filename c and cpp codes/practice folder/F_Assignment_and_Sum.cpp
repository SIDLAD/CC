#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const int MAXN = 2e6;
int n,m;

int h;

ll t[2 * MAXN];
int d[MAXN];

void calc(int p, int k) {
    if (d[p] == -1) t[p] = t[p<<1] + t[p<<1|1];
    else t[p] = (ll)d[p] * k;
}
  
void apply(int p, int value, int k) {
t[p] = (ll)value * k;
if (p < n) d[p] = value;
}
  
void push(int l, int r) {
int s = h, k = 1 << (h-1);
for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != -1) {
    apply(i<<1, d[i], k);
    apply(i<<1|1, d[i], k);
    d[i] = -1;
    }
}

void modify(int l, int r, int value) {
    if (value == 0) return;
    push(l, l + 1);
    push(r - 1, r);
    bool cl = false, cr = false;
    int k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (cl) calc(l - 1, k);
      if (cr) calc(r, k);
      if (l&1) apply(l++, value, k), cl = true;
      if (r&1) apply(--r, value, k), cr = true;
    }
    for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
      if (cl) calc(l, k);
      if (cr && (!cl || l != r)) calc(r, k);
    }
}

ll query(int l, int r) {
    push(l, l + 1);
    push(r - 1, r);
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
}

int qt,x,y,z;

signed main() {
    memset(d,-1,sizeof(d));
    cin >> n >> m;
    h = sizeof(int) * 8 - __builtin_clzll(n);
    while(m--) {
        cin >> qt;
        switch(qt) 
        {
            case 1:
                cin >> x >> y >> z;
                modify(x,y,z);
                break;
            case 2:
                cin >> x >> y;
                cout << query(x,y) << endl;
        }
    }
}