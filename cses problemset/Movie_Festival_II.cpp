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
    int n,k;
    cin>>n>>k;
    int ans = n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    int activecount=0;
    set<pair<int,int>> r;
    vector<int> active(n);
    vector<array<int,3>> pts;
    for(int i=0;i<n;i++)
    {
        pts.push_back({v[i].first,1,i});
        pts.push_back({v[i].second,0,i});
    }
    sort(all(pts));
    for(int i=0;i<2*n;i++)
    {
        auto [loc,o,idx] = pts[i];
        if(o)
        {
            activecount++;
            active[idx] =1 ;
            r.insert({v[idx].second,idx});
            if(activecount > k)
            {
                auto [rval,delidx]=*(--r.end());
                r.erase(--r.end());
                activecount--;
                active[delidx] = 0;
                ans --;
            }
        }
        else if(active[idx])
        {
            activecount--;
            active[idx] = 0;
        }
    }
    cout<<ans<<endl;
}