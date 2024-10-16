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
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>> da(n);
        for(int i=0;i<n;i++)cin>>da[i].first>>da[i].second;

        stack<pair<int,int>> st;
        int curday = 0;
        int ans = 0;
        int remcartmod = 0; // 0 <=> m
        for(int i=0;;i++)
        {
            while(st.size() and (i == n or curday < da[i].first))
            {
                auto& [day, count] = st.top();
                if(curday >= day + k)
                {
                    stack<pair<int,int>> tmp;
                    st = tmp;
                    break;
                }

                if(remcartmod != 0)
                {
                    int del = min(remcartmod,count);
                    remcartmod -= del;
                    count -= del;
                    if(remcartmod == 0) ans++,curday++;
                    if(count == 0)st.pop();
                }
                else
                {
                    int q = min({count/m,i==n?INF:(da[i].first - curday),day + k - curday});
                    ans += q;
                    curday += q;
                    count -= m * q;
                    
                    if(count == 0)st.pop();
                    else if(curday < min(i==n?INF:da[i].first,day + k))
                    {
                        assert(count <= m);
                        remcartmod = m - count;
                        st.pop();
                    }
                    else if(curday == da[i].first)break;
                }
            }

            if(i==n)break;
            if(curday != da[i].first)
            {
                curday = da[i].first;
                remcartmod = 0;
            }
            st.push(da[i]);
        }

        cout<<ans<<endl;
    }
}