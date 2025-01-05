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

const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;

vector<int> eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vector<int> pr;
	range(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    eratosthenesSieve(5e6);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n;
        cin>>n;
        vector<vector<int>> edges(n + 1);
        vector<int> assignment(n + 1);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        set<int> oddst,evenst;

        for(int i=2;i<=2*n;i++)if(i&1)oddst.insert(i);else evenst.insert(i);

        vector<int> parent(n + 1);
        auto dfs = [&](auto self,int cur, int p)->void
        {
            parent[cur] = p;
            if(p == cur)assignment[cur] = 1;
            else
            {
                int prevass = assignment[parent[cur]];
                if(oddst.count(prevass - 1) or evenst.count(prevass - 1))
                {
                    assignment[cur] = prevass - 1;
                    oddst.erase(assignment[cur]);
                    evenst.erase(assignment[cur]);
                }
                else if(oddst.count(prevass + 1) or evenst.count(prevass + 1))
                {
                    assignment[cur] = prevass + 1;
                    oddst.erase(assignment[cur]);
                    evenst.erase(assignment[cur]);
                }
                else if(prevass & 1 and oddst.size() and prevass - *oddst.begin() >= 4)
                {
                    assignment[cur] = *oddst.begin();
                    oddst.erase(assignment[cur]);
                }
                else if(prevass & 1 and oddst.size() and *oddst.rbegin() - prevass >= 4)
                {
                    assignment[cur] = *oddst.rbegin();
                    oddst.erase(assignment[cur]);
                }
                else if(~prevass & 1 and evenst.size() and prevass - *evenst.begin() >= 4)
                {
                    assignment[cur] = *evenst.begin();
                    evenst.erase(assignment[cur]);
                }
                else if(~prevass & 1 and evenst.size() and *evenst.rbegin() - prevass >= 4)
                {
                    assignment[cur] = *evenst.rbegin();
                    evenst.erase(assignment[cur]);
                }                
            }
            outer:
            assert(assignment[cur]);
            for(auto c:edges[cur])if(c != p)
            {
                self(self,c,cur);
            }
        };

        dfs(dfs,1,1);

        for(int i=1;i<=n;i++)cout<<assignment[i]<<" \n"[i==n]; 
    }
}