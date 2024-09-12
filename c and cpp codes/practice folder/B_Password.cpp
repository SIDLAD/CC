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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"Just a legend"<<endl

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    vector<int> z(s.size());
    z[0] = 0;
    int l = 0 , r = 0;
    for(int i=1;i<s.size();i++)
    {
        if(r >= i)z[i] = min(z[i-l],r-i + 1);
        while(i + z[i] < s.size() and s[i + z[i]] == s[z[i]])
        {
            z[i]++;
        }
        if(i + z[i] > r)l = i,r = i + z[i] - 1;
    }
    debug(z);
    int ans= 0,len = -1;
    int curmax = 0;
    for(int i=0;i<s.size();i++)
    {
        if(z[i] == 0)continue;
        debug(z[i],curmax,i+z[i],s.size());
        if(i + z[i] == s.size() and z[i] <= curmax)
        {
            ans = i;
            len = z[i];
            break;
        }
        curmax = max(curmax,z[i]);
    }
    if(len != -1)
    {
        cout<<s.substr(ans,len);
    }
    else cout(false);
}