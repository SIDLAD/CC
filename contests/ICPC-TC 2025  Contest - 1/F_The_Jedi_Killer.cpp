#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int lm, lg;

struct Line {
    int a,b,c;
    Line(int a, int b, int c) : a(a),b(b),c(c){}
};

Line getLine(int x1, int y1, int x2, int y2) {
    return Line(y2 - y1,x1 - x2,x2*y1 - x1 * y2); // working
}

Line getPerpendicularLine(Line l, int x, int y) {
    return Line(l.b, -l.a, l.a * y - l.b * x); // working
}

bool isParallel(Line l1, Line l2) {
    return (l1.a * l2.b == l2.a * l1.b);
}

pair<double,double> getIntersection(Line l1, Line l2) { // working
    double y = 1.0 * (l1.a * l2.c - l2.a * l1.c) / (l2.a * l1.b - l1.a * l2.b);
    double x = 1.0 * (l1.b * l2.c - l2.b * l1.c) / (l2.b * l1.a - l1.b * l2.a);
    return {x,y};
}

template<typename T, typename U>
double getSquareDistance(pair<T,T> p1, pair<U,U> p2) { // working
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
    auto l1 = getLine(x1,y1,x2,y2);
    auto l2 = getLine(x2,y2,x3,y3);
    if(isParallel(l1,l2)) { // if collinear, need to only check max dist bw them, and compare with 2 * Lg / Lm
        auto d1 = getSquareDistance(make_pair(x1,y1),make_pair(x2,y2));
        auto d2 = getSquareDistance(make_pair(x2,y2),make_pair(x3,y3));
        auto d3 = getSquareDistance(make_pair(x1,y1),make_pair(x3,y3));
        auto sqd = max({d1,d2,d3});
        return (sqd <= max(lm * lm,4 * lg * lg) + EPS);
    }

    auto baseLine = getLine(x1,y1,x2,y2);
    auto perpendicular = getPerpendicularLine(baseLine, x3, y3);
    auto intersection = getIntersection(baseLine, perpendicular);

    auto sq1 = max(getSquareDistance(intersection, make_pair(x1,y1)), getSquareDistance(intersection, make_pair(x2,y2)));
    auto sq2 = getSquareDistance(intersection, make_pair(x3,y3));
    if((intersection.first <= min(x1,x2) + EPS or intersection.first + EPS >= max(x1 , x2)) and (intersection.second <= min(y1,y2) + EPS or intersection.second + EPS >= max(y1 , y2))) {
        if (sq2 <= lg * lg + EPS and sq1 <= lm * lm + EPS)return true;
    }

    return (sq1 <= lg * lg + EPS and sq2 <= lm * lm + EPS);
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
        int x1,y1,x2,y2,x3,y3;
        cin >> lm >> lg >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        bool answer = false;
        answer |= check(x1,y1,x2,y2,x3,y3);
        answer |= check(x2,y2,x3,y3,x1,y1);
        answer |= check(x3,y3,x1,y1,x2,y2);
        cout(answer);
    }
}