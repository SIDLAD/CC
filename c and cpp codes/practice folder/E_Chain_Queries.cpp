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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

void dfs(int node, int p, vector<int>& c, vector<vector<int>> & edges, vector<int>& parent, vector<int>& bchild)
{
    parent[node] = p;
    for(auto child: edges[node])if(child != p)
    {
        dfs(child, node, c,edges,parent,bchild);
        if(c[child])bchild[node]++;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,q;
        cin>>n>>q;
        vector<int> c(n);
        for(int i=0;i<n;i++)cin>>c[i];
        vector<int> parent(n),bchild(n);
        vector<vector<int>> edges(n);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        dfs(0,-1,c,edges,parent,bchild);
        set<int> blacks;
        set<int> bb0;
        set<int> bb2;
        set<int> bb1;
        auto check = [&]()->bool
        {
            return (blacks.size() == bb0.size() + bb1.size() + bb2.size()) and (bb2.size() == 0 or bb2.size() == 1 and(*bb2.begin() == 0 or c[parent[*bb2.begin()]] == 0)) and bb2.size() == bb0.size() - 1;
        };

        for(int i=0;i<n;i++)
        {
            if(c[i])
            {
                blacks.insert(i);
                if(bchild[i] == 0)bb0.insert(i);
                if(bchild[i] == 1)bb1.insert(i);
                if(bchild[i] == 2)bb2.insert(i);
            }
        }
        debug();
        while(q--)
        {
            int a;
            cin>>a;
            a--;
            debug(a);

            if(c[a])
            {
                blacks.erase(a);
                bb2.erase(a);
                bb1.erase(a);
                bb0.erase(a);
                if(a != 0)
                {
                    if(c[parent[a]])
                    {
                        if(bchild[parent[a]] == 2)bb2.erase(parent[a]);
                        if(bchild[parent[a]] == 1)bb1.erase(parent[a]);
                        if(bchild[parent[a]] == 0)bb0.erase(parent[a]);
                    }
                    bchild[parent[a]] --;
                    if(c[parent[a]])
                    {
                        if(bchild[parent[a]] == 2)bb2.insert(parent[a]);
                        if(bchild[parent[a]] == 1)bb1.insert(parent[a]);
                        if(bchild[parent[a]] == 0)bb0.insert(parent[a]);
                    }
                }
            }
            else
            {
                blacks.insert(a);
                if(bchild[a] == 0)bb0.insert(a);
                if(bchild[a] == 1)bb1.insert(a);
                if(bchild[a] == 2)bb2.insert(a);
                if(a != 0)
                {
                    if(c[parent[a]])
                    {
                        if(bchild[parent[a]] == 2)bb2.erase(parent[a]);
                        if(bchild[parent[a]] == 1)bb1.erase(parent[a]);
                        if(bchild[parent[a]] == 0)bb0.erase(parent[a]);
                    }
                    bchild[parent[a]] ++;
                    if(c[parent[a]])
                    {
                        if(bchild[parent[a]] == 2)bb2.insert(parent[a]);
                        if(bchild[parent[a]] == 1)bb1.insert(parent[a]);
                        if(bchild[parent[a]] == 0)bb0.insert(parent[a]);
                    }
                }
            }
            c[a] ^= 1;
            debug(blacks,bb0,bb1,bb2);
            cout(check());
        }
    }
}