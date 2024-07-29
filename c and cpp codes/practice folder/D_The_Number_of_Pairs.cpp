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

#define double long double
#define all(x) (x).begin(),(x).end()
// #define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

int mind[(int)(2*1e7 + 1)];
int val[(int)(2*1e7 + 1)];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    memset(mind,-1,sizeof(mind));
    memset(val,-1,sizeof(val));
    val[1] = 0;
    for(int i=2;i*i <= 2*1e7; i++)
    {
        if(mind[i] != -1)continue;
        mind[i] = i;
        for(int j = i*i;j<=2*1e7;j += i)
        {
            if(mind[j] == -1)
                mind[j] = i;
        }
    }
    
    // debug("hello");
    for(int i=2; i <= 2*1e7; i++)
    {
        if(mind[i] == i or mind[i] == -1)
            val[i] = 1;
        else if(mind[i] != mind[i/mind[i]])
            val[i] = 1 + val[i/mind[i]];
        else val[i] = val[i/mind[i]];
    }


    for(;T--;)
    {
        int c,d,x;
        cin>>c>>d>>x;
        int ans = 0;
        for(int i=1;i*i <= x; i ++)if(x%i == 0)
        {
            vector<int> v({i});
            if(i!=x/i)v.push_back(x/i);
            for(auto ele: v)
            {
                int gcd = ele;
                int l = x/gcd;
                if((l + d) % c != 0) continue;
                // debug(gcd);
                int r = (l + d) / c;
                // debug(r);
                int prodsum = 1 << val[r];
                ans += prodsum;
                // debug(prodsum);
            }
        }
        // debug();
        cout<<ans<<endl;
    }
}