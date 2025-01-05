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
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
// #define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int n;

int qc = 0;

void answer(int a, int b, int c)
{
    cout<<"ans "<<a<<" "<<b<<" "<<c<<endl;
}

int ask(int l, int r)
{
    if(qc >= 150)assert(false);
    qc++;
    cout<<"xor "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;

    // if(l <= 288230376151711744)
    // {
    //     if(r >= 864691128455135232)return 0;
    //     if(r >= 576460752303423488)return 864691128455135232;
    //     if(r >= 288230376151711744)return 288230376151711744;
    //     return 0;
    // }
    // if(l <= 576460752303423488)
    // {
    //     if(r >= 864691128455135232)return 288230376151711744;
    //     if(r >= 576460752303423488)return 576460752303423488;
    //     return 0;
    // }
    // if(l <= 864691128455135232)
    // {
    //     if(r >= 864691128455135232)return 864691128455135232;
    //     return 0;
    // }
    // return 0;
    // assert(false);
}

//1000000000000000000 864691128455135232 576460752303423488 288230376151711744

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
        qc = 0;
        cin>>n;
        int inp = ask(1,n);
        if((inp)!= 0)
        {
            int ll = 0;
            int ul = n;
            int xort = inp;
            while(ul - ll > 1)
            {
                int mid = ll + ul >> 1;
                inp = ask(1,mid);
                if(inp == xort)ul = mid;
                else ll = mid;
            }
            int c = ul;
            ul--;
            xort = ask(1,ul);
            ll = 0;
            while(ul - ll > 1)
            {
                int mid = ul + ll >> 1;
                if((ask(1,mid)) == xort)ul = mid;
                else ll = mid;
            }
            int b = ul;
            ul--;
            int a = ask(1,ul);
            answer(a,b,c);
            continue;
        }

        int bitw = bit_width((unsigned long long)n);

        for(int x = bitw;x >= 1; x--)
        {
            int l = (1ll<<x - 1);
            int r = (1ll<<x) - 1;
            if(r > n)r = n;

            int xort;
            xort = ask(l,r);
            if(0 == xort)continue;
            int ll = l - 1;
            int ul = r;
            while(ul - ll > 1)
            {
                int mid = ll + ul >> 1;
                if(ask(l,mid) == xort)ul = mid;
                else ll = mid;
            }
            int c = ul;

            ul -- ;
            xort = ask(1,ul);
            ll = 0;
            while(ul - ll > 1)
            {
                int mid = ul + ll >> 1;
                if((ask(1,mid)) == xort)ul = mid;
                else ll = mid;
            }
            int b = ul;
            ul--;
            int a = ask(1,ul);
            answer(a,b,c);
            goto outer;
        }

        assert(false);
        outer:42;
    }
}
//5 2 4 5
//1000000000000000000 864691128455135232 576460752303423488 288230376151711744

//288230376151711744