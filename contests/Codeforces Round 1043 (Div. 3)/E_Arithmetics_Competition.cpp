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

struct node {
    int sum;
    int ac;
    int bc;
    node() : sum(0), ac(0), bc(0) {}
    node(int sum, int ac, int bc) : sum(sum), ac(ac), bc(bc) {}

    node operator+(const node& o) {
        return node(sum + o.sum, ac + o.ac, bc + o.bc);
    }
};

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
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> a(n), b(m);
        arrput(a) arrput(b);
        sort(all(a)), sort(all(b)), reverse(all(a)), reverse(all(b));

        vector<int> prea(n), preb(m);
        partial_sum(all(a), prea.begin()), partial_sum(all(b), preb.begin());
        
        vector<node> ab;
        int ia = 0, ib = 0;
        while(ia < n || ib < m) {
            if(ia == n || ib != m && b[ib] > a[ia]) ab.emplace_back(b[ib++],0,1);
            else ab.emplace_back(a[ia++],1,0);
        }

        partial_sum(all(ab), ab.begin());

        while(q--) {
            int x,y,z;
            cin >> x >> y >> z;

            if(z == n + m) {
                cout << prea.back() + preb.back() << endl;
                continue;
            }

            int ll = -1; // always satisfies
            int ul = z; // does not satisfy
            while(ul - ll > 1) {
                int mid = ll + ul >> 1;
                if(ab[mid].ac > x || ab[mid].bc > y) ul = mid;
                else ll = mid;
            }
            
            assert(ll == z-1 || (ll == -1 ? 0 : ab[ll].ac) == x || (ll == -1 ? 0 : ab[ll].bc) == y);
            int ans = ll == -1 ? 0 : ab[ll].sum;
            int ataken = (ll == -1 ? 0 : ab[ll].ac);
            int btaken = (ll == -1 ? 0 : ab[ll].bc);
            int rem = z - ataken - btaken;
            if(ll == z-1);
            else if((ll == -1 ? 0 :ab[ll].ac) == x) ans += (rem + btaken? preb[rem + btaken - 1] : 0) - (ll == -1 ? 0 : ab[ll].bc == 0 ? 0 : preb[ab[ll].bc - 1]);
            else ans += (rem + ataken ? prea[rem + ataken - 1] : 0) - (ll == -1 ? 0 : ab[ll].ac == 0 ? 0 : prea[ab[ll].ac - 1]);
            cout << ans << endl;
        }
    }
}