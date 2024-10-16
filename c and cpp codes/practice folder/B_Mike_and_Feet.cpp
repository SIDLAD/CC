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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    stack<int> st;
    vector<int> prev(n);
    for(int i=0;i<n;i++)
    {
        while(st.size())
        {
            int idx = st.top();
            if(v[idx] >= v[i])st.pop();
            else break;
        }
        if(st.size())
        {
            prev[i] = st.top() + 1;
        }
        else prev[i] = 0;
        st.push(i);
    }
    vector<int> next(n);
    st = stack<int>();
    for(int i=n-1;i>=0;i--)
    {
        while(st.size())
        {
            int idx = st.top();
            if(v[idx] >= v[i])st.pop();
            else break;
        }
        if(st.size())
        {
            next[i] = st.top() - 1;
        }
        else next[i] = n-1;
        st.push(i);
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        ans[next[i] - prev[i]] = max(v[i],ans[next[i] - prev[i]]);
    }

    for(int i=n-2;i>=0;i--)
    {
        ans[i] = max(ans[i],ans[i+1]);
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}