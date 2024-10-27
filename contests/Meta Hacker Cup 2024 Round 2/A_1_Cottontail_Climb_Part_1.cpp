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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int a,b,m;

bool check(int num)
{
    if(num >= a and num <= b and num%m == 0)return 1;
    return 0;
}

int count(int digits)
{
    int tmp = digits + 1 >> 1;
    int count = 0;
    for(int mid = 9;mid >= tmp; mid--)
    {
        int start = mid - tmp + 1;
        int tenpow = 1;
        int num = 0;
        for(int i=1;i<=tmp;i++)
        {
            num += start * tenpow;
            tenpow *= 10;
            start++;
        }
        start--;
        assert(start == mid);
        start--;
        for(int i=1;i<tmp;i++)
        {
            num += start * (tenpow);
            tenpow*= 10;
            start--;
        }
        if(check(num))count++;
    }
    return count;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("cottontail_climb_part_1_input.txt","r",stdin);
    freopen("A1_output.txt","w",stdout);
    int T;
    cin>>T;
    for(int TT = 1;T--;TT++)
    {
        cin>>a>>b>>m;
        int diga = a == 0?1:log10(a) + 1;
        int digb = b==0?1:log10(b) + 1;
        int ans = 0;
        for(int i=diga;i <= digb; i++)
        {
            if(~i&1)continue;
            ans += count(i);
        }

        cout<<"Case #"<<TT<<": "<<ans<<endl;
    }
}