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
    int n,q;
    cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    map<int,int> latest;
    vector<pair<pair<int,int>,int>> queries;
    for(int i=0;i<q;i++)
    {
        queries.push_back({{0,0},i});
        cin>>queries[i].first.first>>queries[i].first.second;
    }

    sort(all(queries),[&](auto& a, auto& b){return a.first.second < b.first.second;});
    int lastindex = 0;
    vector<int> fenwick(n + 1);
    vector<int> fenwickdebug(n+1);
    auto modify = [&](int inc, int index)
    {
        fenwickdebug[index] += inc;
        for(int i=index;i<=n;i += (i & -i))
        {
            fenwick[i] += inc;
        }
    };


    auto query = [&](int l, int r)
    {
        l--;
        int rsum = 0;
        int lsum = 0;
        for(int i = r;i>=1; i-= (i & -i))
        {
            rsum += fenwick[i];
        }
        for(int i = l;i>=1; i-= (i & -i))
        {
            lsum += fenwick[i];
        }
        return rsum - lsum;
    };
    vector<int> ans(q);
    for(int i=0;i<q;i++)
    {
        debug(i);
        auto [a,b] = queries[i].first;
        while(lastindex < b)
        {
            lastindex++;
            if(latest.count(v[lastindex])){
                modify(-1,latest[v[lastindex]]);
                latest.erase(v[lastindex]);
            }
            latest[v[lastindex]] = lastindex;
            modify(1,lastindex);
        }
        ans[queries[i].second] = query(a,b);
    }
    for(auto& ele:ans)
    {
        cout<<ele<<endl;
    }
}