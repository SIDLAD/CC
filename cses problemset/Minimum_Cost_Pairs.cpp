#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define endl '\n' //comment out for interactive problems
#define cout(x) cout << ((x) ? "YES" : "NO") << endl
#define rep(it, start, end) for (auto it = start; it != end; ++it)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

template<typename T=int>
T input() {
    T x;
    cin >> x;
    return x;
}
const int MAXN = (int) 2e5 + 1;
int n;
vector<int> a;
set<int> remaining;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Data {
    int pt;
    int cost;
    bool operator<(const Data& other) const {
        return cost > other.cost;
    }
};

int hasher(int a, int b) {
    return a * MAXN + b;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    n = input();
    a.resize(n);
    for(int i=0;i<n;++i) cin >> a[i], remaining.insert(i);
    sort(all(a));
    debug(a);

    priority_queue<Data> pq;
    vector<int> D(n - 1);
    vector<int> L(n - 1, -1), R(n - 1, -1);

    vector<bool> valid(n - 1, true);

    for(int i=0;i<n-1;++i) {
        int pt{i};
        int cost{a[i + 1] - a[i]};
        D[i] = cost;
        pq.emplace(pt, D[i]);
    }
    for(int i=1;i<n-1;++i) L[i] = i-1, R[i - 1] = i;

    int totalCost = 0;

    while(pq.size()) {
        Data processData = pq.top();
        pq.pop();

        int i = processData.pt;
        int cost = processData.cost;
        debug();
        debug(i, cost);
        // check if data is stale
        if(!valid[i]) continue;

        debug(i, cost);

        assert(cost == D[i]);
        totalCost += cost;
        cout << totalCost << " ";

        if(L[i] != -1) valid[L[i]] = false;
        if(R[i] != -1) valid[R[i]] = false;
        if(min(L[i], R[i]) == -1) {
            valid[i] = false;
            if(R[i] + 1 and R[R[i]] + 1) L[R[R[i]]] = -1;
            if(L[i] + 1 and L[L[i]] + 1) R[L[L[i]]] = -1;
            continue;
        }

        D[i] = D[L[i]] + D[R[i]] - D[i];
        L[i] = L[L[i]];
        R[i]  = R[R[i]];
        if(L[i] != -1) R[L[i]] = i;
        if(R[i] != -1) L[R[i]] = i;
        pq.emplace(i, D[i]);
    }
}