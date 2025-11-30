#include<bits/stdc++.h>
using namespace std;

constexpr int MN = -(int)1e9, MX = (int) 1e9;
int curPtr = 0;

struct segnode {
    int lp{},rp{},val{};
    segnode(int val) : lp(0), rp(0), val(val) {}
    segnode() {}
    segnode(int lp, int rp, segnode* nodes): lp(lp), rp(rp) {
        val = nodes[lp].val + nodes[rp].val;
    }
} nodes[(int) 4e6 + 1];

int createNode(int val) {
    nodes[curPtr] = segnode(val);
    return curPtr ++;
}

int mergeNodes(int lp, int rp) {
    nodes[curPtr] = segnode(lp, rp, nodes);
    return curPtr ++;
}

int updateNode(int p) {
    nodes[curPtr] = nodes[p];
    nodes[curPtr].val++;
    return curPtr++;
}

segnode firstroot = createNode(0);

int update(int id, int segl, int segr, int pos) {
    if(pos < segl || pos > segr) return id;
    if(segl == segr) return updateNode(id);
    int mid = segl + segr >> 1;
    if(pos <= mid) {
        return mergeNodes(update(nodes[id].lp, segl, mid, pos), nodes[id].rp);
    }
    else {
        return mergeNodes(nodes[id].lp, update(nodes[id].rp, mid + 1, segr, pos));
    }
}

int query(int idO, int idN, int segl, int segr, int rem) {
    assert(nodes[idN].val - nodes[idO].val >= rem);
    if(segl == segr) return segl;
    int mid = segl + segr >> 1;
    int ltot = nodes[nodes[idN].lp].val - nodes[nodes[idO].lp].val;
    if(ltot >= rem) return query(nodes[idO].lp, nodes[idN].lp, segl, mid, rem);
    else return query(nodes[idO].rp, nodes[idN].rp, mid + 1, segr, rem - ltot);
}

int v[100001];
int root[100001]{};

int main() {
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> v[i], root[i] = update(root[i-1], MN, MX, v[i]);
    while(m--) {
        int i,j,k;
        cin >> i >> j >> k;
        cout << query(root[i-1], root[j], MN, MX, k) << endl;
    }
}