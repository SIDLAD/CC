#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

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
        int n;
        cin>>n;
        vector<array<int,3>> lr(n);
        for(int i=0;i<n;i++)
        {
            cin>>lr[i][0]>>lr[i][1];
            lr[i][2] = i;
        }

        sort(all(lr),[](auto a, auto b)->bool
        {
            if(a[0] < b[0])return true;
            if(a[0] == b[0] and a[1] > b[1])return true;
            return false;
        });

        vector<int> ans(n);

        set<int> rightends;
        for(int i=0;i<n;i++)
        {
            auto val = rightends.lower_bound(lr[i][1]); 
            if(val != rightends.end())ans[lr[i][2]] += *val - lr[i][1];
            rightends.insert(lr[i][1]);
        }
        
        sort(all(lr),[](auto a, auto b) -> bool
        {
            if(a[1] > b[1])return true;
            if(a[1] == b[1] and a[0] < b[0])return true;
            return false;
        });

        set<int> leftends;
        for(int i=0;i<n;i++)
        {
            auto val = leftends.upper_bound(lr[i][0]);
            if(val != leftends.begin())ans[lr[i][2]] += lr[i][0] - *(--val);
            leftends.insert(lr[i][0]);
        }

        map<pair<int,int>,int> mp;
        range(i,0,n)
        {
            mp[{lr[i][0],lr[i][1]}]++;
        }

        range(i,0,n)
        {
            if(mp[{lr[i][0],lr[i][1]}] > 1)ans[lr[i][2]] = 0;
        }
        range(i,0,n)
        {
            cout<<ans[i]<<endl;
        }
    }
}