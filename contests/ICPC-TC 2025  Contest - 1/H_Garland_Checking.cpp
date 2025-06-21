#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
#define SPEED std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define vi vector<int>
#define pi pair<int,int>
#define si set<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rev(i,a,b) for(int i = a;i>=b;i--)
#define vpi vector<pair<int, int> >
#define int long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
    
const int M = 1e9 + 7;
const int N = 1e5 + 1;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                DON'T MAKE CHANGES BEFORE THIS LINE!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int parent[N], sz[N];
map<pair<int, int>, pair<int, int>> x;

void make(int n) {
    parent[n] = n;
    sz[n] = 1;
}

int find(int v) {
    if(parent[v] == v) return v;
    return find(parent[v]);
}

void unite(int a, int b) {
    int tempA = a, tempB = b;
    a = find(a), b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b]; 
    if(tempA > tempB)swap(tempA,tempB);
    x[{tempA, tempB}] = {a, b};
}

void disconnect(int a, int b) {
    if(a > b)swap(a,b);
    assert(x.count({a,b}));
    int tempA = x[{a, b}].first, tempB = x[{a, b}].second;
    x.erase({a,b});
    parent[tempB] = tempB;
    while(parent[tempA] != tempA)
    sz[tempA] -= sz[tempB], tempA = parent[tempA];
    sz[tempA] -= sz[tempB];
}

void solve(){
    int n;
    cin >> n;
    rep(i,0,n) {
        make(i);
    }
    char c;
    int a, b;
    while(true) {
        cin >> c;
        if(c == 'E') break;
        cin >> a >> b;
        a--;
        b--;
        if(c == 'C') {
            unite(a, b);
        }
        else if(c == 'D') {
            disconnect(a, b);
        }
        else {
            if(find(a) == find(b)) yes;
            else no;
        }
    } 
}
    
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                DON'T MAKE CHANGES AFTER THIS LINE!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
int32_t main()
{
    solve();
    return 0;
}
