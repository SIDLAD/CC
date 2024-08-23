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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int tot = accumulate(all(v),0ll);
    // int tgt = tot/2;

    // int closest_sum = 0;
    // for(int i=0;i<(1ll<<n);i++)
    // {
    //     int sum = 0;
    //     for(int j=0;j<n;j++)
    //     {
    //         if(~i&(1ll<<j))continue;
    //         sum += v[j];
    //         if(sum > tgt)goto inner;
    //     }
    //     debug(sum);
    //     closest_sum = max(closest_sum,sum);
    //     debug(closest_sum);
    //     inner:
    //     42;
    // }

    // cout<<(tgt - closest_sum)*2 + (tot&1)<<endl;
    // debug(tgt,closest_sum);

    vector<int> a(v.begin(),v.begin() + (v.end() - v.begin() >> 1));
    vector<int> b(v.begin() + (v.end() - v.begin()>>1),v.end());
    vector<int> sums_a;
    vector<int> sums_b;
    for(int i=0;i<(1ll<<a.size());i++)
    {
        int cur_sum = 0 ;
        for(int j=0;j<a.size();j++)
        {
            if((1ll<<j) & i)cur_sum += a[j];
        }
        sums_a.push_back(cur_sum);
    }

    for(int i=0;i<(1ll<<b.size());i++)
    {
        int cur_sum = 0;
        for(int j=0;j<b.size();j++)
        {
            if((1ll<<j) & i)cur_sum += b[j];
        }
        sums_b.push_back(cur_sum);
    }

    sort(all(sums_a)),sort(all(sums_b));
    debug(sums_a,sums_b);

    int ptr1 = 0;
    int ptr2 = sums_b.size() - 1;

    int optimal_ans = -1;
    int tgt = accumulate(all(v),0ll)/2;
    for(;ptr1<sums_a.size();ptr1++)
    {
        debug(sums_a[ptr1],sums_b[ptr2]);
        if(sums_a[ptr1] + sums_b[ptr2] > tgt){ptr2--;if(ptr2 <0)break;else {ptr1--;continue;}}
        optimal_ans = max(optimal_ans,sums_a[ptr1] + sums_b[ptr2]);
    }
    debug(optimal_ans);

    cout<<(tgt - optimal_ans)*2 + (tot&1)<<endl;
}