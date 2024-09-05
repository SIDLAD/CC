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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    if(a == 0 and b == 0)
    {
        if(c == 0)cout<<-1<<endl;
        else cout<<0<<endl;
        return 0;
    }

    if(a == 0)
    {
        cout<<1<<endl;
        cout<<-1.0 * c / b<<endl;
        return 0;
    }

    if(b * b < 4 * a * c)
    {
        cout<<0<<endl;
        return 0;
    }

    if(b * b == 4 * a *c)
    {
        cout<<1<<endl;
        cout<< -1.0 * b / 2 / a;
        return 0;
    }
    cout<<2<<endl;
    double srt = sqrt(b*b - 4 * a * c);
    if(a > 0){
    cout<< (-1.0 * b - srt)/2/a<<endl;
    cout<< (-1.0 * b + srt)/2/a<<endl;}
    else {cout<< (-1.0 * b + srt)/2/a<<endl;
    cout<< (-1.0 * b - srt)/2/a<<endl;}
}