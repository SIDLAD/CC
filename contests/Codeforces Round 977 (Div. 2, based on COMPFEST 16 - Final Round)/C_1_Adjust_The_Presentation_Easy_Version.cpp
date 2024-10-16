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
#define cout(x) x?cout<<"YA"<<endl:cout<<"TIDAK"<<endl

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
        int n,m,q;
        cin>>n>>m>>q;
        assert(q==0);
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int> b(m);
        for(int i=0;i<m;i++)cin>>b[i];
        debug(a,b);
        set<int> arrived;
        vector<int> order;
        for(int i=0;i<m;i++)
        {
            if(!arrived.count(b[i]))
            {
                arrived.insert(b[i]);
                order.push_back(b[i]);
            }
        }
        bool check = true;
        assert(order.size() <= n);
        for(int i=0;i<order.size();i++)
        {
            if(order[i] == a[i]);
            else
            {
                check= false;
                break;
            }
        }
        cout(check);
    }
}