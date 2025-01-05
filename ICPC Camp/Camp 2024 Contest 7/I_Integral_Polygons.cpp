#include <bits/stdc++.h>
const long double EPS = 1e-7;
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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

bool parity(pair<int,int> a, pair<int,int> b)
{
    debug(a,b,(a.first&b.second) ^ (a.second&b.first));
    return (a.first&b.second) ^ (a.second&b.first);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("integral.in","r",stdin);
    freopen("integral.out","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    map<pair<pair<int,int>,int>,int> freq;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a&1,b&1});
    }

    debug(v);
    
    vector<int> prepar(n);
    for(int i=0;i<n;i++)
    {
        prepar[i] = parity(v[i],v[(i+1)%n]);
        if(i!=0)prepar[i] = prepar[i]^prepar[i-1];
        freq[{v[(i + 1)%n],prepar[i]}]++;
    }
    debug(prepar);

    for(auto [pr,f]:freq)
    {
        debug(pr,f);
    }
    

    if(prepar.back() == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    debug();

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        freq[{v[(i+1)%n],prepar[(i)%n]}]--;
        freq[{v[i],prepar[(i+n-1)%n]}]--;
        freq[{v[(i+n-1)%n],prepar[(i+n - 2)%n]}]--;

        debug(i,(prepar[(i+n-1)%n]));
        for(auto [pr,f]:freq)
        {
            debug(pr,f);
        }
        for(auto [pr,f]:freq)
        if((prepar[(i+n-1)%n]) ^ parity(v[i],pr.first) == pr.second)
        {
            ans += f;
        }
        
        freq[{v[(i+1)%n],prepar[(i)%n]}]++;
        freq[{v[i],prepar[(i+n-1)%n]}]++;
        freq[{v[(i+n-1)%n],prepar[(i+n - 2)%n]}]++;

        debug(ans,i);
        debug();
    }
    assert(ans%2 == 0);
    cout<<ans/2<<endl;
}