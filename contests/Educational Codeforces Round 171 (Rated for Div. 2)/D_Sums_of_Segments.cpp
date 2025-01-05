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

vector<int> simplepre;
vector<int> weightedpre;
int _[(int)3e5 + 10] = {};
int* racksumpre = _ + 5;
int n;
vector<int> v;

int getsimplepre(int l,int r)
{
    if(r < l)return 0;
    return simplepre[r] - (l==0?0:simplepre[l-1]);
}
int getweightedpre(int l, int r)
{
    if(r < l)return 0;
    return weightedpre[r] - (l==0?0:weightedpre[l-1]);
}


int solve(int ri)
{
    int ll = -1;
    int ul = n;
    while(ul - ll > 1)
    {
        int mid = ll + ul >> 1;
        if((mid + 1)* n - mid * (mid + 1)/2 <= ri)ll = mid;
        else ul = mid;
    }
    
    int ans = racksumpre[ll];

    int rem = ri - ((ll + 1)* n - ll * (ll + 1)/2);

    int i = ul;
    int u = rem + i - 1;
    ans += (u + 1) * (getsimplepre(i,u)) - (getweightedpre(i,u));

    debug(ri,ll,ul,ans,rem);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    v.assign(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    simplepre.assign(n,0);
    weightedpre.assign(n,0);
    partial_sum(all(v),simplepre.begin());
    weightedpre[0] = 0;
    for(int i=1;i<n;i++)
    {
        weightedpre[i] = weightedpre[i-1] + (i * v[i]);
    }
    
    for(int i = 0;i<n;i++)
    {
        racksumpre[i] = n * getsimplepre(i,n-1) - getweightedpre(i,n-1);
        racksumpre[i] += racksumpre[i-1];
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        int li,ri;
        cin>>li>>ri;
        cout<<solve(ri) - solve(li - 1)<<endl;
    }
}