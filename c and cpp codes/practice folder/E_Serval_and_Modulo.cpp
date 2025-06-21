#include <bits/stdc++.h>
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

int n;
int a[(int)1e6 + 1];
int b[(int)1e6 + 1];
int c[(int)1e6 + 1];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    auto getF = [&](int x){
        if(x == 0) return vector{1000001ll};
        vector<int> fs;
        int i;
        for(i=1;i*i < x; ++i) if(x%i == 0) fs.push_back(i), fs.push_back(x/i);
        if(i*i == x) fs.push_back(i);
        return fs;
    };

    int T;
    cin>>T;
    for(;T--;)
    {
        cin >> n;
        for(int i=0;i<n;i++)cin >> a[i];
        for(int i=0;i<n;i++)cin >> b[i];
        sort(b,b+n);
        int xf = accumulate(a,a+n, 0ll) - accumulate(b,b+n,0ll);
        auto fs = getF(xf);
        for(auto f: fs) {
            for(int i=0;i<n;i++)c[i] = a[i] % f;
            sort(c,c + n);
            bool ch = true;
            for(int i=0;i<n;i++)if(c[i] != b[i])ch = false;
            if(ch) {cout << f << endl; goto outer;}
        }

        cout << -1 << endl;
        outer:42;
    }
}