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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T=1;
    for(;T--;)
    {
        int n,m1,m2;
        cin>>n>>m1;
        vector<pair<int,int>> e1(m1);
        for(int i=0;i<m1;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a>b)swap(a,b);
            e1[i] = {a,b};
        }
        debug(e1);
        cin>>m2;
        set<pair<int,int>> st;
        for(int i=0;i<m2;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a>b)swap(a,b);
            st.insert({a,b});
        }
        debug(st);
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
        {
            cin>>cost[i+1][j+1];
            debug(i+1,j+1,cost[i+1][j+1]);
        }
        debug(cost);
        vector<int> v(n);
        int mn = INF;
        iota(all(v),1ll);
        do
        {
            debug(v);
            set<pair<int,int>> stc = st;
            int ans = 0;
            for(auto [a,b]:e1)
            {
                a = v[a-1];
                b = v[b-1];
                if(a > b)swap(a,b);
                if(stc.count({a,b}))
                {
                    stc.erase({a,b});
                }
                else
                {
                    ans += cost[a][b];
                    debug(a,b);
                }
            }
            for(auto [a,b]:stc)
            {
                ans += cost[a][b];
                debug(a,b,"");
            }
            debug(ans);
            mn = min(mn,ans);
        } while (next_permutation(all(v)));
        cout<<mn<<endl;
    }
}