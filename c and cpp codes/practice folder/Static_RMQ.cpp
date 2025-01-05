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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int n,q;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int lgn = bit_width((unsigned long long)n) - 1;
    vector<vector<int>> sparse(lgn + 1,vector<int>(n));
    copy(all(v),sparse[0].begin());
    for(int i=1;i<=lgn;i++)for(int j=0;j + (1<<i)<=n;j++)
    sparse[i][j] = min(sparse[i-1][j],sparse[i-1][j + (1<<i-1)]);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int lgdiff = bit_width((unsigned long long)r - l) - 1;
        cout<<min(sparse[lgdiff][l],sparse[lgdiff][r-(1<<lgdiff)])<<endl;
    }
}