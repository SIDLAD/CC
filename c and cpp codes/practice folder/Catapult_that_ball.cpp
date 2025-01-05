#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

struct SparseTable
{
    vector<int>& a;
    vector<vector<int>> table;
    int n;

    bool _compare(auto a, auto b) { return a > b; } // Change according to QUERY operation
    int identity = -INF; // Change according to QUERY operation

    SparseTable(vector<int>& a) : a(a), n(a.size())
    {
        int lgN = (int)bit_width((unsigned int)n) - 1;
        table.resize(lgN + 1,vector<int>(n));
        range(i,0,lgN + 1)range(j,0,n - (1<<i) + 1)
        {
            if(i == 0)
                table[i][j] = j;
            else if(_compare (a[table[i-1][j]] , a[table[i-1][j + (1<<i-1)]]) )
                table[i][j] = table[i-1][j];
            else
                table[i][j] =  table[i-1][j + (1<<i-1)];
        }
    }

    int query_i(int l, int r)
    {
        assert(l <= r and l < n and r >= 0);
        int lgN = (int)bit_width((unsigned int)(r - l + 1)) - 1;
        if(_compare (a[table[lgN][l]] , a[table[lgN][r - (1<<lgN) + 1]]) )
            return table[lgN][l];
        else
            return table[lgN][r - (1<<lgN) + 1];
    }

    int query_val(int l, int r) { return (l > r || l >= n || r < 0) ? identity : a[query_i(l,r)]; }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    arrPut(v);
    SparseTable st(v);

    int cnt = 0;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if(a == b)cnt++;
        else if(a < b)cnt += (st.query_val(a-1,b-2) == v[a-1]);
        else cnt += (st.query_val(b,a-1) == v[a-1]);
    }
    cout<<cnt<<endl;
}

// #include <bits/stdc++.h>
// const long double EPS = 1e-7;
// const long long int M = (long long int) 1e9 + 7;//998'244'353;
// using namespace std;
// //insert policy here

// //insert mintcode here

// #if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
//     void _exe() {}
//     template <typename T, typename... V>
//     const T& _exe(const T &t,const V&... v) {return t;}
//     template <typename T, typename... V>
//     T& _exe(T &t,V&... v) {return t;}
    
//     #define debug(x...) (_exe(x))
    
//     class CNothing {};

//     template <typename T>
//     const CNothing& operator<<(const CNothing& proxy, const T&)
//     {
//         return proxy;
//     }

//     const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
//     {
//         return proxy;
//     }
//     CNothing cnothing;
//     #define cerr cnothing
// #else
//     #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
// #endif

// #define int long long
// #define double long double
// #define all(x) (x).begin(),(x).end()
// #define endl "\n" //comment out for interactive problems
// #define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

// const int INF =
// #ifdef int
//     LONG_LONG_MAX/2
// #else
//     INT_MAX/2
// #endif
// ;

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cout.precision(numeric_limits<double>::max_digits10);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     int n,m;
//     cin>>n>>m;
//     vector<int> v(n);
//     for(int i=0;i<n;i++)cin>>v[i];
//     int lgn = 31 - __builtin_clz(n);
//     vector<vector<int>> sparse(lgn + 1,vector<int> (n));
//     copy(all(v),sparse[0].begin());
//     for(int i=1;i<=lgn;i++)for(int j=0;j + (1<<i)<=n;j++)
//     {
//         sparse[i][j] = max(sparse[i-1][j],sparse[i-1][j+(1<<i-1)]);
//     }
//     int cnt = 0;
//     while(m--)
//     {
//         int a,b;
//         cin>>a>>b;
//         b-=2;
//         if(a > b)
//         {cnt++;continue;}

//         int k = 31 - __builtin_clz(b - a + 1);
//         if(debug(max(sparse[k][a],sparse[k][b-(1<<k) + 1])) <= debug(v[a-1]))cnt++;
//     }
//     cout<<cnt<<endl;
// }