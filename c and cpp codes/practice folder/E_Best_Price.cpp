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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    int TT = 1;
    for(;T--;TT++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        arrPut(a) arrPut(b);
        vector<pair<int,bool>> pts;
        range(i,0,n) {
            pts.emplace_back(a[i],0);
            pts.emplace_back(b[i],1);
        }

        sort(all(pts));
        int mx = pts.begin()->first * n;
        int curK = 1;
        int curN = n;
        for(int i=1; i<pts.size(); i++) {

            if((i==0 or pts[i - 1].first != pts[i].first) and curK <= k) mx = max(curN * pts[i].first, mx), debug(pts[i].first, curN, curK);

            if(pts[i].second == 0) {
                curK ++;
            }
            else {
                curN --;
                curK --;
            }
        }
        cout << mx << endl;
    }
}