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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++)cin>>v[i][0]>>v[i][1],v[i][2] = i;

    sort(all(v), [](array<int,3>& a,array<int,3> & b){
        if(a[0] == b[0])return a[1] > b[1];
        return a[0] < b[0];
    });

    int max_min = INF;
    vector<int> ans1(n);
    for(int i=n-1;i>=0;i--)
    {
        ans1[v[i][2]] = v[i][1] >= max_min || (i!=0 and v[i] == v[i-1]);
        max_min = min(v[i][1],max_min);
    }
    for(int i=0;i<n;i++)cout<<ans1[i]<<" ";
    cout<<endl;

    
    int min_max = -INF;
    vector<int> ans2(n);
    for(int i=0;i<n;i++)
    {
        ans2[v[i][2]] = v[i][1] <= min_max || (i!=n-1 and v[i] == v[i+1]);
        min_max = max(v[i][1],min_max);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans2[i]<<' ';
    }
    cout<<endl;
    
    // sort(all(v),[](pair<int,int>& a, pair<int,int>& b){
    //     return a.second < b.second;
    // }
    // );

    // int min_min = INF;
    // for(int i=n-1;i>=0;i--)
    // {
    //     if(v[i].first >= min_min)cout<<1<<" ";
    //     else cout<<0<<" ";
    //     min_min = min(min_min, v[i].first);   
    // }
    // cout<<endl;
}