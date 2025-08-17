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
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int calcAng(vector<int>& v) {
    int ans = 0;
    for(auto k: v) {
        ans += k * (k + 1) / 2;
    }
    return ans;
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
        debug();
        debug(TT);
        int n,k;
        cin >> n >> k;
        vi a(n);
        arrput(a);
        debug(a);
        int tot = accumulate(all(a), 0ll);
        if(*max_element(all(a)) - *min_element(all(a)) <= k) {
            cout << (calcAng(a)) << endl;
            continue;
        }
        int initSum = accumulate(all(a),0ll);
        int ll = -k;
        int ul = *max_element(all(a)) + 1;
        while(ul - ll > 1) {
            int mid = ll + ul >> 1;
            int exc = 0;
            int def = 0;
            int rf = mid + k;
            for(auto e:a) exc += max(0ll, e - rf), def += max(0ll, mid - e);
            debug(mid, exc, def);
            if(exc >= def) ll = mid;
            else ul = mid;
        }
        int exc = 0, def = 0, excls = 0, defls = 0;
        int rf = ll + k;
        debug(ll, rf);
        vector<int> ansArr;
        for(auto e: a) {
            debug(e);
            int curexc = max(0ll, e - rf), curdef = max(0ll, ll - e);
            exc += curexc, def += curdef;
            bool isexc = (bool) curexc;
            bool isdef = (bool) curdef  || ll - e == 0;
            excls += isexc, defls += isdef;
            if(!isexc && !isdef) ansArr.push_back(e);
            assert(! (isexc && isdef));
        }
        debug(exc, def, excls, defls, sz(ansArr));
        assert(excls + defls + sz(ansArr) == n);
        int llc1 = min(defls, exc - def);
        int llc = defls - llc1;
        int rfc1 = max(exc - def - defls, 0ll);
        int rfc = excls - rfc1;
        debug(ll, ansArr, llc1, llc, rfc1, rfc);
        while(llc1--) ansArr.push_back(ll + 1);
        while(llc--) ansArr.push_back(ll);
        while(rfc1--) ansArr.push_back(rf + 1);
        while(rfc--) ansArr.push_back(rf);
        debug(ansArr);
        assert(sz(ansArr) == n);
        assert(accumulate(all(ansArr), 0ll) == initSum);
        cout << calcAng(ansArr) + k * min(exc, def + defls) << endl;
    }
}