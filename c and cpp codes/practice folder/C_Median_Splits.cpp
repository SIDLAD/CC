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
#define sz(x) (int)(x).size()
#define endl '\n' //comment out for interactive problems
#define cout(x) cout << ((x) ? "YES" : "NO") << endl
#define rep(it, start, end) for (auto it = start; it != end; ++it)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool ch1(vi v, int n, bool flag=false) {
    if(flag) reverse(all(v));
    int mxSum = -5;
    int curSum = 0;
    int mxSumCnt = 1;
    for(int i=0;i<n-1;++i) {
        curSum += v[i];
        if(i >= 1) {
            if(mxSum == curSum) mxSumCnt += 1;
            else if(mxSum < curSum) mxSum = curSum, mxSumCnt = 1;
        }
    }

    return mxSum > 0 || mxSumCnt >= 2 && mxSum == 0;
} 

bool ch2(vi v, int n) {
    int i1 = -1;
    int curSum = 0;
    for(int i=0;i<n;++i) {
        curSum += v[i];
        if(curSum >= 0) {i1 = i; break;}
    }
    curSum = 0;
    int i2 = -1;

    for(int i=n-1;i>=0;--i) {
        curSum += v[i];
        if(curSum >= 0) {i2 = i; break;}
    }

    if(i1 == -1 || i2 == -1) return false;
    if(i1 + 1 >= i2) return false;
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n,k;
        cin >> n >> k;
        vi a(n);
        arrput(a);
        for(int i=0;i<n;++i) if(a[i] <= k) a[i] = 1; else a[i] = -1;

        bool check1 = ch1(a, n) || ch1(a,n,1);
        bool check2 = ch2(a, n);
        cout(check1 || check2);
    }
}