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
    int T;
    cin>>T;
    int x = 1;
    int ans[2][2][2] = {0,1,0,0,1,0,1,0};
    for(;T--;x++)
    {
        int b,c,d;
        cin>>b>>c>>d;
        int a = 0;
        bool check = true;
        for(int i=0;i<62;i++)
        {
            // debug(i,(b&(1ll<<i))!=0,(c&(1ll<<i))!=0,(d&(1ll<<i))!=0,ans[(b&(1ll<<i)) != 0][(c&(1ll<<i) )!= 0][(d&(1ll<<i)) != 0]);
            if(((b&(1ll<<i)) ^ (c&(1ll<<i))) and ((d&(1ll<<i)) == (c&(1ll<<i))))
            {
                check = false;
                break;
            }
            else a |= (ans[(b&(1ll<<i)) != 0][(c&(1ll<<i) )!= 0][(d&(1ll<<i)) != 0]) << i;
        }
        if(check){
            // if((a|b) - (a&c) != d)
            // {
            //     cout<<b<<"\\"<<c<<"\\"<<d<<"\\"<<endl;
            // }
            // else
            cout<<a<<endl;

        }
        else cout<<-1ll<<endl;
    }
}