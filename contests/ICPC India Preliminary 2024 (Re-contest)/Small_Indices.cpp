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

int n;
vector<int> a,b;

map<array<int,3>,int> dp;
int solve(int curidx, int biggest, int secondbiggest)
{
    if(curidx == n)return 0;
    if(dp.count({curidx,biggest,secondbiggest}))return dp[{curidx,biggest,secondbiggest}];
    if(b[curidx] <= biggest + secondbiggest or a[curidx] > biggest + secondbiggest)
    {
        vector<int> v = {biggest,secondbiggest, b[curidx]};
        sort(all(v));
        int ans = solve(curidx + 1, v[2],v[1]);
        if(b[curidx] <= biggest + secondbiggest)ans++;
        return dp[{curidx,biggest,secondbiggest}] = ans;
    }
    else
    {
        assert(b[curidx] > biggest + secondbiggest and a[curidx] <= biggest + secondbiggest);
        vector<int> ara = {biggest,secondbiggest,a[curidx]};
        vector<int> arb = {biggest,secondbiggest,b[curidx]};
        sort(all(ara));
        sort(all(arb));
        int ans1 = solve(curidx + 1, ara[2],ara[1]) + 1;
        int ans2 = solve(curidx + 1,arb[2],arb[1]);
        return dp[{curidx,biggest,secondbiggest}] = max(ans1,ans2);
    }
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
        cin>>n;
        dp.clear();
        a.assign(n,0);
        b.assign(n,0);
        arrPut(a);
        arrPut(b);

        for(int i=0;i<n;i++)
        {
            if(a[i] > b[i])swap(a[i],b[i]);
        }
        cout<<solve(2,max(b[0],b[1]),min(b[0],b[1]))<<endl;
    }
}