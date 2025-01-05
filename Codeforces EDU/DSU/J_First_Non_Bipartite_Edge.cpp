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
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

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
struct UF {
	vi e;
    vi parity;
	UF(int n) : e(n, -1), parity(n,0) {}
	int size(int x) { return -e[find(x).first]; }
	pair<int,int> find(int x) {
        if(e[x] < 0) return {x,0};
        auto pr = find(e[x]);
        e[x] = pr.first;
        parity[x] ^= pr.second;
        return {e[x],parity[x]};
    }
	bool join(int a, int b) {
		auto pa = find(a), pb = find(b);
        if(pa.first == pb.first and pa.second == pb.second) return false;
        else if(pa.first == pb.first) return true;
		if (e[pa.first] > e[pb.first]) swap(pa, pb);
		e[pa.first] += e[pb.first]; e[pb.first] = pa.first;
        assert(parity[pa.first] == 0 and parity[pb.first] == 0);
        parity[pb.first] = pa.second ^ pb.second ^ 1;
		return true;
	}
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    UF dsu(n + 1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        if(!dsu.join(a, b)){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<< -1 <<endl;
}