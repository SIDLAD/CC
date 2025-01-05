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
    vector<map<int,int>> st;
    int thresh;
    map<int,int> lss;
	UF(int n, vector<int>& v, int thresh) : e(n, -1), st(n), thresh(thresh) {
        for(int i=0;i<n;i++)if(v[i] < thresh)st[i][v[i]]++;
        for(int i=0;i<n;i++)if(st[i].size() == thresh){lss[1]++;}
    }
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
        if(st[a].size() == thresh){lss[size(a)]--;if(lss[size(a)] == 0)lss.erase(size(a));}
        if(st[b].size() == thresh){lss[size(b)]--;if(lss[size(b)] == 0)lss.erase(size(b));}
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        for(auto [ele,f] : st[b]){
            st[a][ele] += f;
        }
        st[b].clear();
        assert(st[a].size() <= thresh);
        if(st[a].size() == thresh){lss[size(a)]++;}
		return true;
	}

    void editval(int i, int prevval, int newval){
        assert(newval >= 0);
        assert(newval < prevval);
        int p = find(i);
        if(st[p].size() == thresh){lss[size(p)]--;if(lss[size(p)] == 0)lss.erase(size(p));}
        if(newval < thresh)
        st[p][newval]++;
        if(prevval < thresh)
        {
            st[p][prevval]--;
            if(st[p][prevval] == 0)st[p].erase(prevval);
        }
        assert(st[p].size() <= thresh);
        if(st[p].size() == thresh){lss[size(p)]++;}
    }

    int longestsat(){
        if(lss.size() == 0)return 0;
        return lss.rbegin()->first;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,q;
        cin >> n >> q;
        vector<int> v(n);
        arrPut(v);
        vector<pair<int,int>> queries;
        vector<int> rans(q);

        range(_,0,q){
            int i,x;
            cin>>i>>x;
            queries.emplace_back(i-1,x);
        }
        reverse(all(queries));
        for(int i=0;i<q;i++){
            v[queries[i].first] += queries[i].second;
        }
        vector<UF> dsus;
        for(int i=0;i<20;i++){
            dsus.emplace_back(n,v,1<<i);
            for(int j=1;j<n;j++){
                if(v[j-1] < dsus.back().thresh and v[j] < dsus.back().thresh){
                    dsus.back().join(j-1,j);
                }
            }
        }
        for(int i=0;i<q;i++){
            debug(v);
            auto [updind, dec] = queries[i];
            int prevval = v[updind];
            int newval = v[updind] - dec;
            v[updind] = newval;
            int ans = 0;
            for(auto& dsu: dsus){
                ans = max(ans,dsu.longestsat());
                dsu.editval(updind, prevval, newval);
                if(v[updind] < dsu.thresh){
                    if(updind != 0 and v[updind - 1] < dsu.thresh){
                        dsu.join(updind,updind - 1);
                    }
                    if(updind != n - 1 and v[updind + 1] < dsu.thresh){
                        dsu.join(updind,updind + 1);
                    }
                }
            }
            rans[i] = ans;
        }
        reverse(all(rans));
        for(int i=0;i<q;i++){
            cout<<rans[i]<<endl;
        }
    }
}