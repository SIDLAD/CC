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

using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

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
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];

        int lb = *min_element(all(v));
        int ub = *max_element(all(v)) + 1;
        while(ub - lb > 1)
        {
            int mid = lb + ub >> 1;
            vector<int> b = v;
            for_each(all(b), [&](int &ele){ele = mid > ele;});
            vector<int> dp(n);
            for(int i=0;i<n;i++)
            {
                if(i%k == 0)
                    dp[i] = min(i-k>=0?dp[i-k]:INF, b[i]);
                else
                    dp[i] = min(i-k>=0?dp[i-k]:INF, dp[i-1] + b[i]);
            }
            if(dp.back() < ((n-1)%k + 1 + 1)/2) lb = mid;
            else ub = mid;
        }
        cout<<lb<<endl;
    }
}