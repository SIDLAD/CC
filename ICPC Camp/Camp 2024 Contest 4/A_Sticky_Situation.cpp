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
#define cout(x) x?cout<<"S"<<endl:cout<<"N"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m,w;
    cin>>n>>m>>w;
    vector<vector<int>> edges(w + 2);
    //w -> left or top wall
    //w + 1 -> right or down wall
    vector<array<int,3>> circles(w);
    for(int i=0;i<w;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        circles[i] = {x,y,r};
        if(x - r <= 0 or y + r >= m)
        {
            edges[w+1].push_back(i);
            edges[i].push_back(w+1);
        }
        if(x + r >= n or y - r <= 0)
        {
            edges[w].push_back(i);
            edges[i].push_back(w);
        }

        for(int j=0;j<i;j++)
        {
            if((x - circles[j][0]) * (x - circles[j][0]) + (y - circles[j][1])*(y - circles[j][1]) <= (r + circles[j][2]) *  (r + circles[j][2]))
            {
                edges[j].push_back(i);
                edges[i].push_back(j);
            }
        }
    }

    vector<int> visited(w + 2);

    auto dfs = [&](auto self,int node, int tgtnode)->bool
    {
        visited[node] = true;
        if(node == tgtnode)return true;
        for(auto nbr: edges[node])if(!visited[nbr])
        {
            if(self(self,nbr,tgtnode))return true;
        }
        return false;
    }
    ;
    cout(!dfs(dfs,w,w+1));
}