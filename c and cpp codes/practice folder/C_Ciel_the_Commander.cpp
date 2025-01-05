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

constexpr int LIM = 1e5 + 1;

int n;
vector<int> edges[LIM];
int is_removed[LIM];
vector<pair<int,int>> ancestors[LIM];
int subsz[LIM];

void set_subsz(int node, int parent = -1)
{
    subsz[node] = 1;
    for(auto child: edges[node])if(!is_removed[child] and child != parent)
    {
        set_subsz(child,node);
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

void set_ancestor(int node, int centroid, int parent = -1, int dist = 0)
{
    for(auto child: edges[node])if(!is_removed[child] and child != parent)
    {
        set_ancestor(child, centroid, node, dist + 1);
    }
    ancestors[node].emplace_back(centroid,dist);
}

void centroid_decomposition(int node = 1)
{
    set_subsz(node);
    int centroid = get_centroid(node, subsz[node]);
    is_removed[centroid] = 1;
    set_ancestor(centroid,centroid);
    for(auto nxt: edges[centroid])if(!is_removed[nxt])centroid_decomposition(nxt);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    centroid_decomposition();
    for(int i=1;i<=n;i++)
    {
        cout<<(char)('A' - 1 + ancestors[i].size())<<" ";
    }
    cout<<endl;
}