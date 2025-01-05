#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

unordered_map<int,char> mapping = {{0,'q'},{1,'k'},{2,'j'}};

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
        int n;
        cin>>n;
        vector<vector<int>> inp(3,vector<int>(n + 1));
        for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
        cin>>inp[i][j];

        vector<pair<int,int>> prev(n + 1);
        vector<array<pair<int,int>,3>> dp(n + 1);

        dp[1][0] = {inp[0][1],1};
        dp[1][1] = {inp[1][1],1};
        dp[1][2] = {inp[2][1],1};

        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1];
            bool check = false;
            for(int j=0;j<3;j++)
            {
                if(inp[j][i] < dp[i][j].first)
                {
                    prev[i] = {dp[i][j].second,j};
                    check = true;
                    break;
                }
            }

            if(check)
            {
                for(int j=0;j<3;j++)
                {
                    if(inp[j][i] > dp[i][j].first)dp[i][j] = {inp[j][i],i};
                }
            }
        }

        if(prev[n].first == 0)cout(false);
        else
        {
            cout(true);
            stack<pair<char,int>> st;
            int cur = n;
            while(cur != 1)
            {
                st.emplace(mapping[prev[cur].second],cur);
                cur = prev[cur].first;
            }

            cout<<st.size()<<endl;
            while(st.size())
            {
                cout<<st.top().first<<" "<<st.top().second<<endl;
                st.pop();
            }
        }
    }
}