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
        sort(all(v));
        int g = v[0];
        for(int i=1;i<n;i++)g = gcd(v[i],g);

        if(n == 1)
        {
            if(k > v[0])cout<<k<<endl;
            else cout<<k-1<<endl;
            debug(1);
            continue;
        }
        if(g == 1)
        {
            cout<<n-1 + k<<endl;
            debug(2);

            continue;
        }
        int q = k/(g-1);
        if(q + 1 > n)
        {
            k -= (g-1)*(n-1);
            cout<<(n-1)*g + k<<endl;
            debug(3);
        }
        else
        {
            if(k == q * (g-1))
            {
                cout<<q * g - 1<<endl;
                debug(4);
            }
            else
            {
                cout<<q * g + (k%(g-1))<<endl;
                debug(5);
            }
        }
    }
}