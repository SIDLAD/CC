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
        int n,m;
        cin>>n>>m;
        int tevent,tcs,tce;
        cin>>tevent>>tcs>>tce;
        vector<vector<array<int,3>>> edgel(n+1);
        for(int i=0;i<m;i++)
        {
            int u,v,l1,l2;
            cin>>u>>v>>l1>>l2;
            edgel[u].push_back({v,l1,l2});
            edgel[v].push_back({u,l1,l2});
        }

        vector<int> djikstra(n+1,-INF);
        priority_queue<pair<int,int>> pq;
        pq.push({tevent,n});
        djikstra[n] = tevent;
        while(pq.size())
        {
            auto [time, node] = pq.top();
            pq.pop();
            if(djikstra[node] != time)continue;
            debug(time,node);
            for(auto [nbr,bus,walk]: edgel[node])
            {
                int ntime;
                
                if(time - bus < tce and tcs < time)
                    ntime = max(time - walk,tcs - bus);
                else
                    ntime =  time - bus;
                if(ntime > djikstra[nbr])
                {
                    djikstra[nbr] = ntime;
                    pq.push({ntime,nbr});
                }
            }
        }
        cout<<max(djikstra[1],-1ll)<<endl;
    }
}