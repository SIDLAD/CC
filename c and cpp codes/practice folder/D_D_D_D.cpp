#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<1:cout<<0)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

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
        int n,m,l;
        cin >> n >> m >> l;
        vector<int> a(l);
        arrPut(a);
        int highestOdd = accumulate(all(a),0ll), highestEven = highestOdd;
        int minOdd = INF;
        for(auto e:a)if(e&1)minOdd = min(e,minOdd);
        if(highestOdd & 1) highestEven -= minOdd;
        else highestOdd -= minOdd;

        vector<array<int,2>> dijkstra(n + 1, {INF,INF});
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{1,0}});
        
        dijkstra[1][0] = 0;
        vector<vector<int>> edges(n + 1);
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        while(pq.size()) {
            auto [d, pr] = pq.top(); pq.pop();
            auto [index, parity] = pr;
            parity ^=1;
            d ++;
            for(auto nbr : edges[index]) {
                if(dijkstra[nbr][parity] > d) {
                    dijkstra[nbr][parity] = d;
                    pq.push({d, {nbr, parity}});
                }
            }
        }

        for(int i=1;i<=n;i++) {
            cout(dijkstra[i][0] <= highestEven || dijkstra[i][1] <= highestOdd);
        } cout<<endl;
    }
}