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

using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

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
        vector<int> b(n-1);
        for(int i=0;i<n-1;i++)cin>>b[i];  

        bool check = true;
        vector<int> ans(n);
        for(int i=0;i<31;i++)
        {
            vector<bool> confirm(n);
            for(int j=0;j<n-1;j++)
            {
                if(b[j] & (1<<i))
                {
                    ans[j + 1] |= (1<<i);
                    confirm[j+1] = true;
                    if(!confirm[j])
                    {
                        ans[j] |= (1<<i);
                        confirm[j] = true;
                    }
                    else if(~ans[j]&(1<<i))
                    {
                        check = false;
                        goto outer;
                    }
                }
                else
                {
                    if(j == 0)
                    {
                        ans[j]&=((-1)^(1<<i));
                        confirm[j] = true;
                    }
                    else
                    {
                        if(!confirm[j]){
                        ans[j]&=((-1)^(1<<i));
                        confirm[j] = true;}
                        
                        else if((ans[j]&(1<<i)))
                        {
                            if(confirm[j+1] and (ans[j+1]&(1<<i)))
                            {
                                check = false;
                                goto outer;
                            }
                            ans[j+1]&=((-1)^(1<<i));
                            confirm[j+1] = true;
                        }
                    }
                }
            }
        }
        outer:
        if(check==false){
        cout<<-1<<endl;continue;}
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}