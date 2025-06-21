#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int)1e9 + 7; // 998'244'353;
using namespace std;
// insert policy here

// insert mintcode here

// insert randnum here

#if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
void _exe() {}
template <typename T, typename... V>
const T &_exe(const T &t, const V &...v) { return t; }
template <typename T, typename... V>
T &_exe(T &t, V &...v) { return t; }
#define debug(x...) (_exe(x))

class CNothing
{
} cnothing;
template <typename T>
const CNothing &operator<<(const CNothing &proxy, const T &) { return proxy; }
const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &)) { return proxy; }
#define cerr cnothing
#else
#include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int __int128_t
#define double long double
#define all(x) (x).begin(), (x).end()
#define endl '\n' // comment out for interactive problems
#define cout(x) (x ? cout << "YES" << endl : cout << "NO" << endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var)         \
    for (auto &inVar : var) \
    {                       \
        cin >> inVar;       \
    }
#define arrPrint(var)          \
    for (auto outVar : var)    \
    {                          \
        cout << outVar << ' '; \
    }                          \
    cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
struct Point {
    typedef __int128_t T;
	typedef Point P;
	T x, y;
	explicit Point(T x, T y) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

__int128_t calcDist(pair<__int128_t,__int128_t> a, pair<__int128_t,__int128_t> b) {return max(a.first - b.first,b.first - a.first) + max(a.second - b.second,b.second - a.second);}
pair<__int128_t,__int128_t> mp(Point x) { return {x.x,x.y};}

pair<int,int> getPt(const pair<int,int>& cur, const pair<int,int>& dest, __int128_t dist, __int128_t mov) {
    //find a point dist away from dest and mov away from cur -> given it exists for sure
    if(dist == 0) {
        if(calcDist(cur,dest) == mov) return dest;
        else assert(false);
    }
    if(mov == 0) {
        if(calcDist(cur,dest) == dist) return cur;
        else assert(false);
    }
    // debug();
    pair<__int128_t,__int128_t> loc = cur;
    int curDist = calcDist(cur, dest);

    vector<pair<__int128_t,__int128_t>> deltas = {{-1,0}, {0,1}, {1,0}, {0,-1} };
    // debug(cur,dest,dist, mov);
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            auto delta1 = deltas[i];
            auto delta2 = deltas[j];
            auto nextdelta1 = deltas[(i + 1) % 4];
            auto nextdelta2 = deltas[(j + 1) % 4];
            vector line1 = {Point(delta1.first * mov + cur.first,delta1.second * mov + cur.second), Point(nextdelta1.first * mov + cur.first,nextdelta1.second * mov + cur.second)};
            vector line2 = {Point(delta2.first * dist + dest.first,delta2.second * dist + dest.second), Point(nextdelta2.first * dist + dest.first,nextdelta2.second * dist + dest.second)};
            auto [match, interPt] = lineInter(line1[0], line1[1],line2[0],line2[1]);
            auto ip = mp(interPt);
            if(match != 1)continue;
            if(calcDist(ip, dest) == dist and calcDist(ip, cur) == mov){
                return ip;
            }
        }
    }
    assert(false);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    signed n;
    cin >> n;
    signed a, b;
    cin >> a >> b;
    vector<signed> d(n - 1);
    arrPut(d);

    int tot = accumulate(all(d), 0ll);
    if((tot^(a + b))&1){cout(false); return 0;}
    vector<pair<int,int>> prs;
    prs.emplace_back(a + b, a + b);
    for(int i=0;i<n-1;i++) {
        auto& pr = prs.back();
        int newmin = max(pr.first - d[i], d[i] - pr.first);
        newmin = min(newmin,max(pr.second - d[i], d[i] - pr.second));
        if(pr.first <= d[i] and d[i] <= pr.second)newmin = 0;
        int newmax = pr.second + d[i];
        prs.emplace_back(newmin, newmax);
    }
    if(prs.back().first == 0)cout<<"YES"<<endl;
    else{cout<<"NO"<<endl; return 0;}
    prs.back() = {0,0};
    for(int i=n-2;i>=0;i--) {
        // dists[i] = ?
        // use d[i] and dists[i + 1]
        auto& pr = prs[i + 1];
        int newmin = max(pr.first - d[i], d[i] - pr.first);
        newmin = min(newmin,max(pr.second - d[i], d[i] - pr.second));
        if(pr.first <= d[i] and d[i] <= pr.second)newmin = 0;
        int newmax = pr.second + d[i];
        prs[i] = {max(newmin,prs[i].first), min(newmax, prs[i].second)};
        assert(prs[i].first <= prs[i].second);
    }  

    auto printPt = [&](auto x) { cerr << (signed)x.first << " " << (signed)x.second << endl;};

    pair<int,int> curPt = {0,0};
    printPt(curPt);

    for(int i=0;i<n-1;i++) {
        curPt = getPt(curPt,{a,b},prs[i + 1].first,d[i]);
        printPt(curPt);
    }
}