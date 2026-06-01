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

template<typename T=int>
T input() {
    T x;
    cin >> x;
    return x;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
        int n;
        cin >> n;
        vi v(n), pre(n), suf(n);
        arrput(v);
        suf = v;
        partial_sum(suf.rbegin(), suf.rend(), suf.rbegin());
        suf.push_back(0);
        for(int i=0;i<n;++i) pre[i] = abs(v[i]);
        partial_sum(all(pre), pre.begin());
        pre.insert(pre.begin(), 0);
        int mxI = -1;
        auto calc = [&](int ind) {
            return pre[ind] - v[ind] + suf[ind + 1];
        };
        for(int i=0;i<n;++i) {
            if(v[i] > 0 and (mxI == -1 or calc(mxI) < calc(i))) mxI = i;
        }

        if(mxI == -1 or calc(mxI) < accumulate(all(v), 0ll)) {
            cout << 0 << endl;
            continue;
        }

        vi order {mxI + 1};
        for(int i=mxI - 1;i>=0;--i) {
            if((sz(order)&1) ^ (v[i] < 0)) { // needs to be flipped
                auto tp = order.back();
                order.pop_back();
                order.push_back(i + 1);
                order.push_back(tp);
            }
        }

        cout << order.size() << endl;
        arrprint(order);
    }
}