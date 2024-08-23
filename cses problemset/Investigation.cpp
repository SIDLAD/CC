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
// #define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> edges(n,vector<pair<int,int>>(0));
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        edges[a].push_back({b,w}); 
    }

    vector<int> mx(n);
    vector<int> mn(n);
    vector<int> cnt(n);
    vector<int> d(n,INF);
    // vector<bool> processed(n);
    set<pair<int,int>> st;

    st.insert({0,0});
    cnt[0] = 1;
    d[0] = 0;

    while(st.size())
    {
        auto [dist,node] = (*st.begin());
        st.erase(st.begin());
        // processed[node] = true;
        for(auto [neighbour,weight]: edges[node])
        {
            if(d[neighbour] > d[node] + weight)
            {
                mx[neighbour] = mx[node] + 1;
                mn[neighbour] = mn[node] + 1;
                cnt[neighbour] = cnt[node];
                st.erase({d[neighbour],neighbour});
                d[neighbour] = d[node] + weight;
                st.insert({d[neighbour],neighbour});
            }
            else if(d[neighbour] == d[node] + weight)
            {
                mx[neighbour] = max(mx[neighbour],mx[node] + 1);
                mn[neighbour] = min(mn[neighbour],mn[node] + 1);
                cnt[neighbour] = (cnt[neighbour] + cnt[node])%M;
            }
        }
    }
    cout<<d[n-1]<<" "<<cnt[n-1]<<" "<<mn[n-1]<<" "<<mx[n-1]<<endl;
}