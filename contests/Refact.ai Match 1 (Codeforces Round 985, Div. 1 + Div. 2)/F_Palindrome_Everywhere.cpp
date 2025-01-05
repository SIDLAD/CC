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
int n;
string s;

void solve(char major, char minor)
{
    bool check = true;
    int high = 0;
    int low = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == minor and s[(i + 1)%n] == minor)
        {
            check = false;
            break;
        }
        if(s[i] == major)high++;
        else low++;
    }
    
    if(check)
    {
        if(low > 1 and n%2 == 0)
        {
            check = false;
        }
        else if(low > 2)
        {
            int start = -1;
            for(int i=0;i<n;i++)
            {
                if(s[i] == minor)start = i;
            }
            start++;
            int oddc = 0;
            int evenc = 0;
            int curdist = 0;
            for(int i=0;i<=n;i++,start = (start + 1)%n)
            {
                curdist++;
                if(s[start] == minor)
                {
                    if(curdist%2 == 1)oddc++;
                    else evenc++;
                    curdist = 0;
                }
 
            }
            debug(oddc,evenc);
            if(oddc <= 1)check = true;
            else check = false;
        }
    }

    cout(check);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(int TT = 1;T--;TT++)
    {
        cin>>n;
        cin>>s;
        // if(TT == 651)
        // {
        //     cout<<n<<"/"<<s<<endl;
        // }
        int rc = 0,bc = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')rc++;
            else bc++;
        }
        if(rc > bc)solve('R','B');
        else solve('B','R');
    }
}