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
double mn, mx;
double calcArea(pair<int, int> a, pair<int, int> b, pair<int,int> c) {
    double x1 = b.second * b.first - (2 * b.second * a.first) - (a.second * a.first);
    x1 /= (a.second - b.second);
    x1 = max(x1, mn);
    double x2 = c.second * c.first - (2 * c.second * a.first) - (a.second * a.first);
    x2 /= (a.second - c.second);
    x2 = min(x2, mx);
    return abs(0.5 * a.second * (x2 - x1));
}

void solvee(){ 
    int n;
    cin >> n;
    vector<pair<double, double>> a(n);
    range(i,0,n) {
        cin >> a[i].first >> a[i].second;
        mn = min(mn, a[i].first);
        mx = max(mx, a[i].first);
    }
    set<pair<double, int>> mns;
    vector<pair<int, int>> lefsAndRights(n);
    lefsAndRights[0].first = 0;
    lefsAndRights[n - 1].second = n - 1;
    range(i,1,n - 1) {
        double curr = atan2(a[i].second, a[i].first);
        if(mns.size() == 0) {
            mns.insert({curr, i});
            lefsAndRights[i].first = 0;
            continue;
        }
        auto mn_curr = *mns.begin();
        if(mn_curr.first > curr) {
            lefsAndRights[i].first = 0;
        }
        else {
            lefsAndRights[i].first = mn_curr.second;
        }
        mns.insert({curr, i});
    }

    set<pair<double, int>> mxs;
    for(int i = n - 2;i>=1;i--) {
        double curr = atan2(a[i].second, a[i].first - mx);
        debug(i, curr);
        if(mxs.size() == 0) {
            mxs.insert({curr, i});
            lefsAndRights[i].second = n - 1;
            continue;
        }
        auto mn_curr = *(--mxs.end());
        if(mn_curr.first > curr) {
            lefsAndRights[i].second = mn_curr.second;
        }
        else {
            lefsAndRights[i].second = n - 1;
        }
        mxs.insert({curr, i});
    }
    debug(lefsAndRights);
    double finalAns = 0.0;
    range(i,1,n-1) {
        finalAns = max(finalAns, calcArea(a[i], a[lefsAndRights[i].first], a[lefsAndRights[i].second]));
        debug(i, calcArea(a[i], a[lefsAndRights[i].first], a[lefsAndRights[i].second]));
    }
    debug(finalAns);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solvee();
}