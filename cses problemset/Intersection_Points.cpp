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
    int sum = 0;
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

    void add(int k, int x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    for(;T--;)
    {
        int n;
        cin>>n;
        vector<array<int,3>> verticalline;
        vector<array<int,3>> horizontalline;
        for(int i=0;i<n;i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            if(x1 == x2)
            {
                horizontalline.push_back({x1,y1,y2});
            }
            else
            {
                verticalline.push_back({y1,x1,x2});
            }
        }

        vector<array<int,4>> ordering;
        //first value => y coordinate
        //second value => horizontal/vertical start/vertical end
        //third value => x coord
        //fourth value => x end

        for(auto [xc,ys,ye]: verticalline)
        {
            ordering.push_back({ys,1,xc,xc});
            ordering.push_back({ye,2,xc,xc});
        }
        for(auto [yc,xs,xe]: horizontalline)
        {
            ordering.push_back({yc,0,xs,xe});
        }

        sort(all(ordering));
        Vertex st(-1e6,1e6 + 1);

        int ans = 0;
        range(i,0,ordering.size())
        {
            if(ordering[i][1] == 1)
            {
                st.add(ordering[i][2],1);
            }
            else if(ordering[i][1] == 2)
            {
                st.add(ordering[i][2], -1);
            }
            else
            {
                ans += st.get_sum(ordering[i][2] + 1,ordering[i][3]);
            }
        }

        cout<<ans<<endl;
    }
}