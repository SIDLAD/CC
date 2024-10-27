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
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        sort(all(v));
        
        // vector<int> pre(n);
        // pre[0] = n*v[0];
        // for(int i=1;i<n;i++)
        // {
        //     pre[i] = (n-i) * (v[i] - v[i-1]) + pre[i-1];
        // }

        // int ll = 0;
        // int ul = n* (*max_element(all(v)));

        // while(ul - ll > 1)
        // {
        //     int mid = ll + ul >> 1;
        //     int cnt = 0;
        //     int rnd = mid/n;
        //     int rem = (mid%n);
        //     for(int i=0;i<n;i++)
        //     {
        //         cnt += min(v[i],rnd + (rem >= i + 1));
        //     }
        //     debug(mid,rnd,rem,cnt,k);
        //     if(cnt >= k) ul = mid;
        //     else ll = mid;
        // }    
        // debug();            
        // cout<<ul<<endl;

        vector<int> misses;
        misses.push_back(n*v[0] + 1);
        for(int i=1;i<n;i++)
        {
            misses.push_back((n-i) * (v[i] - v[i-1]) + misses.back() + 1);
        }
        debug(misses);

        int ll = 0;
        int ul = n* (*max_element(all(v)));

        while(ul - ll > 1)
        {
            int mid = ll + ul >> 1;
            int cnt = mid - (upper_bound(all(misses),mid) - misses.begin());
            if(cnt >= k)ul=mid;
            else ll = mid;
        }             
        cout<<ul<<endl;
    }
}