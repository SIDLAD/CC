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

#define all(v) (v).begin(),(v).end()

int k[200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>k[i];
    int ll = 1;
    int ul = n+1;
    vector<pair<int,int>> create_mapping(n);
    for(int i=0;i<n;i++)
    {
        create_mapping[i].first = k[i];
        create_mapping[i].second = i;
    }
    sort(all(create_mapping));
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(i==0 or create_mapping[i].first != create_mapping[i-1].first)
        {
            cnt++;
        }
        k[create_mapping[i].second] = cnt;
    }
    while(ul - ll > 1)
    {
        int mid = ll + ul>>1;
        unordered_map<int,int> mp;
        int greater_than_one = 0;
        bool check = false;
        for(int i=0;i<n;i++)
        {
            mp[k[i]] ++;
            if(mp[k[i]] == 2)greater_than_one ++;

            if(mp.size() == mid and !greater_than_one)
            {
                check = true;
                break;
            }
            if(i -mid + 1 >= 0)
            {
                mp[k[i-mid + 1]]--;
                if(mp[k[i-mid + 1]] == 1)greater_than_one --;
                if(mp[k[i-mid+1]] == 0)mp.erase(k[i-mid+1]);
            }
        }
        if(check)ll = mid;
        else ul = mid;
    }
    cout<<ll<<endl;
}