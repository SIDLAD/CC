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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

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
        int n,m,k;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        int onland = true;
        int curidx = -1;
        int swimmeter = 0;
        bool pass = true;
        past:
        while(curidx < n)
        {
            if(swimmeter > k){pass = false;break;}
            if(onland)
            {
                int lastw = -1;
                for(int i=curidx + 1;i <= min(curidx + m,n);i++)
                {
                    if(i == n or s[i] == 'L')
                    {
                        curidx = i;
                        goto past;
                    }
                    if(s[i] == 'W')
                    {
                        lastw = i;
                    }
                }

                if(lastw != -1)
                {
                    swimmeter ++;   
                    onland = false;
                    curidx = lastw;
                    goto past;
                }

                pass = false;
                break;
            }

            if(curidx + 1 == n){break;}
            if(s[curidx + 1] == 'L'){curidx ++; onland = true; continue;}
            if(s[curidx + 1] == 'W'){curidx++;swimmeter++;continue;}
            pass = false;
            break;
        }
        cout(pass);
    }
}