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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

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
        if(n%2 == 0)
        {
            range(i,0,n/2)cout<<i + 1 <<" " << i + 1 <<' ';
            cout<<endl;
            continue;
        }

        if(n  < 27)
        {
            cout<<-1<<endl;
            continue;
        }

        //n >= 27
        vector<int> ans(n);
        ans[0] = 1;
        ans[9] = 1;
        ans[25] = 1;
        ans[10] = 2;
        ans[26] = 2;
        int cur = 3;
        for(int i=1;i<9;i+=2)
        {
            ans[i] = cur,ans[i+1] = cur;
            cur++;
        }
        for(int i=11;i<25;i+=2)
        {
            ans[i] = cur,ans[i+1]=cur;
            cur++;
        }

        for(int i=27;i<n;i+=2)
        {
            ans[i] = cur;
            ans[i+1] = cur;
            cur++;
        }
        arrPrint(ans);
    }
}