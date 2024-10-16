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
#define N 30

int n;
vector<int> v;
int binlift[(int)2e5 + 1][N + 1];

int solve(int cur, int ancn)
{
    if(ancn == 0)return cur;
    int p = log2(ancn);
    ancn -= 1<<p;
    return solve(binlift[cur][p],ancn);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int q;
    cin>>n>>q;
    v.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];

    for(int i=1;i<=n;i++)binlift[i][0] = v[i];
    for(int i=1;i<=N;i++)for(int j=1;j<=n;j++)binlift[j][i] = binlift[binlift[j][i-1]][i-1];
    
    for(int i=0;i<q;i++)
    {
        int x,k;
        cin>>x>>k;
        cout<<solve(x,k)<<endl;
    }
}