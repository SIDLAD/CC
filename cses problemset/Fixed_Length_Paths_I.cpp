#include <bits/stdc++.h>
const long double EPS = 1e-10;
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

constexpr int LIM = 2e5 + 1;

int n,k;
vector<int> edges[LIM];
bool is_removed[LIM] = {};
int subsz[LIM] = {};

int ans = 0;
int mxdepth = 0;
int cnt[LIM] = {};
int curcnt[LIM] = {};

void set_subsz(int node, int parent = -1, int depth = 0)
{
    mxdepth = max(mxdepth, depth);
    subsz[node] = 1;
    for(auto child: edges[node])if(!is_removed[child] and child != parent)
    {
        set_subsz(child,node, depth + 1);
        subsz[node] += subsz[child];
    }
}

int get_centroid(int node, int totsz, int parent = -1)
{
    for(auto child: edges[node])if(!is_removed[child] and child != parent)
    {
        if(subsz[child] > totsz/ 2)return get_centroid(child,totsz,node);
    }
    return node;
}

void getcnt(int node, int parent = -1, int depth = 1)
{
    curcnt[depth]++;
    for(auto child: edges[node]) if(!is_removed[child] and child != parent)
    {
        getcnt(child,node, depth + 1);
    }
}

void centroid_decomposition(int node = 1)
{
    mxdepth = 0;
    set_subsz(node);
    int centroid = get_centroid(node, subsz[node]);
    is_removed[centroid] = 1;
    fill(cnt,cnt + mxdepth + 1,0ll);
    cnt[0] = 1;
    for(auto nxt: edges[centroid])if(!is_removed[nxt])
    {
        fill(curcnt,curcnt + mxdepth + 1, 0ll);
        getcnt(nxt);
        for(int i= max(0ll,k - mxdepth);i<=min(mxdepth,k);i++)
        {
            ans += cnt[i] * curcnt[k-i];
        }
        for(int i=0;i<=mxdepth;i++)
        {
            cnt[i] += curcnt[i];
        }
    }
    for(auto nxt: edges[centroid])if(!is_removed[nxt])centroid_decomposition(nxt);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("tmp_input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    centroid_decomposition();
    cout<<ans<<endl;
}