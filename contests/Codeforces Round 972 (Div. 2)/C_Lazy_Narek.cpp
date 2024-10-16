#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = INT_MAX/2;
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
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

vector<char> letters = {'n','a','r','e','k'};

vector<vector<int>> compute(string& s)
{
    //first index is start
    //second index is end
    //size returned 5 x 5
    int n = s.length();
    vector<vector<int>> dp(5,vector<int>(5));
    int occurence_count = 0;
    vector<int> last_occurence(5,-1);
    for(int i=0;i<s.length();i++)
    {
        for(int j=0;j<5;j++)
        {
            if(s[i] == letters[j]){last_occurence[j] = i;occurence_count++;}
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int curidx = i; //start index
            int firstlastletter = -1;
            int ans = -occurence_count;
            int k;
            for(k=0;k<n;k++)
            {
                if(s[k] == letters[curidx])
                {
                    if(curidx == j)
                    {
                        int tmp = ((j - i  + 1 + 5) % 5);
                        if(tmp == 0)tmp = 5;
                        ans += 2 * tmp;
                        curidx = (curidx + 1)%5;
                        break;
                    }
                    curidx = (curidx + 1)%5;
                }
            }
            if(k == n)
            {
                dp[i][j] = -INF/4;
                continue;
            }
            for(;k<n;k++)
            {
                if(s[k] == letters[curidx])
                {
                    if(curidx == j)
                    {
                        ans  += 2 * 5;
                    }
                    curidx = (curidx + 1)%5;
                }
            }
            dp[i][j] = ans;
        }
    }
    return dp;
}

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
        int n,m;
        cin>>n>>m;
        vector<string> v(n);
        for(int i=0;i<n;i++)cin>>v[i];

        vector<vector<int>> dp(n+1,vector<int>(5));
        dp[0] = {-INF,-INF,-INF,-INF,0};
        vector<vector<vector<int>>> init(n,vector<vector<int>>(5,vector<int>(5)));
        for(int i=0;i<n;i++)
        {
            init[i] = compute(v[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<5;j++)
            {
                dp[i][j] = dp[i-1][j];
                for(int k=0;k<5;k++)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][k] + init[i-1][(k+1)%5][j]);
                }
                if(dp[i][j] < -INF)dp[i][j] = -INF;
            }
        }
        cout<<dp[n][4]<<endl;
    }
}