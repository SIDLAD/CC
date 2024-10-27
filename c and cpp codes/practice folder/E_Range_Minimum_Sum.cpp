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
        vector<int> vinv(n);
        for(int i=0;i<n;i++)cin>>v[i],vinv[v[i] - 1] = i;
        set<int> st;
        int l1[n],l2[n],r1[n],r2[n];
        for(int i=0;i<n;i++)
        {
            set<int>::iterator lb = st.lower_bound(vinv[i]),rb = lb;
            if(lb == st.begin())l1[vinv[i]] = l2[vinv[i]] = -1;
            else
            {
                --lb;
                l1[vinv[i]] = *lb;
                l2[vinv[i]] = lb-- == st.begin()?-1:*lb;
            }

            if(rb == st.end())r1[vinv[i]] = r2[vinv[i]] = n;
            else
            {
                r1[vinv[i]] = *rb++;
                r2[vinv[i]] = rb == st.end()?n:*rb;
            }
            st.insert(vinv[i]);
        }
        
        int _[n + 2] = {};
        int *ans = _ + 1;
        for(int i=0;i<n;i++)
        {
            ans[-1] += (i - l1[i]) * (r1[i] - i) * v[i];
            ans[l1[i]] -= (i - l1[i]) * (r1[i] - i) * v[i];

            if(r1[i] != n)
            {
                ans[r1[i] + 1] += (i - l1[i]) * (r1[i] - i) * v[i];
                ans[n] -= (i - l1[i]) * (r1[i] - i) * v[i];
            }

            ans [l1[i] + 1] += (i - l1[i] - 1) * (r1[i] - i) * v[i];
            ans[i] -= (i - l1[i] - 1) * (r1[i] - i) * v[i];
            ans[i + 1] += (r1[i] - i - 1) * (i - l1[i]) * v[i];
            ans[r1[i]] -= (r1[i] - i - 1) * (i - l1[i]) * v[i];

            if(l1[i] != -1)
            {
                ans[l1[i]] += (i - l2[i] - 1) * (r1[i] - i) * v[i];
                ans[l1[i] + 1] -= (i - l2[i] - 1) * (r1[i] - i) * v[i];
            }
            
            if(r1[i] != n)
            {
                ans[r1[i]] += (r2[i] - i - 1) * (i - l1[i]) * v[i];
                ans[r1[i] + 1] -= (r2[i] - i - 1) * (i - l1[i]) * v[i];
            }
        }
        partial_sum(_,_ + n + 2, _);
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}