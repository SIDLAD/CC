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
    for(;T--;)
    {
        int n,m;
        cin>>n>>m;
        int mx = -INF;
        for(int i=0;i<n;i++)
        {
            int l;
            cin>>l;
            vector<int> v(l);
            for(int i=0;i<l;i++)cin>>v[i];
            sort(all(v));
            int mex1=0,mex2=0;
            debug(l);
            for(int i=0;i<l;i++)
            {
                if(v[i] == mex1)mex1 ++;
                else if(v[i] > mex1){ if(mex2 == 0)mex2 = mex1 + 1;
                    if(v[i] == mex2)mex2 ++; }

                debug(i,mex1,mex2);
            }
            mex2 = max(mex2,mex1 + 1);
            debug(v,mex2);
            mx = max(mx,mex2);
        }
        debug(mx);
        cout<< m * (m+1)/2 - min(mx,m) * (min(mx,m) + 1)/2 + (min(mx,m) + 1)* mx<<endl;
    }
}