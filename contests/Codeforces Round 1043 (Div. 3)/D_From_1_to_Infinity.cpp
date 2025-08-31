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

int tenp(int x) {
    if(x < 0) return 0;
    int ans = 1;
    while(x--) ans *= 10;
    return ans;
}

int digNumTot(int x) {
    if(x == 0) return 0;
    return x * (tenp(x) - tenp(x - 1));
}

int calcSumOfDigs(int x) {
    ++x;
    int sum = 0;
    const int digsetsum = 45;
    for(int freq = 1; freq <= x; freq *= 10) {
        int q = x / freq;
        int r = x % freq;
        int sts = q/10;
        sum += sts * freq * digsetsum;

        int qr = q % 10;
        sum += qr * (qr - 1) / 2 * freq;
        sum += r * qr;
    }
    return sum;
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
        int k;
        cin >> k;
        int kk = k;
        int curDigCnt = 0;
        while(kk > digNumTot(curDigCnt)) {
            kk -= digNumTot(curDigCnt);
            curDigCnt++;
        }

        int finalNum = (kk - 1) / curDigCnt;
        finalNum += tenp(curDigCnt - 1);

        int missingDigCnt = kk % curDigCnt;
        missingDigCnt = missingDigCnt == 0 ? 0 : curDigCnt - missingDigCnt;
        
        debug(curDigCnt);
        debug(finalNum, missingDigCnt);

        int missing = 0; int finC = finalNum;
        while(missingDigCnt--) {
            missing += finC %  10;
            finC /= 10;
        }

        debug(missing);
        cout << debug(calcSumOfDigs(finalNum)) - missing << endl;
        debug();
    }
}