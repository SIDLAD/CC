#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/3;
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
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> e(n+1);
    vector<vector<pair<int,int>>> re(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back({b,c});
        re[b].push_back({a,c});
    }
    vector<int> djikstra1(n+1,INF),djikstra2(n+1,INF);
    priority_queue<pair<int,int>> pq;
    djikstra1[1] = 0;
    pq.push({0,1});
    while(pq.size())
    {
        auto [dist,cur] = pq.top();dist *=-1;
        pq.pop();
        if(dist != djikstra1[cur])continue; //already processed
        for(auto [nbr,wt]:e[cur])
        {
            if(djikstra1[nbr]  > dist + wt)
            {
                djikstra1[nbr] = dist + wt;
                pq.push({-djikstra1[nbr],nbr});
            }
        }
    }
    djikstra2[n] = 0;
    pq.push({0,n});
    
    while(pq.size())
    {
        auto [dist,cur] = pq.top();dist *=-1;
        pq.pop();
        if(dist != djikstra2[cur])continue; //already processed
        for(auto [nbr,wt]:re[cur])
        {
            if(djikstra2[nbr]  > dist + wt)
            {
                djikstra2[nbr] = dist + wt;
                pq.push({-djikstra2[nbr],nbr});
            }
        }
    }

    int ans = INF;

    for(int i=1;i<=n;i++)
    {
        for(auto [j,w]:e[i])
        {
            ans = min(ans,djikstra1[i] + djikstra2[j] + w/2);
        }
    }

    cout<<ans<<endl;
}