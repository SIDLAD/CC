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

int getsecond(int i1, int i2, vector<int>& pre, vector<int>& p, int tot) {
    assert(i1 != i2);
    int l = p[i1];
    int r = p[i2];
    //get sum between l and r
    if(i1 > i2)swap(i1,i2);
    int between = pre[i2-1] - pre[i1];
    int outside = tot - between - l - r;
    return r + min(between,outside);
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
        cin >> n;
        vector<int> p(n);
        arrPut(p);
        int tot = accumulate(all(p), 0ll);

        vector<int> pre(p);
        partial_sum(all(pre),pre.begin());

        int opp = 1;
        int mn = INF;
        for(int start = 0; start < n; start ++) { 
            while((opp == start) or (opp + 1)%n != start and getsecond(start, opp, pre, p, tot) < getsecond(start, (opp + 1) % n, pre, p, tot)){
                opp ++;
                opp%=n;
            }
            mn = min(mn, getsecond(start, opp, pre, p, tot));
        }
        cout << tot - mn << endl;
    }
}