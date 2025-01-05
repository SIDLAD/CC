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

struct info
{
    map<int,set<int>> distinds;
    map<int,int> freq;

    static info* merge(info* a, info* b)
    {
        if(a->freq.size() < b->freq.size())swap(a,b);
        for(auto [ele,f]:b->freq)
        {
            a->distinds[a->freq[ele]].erase(ele);
            if(a->distinds[a->freq[ele]].empty())a->distinds.erase(a->freq[ele]);
            a->freq[ele] += f;
            a->distinds[a->freq[ele]].insert(ele);
        }

        delete b;
        return a;
    }

    static info* createnewinfo(int newd)
    {
        info* val = new info;
        val->distinds[1].insert(newd);
        val->freq[newd] = 1;
        return val;
    }
};

vector<vector<int>> edges;
vector<int> depths;
vector<int> answer;

info* dfs(int node, int p, int curd)
{
    depths[node] = curd;
    info* inode = info::createnewinfo(curd);
    for(auto nbr:edges[node])if(nbr != p)
    {
        inode = info::merge(dfs(nbr,node,curd + 1),inode);
    }
    answer[node] = *(inode->distinds.rbegin()->second.begin()) - curd;
    return inode;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    edges.resize(n + 1);
    depths.resize(n  + 1);
    answer.resize(n + 1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    delete dfs(1,1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<answer[i]<<endl;
    }
}