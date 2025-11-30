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

constexpr int bitlim = 30;
typedef array<int,bitlim> bitrep;

bitrep get(int x) {
    bitrep ans{};
    for(int i=0;i<bitlim;++i) if(x >> i & 1) {
        ans[bitlim - 1 - i] = 1;
    }
    return ans;
}

bitrep operator+(const bitrep& a, const bitrep& b) {
    bitrep c{};
    for(int i=0;i<bitlim;++i) c[i] = a[i] + b[i];
    return c;
}

bitrep operator+=(const bitrep& a, const bitrep& b) {
    return a + b;
}

template<typename T>
bitrep get(T& v) {
    bitrep ans{};
    for(auto& e: v) ans += get(e);
    return ans;
}

int getMaxBit(const bitrep& br){
    for(int i=0;i<bitlim;++i) if(br[i]) return bitlim - 1 - i;
    return -1;
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
        int n, q;
        cin >> n >> q;
        vi a(n);
        arrput(a);
        sort(all(a), [](auto x, auto y){return x > y;});
        while(sz(a) < 30) a.push_back(0);
        a.resize(30);

        while(q--) {
            int c = input();
            multiset<int> working = {all(a)};
            int ans = 0;

            while(c && get(working) < get(c)) {
                int mxE = *max_element(all(working));
                auto mxB = getMaxBit(debug(get(mxE)));
                auto mxBTackle = getMaxBit(debug(get(c)));
                debug(c);
                debug(mxBTackle);
                if(mxB < mxBTackle) {
                    int diff = (1 << mxBTackle) - mxE;
                    ans += diff;
                    c ^= (1 << mxBTackle);
                    working.erase(working.find(mxE));
                } else if(mxB == mxBTackle) {
                    c ^= (1 << mxBTackle);
                    auto mxENew = mxE ^ (1 << mxBTackle);
                    working.erase(working.find(mxE));
                    working.insert(mxENew);
                } else {
                    break;
                }
            }

            cout << ans << endl;
        }
        
    }
}