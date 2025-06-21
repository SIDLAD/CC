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
#define cout(x) (x?cout<<"Yes"<<endl:cout<<"No"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF = 1'000'000'000'000;

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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int anyzero = -1;
        for(int i=0;i<s.length();++i)if(s[i] == '0')anyzero = i;
        vector<int> v(n);
        arrPut(v);
        int initmax = -INF;
        int curSum = 0;
        for(int i=0;i<n;i++) {
            if(curSum <= 0) curSum = 0;
            curSum += s[i] == '0' ? -INF : v[i];
            initmax = max(initmax, curSum);
        }
        if(initmax > k || initmax != k and !(anyzero + 1)) cout(false);
        else {
            cout(true);
            int totsub = 0;
            curSum = 0;
            int lmax = 0;
            for(int i=anyzero - 1;i >= 0 ;--i ) {
                curSum += s[i] == '0' ? -INF : v[i];
                lmax = max(lmax, curSum);
            }
            int rmax = 0;
            curSum = 0;
            for(int i=anyzero + 1;i < n; ++i) {
                curSum += s[i] == '0' ? -INF : v[i];
                rmax = max(rmax, curSum);
            }
            totsub = lmax + rmax;
            
            for(int i=0;i<n;++i) {
                int curEle = s[i] == '0' ? -INF : v[i];
                if(i == anyzero) curEle = k - totsub;
                cout << curEle << " ";
            } cout << endl;
        }
    }
}