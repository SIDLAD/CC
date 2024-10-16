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
    freopen("subsonic_subway_validation_input.txt","r",stdin);
    freopen("A_output.txt","w",stdout);
    int T;
    cin>>T;
    int TT = 1;
    for(;T--;TT++)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        pair<double,double> allowed_speed = {INF,-INF};
        // debug(allowed_speed);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
            double start = (i + 1) * 1.0/ v[i].first;
            if(v[i].first == 0)start = INF;
            double end = (i + 1)*1.0 /v[i].second;
            if(v[i].second == 0)end = INF;
            // debug(start,end);
            allowed_speed.first = min(allowed_speed.first,start);
            allowed_speed.second = max(allowed_speed.second,end);
            // debug(allowed_speed);
        }
        cout<<"Case #"<<TT<<": ";
        if(allowed_speed.first < allowed_speed.second)cout<<-1<<endl;
        else cout<<allowed_speed.second<<endl;
    }
}