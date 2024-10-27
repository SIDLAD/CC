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
        int n,q;
        cin>>n>>q;
        vector<int> l1 = {0};
        vector<vector<int>> modo = {{}};
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(x == 1)
            {
                modo.back().push_back(y);
            }
            else
            {
                if(l1.back() + modo.back().size() == 0)continue;
                if(log10(l1.back() + modo.back().size()) + log10(y + 1) >= 18) l1.push_back(INF);
                else l1.push_back((l1.back() + modo.back().size()) * (y + 1));
                modo.push_back({});
            }
        }
        debug(l1);
        while(q--)
        {
            int pos;
            cin>>pos;
            int ans = -1;
            while(true)
            {
                int id = lower_bound(all(l1),pos) - l1.begin() - 1;
                debug(id,pos);
                if(l1[id] + modo[id].size() < pos)
                {
                    pos %= (l1[id] + modo[id].size());
                    if(pos == 0)pos = (l1[id] + modo[id].size());
                    continue;
                }
                else
                {
                    ans = modo[id][pos - l1[id] - 1];
                    break;
                }
            }
            debug(ans);
            cout<<ans<<" ";
        }
        debug();
        cout<<endl;
    }
}