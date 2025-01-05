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

using vi = vector<int>;
using pii = pair<int,int>;
#define sz(x) ((int)x.size())

struct RollbackUF {
	vi e; vector<pii> st;
	RollbackUF(int n) : e(n, -1){}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return sz(st); }
    int count() { return sz(e) - 1 - (sz(st) >> 1);}
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
vector<pair<int,int>> answers;
int m;

using info = array<int,5>;

void solve(int l, int r, vector<info>& lst, RollbackUF& dsu)
{
    if(r < l)return;
    int savept = dsu.time();
    int mid = l + r >> 1;
    vector<info> leftlst,rightlst;
    for(auto& ar:lst)
    {
        assert(ar[1] <= r and ar[2] >= l);
        if(ar[1] <= l and ar[2] >= r)
        {
            if(ar[0] == 0)
            dsu.join(ar[3],ar[4]);
            else
            answers.push_back({l,dsu.count()});
        }
        else
        {
            if(ar[1] <= mid)
            {
                leftlst.push_back(ar);
            }
            if(ar[2] > mid)
            {
                rightlst.push_back(ar);
            }
        }
    }
    lst.clear();
    if(l != r)
    {
        solve(l,mid,leftlst,dsu);
        solve(mid + 1,r,rightlst,dsu);
    }
    dsu.rollback(savept);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n>>m;
    vector<info> lst;
    RollbackUF dsu(n + 1);

    map<pair<int,int>,int> active;

    for(int i=0;i<m;i++)
    {
        char c;
        cin>>c;
        if(c == '?')
        {
            lst.push_back({1,i,i,-1,-1});
        }
        else if(c == '+')
        {
            int a,b;
            cin>>a>>b;
            if(a > b)swap(a,b);
            active[{a,b}] = i;
        }
        else if(c == '-')
        {
            int a,b;
            cin>>a>>b;
            if (a > b)swap(a,b);
            assert(active.count({a,b}));
            lst.push_back({0,active[{a,b}],i,a,b});
            active.erase({a,b});
        }
        else
        {
            assert(false);
        }
    }
    for(auto [pr,time] : active)
    {
        auto [a,b] = pr;
        lst.push_back({0,time,m - 1,a,b});
    }

    sort(all(lst));
    solve(0,m - 1,lst,dsu);
    sort(all(answers));
    for(auto [_,ans]:answers)cout<<ans<<endl;
}