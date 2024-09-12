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

map<int,int>& create(int val, int depth)
{
    map<int,int>& mp = *new map<int,int>();
    mp[depth] = val;
    return mp; 
}
map<int,int>& create()
{
    map<int,int>& mp = *new map<int,int>();
    return mp; 
}

map<int,int>& merge(map<int,int>& m1, map<int,int>& m2)
{
    if(m1.size() > m2.size())
    {
        swap(m1,m2);
    }
    for(auto [id,v]:m1)
    {
        m2[id] += v;
    }
    
    delete &m1;
    return m2;
}

map<int,int>& dfs(int node, int depth, vector<vector<int>>& children,vector<int>&v, int& cost, vector<int>& closest_leaf)
{
    if(!children[node].size())
    {
        return create(1e13,depth);
    }
    else
    {
        map<int,int>* combo = &create();
        int b = - v[node];
        for(auto child: children[node])
        {
            combo = &merge(*combo,dfs(child,depth+1,children,v,cost,closest_leaf));
            b += max(0ll,v[child]);
        }
        while(b < 0)
        {
            int temp;
            auto& [d,val] = *(combo->begin());
            temp = min(abs(b),val);
            b += temp;
            val -= temp;
            if(val == 0)combo->erase(combo->begin());
            cost += (d - depth) * temp;
        }
        if(b > 0)(*combo)[depth] += b;
        return *combo;
    }
}

void dfs2(int node, vector<vector<int>>& children, vector<int>& closest_leaf)
{
    if(!children[node].size()){
        return;
    }

    int ans = INF;
    for(auto child: children[node])
    {
        dfs2(child,children,closest_leaf);
        ans = min(ans,closest_leaf[child] + 1);
    }
    closest_leaf[node] = ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    int n;
    for(int TT = 1;cin>>n;TT++)
    {
        vector<int> v(n);
        for(auto& a: v)cin>>a;
        vector<vector<int>> children(n);
        vector<int> closest_leaf(n);
        for(int i=0;i<n-1;i++)
        {
            int x;
            cin>>x;
            children[--x].push_back(i+1);
        }
        dfs2(0,children,closest_leaf);
        int cost = 0;
        delete &dfs(0,0,children,v,cost,closest_leaf);

        cout<<cost<<endl;
    }
}