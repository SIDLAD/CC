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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    // cin>>T;
    for(;T--;)
    {
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<pair<int,int>> ai(n);
        for(int i=0;i<n;i++)ai[i].first = a[i],ai[i].second = i;
        sort(all(ai),greater<pair<int,int>>());

        ordered_set<int> os;
        for(int i=0;i<n;i++)os.insert(i);

        vector<vector<int>> monsters(n + 1);

        for(int level = 1;level <= n;level++)
        {
            for(int k=1; k<= n; k++)
            {
                if(monsters[k].size() and monsters[k].back() == n)break;
                int curorder = monsters[k].empty()? 0 : os.order_of_key(monsters[k].back() + 1);
                int nextorder = (curorder + k - 1 >= os.size() ? n : *os.find_by_order(curorder + k - 1));
                monsters[k].push_back(nextorder);
                debug(level,k,curorder,nextorder);
            }
            while(ai.size() and ai.back().first <= level)
            os.erase(ai.back().second),ai.pop_back();
        }
        while(q--)
        {
            int i,x;
            cin>>i>>x;
            i--;
            int curlevel = lower_bound(all(monsters[x]),i) - monsters[x].begin() + 1;
            cout(curlevel <= a[i]);
        }
    }
}