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
    int a=0,b=0,c=0,ab=0,bc=0,ca=0,abc=0;
    node() {}
    node(char x) {
        switch(x) {
            case 'a':
                ++a;
                break;
            case 'b':
                ++b;
                break;
            case 'c':
                ++c;
                break;
        }
    }

    node operator+(const node& o) {
        node ans;
        ans.a = a + o.a;
        ans.b = b + o.b;
        ans.c = c + o.c;
        ans.ab = min({ab + o.b, a + o.ab});
        ans.bc = min({bc + o.c, b + o.bc});
        ans.abc = min({a + o.abc, ab + o.bc, abc + o.c});
        return ans;
    }
};

node segtree[(int)2e5 - 1];
int n;
string s;

void construct(int id=0, int segl=0, int segr=-1) {
    if(segr == -1) segr = n - 1;
    if(segl == segr) {segtree[id] = s[segl]; return;}
    int mid = segl + segr >> 1;
    construct(id + 1, segl, mid);
    construct(id + 2*(mid - segl + 1), mid + 1, segr);
    segtree[id] = segtree[id + 1] + segtree[id + 2*(mid - segl + 1)];
}

void update(int ind, char val, int id=0, int segl=0, int segr=-1) {
    if(segr == -1) segr = n - 1;
    if(segl > ind || segr < ind) return;
    if(segl == segr) {segtree[id] = val; return;}
    int mid = segl + segr >> 1;
    update(ind, val, id + 1, segl, mid);
    update(ind, val, id + 2*(mid - segl + 1), mid + 1, segr);
    segtree[id] = segtree[id + 1] + segtree[id + 2*(mid - segl + 1)];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    // cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int q;
        cin >> n >> q;
        cin >> s;
        construct();
        while(q--) {
            int pos;
            char x;
            cin >> pos >> x;
            update(pos - 1, x);
            cout << segtree[0].abc << endl;
        }
    }
}