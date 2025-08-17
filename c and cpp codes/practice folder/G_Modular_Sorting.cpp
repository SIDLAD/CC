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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    auto getDivs = [&](int a) {
        vi v;
        for(int i=1;i * i <= a;++i) {
            if(a%i); else v.push_back(i),v.push_back(a/i);
        }
        sort(all(v)),v.erase(unique(all(v)), v.end());
        return v;
    };

    for(int TT = 1; TT <= T; ++TT)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vi divs = getDivs(m);
        map<int,int> rmap;
        int dc = divs.size();
        rep(i,0,dc) rmap[divs[i]] = i;
        vector<vi> vals(n, vi(dc));
        vi v(n);
        arrput(v);
        vi downCount(dc, 1);
        rep(i,0,n) rep(j,0,dc) {
            vals[i][j] = v[i] % divs[j];
            if(i) if(vals[i][j] < vals[i-1][j]) downCount[j]++;
        }

        auto upd = [&] (int i, int x) {
            rep(j,0,dc) {
                if(i) downCount[j] -= (vals[i][j] < vals[i-1][j]);
                if(n - 1 - i) downCount[j] -= (vals[i + 1][j] < vals[i][j]);
                v[i] = x;
                vals[i][j] = v[i] % divs[j];
                if(i) downCount[j] += (vals[i][j] < vals[i-1][j]);
                if(n - 1 - i) downCount[j] += (vals[i + 1][j] < vals[i][j]);
            }
        };

        while(q--) {
            int t,i,x,k;
            cin >> t;
            int g, gc;
            switch(t) {
                case 1:
                    cin >> i >> x; --i;
                    debug(i + 1, x);
                    upd(i,x);
                    break;
                case 2:
                    cin >> k;
                    debug(k);
                    g = gcd(m,k);
                    gc = m/g;
                    cout(downCount[rmap[g]] <= gc);
            }
        }
    }
}