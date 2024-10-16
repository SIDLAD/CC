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
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

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
        int n;
        cin>>n;
        vector<array<int,2>> votes(n);
        for(int i=0;i<n;i++)
        {
            char x;
            cin>>x;
            if(x == 'A')votes[i][0]++;
        }
        for(int i=0;i<n;i++)
        {
            char x;
            cin>>x;
            if(x == 'A')votes[i][1]++;
        }
        vector<vector<int>> dp(n + 1,vector<int>(3,-INF));
        dp[0][0] = 0;
        int tmp;
        for(int i=0;i<n;i++)
        {
            if(i + 2 <= n)
            {
                tmp = (votes[i][0] + votes[i][1] + votes[i+1][0] > 1);
                dp[i+2][1] = max(dp[i+2][1],dp[i][0] + tmp);
                tmp = (votes[i][0] + votes[i][1] + votes[i+1][1] > 1);
                dp[i+2][2] = max(dp[i+2][2],dp[i][0] + tmp);
            }
            if(i + 1 <= n and i > 0)
            {
                tmp = (votes[i][0] + votes[i][1] + votes[i-1][0] > 1);
                dp[i+1][0] = max(dp[i+1][0],dp[i][2] + tmp);
                tmp = (votes[i][0] + votes[i][1] + votes[i-1][1] > 1);
                dp[i+1][0] = max(dp[i+1][0],dp[i][1] + tmp);
            }
            if(i + 3 <= n  and i > 0)
            {
                int lsum = (votes[i][0] + votes[i + 1][0] + votes[i + 2][0] > 1) + (votes[i-1][1] + votes[i][1] + votes[i+1][1] > 1);
                int rsum = (votes[i][1] + votes[i + 1][1] + votes[i + 2][1] > 1) + (votes[i-1][0] + votes[i][0] + votes[i+1][0] > 1);
                dp[i+3][1] = max(dp[i+3][1], dp[i][1] + lsum);
                dp[i+3][2] = max(dp[i+3][2], dp[i][2] + rsum);
            }
            if(i + 3 <= n)
            {
                int sum = (votes[i][0] + votes[i+1][0] + votes[i+2][0] > 1) + (votes[i][1] + votes[i+1][1] + votes[i+2][1] > 1);
                dp[i+3][0] = max(dp[i+3][0], dp[i][0] + sum);
            }
        }
        #ifndef cerr
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j < 3; j++)
            {
                if(dp[i][j] < -1)cerr<<-1<<" ";
                else cerr<<dp[i][j]<<" ";
            }
            cerr<<endl;
        }
        cerr<<endl;
        #endif
        cout<<dp[n][0]<<endl;
    }
}