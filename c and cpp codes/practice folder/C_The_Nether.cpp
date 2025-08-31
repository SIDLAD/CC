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
// #define endl '\n' //comment out for interactive problems
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

int n;


int query(int start, vector<int> st) {
    cout << "? " << start << " " << sz(st) << " ";
    for(auto e: st) cout << e << " ";
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

void answer(vector<int> path) {
    cout << "! " << sz(path) << " ";
    for(auto e:path) cout << e << " ";
    cout << endl;
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
        cin >> n;
        vector<int> v(n); iota(all(v), 1ll);
        vector<int> lens(n + 1);
        map<int, vector<int>> mp;
        for(int i=1;i<=n;++i) lens[i] = query(i, v), mp[lens[i]].push_back(i);

        int maxLen = *max_element(all(lens));
        int start = max_element(all(lens)) - lens.begin();

        vector<int> ans = {start};
        for(int curLen = maxLen - 1; curLen >= 1; --curLen) {
            for(auto e: mp[curLen]) {
                if(query(ans.back(), {ans.back(), e}) == 2) {
                    ans.push_back(e);
                    break;
                }
            }
        }

        answer(ans);
    }
}