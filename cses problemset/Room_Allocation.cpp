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

    vector<array<int,3>> pts;
    for(int i=0;i<n;i++)
    {
        pts.push_back({v[i].first,0,i});
        pts.push_back({v[i].second,1,i});
    }
    sort(all(pts));
    int ans = 0;
    int cur_clr = 0;
    vector<int> ar(n);
    set<int> inactive;
    for(int i=1;i<=n;i++)inactive.insert(i);
    for(int i=0;i<pts.size();i++)
    {
        auto [pos,type,idx] = pts[i];
        if(type == 0)
        {
            cur_clr++;
            ans = max(ans,cur_clr);
            ar[idx] = *inactive.begin();
            inactive.erase(inactive.begin());
        }
        else {
            cur_clr--;
            inactive.insert(ar[idx]);
        }
    }

    cout<<ans<<endl;
    for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    cout<<endl;
}