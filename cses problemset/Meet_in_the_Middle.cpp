#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order

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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<40;i++)cin>>v[i];
    vector<int> v1(n/2),v2(n - n/2);
    int i;
    for(i=0;i<n/2;i++)v1[i] = v[i];
    for(;i<n;i++)v2[i - n/2] = v[i];

    int s1 = n/2,s2 = n - n/2;
    umap<int,int> m1;
    umap<int,int> m2;
    for(int i=0;i<(1<<s1);i++)
    {
        int cursum = 0;
        for(int j=0;j<s1;j++)
        {
            if((1<<j) & i)
            {
                cursum += v1[j];
            }
        }
        m1[cursum]++;
    }
    for(int i=0;i<(1<<s2);i++)
    {
        int cursum = 0;
        for(int j=0;j<s2;j++)
        {
            if((1<<j) & i)
            {
                cursum += v2[j];
            }
        }
        m2[cursum]++;
    }
    int ans = 0;
    debug(m1,m2);
    for(auto [ele,cnt]:m1)
    {
        if(m2.find(x - ele)!=m2.end())
        ans += (cnt * m2[x-ele]);
    }
    cout<<ans<<endl;
}