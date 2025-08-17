#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int ctr = 0;
map<vector<int>, int> mp;

int getRootedTreeHash(vector<vector<int>>& edges, int cur) {
    vector<int> childH;
    for(auto c: edges[cur]) {
        childH.push_back(getRootedTreeHash(edges, c));
    }
    if(mp.count(childH)) return mp[childH];
    return mp[childH] = ++ctr;
}

bool checkRot(vector<int> v1, vector<int> v2) {
    if(v1.size() != v2.size()) return 0;
    auto v3 = v1;
    v3.push_back(-1);
    v3.insert(v3.end(), v2.begin(), v2.end());
    v3.insert(v3.end(), v2.begin(), v2.end());

    vector<int> zval(v3.size());
    int l=0, r=0;
    for(int i=1;i<zval.size();++i) {
        if(r > i) zval[i] = min(zval[i-l], r-i);
        while(i + zval[i] < v3.size() && v3[i + zval[i]] == v3[zval[i]]) zval[i]++;
        if(i + zval[i] > r) r = i + zval[i], l = i;
    }
    return *max_element(all(zval)) == v1.size();
}

bool inBetween(int l, int u, int s) {
    if(l < u) return l <= s && s <= u;
    else return l <= s || s <= u;
}

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
        int n,m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        arrput(a) arrput(b);

        vector<vector<int>> aoccs(m + 1), boccs(m + 1);
        for(int i=0;i<n;++i) aoccs[a[i]].push_back(i), boccs[b[i]].push_back(i);

        vector<vector<int>> aedges(n), bedges(n);

        for(int i=2;i<=m;++i) {

            int k;
            k = upper_bound(all(aoccs[i - 1]), aoccs[i][0]) - aoccs[i-1].begin();
            k %= aoccs[i-1].size();

            auto kstart = k;

            for(int j=0;j<aoccs[i].size();++j) {
                while(
                    inBetween(
                        aoccs[i][j],
                        aoccs[i][(j + 1) % aoccs[i].size()],
                        aoccs[i-1][k]))
                {
                    aedges[aoccs[i][j]].push_back(aoccs[i-1][k]);
                    k++;
                    k%=aoccs[i-1].size();
                    if(k == kstart) break;
                }
            } 

            k = upper_bound(all(boccs[i - 1]), boccs[i][0]) - boccs[i-1].begin();
            k %= boccs[i-1].size();
            kstart = k;
            for(int j=0;j<boccs[i].size();++j) {
                while(
                    inBetween(
                        boccs[i][j],
                        boccs[i][(j + 1) % boccs[i].size()],
                        boccs[i-1][k]))
                {
                    bedges[boccs[i][j]].push_back(boccs[i-1][k]);
                    k++;
                    k%=boccs[i-1].size();
                    if(k == kstart) break;
                }
            } 
        }
        vector<int> aforest, bforest;
        for(auto i: aoccs[m]) aforest.push_back(getRootedTreeHash(aedges, i));
        for(auto i: boccs[m]) bforest.push_back(getRootedTreeHash(bedges, i));
        cout(checkRot(aforest, bforest));
    }
}