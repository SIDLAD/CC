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
    int T;
    cin>>T;
    vector<vector<pair<int,int>>> answers(101);
    answers[2] = {
        {20 ,18},
        {219 ,216},
        {2218, 2214}
    };
    answers[3] = {
        {165, 162},
    };
    answers[4] = {
        {14, 12},
        {147 ,144},
        {1480 ,1476}
    };
    answers[5] = {
        {138, 135},
    };
    answers[7] = {
        {129, 126},
    };
    answers[10] = {
        {1262, 2519},
    };
    answers[11] = {
       { 12 ,21},
        {123, 242},
        {1234, 2463},
    };
    answers[13] = {
        {119, 234},
    };
    answers[14] = {
        {1178, 2351},
    };
    answers[16] = {
        {1154, 2303},
    };

    answers[18] = {
        {1136, 2267},
    };
    
    answers[20] = {
        {112 ,220},
    };

    answers[21] = {
        {11, 19},
    };

    answers[24] = {
        {110, 216},
    };

    answers[35] = {
        {107, 210},
    };

    answers[68] = {
        {104, 204},
    };
    answers[90] = {
        {1033, 2061},
    };

    answers[94] = {
        {1032, 2059},
    };
    for(;T--;)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            vector<pair<int,int>> ans;
            for(int b=1,a=2;a<=10000;b++,a++)
            {
                ans.push_back({a,b});
            }
            cout<<ans.size()<<endl;
            for(auto [a,b]:ans)
            {
                cout<<a<<" "<<b<<endl;
            }
        }
        else
        {
            cout<<answers[n].size()<<endl;
            for(auto [a,b]:answers[n])
            {
                cout<<a<<" "<<b<<endl;
            }
        }
    }
}