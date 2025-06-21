#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int n,i,j;

// vector<int> activity;
vector<int> solution;


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>i>>j;
    // activity.resize(n);
    solution.resize(2 * n + 1,INF);

    vector<int> insertedalready(2 * n + 1);

    queue<pair<int,int>> q;
    q.push({i,0});
    insertedalready[i] = 1;
    while(q.size())
    {
        auto [cur,curans] = q.front();q.pop();
        solution[cur] = curans;
        int nxt1,nxt2;
        if(cur > n)nxt1 = 2 * (cur - n);
        else nxt1 = 2* cur - 1;
        nxt2 = cur % 2 == 0 ? cur - 1 : cur + 1;
        if(!insertedalready[nxt1])
        {
            insertedalready[nxt1] = 1;          
            q.push({nxt1,curans + 1});
        }
        if(nxt2 != nxt1 and !insertedalready[nxt2])
        {
            insertedalready[nxt2] = 1; 
            q.push({nxt2,curans + 1});
        }
    }

    cout<<solution[j]<<endl;
}