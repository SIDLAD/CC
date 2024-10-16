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
vector<int> a,b;
vector<int> pregcda,pregcdb,sufgcda,sufgcdb;
int n;

int gcd(int a, int b)
{
    if(a > b)swap(a,b);
    if(b == INF)return a;
    return __gcd(a,b);
}

int gcd(initializer_list<int> nums)
{
    int result = INF;
    for(auto ele:nums)result = gcd(result,ele);
    return result;
}

pair<int,int> gcdfreq(int l, int r)
{
    if(l == r)
    {
        int ga = gcd({pregcda[l-1],b[l],sufgcda[l+1]});
        int gb = gcd({pregcdb[l-1],a[l],sufgcdb[l+1]});
        return {ga+gb,1};
    }
    
    int mid = l + r>>1;
    auto lg = gcdfreq(l,mid);
    auto rg = gcdfreq(mid+1,r);
    if(lg.first < rg.first)swap(lg,rg);
    if(lg.first == rg.first)lg.second += rg.second;

    map<pair<int,int>, int> lm,rm;

    int curlga = INF,curlgb = INF;
    for(int i=mid;i>=l;i--)
    {
        curlga = gcd(curlga,b[i]);
        int ag = gcd(curlga,pregcda[i-1]);
        curlgb = gcd(curlgb,a[i]);
        int bg = gcd(curlgb,pregcdb[i-1]);
        lm[{ag,bg}]++;
    }
    int currga = INF,currgb = INF;
    for(int i=mid+1;i<=r;i++){
        currga = gcd(currga,b[i]);
        int ag = gcd(currga,sufgcda[i+1]);
        currgb = gcd(currgb,a[i]);
        int bg = gcd(currgb,sufgcdb[i+1]);
        rm[{ag,bg}]++;
    }

    map<int,int> gcdmp;

    for(auto [lgcd,lfreq]:lm)
    {
        auto [lgcda,lgcdb] = lgcd;
        for(auto [rgcd,rfreq]:rm)
        {
            auto [rgcda,rgcdb] = rgcd;
            int sum = gcd(lgcda,rgcda) + gcd(lgcdb,rgcdb);
            gcdmp[sum] += lfreq * rfreq;
        }
    }

    auto [mxgcdsum,mxgcdsum_freq] = *(--gcdmp.end());
    if(mxgcdsum > lg.first)
    {
        lg.first = mxgcdsum;
        lg.second = mxgcdsum_freq;
    }
    else if(mxgcdsum == lg.first)
    {
        lg.second += mxgcdsum_freq;
    }
    return lg;
}

auto solve(){
    return gcdfreq(1,n);
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
        a.resize(n+2),b.resize(n+2);
        a[0] = a[n+1] = b[0] = b[n+1] = INF;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];


        pregcda.resize(n+2),pregcdb.resize(n+2),sufgcda.resize(n+2),sufgcdb.resize(n+2);
        pregcda[0] = sufgcda[n+1] = pregcdb[0] = sufgcdb[n+1] = INF;
        for(int i=1,j=n;i<=n;i++,j--)
        {
            pregcda[i] = gcd(pregcda[i-1],a[i]);
            pregcdb[i] = gcd(pregcdb[i-1],b[i]);
            sufgcda[j] = gcd(sufgcda[j+1],a[j]);
            sufgcdb[j] = gcd(sufgcdb[j+1],b[j]);
        }
        auto answer = solve();
        cout<<answer.first<<" "<<answer.second<<endl;
    }
}