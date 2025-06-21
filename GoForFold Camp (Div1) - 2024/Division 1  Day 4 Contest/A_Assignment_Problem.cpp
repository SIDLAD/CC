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

// #define int long long
// #define double long double
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

bool active[1001];
bool satisfies[1001];
int curpos[12];
int taken[12];
int n,m;

vector<vector<int>> pref;

void dfs(int poscnt = 0)
{
    if(poscnt == m)
    {
        for(int i=0;i<m;i++)
        {
            satisfies[taken[i]] = true;
        }
        return;
    }
    
    int curposchange = 0;
    for(int i=0;i<m;i++)if(!taken[i])
    {
        while(curpos[i] < n and active[pref[i][curpos[i]]])curpos[i]++,curposchange++;

        if(curpos[i] < n)
        {
            active[pref[i][curpos[i]]] = true;
            taken[i] = pref[i][curpos[i]];
            curpos[i]++;
            dfs(poscnt + 1);

            curpos[i]--;
            taken[i] = false;
            active[pref[i][curpos[i]]] = false;
        }

        curpos[i] -= curposchange;
        curposchange = 0;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    pref.resize(m,vector<int>(n));
    for(int i=0;i<m;i++)arrPut(pref[i]);
    dfs();
    cout<<accumulate(satisfies + 1,satisfies + n + 1,0ll)<<endl;
    for(int i=1;i<=n;i++)if(satisfies[i])
    {
        cout<<i<<" ";
    }
    cout<<endl;
}