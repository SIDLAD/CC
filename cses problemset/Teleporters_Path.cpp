#include <bits/stdc++.h>
const long double EPS = 1e-7;
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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int n,m;
vector<vector<pair<int,int>>> edges;
vector<forward_list<int>::iterator> iterind;

signed main()
{
    cin>>n>>m;
    edges.resize(n);
    vector<int> ind(n),outd(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        edges[a].push_back({b,i});
        outd[a]++,ind[b]++;
    }
    vector<int> mark(n);
    for(int i=0;i<n;i++)
    {
        if(ind[i] + (i==0) != outd[i] + (i == n-1)){cout<<"IMPOSSIBLE"<<endl;return 0;}
        else if(!edges[i].size())mark[i] = 1;
    }
    vector<int> seen(m);
    vector<int> revans;
    auto dfs = [&](auto self, int node)->void
    {
        mark[node] = 1;
        while(edges[node].size())
        {
            auto [next,id] = edges[node].back();
            edges[node].pop_back();
            if(seen[id])continue;
            seen[id] = 1;
            self(self,next);
        }
        revans.push_back(node);
    };
    dfs(dfs,0);
    debug(revans);
    if(*min_element(all(mark)) == 0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    reverse(all(revans));
    for(int ele:revans)cout<<ele+1<<" ";
}