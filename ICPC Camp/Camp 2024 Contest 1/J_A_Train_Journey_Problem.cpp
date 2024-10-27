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
#define all(x) (x).begin(),(x).dest()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int n,m,start,dest;
vector<vector<array<int,3>>> edges;

const int XMAX = 5 * 1e6;
int isprime[XMAX + 1];
vector<int> primes;
void sieve()
{
    memset(isprime,1,sizeof(isprime));
    primes.push_back(0),primes.push_back(1);
    for(int i=2;i<=XMAX;i++)
    {
        if(isprime[i])primes.push_back(i);
        for(int j = i*i; j <=XMAX; j+= i)
        {
            isprime[j] = false;
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    sieve();
    debug(primes.back());
    cin>>n>>m>>start>>dest;
    start--,dest--;
    edges.resize(n);
    for(int i=0;i<m;i++)
    {
        int a,b,s,c;
        cin>>a>>b>>s>>c;
        a--,b--;
        edges[a].push_back({b,s,c});
    }

    int ll = 0,llv = 0;
    int ul = primes.size();
    while(ul -ll > 1)
    {
        int mid = ll + ul >> 1;
        vector<int> djikstra(n,INF);
        djikstra[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,start);
        while(pq.size())
        {
            auto [cost, node] = pq.top();pq.pop();
            if(djikstra[node] != cost)continue;
            for(auto [nbr,space,price]: edges[node])if(space >= primes[mid])
            {
                if(cost + price < djikstra[nbr])
                {
                    djikstra[nbr] = cost + price;
                    pq.emplace(djikstra[nbr],nbr);
                }
            }
        }
        if(djikstra[dest] == INF)ul = mid;
        else ll = mid,llv = djikstra[dest];
    }
    cout<<primes[ll]<<" "<<llv*primes[ll]<<endl;
}