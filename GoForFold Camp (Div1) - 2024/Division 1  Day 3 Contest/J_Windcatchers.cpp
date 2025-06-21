#include <bits/stdc++.h>
const long double EPS = 1e-9;
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
#define myPi pair<double, double>
int n;
vector<myPi> a;

double calcLine(vector<double> &l, myPi p1) {
    return l[0] * p1.first + l[1] * p1.second + l[2];
}

vector<double> makeLine(myPi p1, myPi p2) {
    return {p2.second - p1.second, p1.first - p2.first, p2.first * p1.second - p1.first * p2.second};
}

vector<double> makeUpperLine(myPi p1, myPi p2, double width) {
    auto midLine = makeLine(p1, p2);
    double theta = atan2(-1 * midLine[0], midLine[1]);
    double secTheta = 1.0 / cosl(theta);
    return {midLine[0], midLine[1], midLine[2] + width * secTheta * (p2.first - p1.first)};
}

vector<double> makeLowerLine(myPi p1, myPi p2, double width) {
    auto midLine = makeLine(p1, p2);
    double theta = atan2(-1 * midLine[0], midLine[1]);
    double secTheta = 1.0 / cosl(theta);
    return {midLine[0], midLine[1], midLine[2] + width * secTheta * (p1.first - p2.first)};
}

bool possible(double mid) {
    bool check = false;
    for(int i = 0;i<n;i++) {
        for(int j = i + 1;j<n;j++) {
            auto midLine = makeLine(a[i], a[j]);
            auto upperLine = makeUpperLine(a[i], a[j], mid), lowerLine = makeLowerLine(a[i], a[j], mid);
            double upMid = calcLine(upperLine, a[i]), loMid = calcLine(lowerLine, a[i]);
            
            if(upMid < EPS) {
                int ct1 = 0;

            }
        }
    }
    auto midLine = makeLine() 
}

void solve() {
    cin >>n;
    a.resize(n);
    range(i,0,n) {
        cin >> a[i].first >> a[i].second;
    }
    double lo = EPS, hi = 1e9;
    double ans = 0;
    while(hi - lo >= -EPS) {
        double mid = (lo + hi)/2.0;
        if(possible(mid)) {
            ans = mid;
            lo = mid + EPS;
        }
        else {
            hi = mid - EPS;
        }
    }
    cout << fixed << setprecision(9);
    cout << ans << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}