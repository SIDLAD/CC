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
    int T = 1;
    cin>>T;
    for(;T--;)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<int> nextexp;
        set<int> st;
        for(int i=1;i<=n;i++)st.insert(i);
        vector<int> v0,v1;
        for(int i=1;i<=n;i++)if(s[i-1] == '0')v0.push_back(i);else v1.push_back(i);
        reverse(all(v1));


        int totdisc = 0;
        for(int i=n;i>=1;i--)if(st.count(i))
        {
            debug(i);
            debug(v0,v1);
            while(v0.size() and v0.back() > i)v0.pop_back();
            if(s[i-1] == '1')
            {
                if(v0.size()){
                totdisc += i;
                v0.pop_back();
                }
                else if(v1.size())
                {
                    if(v1.back() >= i)
                    {
                        v1.clear();
                        break;
                    }
                    else totdisc += i,v1.pop_back();
                }
            }

            st.erase(i);
        }

        cout<<n * (n + 1) / 2 - totdisc<<endl;
    }
}