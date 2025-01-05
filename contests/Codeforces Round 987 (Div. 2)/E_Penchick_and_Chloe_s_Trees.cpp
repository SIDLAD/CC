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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

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
    int T;
    cin>>T;
    for(;T--;)
    {
        int n;
        cin>>n;
        vector<vector<int>> edges(n + 1);
        vector<int> p(n + 1);
        range(i,2,n+1)cin>>p[i];
        range(i,2,n+1)
        {
            edges[i].push_back(p[i]);
            edges[p[i]].push_back(i);
        }
        // debug(edges);

        vector<int> tempdist(n + 1);
        auto dfs_temp = [&](auto self,int cur, int prev, int depth)->void
        {
            tempdist[cur] = depth;
            for(auto nbr:edges[cur])if(nbr != prev)
            {
                self(self,nbr,cur,depth + 1);
            }
        };

        dfs_temp(dfs_temp,1,1,1);

        // int id = max_element(all(tempdist)) - tempdist.begin();
        // tempdist.assign(n + 1,0);
        // dfs(dfs,id,id,1);
        int dia = *max_element(all(tempdist));
        // debug(dia);

        int ans = (int)ceill(log2l(n + 1) - 1);
        ans = max({dia/2,ans,0ll});

        vector<int> dp(n + 1);
        // vector<int> mxhtdown(n + 1);
        
        auto dfs = [&](auto self, int cur, int prev)->void
        {
            int childcount = 0;
            priority_queue<int,vector<int>,greater<int>> cdepths;
            int ans = 0;
            for(auto c:edges[cur])if(c != prev)
            {
                self(self,c,cur);
                childcount++;
                cdepths.push(dp[c]);
                ans = max(ans,dp[c]);
            }
            if(childcount == 0)
            {
                dp[cur] = 0;
                return;
            }
            while(cdepths.size() > 2)
            {
                ans = max(ans,cdepths.top());
                int cur = cdepths.top();
                cdepths.pop();
                if(cdepths.size() == 0)break;
                int cur2 = cdepths.top();
                cdepths.pop();
                cdepths.push(1 + max(cur,cur2));
                ans = max(1 + max(cur,cur2),ans);
            }

            dp[cur] = 1 + ans;
        };
        dfs(dfs,1,1);
        debug(dp);
        cout<<dp[1]<<endl;
    }
}