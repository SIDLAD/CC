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

int gcd(int a,int b)
{
    if(a > b)swap(a,b);
    if(b == INF)return a;
    return __gcd(a,b);
}

int gcd(initializer_list<int> list)
{
    int answer = INF;
    for(auto& ele: list)
    {
        answer = gcd(answer,ele);
    }
    return answer;
}

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
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int g = accumulate(all(v),INF,[](int a,int b){return gcd(a,b);});

        vector<int> taken(n);
        int curgcd = INF;
        int minimgcd=INF;
        int index;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            if(!taken[j] and gcd(curgcd,v[j]) <= minimgcd)
            {
                minimgcd = gcd(curgcd,v[j]);
                index = j;
            }

            ans.push_back(debug(v[index],index));
            curgcd = minimgcd;
            taken[index] = 1;
            if(minimgcd == g)break;
        }
        int curans =INF;
        int sum =0;
        for(auto ele: ans)
        {
            debug(ele);
            curans = gcd(curans,ele);
            sum += curans;
        }
        for(int i=0;i<n;i++)if(!taken[i])
        {
            debug(v[i]);
            curans = gcd(curans,v[i]);
            sum += curans;
        }
        debug();
        cout<<sum<<endl;
    }
}