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
    int n;
    cin>>n;
    vector<array<int,3>> v(n);
    for(int i=0;i<n;i++)cin>>v[i][0]>>v[i][1],v[i][2] = i;

    vector<int> ans1(n),ans2(n);
    sort(all(v),[&](auto& a,auto& b)
    {
        if(a[0] == b[0])return a[1] < b[1];
        return a > b;
    });

    int x = 0;
    ordered_set<pair<int,int>> s;
    for(int i=0;i<n;i++)
    {
        auto [l,r,idx] = v[i];
        auto ub = s.upper_bound({r,INF});
        if(ub == s.end())
        {
            ans1[idx] = s.size();
        }
        else
        ans1[idx] = s.order_of_key(*ub);
        s.insert({r,x++});
    }
    
    for(int i=0;i<n;i++)cout<<ans1[i]<<" ";
    cout<<endl;

    s.clear();
    sort(all(v),[&](auto& a,auto& b)
    {
        if(a[0] == b[0])return a[1] > b[1];
        return a < b;
    });

    x=0;
    for(int i=0;i<n;i++)
    {
        auto [l,r,idx] = v[i];
        auto ub = s.upper_bound({r,-INF});
        if(ub == s.end())
        {
            ans2[idx] = 0;
        }
        else
        ans2[idx] = s.size() - s.order_of_key(*ub);
        s.insert({r,x++});
    }

    for(int i=0;i<n;i++)cout<<ans2[i]<<" ";
    cout<<endl;
}