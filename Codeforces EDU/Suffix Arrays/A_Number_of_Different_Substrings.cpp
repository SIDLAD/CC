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


struct SparseTable
{
    vector<int>& a;
    vector<vector<int>> table;
    int n;

    bool _compare(auto a, auto b) { return a < b; } // Change according to QUERY operation
    int identity = INF; // Change according to QUERY operation

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
        l = max(l, (int)0), r = min(r, n - 1);

        int lgN = (int)bit_width((unsigned int)(r - l + 1)) - 1;
        if(_compare (a[table[lgN][l]] , a[table[lgN][r - (1<<lgN) + 1]]) )
            return table[lgN][l];
        else
            return table[lgN][r - (1<<lgN) + 1];
    }

    int query_val(int l, int r) { return (l > r || l >= n || r < 0) ? identity : a[query_i(l,r)]; }
};

void count_sort(vector<int>& p, vector<int>&c)
{
    int n = p.size();
    vector<int> cnt(n);
    for(auto x:c)cnt[x]++;
    vector<int> pos(n);
    vector<int> p_new(n);
    pos[0] = 0;
    for(int i=1;i<n;i++)pos[i] = pos[i-1] + cnt[i-1];
    for(auto x:p)p_new[pos[c[x]]++] = x;
    p = p_new;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    s+='#';
    int n = s.length();

    vector<int> p(n),c(n);
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)a[i] = {s[i],i};
    sort(all(a));
    for(int i=0;i<n;i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i=1;i<n;i++)
    {
        if(a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
        else c[p[i]] = c[p[i-1]] + 1;
    }

    for(int k=0;1<<k < n; k++)
    {
        for(int i=0;i<n;i++)
        {
            p[i] = (p[i] - (1<<k) + n)%n;
        }

        count_sort(p,c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i=1;i<n;i++)
        {
            pair<int,int> now = {c[p[i]],c[(p[i] + (1<<k))%n]};
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1] + (1<<k))%n]};
            if(now == prev)c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }

        c = c_new;
    }

    vector<int> lcp(n);
    for(int i=0,k=0;i<n-1;i++)
    {
        int j = p[c[i]-1];
        while(s[j + k] == s[i + k])k++;
        lcp[j] = k;
        k&&k--;
    }
    int ans = 0; // 1 if empty is counted
    for(int i=1;i<n;i++)
    {
        int now = p[i],prev = p[i-1];
        ans += (n - 1 - now) - (lcp[prev]);
    }

    cout<<ans<<endl;
}