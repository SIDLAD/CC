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
        vi a(n);
        arrput(a);
        map<int, vi> mp;
        for(int i=0;i<n;++i) mp[a[i]].push_back(i);
        sort(all(a)), reverse(all(a));
        a.erase(unique(all(a)), a.end());
        debug(a);
        vi minDels(n, INF);
        map<int, int> bestAns;
        for(int i=0;i<a.size();++i) {
            vi poss = mp[a[i]];
            reverse(all(poss));
            bool fl = false;
            if(i && a[i-1] == a[i] + 1) fl = true;
            if(!fl) {
                //best ans remains the same
                for(int ind=0;ind<poss.size();++ind)
                    minDels[poss[ind]] = (i == 0 ? 0 : bestAns[a[i-1]]); 
                bestAns[a[i]] = i ? bestAns[a[i-1]] : 0;
                continue;
            }
            vi& prevPos = mp[a[i] + 1];
            int curBestAns = bestAns[a[i] + 1] + poss.size();
            for(int ind=0;ind<poss.size();++ind) {
                int ep1Ind = lower_bound(all(prevPos), poss[ind]) - prevPos.begin() - 1;
                int curDels = (i == 1 ? 0 : bestAns[a[i-2]]) + sz(mp[a[i] + 1]);
                if(ep1Ind != -1) {
                    curDels = min(curDels, minDels[prevPos[ep1Ind]] + sz(prevPos) - ep1Ind - 1);
                }
                curDels += sz(poss) - ind - 1;;
                curBestAns = min(curBestAns, curDels);
                debug(a[i], curDels);
                minDels[poss[ind]] = curDels;
            }
            for(int ind=poss.size() - 2; ind >= 0; --ind) {
                minDels[poss[ind]] = min(minDels[poss[ind + 1]], minDels[poss[ind]]);
            }
            bestAns[a[i]] = curBestAns;
        }

        debug(minDels);
        debug(bestAns);
        debug("--------------");

        int ans = bestAns[a.back()];
        if(a.size() >= 2 and a[a.size() - 2] == a.back() + 1)
            ans = min(ans, bestAns[a.back() + 1] + (int)mp[a.back() + 1].size());
        cout << ans << endl;
    }
}