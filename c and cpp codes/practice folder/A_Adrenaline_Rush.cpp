#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

struct fenwick
{
    vector<int> s;
    fenwick(int n):s(n){}
    void update(int pos, int diff)
    {
        for(;pos < s.size(); pos |= pos + 1)s[pos] += diff;
    }
    int query(int pos)
    {
        pos++;
        int res = 0;
        for(;pos > 0; pos &= pos - 1) res += s[pos - 1];
        return res;
    }
    
    int query(int l, int r)
    {
        return debug(query(r) - query(l-1));
    }
};

int invcount(vector<int> & v)
{
    int n = v.size();
    vector<int> pos(n + 1);
    for(int i=0;i<n;i++)pos[v[i]] = i;
    debug(pos);

    fenwick ft(n);
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        cnt += (ft.query(pos[i], n-1));
        ft.update(pos[i],1);
    }
    return cnt;
}

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
    cout<<n * (n - 1)  - invcount(v)<<endl;
    vector<int> pos(n + 1);
    for(int i=0;i<n;i++)pos[v[i]] = i + 1;
    vector<bool> marked(n + 1);
    for(int i=n;i>=1;i--)
    {
        int cur = v[i-1];
        for(int j=cur - 1; j >= 1;j--)
        {
            if(!marked[j])
            cout<<cur<<" "<<j<<endl;
        }
        for(int j=1;j<=n;j++)
        {
            if(!marked[j] and j!=cur)
            cout<<j<<" "<<cur<<endl;
        }
        marked[cur] = true;
    }
}