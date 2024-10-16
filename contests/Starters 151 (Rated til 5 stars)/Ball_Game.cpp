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

struct fraction
{
    int n,d;
    bool operator<(const fraction& f) const
    {
        return n * f.d < d * f.n;
    };
};

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
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<pair<int,int>> c(n);
        for(int i=0;i<n;i++)c[i] = {a[i],b[i]};
        sort(all(c));
        for(int i=0;i<n;i++)tie(a[i],b[i]) = c[i];
        vector<fraction> t(n);
        for(int i=0;i<n;i++)
        {
            t[i] = {a[i],b[i]};
        }
        vector<fraction> lis = {t[0]};
        for(int i=1;i<n;i++)
        {
            int index = upper_bound(all(lis),t[i]) - lis.begin();
            if(index == lis.size())
            {
                lis.push_back(t[i]);
            }
            else lis.resize(index + 1),lis[index] = t[i];
        }
        cout<<lis.size()<<endl;
    }
}