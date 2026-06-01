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
    LLONG_MAX/10
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
        vector<string> v(n);
        arrput(v);
        array<int,3> x{}, o{};
        int tot = 0;
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) {
            if(v[i][j] == 'O') o[(i + j) % 3] ++, tot += 1;
            if(v[i][j] == 'X') x[(i + j) % 3] ++, tot += 1;
        }

        int xi = -1, oj = -1;
        for(int i=0;i<3;++i) for(int j=0;j<3;++j) if(i != j) {
            if(xi == -1) xi = i, oj = j;
            else if(x[i] + o[j] < x[xi] + o[oj]) xi = i, oj = j;
        }
        assert(xi != -1);
        assert((x[xi] + o[oj]) * 3 <= tot);

        for(int i=0;i<n;++i) for(int j=0;j<n;++j) {
            if((i + j) % 3 == xi and v[i][j] == 'X') v[i][j] = 'O';
            else if((i + j) % 3 == oj and v[i][j] == 'O') v[i][j] = 'X';
        }

        for(auto e: v) cout << e << endl;
        cout << endl;
    }
}