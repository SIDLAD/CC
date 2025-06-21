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

const int INF = 8e5 + 2;

vector<vector<int>> pos;

array<int,2> LDBias_LDminusRDBias(int ind, int ele) {
    int l, r;
    if(lower_bound(all(pos[ele]), ind) == pos[ele].begin()) l = -INF;
    else l = *--lower_bound(all(pos[ele]), ind);
    if(lower_bound(all(pos[ele]), ind) == pos[ele].end()) r = INF;
    else r = *lower_bound(all(pos[ele]), ind);
    int ld = ind - 1 - l;
    int rd = r - ind;
    int ldminusrdbias = ld - rd - 2* ind;
    return {ld - ind, ldminusrdbias};
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
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        arrPut(v);
        for(auto&e:v)--e;

        int hfl = k/2;
        int hfr = k - hfl;

        pos.assign(k, vector<int>());
        for(int i=0;i<n;i++)pos[v[i]].push_back(i);

    
        set<pair<int,int>> rminuslbias;
        set<pair<int,int>> lminusrbias;
        vector<int> lminusrbiasvals(k);
        vector<int> ldbiasvals(k);

        vector<bool> lchosen(k, true);
        int curans = 0;
        int ans = INF*INF;
        int ind = 0;
        for(int i=0;i<k;i++) {
            auto [ld, lrb] = LDBias_LDminusRDBias(ind, i);
            curans += ldbiasvals[i] = ld;
            lminusrbiasvals[i] = lrb;
            rminuslbias.emplace(-lrb, i);
        }
        for(int _ = hfr; _--;) {
            auto [__, ele] = *rminuslbias.begin();
            rminuslbias.erase(rminuslbias.begin());
            lchosen[ele] = false;
            curans +=  - lminusrbiasvals[ele] - 2* ind;
            lminusrbias.emplace(lminusrbiasvals[ele], ele);
        }
        ans = min(ans, curans);
        debug(),debug(),debug();
        debug(hfl, hfr);
        debug(curans);
        debug(lchosen);
        debug(lminusrbiasvals);
        debug(),debug();
        for(; ++ind < n;) {

            int ele = v[ind - 1];
            curans += hfl - hfr;
            if(lchosen[ele]) curans -=  ldbiasvals[ele] + ind, assert(rminuslbias.erase({-lminusrbiasvals[ele], ele}));
            else curans -= ldbiasvals[ele] + ind - (lminusrbiasvals[ele] + 2 * ind), assert(lminusrbias.erase({lminusrbiasvals[ele], ele}));
            auto [ld, lrb] = LDBias_LDminusRDBias(ind, ele);

            ldbiasvals[ele] = ld;
            lminusrbiasvals[ele] = lrb;
            curans += ld + ind;
            debug(curans);
            lminusrbiasvals[ele] = lrb;
            if(rminuslbias.size() == hfl - 1) {
                debug("Putting first in right");
                //put in right first then remove one
                assert(lminusrbias.size() == hfr);
                lchosen[ele] = false;
                curans += - lminusrbiasvals[ele] - 2* ind;
                debug(curans);
                lminusrbias.emplace(lrb, ele);
                auto [_, transferEle] = *lminusrbias.begin();
                lminusrbias.erase(lminusrbias.begin());
                lchosen[transferEle] = true;
                debug(lminusrbiasvals);
                curans += lminusrbiasvals[transferEle] + 2 * ind;
                debug(ele, transferEle, curans);
                rminuslbias.emplace(-lminusrbiasvals[transferEle], transferEle);
            }
            else {
                debug("Putting first in left");
                // put in left first then remove one
                assert(lminusrbias.size() == hfr - 1);
                assert(rminuslbias.size() == hfl);
                lchosen[ele] = true;
                rminuslbias.emplace(-lrb, ele);
                
                auto [_, transferEle] = *rminuslbias.begin();
                rminuslbias.erase(rminuslbias.begin());
                lchosen[transferEle] = false;
                curans += - lminusrbiasvals[transferEle] - 2* ind;
                debug(ele, transferEle, curans);
                lminusrbias.emplace(lminusrbiasvals[transferEle] , transferEle);
             }
            

            ans = min(ans, curans);
        }

        cout << ans - (hfl) * (hfl - 1) / 2 - (hfr) * (hfr - 1) / 2 << endl;
    }
}