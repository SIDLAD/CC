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

void print(int x, int TT) {
    cout << "Case #" << TT << ": " << x << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("snake_scales_chapter_2_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        vi v(n);
        arrput(v);

        int ll = -1;
        int ul = *max_element(all(v));
        while(ul - ll > 1) {
            int mid = ll + ul >> 1;
            vector<int> reachable(n);
            queue<int> processing;
            for(int i=0;i<n;++i) {
                if(v[i] <= mid) {
                    processing.push(i);
                }
            }

            while(processing.size()) {
                auto f = processing.front();
                processing.pop();
                if(reachable[f]) continue;
                reachable[f] = true;
                if(f and abs(v[f] - v[f-1]) <= mid) processing.push(f - 1);
                if(f != n - 1 and abs(v[f] - v[f+1]) <= mid) processing.push(f + 1);
            }
            if(accumulate(all(reachable), 0ll) == n) ul = mid;
            else ll = mid;
        }

        print(ul, TT);
    }
}