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
using Line = array<pair<int,int>,2>;

struct fract
{
    int num,den;
    fract(int num,int den){
        if(den < 0){
            den *=-1;
            num *= -1;
        }
        int g = gcd(den,num);
        num /= g, den /= g;
        this->num = num;
        this->den = den;
    }
    bool isgreaterorequal(fract f2)
    {
        return this->num * f2.den >= f2.num * this->den;
    }
    bool islessorequal(fract f2)
    {
        return this->num * f2.den <= f2.num * this->den;
    }
    bool isgreaterorequal(int n2)
    {
        fract f2 = {n2,1};
        return this->num * f2.den >= f2.num * this->den;
    }
    bool islessorequal(int n2)
    {
        fract f2 = {n2,1};
        return this->num * f2.den <= f2.num * this->den;
    }
};

vector<pair<int,int>> pts1,pts2;
int n;

array<int,3> solveabcLine(Line line)
{
    auto [x1,y1] = line[0];
    auto [x2,y2] = line[1];
    int a,b,c;
    b = (x2 - x1);
    a = (y1 - y2);
    c = -(b*y1 + a*x1);
    return {a,b,c};
}

fract getintersecty(Line a, Line b)
{
    auto [a1,b1,c1] = solveabcLine(a);
    auto [a2,b2,c2] = solveabcLine(b);
    // debug(a1,b1,c1);
    // debug(a2,b2,c2);
    int numy = a1*c2 - a2*c1;
    int deny = a2*b1 - a1*b2;
    return fract(numy,deny);
}

fract getintersectx(Line a, Line b)
{
    auto [a1,b1,c1] = solveabcLine(a);
    auto [a2,b2,c2] = solveabcLine(b);
    // debug(a1,b1,c1);
    // debug(a2,b2,c2);
    int numy = b1*c2 - b2*c1;
    int deny = b2*a1 - b1*a2;
    return fract(numy,deny);
}

Line createLine(pair<int,int> pt1,pair<int,int> pt2)
{
    return Line({pt1,pt2});
}

bool doIntersect(Line a, Line b)
{
    auto yintersect = getintersecty(a,b);
    auto xintersect = getintersectx(a,b);
    // debug(yintersect.num,yintersect.den);
    // debug(xintersect.num,xintersect.den);
    // debug(a[0],a[1],b[0],b[1]);
    // debug(yintersect.isgreaterorequal(min(a[0].second,a[1].second)) and yintersect.islessorequal(max(a[0].second,a[1].second)));
    // debug(yintersect.isgreaterorequal(min(b[0].second,b[1].second)) and yintersect.islessorequal(max(b[0].second,b[1].second)));
    // debug(xintersect.isgreaterorequal(min(a[0].first,a[1].first)) and xintersect.islessorequal(max(a[0].first,a[1].first)));
    // debug(xintersect.isgreaterorequal(min(b[0].first,b[1].first)) and xintersect.islessorequal(max(b[0].first,b[1].first)));
    if(yintersect.isgreaterorequal(min(a[0].second,a[1].second)) and yintersect.islessorequal(max(a[0].second,a[1].second))
        and
        yintersect.isgreaterorequal(min(b[0].second,b[1].second)) and yintersect.islessorequal(max(b[0].second,b[1].second))
        and 
        xintersect.isgreaterorequal(min(a[0].first,a[1].first)) and xintersect.islessorequal(max(a[0].first,a[1].first))
        and
        xintersect.isgreaterorequal(min(b[0].first,b[1].first)) and xintersect.islessorequal(max(b[0].first,b[1].first)))
        return true;
    return false;  
}

bool acceptablePermutation(vector<int>& permutation)
{
    // debug(permut `ation);
    vector<Line> lines;
    for(int i=0;i<n;i++)
    {
        lines.push_back(createLine(pts1[i],pts2[permutation[i]]));
    }
    // debug(lines.size());
    for(int i=0;i<lines.size();i++)for(int j=i + 1;j<lines.size();j++)
    {
        if(doIntersect(lines[i],lines[j])){
            if(permutation == vector<int>({0, 2, 1})) {
                debug(i, j);
            }
            return false;
        }
    }
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    // Line a = {make_pair(1l,1l),make_pair(4l,1l)};
    // Line b = {make_pair(-1l,2l),make_pair(-1l,0l)};
    // debug(doIntersect(a,b));
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pts1.resize(n);
        pts2.resize(n);
        for(auto& [x,y]:pts1)cin>>x>>y;
        for(auto& [x,y]:pts2)cin>>x>>y;

        vector<int> permutation(n);
        iota(all(permutation),0ll);

        do
        {
            // debug(permutation);
            if(acceptablePermutation(permutation))
            {
                for(int i=0;i<n;i++)
                {
                    cout<<2<<endl;
                    cout<<pts1[i].first<<" "<<pts1[i].second<<endl;
                    cout<<pts2[permutation[i]].first<<" "<<pts2[permutation[i]].second<<endl;
                }
                goto outer;
            }

        } while (next_permutation(all(permutation)));
        
        assert(false);
        outer:42;
    }
}