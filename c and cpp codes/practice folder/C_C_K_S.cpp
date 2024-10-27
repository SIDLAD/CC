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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(auto& x:a)cin>>x;
        int m;
        cin>>m;
        vector<vector<int>> graph1(n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            graph1[a].push_back(b);
        }
        vector<int> b(n);
        for(auto& x:b)cin>>x;
        cin>>m;
        vector<vector<int>> graph2(n);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            graph2[a].push_back(b);
        }

        vector<int> out1(k),in1(k),out2(k),in2(k);

        vector<int> visited1(n),visited2(n);

        auto dfs = [&](auto self, int node, int kval,vector<int>& c, vector<int>& out, vector<int>& in, vector<int>& visited, vector<vector<int>>& edges)->void
        {
            if(visited[node])return;
            visited[node] = true;
            if(c[node] == 0) // incoming
            {
                in[kval]++;
            }
            else
            {
                out[kval]++;
            }
            for(auto nbr: edges[node])
            {
                self(self,nbr,(kval + 1)%k,c,out,in,visited,edges);
            }
        };
        dfs(dfs,0,0,a,out1,in1,visited1,graph1);
        dfs(dfs,0,0,b,out2,in2,visited2,graph2);

        if(accumulate(all(a),0ll) == 0 and accumulate(all(b),0ll) == n or accumulate(all(b),0ll) == 0 and accumulate(all(a),0ll) == n)
        {
            cout(true);
            continue;
        }
        vector<pair<int,int>> one(k);
        vector<pair<int,int>> two(k);
        for(int i=0;i<k;i++)
        {
            one[i] = {in1[i],out1[i]};
            two[i] = {out2[(i+k-2)%k], in2[i]};
        }
        two.insert(two.end(),two.begin(),two.end());

        vector<int> z1(k), z2(2*k);

        int l = 0,r = 0;
        for(int i=1;i<k;i++)
        {
            if(r > i)z1[i] = min(z1[i-l],r-i);
            while(i + z1[i] < k and one[i + z1[i]] == one[z1[i]])z1[i]++;
            if(i + z1[i] > r)l = i,r = i + z1[i];
        }

        l = 0,r = 0;
        for(int i=0;i<2 * k;i++)
        {
            if(r > i)z2[i] = min(z2[i-l],r-i);
            while(z2[i] < k and i + z2[i] < 2*k and two[i + z2[i]] == one [z2[i]])z2[i]++;
            if(i + z2[i] > r)l = i, r = i + z2[i];
        }
        debug(z1,z2);
        cout(*max_element(all(z2)) >= k);
    }
}