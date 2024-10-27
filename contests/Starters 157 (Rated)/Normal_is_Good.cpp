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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

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
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int ans = 0;
        int l =0;
        for(int i=0;i<=n;i++)
        {
            if(i ==n  or v[i] != 1)
            {
                ans += l * (l-1) / 2;
                l=0;
            }
            else l++;
        }
        for(int i=0;i<=n;i++)
        {
            if(i ==n  or v[i] != 3)
            {
                ans += l * (l-1) / 2;
                l=0;
            }
            else l++;
        }
        for(int i=0;i<n;i++)if(v[i]!=2)ans++;
        debug(ans);

        map<int,int> mp;
        int hill = 0;
        stack<int> st;
        st.push(0);
        for(int i=0;i<n;i++)
        {
            debug();
            debug(v[i]);
            if(v[i] == 1)hill++;
            if(v[i] == 3)hill--;
            if(v[i] == 2){while(st.size())mp[st.top()]++,st.pop();}
            st.push(hill);
            debug(hill,mp[hill],i);
            if(mp[hill])ans += mp[hill],debug(ans);
        }
        debug("tt");debug();
        cout<<ans<<endl;
    }
}