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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

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
        int n,m,v;
        cin>>n>>m>>v;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        vector<int> left(n);
        vector<int> right(n);
        vector<int> pre(n);

        int lacc = 0;
        for(int i=0;i<n;i++)
        {
            if(lacc + a[i] >= v)
            {
                left[i] = (i==0?0:left[i-1]) + 1;
                lacc = 0;
            }
            else left[i] = (i==0?0:left[i-1]),lacc += a[i];
            pre[i] = (i==0?0:pre[i-1]) + a[i];
        }
        int racc = 0;

        map<int,int> rlc;
        for(int i=n-1;i>=0;i--)
        {
            if(racc + a[i] >= v)
            {
                right[i] = (i==n-1?0:right[i+1]) + 1;
                racc=0;
            }
            else right[i] = (i==n-1?0:right[i+1]), racc += a[i];
            if(rlc.count(right[i]) == 0)rlc[right[i]] = i;
        }

        if(left[n-1] < m)
        {
            cout<<-1<<endl;
            continue;
        }

        debug(right);

        int ans = 0;
        for(int i=-1;i<n-1;i++)
        {
            int l = i + 1;
            int rem = m - (i == -1 ?0:left[i]);
            if(rem == 0)
            {
                ans = max(ans,pre[n-1] - (i==-1?0:pre[i]));
            }
            else
            {
                if(rlc.count(rem))
                {
                    if(rlc[rem] < l + 1)continue;
                    debug(rem,rlc[rem]);
                    int sum = pre[rlc[rem] - 1] - (i == -1?0 : pre[i]);
                    ans = max(ans,sum);
                }
            }
        }
        cout<<ans<<endl;
    }
}