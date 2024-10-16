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
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        map<int,int> mp;
        int cnt = 0;
        set<int> down,up;
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
            mp[v[i].first] ++;
            if(mp[v[i].first] == 2)cnt++;
            if(v[i].second == 0)down.insert(v[i].first);
            else up.insert(v[i].first);
        }
        int ans = cnt * (n-2);
        
        sort(all(v));
        for(int i=0;i<n;i++)
        {
            if(v[i].second == 1)
            {
                if(down.count(v[i].first + 1) and up.count(v[i].first + 2))ans++;
            }
            else
            {
                if(up.count(v[i].first + 1) and down.count(v[i].first + 2))ans++;
            }
        }

        cout<<ans<<endl;
    }
}