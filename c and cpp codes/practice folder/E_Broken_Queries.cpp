#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

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

int query(int l, int r)
{
    cout<<'?'<<" "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
}

void answer(int p)
{
    cout<<"! "<<p<<endl;
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
        cin>>n;
        int a1 = query(1,n/4);
        int a2 = query(n/4 + 1, n/2);
        int b = query(1, n/2);
        if(a1 != a2)
        {
            //in first half.
            if(b == 1)
            {
                //k > n/2
                int ll = n/2 + 1;
                int ul = n;
                int ans = -1;
                while(ul >= ll)
                {
                    int mid = ll + ul >> 1;
                    int x = query(1,mid);
                    if(x == 0)
                    {
                        ul = mid - 1;
                        ans = mid;
                    }
                    else
                    {
                        ll = mid + 1;
                    }
                }
                assert(ans != -1);
                answer(ans);
            }
            else
            {
                // k <= n/2
                int ll = 1;
                int ul = n/2;
                int ans = -1;
                while(ul >= ll)
                {
                    int mid = ll + ul >> 1;
                    int x = query(n / 2 + 1, mid + n /2);
                    if(x == 0)
                    {
                        ll = mid + 1;
                    }
                    else
                    {
                        ul = mid - 1;
                        ans = mid;
                    }
                }
                assert(ans != -1);
                answer(ans);
            }
        }
        else
        {
            //in second half
            if(b == 1)
            {
                // k <= n/2
                int ll = 1;
                int ul = n/2;
                int ans = -1;
                while(ul >= ll)
                {
                    int mid = ll + ul >> 1;
                    int x = query(1,mid);
                    if(x == 1)
                    {
                        ans = mid;
                        ul = mid - 1;
                    }
                    else
                    {
                        ll = mid + 1;
                    }
                }
                assert(ans != -1);
                answer(ans);
            }
            else
            {
                // k > n/2
                int ll = n/2 + 1;
                int ul = n;
                int ans = -1;
                while(ul >= ll)
                {
                    int mid = ll + ul >> 1;
                    int x = query(n - mid + 1,n);
                    if(x == 1)
                    {
                        ll = mid + 1;
                    }
                    else
                    {
                        ul = mid - 1;
                        ans = mid;
                    }
                }
                assert(ans != -1);
                answer(ans);
            }
        }
    }
}