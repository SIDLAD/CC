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

constexpr int LIM = 210;

int a[LIM][LIM];
int dp[LIM][LIM][LIM];
int fin_dp[LIM][LIM];
int _[LIM + 1];
int* pre = _ + 1;

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
        int n,m,kk;
        cin>>n>>m>>kk;

        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j],fin_dp[i][j] = INF;
        for(int i=0;i<n;i++)for(int k=0;k<m;k++)for(int j=0;j<m;j++)dp[i][j][k] = INF;

        for(int i=0;i<n;i++)
        {
            for(int shift=0;shift<m;shift++)
            {
                int sum = 0;
                for(int j=0;j<m;j++)
                {
                    pre[j] = a[i][j] + (j == 0 ? 0 : pre[j-1]);
                    for(int k=0;k<=j;k++)
                    {
                        dp[i][k][j] =min(pre[j] - pre[k-1] + shift * kk,dp[i][k][j]);
                    }
                }

                rotate(a[i],a[i] + 1,a[i] + m);
            }
            
            if(i == 0)
            {
                for(int j = 0;j<m;j++)fin_dp[i][j] = dp[i][0][j];
            }
            else
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    fin_dp[i][j] = min(fin_dp[i][j],fin_dp[i-1][k] + dp[i][k][j]);
                }
            }
        }
        cout<<fin_dp[n-1][m-1]<<endl;
    }
}