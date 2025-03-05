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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
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
    int TT = 1;
    for(;T--;TT++)
    {
        int n,m;
        cin>>n>>m;
        vector<int> p(n);
        arrPut(p);
        vector<int> h(n);
        arrPut(h);
        vector<vector<int>> edges(n);
        for(int i=0;i<n-1;i++){
            int a,b;
            cin >> a >> b;
            a--,b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        vector<int> subtreesz(n,0);
        auto dfs1 = [&](auto self, int cur, int parent)->void
        {
            subtreesz[cur] = p[cur];
            for(auto c : edges[cur])if(c != parent){
                self(self,c,cur);
                subtreesz[cur] += subtreesz[c];
            }
        };
        dfs1(dfs1,0,0);

        vector<int> happypplcnt(n);
        for(int i=0;i<n;i++)happypplcnt[i] = subtreesz[i] + h[i] >> 1;
        bool check = true;
        for(int i=0;i<n;i++){
            if((subtreesz[i] + h[i])%2 != 0 or (subtreesz[i] + h[i] < 0) or ((subtreesz[i] + h[i]) / 2 > subtreesz[i])){
                check = false;
                break;
            }
        }
        if(!check){
            cout(false);
            continue;
        }

        auto dfs2 = [&](auto self, int cur, int parent)->bool{
            int hpccur = 0;
            for(auto c : edges[cur])if(c != parent){
                if(! self(self, c, cur))return false;
                hpccur += happypplcnt[c];
            }
            if(hpccur > happypplcnt[cur])return false;
            return true;
        };


        cout(dfs2(dfs2,0,0));
    }
}