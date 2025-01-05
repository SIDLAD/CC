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

double intersectX(int m1, int c1, int m2, int c2)
{
    return (double) (c1 - c2) / (m2 - m1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<array<int,3>> pts(n);
    for(int i=0;i<n;i++)
    {
        cin>>pts[i][0]>>pts[i][1]>>pts[i][2];
    }

    sort(all(pts));
    debug(pts);
    vector<int> f(n);
    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    for(int i=0;i<n;i++)
    {
        int variable = pts[i][1];
        while(dq.size() > 1)
        {
            auto [slope,intercept] = dq[0];
            auto [nextslope,nextintercept] = dq[1];
            if(nextslope * variable + nextintercept > slope * variable + intercept)
            dq.pop_front();
            else
            break;
        }

        auto [slope, intercept] = dq[0];
        f[i] = pts[i][0]*pts[i][1] - pts[i][2] + (slope*variable + intercept);
        while(dq.size() > 1)
        {
            if(intersectX(dq[dq.size() - 1].first,dq[dq.size() - 1].second,dq[dq.size() - 2].first,dq[dq.size() - 2].second)
            <= intersectX(dq[dq.size() - 1].first,dq[dq.size() - 1].second,-pts[i][0],f[i]))
            {
                dq.pop_back();
            }
            
            else break;
        }
        dq.push_back({-pts[i][0],f[i]});
    }
    debug(f);
    cout<<*max_element(all(f))<<endl;
}