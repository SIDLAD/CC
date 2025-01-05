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
#define cout(x) (x?cout<<"Yes"<<endl:cout<<"No"<<endl)
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

void count_sort(vector<int>& p, vector<int>& c)
{
    int n = p.size();
    vector<int> cnt(n);
    for(auto x:c)cnt[x]++;
    vector<int> pos(n);
    vector<int> p_new(n);
    pos[0] = 0;
    for(int i=1;i<n;i++)pos[i] = pos[i-1] + cnt[i-1];
    for(auto x: p)p_new[pos[c[x]]++] = x;
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
    s += '#';
    int n = s.size();
    vector<int> p(n),c(n);
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)a[i] = {s[i],i};
    sort(all(a));
    for(int i=0;i<n;i++)p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i=1;i<n;i++)
    if(a[i].first == a[i-1].first)c[p[i]] = c[p[i-1]];
    else c[p[i]] = c[p[i-1]] + 1;

    for(int k=0;(1<<k) < n;k++)
    {
        for(int i=0;i<n;i++)p[i] = (p[i] - (1<<k) + n)%n;
        count_sort(p,c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for(int i=1;i<n;i++)
        {
            pair<int,int> now = {c[p[i]],c[(p[i] + (1<<k))%n]};
            pair<int,int> prev = {c[p[i-1]],c[(p[i - 1] + (1<<k))%n]};
            if(now == prev)c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        c =  c_new;
    }

    int q;
    cin>>q;
    while(q--)
    {
        string t;
        cin>>t;
        int l = -1;
        int u = n;
        for(int i=0;i<t.size();i++)
        {
            int ll = l;
            int ul = u;
            while(ul - ll > 1)
            {
                int mid = ll + ul >>1;
                int startind = p[mid];
                if(s[(startind + i)%n] < t[i])ll = mid;
                else ul = mid;
            }
            l = ll;
            ul = u;
            while(ul - ll > 1)
            {
                int mid = ll + ul >> 1;
                int startind = p[mid];
                if(s[(startind + i)%n] > t[i])ul = mid;
                else ll = mid;
            }
            u = ul;
        }

        cout(u-l > 1);
    }
}