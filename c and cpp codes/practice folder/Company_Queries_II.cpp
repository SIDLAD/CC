#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

#define POLICY_MACRO
#include <bits/extc++.h>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int node, vector<int>* edges, int& timer, vector<pii>& inout) {
    inout[node].first = timer++;
    for(auto nbr: edges[node]) {
        dfs(nbr, edges, timer, inout);
    }
    inout[node].second = timer++;
}

bool inCheck(pii big, pii small) {
    return big.first <= small.first && big.second >= small.second;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int n,q;
    cin >> n >> q;
    int lgn = bit_width(unsigned(n - 1));
    int binlift[lgn][n + 1];
    binlift[0][1] = 1;
    vector<int> edges[n + 1];
    for(int i=2;i<=n;++i) {
        cin >> binlift[0][i];
        edges[binlift[0][i]].push_back(i);
    }

    for(int i=1;i<lgn;++i) for(int j=1;j<=n;++j) binlift[i][j] = binlift[i-1][binlift[i-1][j]];

    int timer = 0;
    vector<pii> inout(n + 1);
    dfs(1, edges, timer, inout);

    while(q--) {
        int a,b;
        cin >> a >> b;
        int l = a;
        for(int i=lgn - 1; i>=0;--i) {
            if(inCheck(inout[binlift[i][l]], inout[b]));
            else l = binlift[i][l];
        }

        if(inCheck(inout[l], inout[b])) cout << l << endl;
        else cout << binlift[0][l] << endl;
    }
}