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
    string s,p;
    cin>>s>>p;
    vector<int> z1(p.size());
    int l=0,r=0;
    for(int i=1;i<p.size();i++)
    {
        if(i < r)z1[i] = min(r-i,z1[i-l]);
        while(i + z1[i] < p.size() and p[i + z1[i]] == p[z1[i]])
        {
            z1[i]++;
        }
        if(i + z1[i] > r)l = i,r = i + z1[i];
    }

    vector<int> z2(s.size());
     l=-1,r=-1;
    int ans = 0;
    for(int i=0;i<s.size();i++)
    {
        if(i < r)z2[i] = min(r-i,z1[i-l]);
        while(i + z2[i] < s.size() and z2[i] < p.size() and s[i + z2[i]] == p[z2[i]])
        z2[i]++;
        if(i+z2[i] > r) l = i,r = i + z2[i];
        if(z2[i] == p.size())ans++;
    }
    cout<<ans<<endl;

}