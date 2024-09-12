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
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        string bc = b;
        for(int i=0;i<n-2;i++)
        {
            if(a[i] == '0' and a[i+2] == '0')bc[i+1] = '1';
        }

        string ac = a;
        for(int i=0;i<n-2;i++)
        {
            if(bc[i] == '1' and bc[i+2] == '1')ac[i+1] = '1';
        }

        vector<int> pre(n);
        for(int i=0;i<n;i++)
        {
            if(ac[i] == '1')pre[i] = 1;
        }
        partial_sum(all(pre),pre.begin());
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;
            --l,--r;

            int ans= 0;
            if(r - l >= 2)
            {
                ans += pre[r-1] - pre[l];
                bool con1 = bc[l] != b[l] and ac[l+1] != a[l+1];
                bool con2 = bc[r]!=b[r] and ac[r-1] != a[r-1];
                if(r - l ==2 and (con1 or con2))ans--;
                else{ if(con1)ans--;if(con2)ans--;}

                if(a[l] == '1')ans++;
                if(a[r] == '1')ans++;
            }
            else
            {
                for(int i=l;i<=r;i++)
                {
                    ans += (a[i] == '1');
                }
            }            
            cout<<ans<<endl;
        }

    }
}