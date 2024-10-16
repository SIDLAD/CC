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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int solve(vector<int>& tmp)
{
    vector<int> x;
    bool active = false;
    bool par = 0;
    for(int i=0;i<tmp.size();i++)
    {
        if(tmp[i] <= 2)
        {
            if(active)
            {
                if(par)
                {
                    x.push_back(1);
                }
                else x.back()++;
            }
            else x.push_back(1);
            par = 0,active = true;

        }
        else if(tmp[i] <= 4)
        {
            if(active)par ^=1;
        }
        else{
            active = false;
        }
    }
    debug(tmp,x);
    int ans = 0;
    for(int i=0;i<x.size();i++)
    {
        ans += x[i]/2;
    }
    return ans;
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
        vector<int> a(n);
        vector<int> tmp;
        int sub = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];

            if(a[i] == 0)
            {
                sub--;
                if(tmp.size())
                sub -= solve(tmp),tmp.clear();
            }
            else tmp.push_back(a[i]);
        }
        if(tmp.size())
        sub -= solve(tmp);

        cout<<n+sub<<endl;

    }
}