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
vector<int> primefactors(int n)
{
    vector<int> ans;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)n/=i;
            ans.push_back(i);
        }
    }
    if(n!=1)ans.push_back(n);
    return ans;
}
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
        vector<vector<int>> primedivs(n);
        set<int> primetemp;
        for(int i=0;i<n;i++)
        {
            primedivs[i] = primefactors(v[i]);
            if(primedivs[i].size() == 1 and primedivs[i][0] == v[i])
            {
                primetemp.insert(v[i]);
            }
            if(v[i] == 4)primetemp.insert(2);
        }

        if(primetemp.size() > 1)
        {
            cout<<-1<<endl;
            continue;
        }

        int maybeans = primetemp.size() == 0 ? 3 : *primetemp.begin();

        bool check = true;
        for(int i=0;i<n;i++)
        {
            if(v[i] % maybeans == 0)continue;
            if(maybeans > v[i])
            {
                check = false;
                break;
            }

            bool subcheck = false;
            for(auto curprime:primedivs[i])
            {
                int y = curprime * 2;
                int nextnum = (2 * maybeans + y - 1)/y*y;
                if(nextnum > v[i])continue;
                subcheck = true;
                break;
            }

            if(!subcheck)
            {
                check = false;
                break;
            }
        }
        if(check)cout<<maybeans<<endl;
        else cout<<-1<<endl;
    }
}