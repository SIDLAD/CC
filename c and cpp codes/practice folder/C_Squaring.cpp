#include <bits/stdc++.h>
const long double EPS = 1e-11;
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

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

bool comp(pair<int,int> p1,pair<int,int> p2) // p1 >= p2 ?
{
    if(p1.first == 1)return p2.first == 1;
    if(p2.first == 1)return 0;
    double llhs = p1.second + log2l(log2l(p1.first));
    double rrhs = p2.second + log2l(log2l(p2.first));
    return llhs >= rrhs;
}

int incrementreq(pair<int,int> p1,const pair<int,int> p2)
{
    double llhs = p1.second;
    double rrhs = p2.second + log2l(log2l(p2.first)) - log2l(log2l(p1.first));
    return max(0ll,(int)(ceill(rrhs - llhs - EPS)));
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    int TT = 1;
    for(;T--;TT++)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        vector<pair<int,int>> b(n);
        for(int i=0;i<n;i++)b[i] = {v[i],0};
        int cnt = 0;
        for(int i=1;i<n;i++)
        {
            if(comp(b[i],b[i-1]))continue;
            if(v[i] == 1)
            {
                cout<<-1<<endl;
                goto end;
            }
            if(v[i-1] == 1)continue;
            int tmp = incrementreq(b[i],b[i-1]);
            assert(tmp != 0);
            cnt += tmp;
            b[i].second += tmp;
        }

        cout<<cnt<<endl;
        end:42;
    }
}