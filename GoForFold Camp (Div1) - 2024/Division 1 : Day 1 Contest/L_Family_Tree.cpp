#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

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
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;


struct Hash {
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t step;
  static vector<uint64_t> pw;

  uint64_t addmod(uint64_t a, uint64_t b) const {
    a += b;
    if (a >= md) a -= md;
    return a;
  }

  uint64_t submod(uint64_t a, uint64_t b) const {
    a += md - b;
    if (a >= md) a -= md;
    return a;
  }

  uint64_t mulmod(uint64_t a, uint64_t b) const {
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret =
        (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }

  void ensure_pw(int sz) {
    int cur = (int)pw.size();
    if (cur < sz) {
      pw.resize(sz);
      for (int i = cur; i < sz; i++) {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }

  vector<uint64_t> pref;
  int n;

  template <typename T>
  Hash(const T& s) {
    n = (int)s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
    }
  }

  inline uint64_t operator()(const int _from = -1, const int _to = -1) const {
    int from = _from;
    int to = _to;
    if(from == -1)
    {
        from = 0;
        to = n - 1;
    }
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
uint64_t Hash::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> Hash::pw = vector<uint64_t>(1, 1);

struct info
{
    map<int,set<int>> mp;
    int sz;

    info(int hashval, int depth):sz(1){
        mp[depth].insert(hashval);
    }

    static info* mergeinfo(info* a, info* b)
    {
        if(b->sz > a->sz)swap(a,b);
        for(auto [freq,st]: b->mp)
        {
            for(auto ele:st){
                if(a->mp[freq].count(ele));
                else
                {
                    a->mp[freq].insert(ele);
                    a->sz++;
                }
            }
        }

        delete b;
        return a;
    }
};

vector<int> ans;
vector<vector<int>> edges;
vector<vector<pair<int,int>>> queries;
vector<int> name;

info* dfs(int cur, int depth = 0){
    info* curinfo = new info(name[cur],depth);
    for(auto child: edges[cur])
    {
        curinfo = info::mergeinfo(curinfo,dfs(child,depth + 1));
    }
    for(auto [kd,i]:queries[cur])
    {
        ans[i] = curinfo->mp[depth + kd].size();
    }
    return curinfo;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> p(n);
    name.resize(n);
    edges.resize(n);
    vector<int> roots;
    for(int i=0;i<n;i++)
    {
        string s1;
        cin>>s1;
        name[i] = Hash(s1)();
        cin>>p[i];
        p[i]--;
        if(p[i] == -1)roots.push_back(i);
        else edges[p[i]].push_back(i);
    }
    debug(name);

    int m;
    cin>>m;
    queries.resize(n);
    ans.resize(m);
    range(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        a--;
        queries[a].push_back({b,i});
    }
    for(auto root: roots)
    delete dfs(root);
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<endl;
    }
}