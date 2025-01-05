#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

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

struct Vertex {
    int left, right;
    int mn = INF;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void set(int k, int x) {
        extend();
        mn = min(mn,x);
        if (left_child) {
            if (k < left_child->right)
                left_child->set(k, x);
            else
                right_child->set(k, x);
        }
    }

    int get_min(int lq, int rq) {
        if (lq <= left && right <= rq)
            return mn;
        if (max(left, lq) >= min(right, rq))
            return INF;
        extend();
        return min(left_child->get_min(lq, rq),right_child->get_min(lq, rq));
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("boards.in","r",stdin);
    freopen("boards.out","w",stdout);
    
    int n,p;
    cin>>n>>p;
    Vertex v(0,n + 1);
    vector<array<int,4>> springboards;
    range(i,0,p)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        springboards.push_back({x1,y1,x2,y2});
    }
    priority_queue<array<int,5>,vector<array<int,5>>,greater<array<int,5>>> pq;
    pq.push({0,-1,0,0,0});
    range(i,0,p)
    {
        auto [x1,y1,x2,y2] = springboards[i];
        pq.push({y1,0,x1,x2,y2});
    }
    while(pq.size())
    {
        if(pq.top()[0] > n)break;
        if(pq.top()[1] == 0)
        {
            auto [ys,t,xs,xe,ye] = pq.top();
            pq.pop();
            auto prevaugans = v.get_min(0,xs + 1);
            pq.push({ye,-1,xe, prevaugans - xe - ye + xs + ys,0});
        }
        else
        {
            auto [ypreve, t, xpreve, augmentedansprev,_] = pq.top();
            pq.pop();
            v.set(xpreve, augmentedansprev);
        }
    }

    int augans = v.get_min(0,n + 1);
    cout<<n + n + augans<<endl;
}