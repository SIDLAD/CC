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

using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

struct rng{
    int start;
    int end;
    int k;
};

rng intersection(rng r1, rng r2)
{
    if(r2.start == -INF)swap(r1,r2);
    if(r1.start == -INF)return r2;

    int k = r1.k;

    rng ans = {-1,-1,k};
    if(r2.start > r2.end)swap(r1,r2);
    if(r1.start <= r1.end or (r1.start > r1.end and r2.start > r2.end))
    {
        ans.start = max(r1.start,r2.start);
        ans.end = min(r1.end,r2.end);
        if(r1.start <= r1.end and not(ans.start <= ans.end))
        {
            ans.start = -1;
            ans.end = -1;
        }
    }
    else
    {
        if(r2.end >= r1.start)
        {
            ans.start = max(r1.start,r2.start);
            ans.end = r2.end;
        }
        else if(r1.end >= r2.start)
        {
            ans.start = r2.start;
            ans.end = min(r2.end,r1.end);
        }
    }
    return ans;
};

int first_time(rng x, int t)
{
    if(x.start == -1)return -1;
    int k = x.k;
    int rem = t%(2*k);

    return t + (x.start + 2*k - rem)%(2*k);
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
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        rng ans = {-INF,INF};
        for(int i=0;i<n;i++)
        {
            rng tmp = {v[i]%(2*k),(v[i] + k - 1) % (2*k), k};
            ans = intersection(ans,tmp);
        }
        debug(ans.start,ans.end,ans.k);
        int mx = *max_element(all(v));
        debug(mx);
        cout<<first_time(ans,mx)<<endl;
    }
}

