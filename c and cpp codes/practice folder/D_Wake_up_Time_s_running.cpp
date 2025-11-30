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

// #define int long long
// #define double long double
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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int hasher(pair<int,int> xy) {
    auto [x,y] = xy;
    return x * 3000 + y;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    --sx, --sy;
    vector<vi> grid(n, vi(n));
    umap<int,pii> tmp;
    umap<int, pii> extra;
    rep(i,0,n) rep(j,0,n) {
        cin >> grid[i][j];
        if(grid[i][j] and tmp.find(grid[i][j]) != tmp.end())
            extra[hasher({i,j})] = tmp[grid[i][j]],
            extra[hasher(tmp[grid[i][j]])] = {i,j};
        if(grid[i][j])
            tmp[grid[i][j]] = {i,j};
    }
    deque<array<int,3>> q;
    vector<vi> visited(n, vi(n));
    q.push_back({sx, sy, 0});
    int ans;
    while(q.size()) {
        auto [curx, cury, time] = q.front();
        q.pop_front();
        if(visited[curx][cury]) 
            continue;
        visited[curx][cury] = 1;
        if(min(curx, cury) == 0 or max(curx, cury) == n-1) {
            ans = time + 1;
            break;
        }
        for(int i=0;i<4;++i) {
            q.push_back({curx + dx[i], cury + dy[i], time + 1});
        }
        if(extra.find(hasher({curx, cury})) != extra.end()) {
            auto [nxtx, nxty] = extra[hasher({curx, cury})];
            q.push_front({nxtx, nxty, time});
        }
    }
    cout (ans <= m);
}