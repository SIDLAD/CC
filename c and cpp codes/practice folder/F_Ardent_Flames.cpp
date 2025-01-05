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
#define endl '\n' //comment out for interactive problems
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

        vector<int> h(n),x(n);
        arrPut(h) arrPut(x);
        bool proceed=false;

        for(int i=0;i+k<=n;i++)
        {
            if(x[i + k - 1] - x[i] + 1<= 2*m - 1){proceed = true;break;}
        }
        if(!proceed)
        {
            cout<<-1<<endl;
            continue;
        }
        int ll = 0;
        int ul = *max_element(all(h));
        while(ul-ll > 1)
        {
            int stompcnt = ll + ul >> 1;
            bool check = false;
            vector<pair<int,int>> pts;
            for(int i=0;i<n;i++)
            {
                int minpow = (h[i] + stompcnt - 1)/stompcnt;
                if(minpow > m)continue;
                int delta = m - minpow;
                pts.emplace_back(x[i] - delta,-1);
                pts.emplace_back(x[i] + delta,1);
            }
            sort(all(pts));
            int cur = 0;
            for(int i=0;i<pts.size();i++)
            {
                cur -= pts[i].second;
                debug(cur);
                if(cur == k)
                {
                    check = true;
                    break;
                }
            }
            if(check)ul = stompcnt;
            else ll = stompcnt;
        }
        cout<<ul<<endl;
    }
}