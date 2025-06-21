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
    int n, m;
    cin >> n >> m;
    int ctD = 0, ctU = 0;
    vector<int> prefD(2*m + 5), prefU(2*m + 5);
    int ansD = 0, ansU = 0;
    // int ansD = 0, 
    range(i,0,n) {
        int x;
        cin >> x;
        char c;
        cin >> c;
        if(x == 0 and c == 'U')c = 'D';
        if(x == m and c == 'D')c = 'U';
        if(c == 'U') {
            ctU++;
            ansU += x;
            prefD[m - x + 1]++;
            prefU[2*m - x + 1]++;
        }
        else {
            ctD++;
            ansD += x;
            prefU[x + 1]++;
            prefD[m + x + 1]++;
        }
    }
    int ans = ansD + ansU;
    range(i,1,2*m + 1) {
        ctD += prefD[i];
        ctU -= prefD[i];
        ctD -= prefU[i];
        ctU += prefU[i];
        ansD += prefD[i] * m;
        ansD -= ctD;
        ansU += ctU;
        ansU -= prefD[i] * m;
        ans = max(ans, ansU + ansD);
        debug(i,ctD,ctU,ansD,ansU,ans,prefD[i],prefU[i]);
    }
    cout << ans << "\n";
}