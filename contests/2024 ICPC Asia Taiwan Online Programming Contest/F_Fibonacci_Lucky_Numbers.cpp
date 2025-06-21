#include <bits/stdc++.h>
const long double EPS = 1e-7;
// const long long int M = (long long int) 1e9 + 7;//998'244'353;
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

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int C = 1.5e10;
int M = 1e10;


template <typename T>
struct Mat
{
    int n, m;
    vector<vector<T>> a;
    Mat() {}
    Mat(int _n, int _m)
    {
        n = _n;
        m = _m;
        a.assign(n, vector<T>(m, (T)0));
    }
    Mat(vector<vector<T>> v)
    {
        n = v.size();
        m = n ? v[0].size() : 0;
        a = v;
    }
    inline void make_unit()
    {
        assert(n == m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                a[i][j] = i == j;
        }
    }
    inline Mat operator+(const Mat &b)
    {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % M;
            }
        }
        return ans;
    }
    inline Mat operator-(const Mat &b)
    {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans.a[i][j] = (a[i][j] - b.a[i][j]) % M;
                if(ans.a[i][j] < 0)ans.a[i][j] += M;
            }
        }
        return ans;
    }
    inline Mat operator*(const Mat &b)
    {
        assert(m == b.n);
        Mat ans = Mat(n, b.m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < b.m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    ans.a[i][j] = ((__int128_t)ans.a[i][j] + (__int128_t)a[i][k] * b.a[k][j] % M)%M;
                }
            }
        }
        return ans;
    }
    inline Mat pow(long long k)
    {
        assert(n == m);
        Mat ans(n, n), t = a;
        ans.make_unit();
        while (k)
        {
            if (k & 1)
                ans = ans * t;
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
    inline Mat &operator+=(const Mat &b) { return *this = (*this) + b; }
    inline Mat &operator-=(const Mat &b) { return *this = (*this) - b; }
    inline Mat &operator*=(const Mat &b) { return *this = (*this) * b; }
    inline bool operator==(const Mat &b) { return a == b.a; }
    inline bool operator!=(const Mat &b) { return a != b.a; }
};


int binpow(int a, int b, int MOD) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (__int128_t) res * a % MOD;
        a = (__int128_t) a * a % MOD;
        b >>= 1;
    }
    return res;
}

int computePhi(int n)
{
    int res = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)n/=i;
            res -= res/i;
        }
    }
    if(n > 1)res -= res/n;
    return res;
}

int getFibo(int n)
{
    Mat<int> op({{0,1},{1,1}});
    return (op.pow(n-1)).a[1][1];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    int phi[4];
    phi[0] = C;
    for(int i=1;i<=3;i++)phi[i] = computePhi(phi[i-1]);
    for(;T--;)
    {
        int n;
        cin>>n;
        n %= phi[3];
        n = binpow(7,n,phi[2]);
        n = binpow(7,n,phi[1]);
        n = binpow(7,n,phi[0]);
        string s = to_string(getFibo(n));
        while(s.length() < 10)s = '0' + s;
        cout<<s<<endl;
    }
}