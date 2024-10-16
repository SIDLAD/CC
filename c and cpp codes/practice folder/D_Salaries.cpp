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



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> parent(n + 1);
    vector<vector<int>> children(n + 1);
    for(int i=2;i<=n;i++)cin>>parent[i],children[parent[i]].push_back(i);

    vector<int> purview(n + 1);

    auto dfs = [&](auto self, int cur)->pair<int,int>
    {
        pair<int,int> mx = {-1,-INF};
        for(auto child: children[cur])
        {
            auto ret = self(self,child);
            if(ret.second > mx.second)mx = ret;
        }
        if(mx.first == -1)
        {
            purview[cur] = 1;
            mx = {cur,1};
            return mx;
        }
        else
        {
            purview[mx.first] ++;
            mx.second++;
            return mx;
        }
    };
    dfs(dfs,1);
    sort(all(purview));
    int ans = 0;
    for(int i=0;i<k;i++)
    {
        ans += purview.back();
        purview.pop_back();
    }
    cout<<ans<<endl;
}