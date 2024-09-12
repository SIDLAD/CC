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
#define cout(x) x?cout<<"first"<<endl:cout<<"second"<<endl


int grundy[(int)1e6 + 1];



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    memset(grundy,-1,sizeof(grundy));
    for(int i=1;i<=2000;i++)
    {
        set<int> v;
        for(int j=1;2*j<i;j++)
        {
            v.insert(grundy[j]^grundy[i-j]);
        }
        auto it=v.begin();
        for(int j=0;j<=v.size();j++)
        {
            if(j == v.size() or *(it++) != j)
            {
                grundy[i] = j;
                break;
            }
        }
    }
    int T;
    cin>>T;
    for(;T--;)
    {
        int n;
        cin>>n;
        cout(grundy[n] != 0);
    }
}