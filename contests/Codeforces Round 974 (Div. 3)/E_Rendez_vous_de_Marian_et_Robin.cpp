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
        int n,m,h;
        cin>>n>>m>>h;
        // vector<int> a(h);
        vector<int> a(n);
        for(int i=0;i<h;i++)
        {
            int x;cin>>x;
            a[x-1] = 1;
        }
        vector<vector<pair<int,int>>> edges(n);
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            edges[--a].push_back({--b,w});
            edges[b].push_back({a,w});
        }

        vector<int> mincost0(n,INF),mincostl(n,INF);
        vector<int> mincost0h(n,INF),mincostlh(n,INF);

        priority_queue<array<int,3>> pq;
        //first element is min distance, second element is if there is a horse on it. third is node. first is negative

        pq.push({0,a[0],0});
        if(a[0])mincost0h[0] = 0;
        else mincost0[0] = 0;
        while(pq.size())
        {
            auto [dist,hashorse,node] = pq.top();dist*=-1;
            pq.pop();
            if(hashorse and mincost0h[node] != dist)continue;
            if(!hashorse and mincost0[node] != dist)continue;
            hashorse |= a[node];
            for(auto [nbr,wt]: edges[node])
            {
                vector<int>& mincostar = hashorse?mincost0h:mincost0;
                if(dist + wt/(1+hashorse) < mincostar[nbr])
                {
                    mincostar[nbr] = dist + wt/(1+hashorse);
                    pq.push({-(dist + wt/(1+hashorse)), hashorse,nbr});
                }
            }
        }

        pq.push({0,a[n-1],n-1});
        if(a[n-1])mincostlh[n-1] = 0;
        else mincostl[n-1] = 0;
        while(pq.size())
        {
            auto [dist,hashorse,node] = pq.top();dist*=-1;
            pq.pop();
            if(hashorse and mincostlh[node] != dist)continue;
            if(!hashorse and mincostl[node] != dist)continue;
            hashorse |= a[node];
            for(auto [nbr,wt]: edges[node])
            {
                vector<int>& mincostar = hashorse?mincostlh:mincostl;
                if(dist + wt/(1+hashorse) < mincostar[nbr])
                {
                    mincostar[nbr] = dist + wt/(1+hashorse);
                    pq.push({-(dist + wt/(1+hashorse)), hashorse,nbr});
                }
            }
        }

        debug(mincost0,mincost0h,mincostl,mincostlh);
        int ans = INF;
        for(int i=0;i<n;i++)
        {
            mincost0[i] = min(mincost0[i],mincost0h[i]);
            mincostl[i] = min(mincostl[i],mincostlh[i]);
            ans = min(ans,max(mincost0[i] , mincostl[i]));
        }
        if(ans >= INF)
        {
            cout<<-1<<endl;
        }
        else
        cout<<ans<<endl;
    }
}