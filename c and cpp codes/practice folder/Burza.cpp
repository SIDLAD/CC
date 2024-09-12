#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    
    #define debug(x...) (_exe(x))
    
    class CNothing {};

    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&)
    {
        return proxy;
    }

    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
    {
        return proxy;
    }
    CNothing cnothing;
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"DA"<<endl:cout<<"NE"<<endl

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dnodes(k+1);
    vector<vector<int>> edges(n+1);
    vector<pair<int,int>> ranges(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    if(k*k >= n)
    {
        cout(true);
        return 0;
    }
    int leafnum = 0;
    auto dfs = [&](auto self, auto node, auto p, int depth)->pair<int,int>
    {
        if(depth == k)
        {
            debug(node);
            ranges[node] = make_pair(leafnum,leafnum);leafnum++;
            dnodes[depth].push_back(node);
            return ranges[node];
        }
        pair<int,int> ori = {-1,-1};
        for(auto child: edges[node])if(child!=p)
        {
            pair<int,int> tmp = self(self,child,node,depth+1);
            if(tmp.first == -1)continue;

            if(ori.first == -1)ori = tmp;
            else ori.second = tmp.second;
        }
        if(ori.first != -1)dnodes[depth].push_back(node);
        return ranges[node] = ori;
    };
    dfs(dfs,1,-1,0);
    debug(ranges, leafnum);
    assert(ranges[1] == make_pair(0ll,leafnum-1));
    vector<int> bitmask(1<<k);

    for(int i=0;i<(1<<k);i++)
    {
        for(int j=0;j<k;j++)if(!((1<<j)&i))
        {
            bitmask[i|(1<<j)] = max(bitmask[i|(1<<j)], bitmask[i]);
            for(auto node: dnodes[j+1])
            {
                auto range = ranges[node];
                if(range.first <=bitmask[i] and range.second + 1 > bitmask[i|(1<<j)])bitmask[i|(1<<j)] = range.second + 1;
            }
        }
    }
    cout(bitmask.back() == leafnum);
}