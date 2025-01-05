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
    map<char,pair<int,int>> mp;
    mp['N'] = {0,1};
    mp['E'] = {1,0};
    mp['S'] = {0,-1};
    mp['W'] = {-1,0};

    int T;
    cin>>T;
    for(;T--;)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        vector<pair<int,int>> coordlist;
        pair<int,int> curcoord = {0,0};
        for(int i=0;i<n;i++)
        {
            auto [dx,dy] = mp[s[i]];
            curcoord.first += dx;
            curcoord.second += dy;
            coordlist.push_back({curcoord});
        }

        auto [multix,multiy] = coordlist.back();
        coordlist.pop_back();
        coordlist.push_back({0,0});
        bool check = false;
        debug(multix,multiy);
        for(int i=0;i<n;i++)
        {
            auto [x,y] = coordlist[i];
            if(multix == 0 and multiy == 0 and x == a and y == b){check = true;break;}
            else if(multiy != 0 and multix == 0 and x== a and (b-y)%multiy == 0 and (b-y)/multiy >=0){check = true;break;}
            else if(multix != 0 and multiy == 0 and y == b and (a-x)%multix == 0 and (a-x)/multix >=0){check = true;break;}
            else if(multix !=0 and multiy != 0 and (a - x)%multix  == 0 and (b-y)%multiy == 0 and (a-x)/multix == (b-y)/multiy and (a-x)/multix >= 0)
            {
                check = true;
                break;
            }
        }
        cout(check);
    }
}