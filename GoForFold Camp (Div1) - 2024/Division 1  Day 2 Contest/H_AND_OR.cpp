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

struct segtreeand
{
    using T = pair<int,int>;
    static constexpr T unit = {(1ll<<33) - 1,0};
    T f(T a, T b)
    {
        return {a.first&b.first,a.second + b.second};
    }
    vector<T> s; int n;
    segtreeand(int n, T def = unit): s(2*n,def), n(n){};

    void modify(int val, int pos)
    {
        for(s[pos += n] = {val,1}; pos >>= 1;)
        s[pos] = f(s[pos * 2],s[pos * 2 + 1]);
    }

    T query(int b, int e)
    {
        e++;
        T ra = unit, rb = unit;
        for(b += n, e+=n;b<e;b>>=1,e>>=1)
        {
            if(b%2)ra = f(ra,s[b++]);
            if(e%2) rb=f(s[--e],rb);
        }
        return f(ra,rb);
    }
};

struct segtreeor
{
    using T = pair<int,int>;
    static constexpr T unit = {0,0};
    T f(T a, T b)
    {
        return {a.first|b.first,a.second + b.second};
    }
    vector<T> s; int n;
    segtreeor(int n, T def = unit): s(2*n,def), n(n){};

    void modify(int val, int pos)
    {
        for(s[pos += n] = {val,1}; pos >>= 1;)
        s[pos] = f(s[pos * 2],s[pos * 2 + 1]);
    }

    T query(int b, int e)
    {
        e++;
        T ra = unit, rb = unit;
        for(b += n, e+=n;b<e;b>>=1,e>>=1)
        {
            if(b%2)ra = f(ra,s[b++]);
            if(e%2) rb=f(s[--e],rb);
        }
        return f(ra,rb);
    }
};

struct segtreecnt
{
    using T = int;
    static constexpr T unit = 0;
    T f(T a, T b)
    {
        return a +b;
    }
    vector<T> s; int n;
    segtreecnt(int n, T def = unit): s(2*n,def), n(n){};

    void modify(int val, int pos)
    {
        for(s[pos += n] = 1; pos >>= 1;)
        s[pos] = f(s[pos * 2],s[pos * 2 + 1]);
    }

    T query(int b, int e)
    {
        e++;
        T ra = unit, rb = unit;
        for(b += n, e+=n;b<e;b>>=1,e>>=1)
        {
            if(b%2)ra = f(ra,s[b++]);
            if(e%2) rb=f(s[--e],rb);
        }
        return f(ra,rb);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    arrPut(v);
    debug(v);
    debug();
    vector<segtreeand> segtreeandarr(32,segtreeand(n));
    vector<segtreeor> segtreeorarr(32,segtreeor(n));
    vector<segtreecnt> segtreecntarr(32,segtreecnt(n));
    debug(segtreeandarr[1].query(0,0));

    for(int i=0;i<n;i++)
    {
        int bitcount = __builtin_popcountll(v[i]);
        debug(i,bitcount);
        for(int j=0;j<=bitcount;j++)
        {
            segtreeandarr[j].modify(v[i],i);
        }
        for(int j=31;j>=bitcount;j--)
        {
            segtreeorarr[j].modify(v[i],i);
        }
        segtreecntarr[bitcount].modify(1,i);
    }

    debug(segtreeandarr[1].query(0,0));

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        bool check = false;
        for(int i=0;i<30;i++)
        {
            auto q1 = segtreeandarr[i + 1].query(l,r);
            auto q2 = segtreeorarr[i].query(l,r);
            if(q1.first == q2.first and q1.second and q2.second)
            {
                debug(l,r,q1,q2);
                check = true;
                break;
            }
        }

        if(!check)
        for(int i=0;i<=30;i++)
        {
            auto q1 = segtreeandarr[i].query(l,r);
            auto q2 = segtreeorarr[i].query(l,r);
            auto cnt = segtreecntarr[i].query(l,r);
            if(q1.first == q2.first and q1.second and q2.second and cnt > 1)
            {
                check = true;
                break;
            }
        }

        cout(check);
    }
}