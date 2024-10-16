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
        int ul = n;
        int ll = 0;
        while(ul - ll > 1)
        {
            int x = ll + ul >> 1;
            int sum = (k + x) * (n -1 - x) + (n -1 - x) * (n - x) / 2;
            sum -= k * (x + 1) + x* (x + 1) / 2;
            if(sum < 0)ul = x;
            else ll = x;
        }

        debug(ul,ll);
        int xmin = abs((k + ll) * (n -1 - ll) + (n -1 - ll) * (n - ll) / 2 - (k * (ll + 1) + ll* (ll + 1) / 2));
        if(ul!=n)
        xmin = min(xmin, abs((k + ul) * (n -1 - ul) + (n -1 - ul) * (n - ul) / 2 - (k * (ul + 1) + ul* (ul + 1) / 2)));
        cout<<xmin<<endl;
    }
}