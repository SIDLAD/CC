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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

struct DSU
{
    int n;
    vector<int> p,len,sz;
    DSU(int n):n(n)
    {
        p.resize(n);
        len.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++)
        {
            p[i] = i;
            len[i] = 0;
            sz[i] = 1;
        }
    };

    pair<int,int> get(int a)
    {
        if(p[a] == a)return {a,0};
        auto ret = get(p[a]);
        ret.second += len[a];
        return ret;
    }

    bool unite(int a, int b)
    {
        auto [pa,lena] = get(a);
        auto [pb,lenb] = get(b);
        if(pa == pb)
        {
            return (lena^lenb)&1;
        }

        if(sz[pa] > sz[pb])
        {
            p[pb] = pa;
            sz[pa] += sz[pb];
            len[pb] = 1 + lena + lenb;
        }
        else
        {
            p[pa] = pb;
            sz[pb] += sz[pa];
            len[pa] = 1 + lena + lenb;
        }
        return true;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    int shift = 0;
    for(int i=0;i<m;i++)
    {
        int q,a,b;
        cin>>q>>a>>b;
        int x = (a+shift)%n;
        int y = (b + shift)%n;
        bool tmp = dsu.unite(x,y);
        if(q)
        {
            cout(!tmp);
            if(!tmp)shift++;
        }
    }
}