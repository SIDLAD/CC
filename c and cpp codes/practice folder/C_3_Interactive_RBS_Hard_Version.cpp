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

#define double long double
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
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

int ask(vector<int>& indices) {
    assert(indices.size());
    int k = indices.size();
    cout << "? " << k << " ";
    for(auto e: indices) cout << e << " ";
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int ask1(int en) {
    vector<int> inds(en);
    iota(all(inds), 1ll);
    return ask(inds);
}

vector<int> getIndices(vector<char>& ans, int cnt = 12) {
    vector<int> indices;
    for(int i=0;i<ans.size() && indices.size() < cnt;++i) if(!ans[i])
    indices.push_back(i);
    return indices;
}

pair<int, vector<int>> constructQueryIndices(vector<int>& indices, int lft, int rt) {
    vector<int> queryIndices;
    int expectedCnt = 0;

    for(int i=0;i<indices.size();++i)  {
        auto curInd = indices[i];
        
        int lowP = 1ll << (i >> 1);
        int highP = 1ll << (i + 1 >> 1);
        --lowP, --highP;

        expectedCnt += lowP * (lowP + 1) / 2 + (highP) * (highP + 1) / 2;
        while(lowP --) queryIndices.push_back(lft), queryIndices.push_back(rt);
        queryIndices.push_back(curInd);
        queryIndices.push_back(rt);
        while(highP --) queryIndices.push_back(lft), queryIndices.push_back(rt);
        queryIndices.push_back(rt);
    }

    return {expectedCnt, queryIndices};
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
        int n;
        cin >> n;

        vector<char> ans(n + 1);
        ans[0] = ')';
        int lft = 0, rt = 0;
        if(!ask1(n)) {
            lft = n;
            rt = 1;
            ans[lft] = '(';
            ans[rt] = ')';
        }
        
        if(!lft) {
            int ll = 1;
            int ul = n;

            while(ul - ll > 1) {
                int mid = ll + ul >> 1;
                if(ask1(mid)) ul = mid;
                else ll = mid;
            }
            lft = ll;
            rt = ul;
            ans[lft] = '(';
            ans[rt] = ')';
        }

        while(true) {
            vector<int> indices;
            if(indices = getIndices(ans); !indices.size()) break;
            auto [baseCnt, queryIndices] = constructQueryIndices(indices, lft, rt);
            int totCnt = ask(queryIndices);
            totCnt -= baseCnt;
            for(int i=0;i<indices.size();++i) {
                if((totCnt >> i) & 1) ans[indices[i]] = '(';
                else ans[indices[i]] = ')';
            }
        }
        cout << "! ";
        for(int i=1;i<=n;++i) cout << ans[i];
        cout << endl;
    }
}