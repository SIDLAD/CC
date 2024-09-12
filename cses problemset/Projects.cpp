#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
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
    
    class CNothing {};

    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&)
    {
        return proxy;
    }

    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
    {
        return proxy;
    }
    CNothing cnothing;
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

struct Vertex {// [l,r)
    int left, right;
    int mx = 0;
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
        mx = max(mx,x);
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_max(int lq, int rq) {
        if (lq <= left && right <= rq)
            return mx;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return max(left_child->get_max(lq, rq), right_child->get_max(lq, rq));
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // Vertex st(0,1e9 + 1);
    int n;
    cin>>n;
    vector<array<int,3>> v(n);
    for(int i =0;i<n;i++)cin>>v[i][0]>>v[i][1]>>v[i][2];
    // for(int i=0;i<n;i++)
    // {
    //     int val = st.get_max(0,v[i][0]);
    //     st.add(v[i][1],val+v[i][2]);
    //     ans = max(ans,val + v[i][2]);
    //     debug(val,v[i][2]);
    // }
    // cout<<ans<<endl;

    sort(all(v),[&](auto& a,auto& b){return a[1]  < b[1];});

    vector<int> dp(n);
    dp[0] = v[0][2];
    for(int i=1;i<n;i++)
    {
        int cur;
        int idx = lower_bound(all(v),array<int,3>{0ll,v[i][0],0ll},[&](auto& a, auto& b){return a[1] < b[1];}) - v.begin() - 1;
        if(idx == -1)
        {
            cur = v[i][2];
        }
        else
        {
            cur = dp[idx] + v[i][2];
        }
        dp[i] = max(cur,dp[i-1]);
    }
    cout<<dp[n-1]<<endl;
}