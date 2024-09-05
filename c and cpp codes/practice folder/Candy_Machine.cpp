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
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;

    sort(all(v),
    [](auto& a,auto& b)->bool
    {
        if(a.first - a.second == b.first - b.second)
        {
            return a.first + a.second > b.first + b.second;
        }
        return a.first-a.second < b.first - b.second;
    });
    debug(v);
    for(int i=0;i<n;i++)debug( v[i].first + v[i].second);
    vector<int> bucket(n);
    vector<int> l = {0};
    for(int i=0;i<n;i++)
    {
        bucket[i] = lower_bound(all(l),i,
        [&](auto& a, auto& b)->bool
        {
            return v[a].first + v[a].second < v[b].first + v[b].second;
        }) - l.begin() + 1;

        if(bucket[i] - 1 == l.size())
        {
            l.push_back(i);
        }
        else
        {
            l[bucket[i] - 1] = i;
        }
        debug(bucket[i]);
    }
    cout<<l.size()<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<" "<<bucket[i]<<endl;
    }
}