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

using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define cout(x) x?cout<<"Bob"<<endl:cout<<"Alice"<<endl
#define endl "\n" //comment out for interactive problems
#define limit (int)1e7

// int grundy[limit + 1] = {};
vector<int> grundy(limit + 1,-1);

void cool_sieve()
{
    grundy[0] = 0;
    grundy[1] = 1;
    
    int x = 0;
    int i;
    for(i=2;i*i<=limit;i++)
    {
        if(grundy[i] != -1)continue;
        grundy[i] = x;
        for(int j = i+i;j <= limit;j += i)
        {
            if(grundy[j] == -1)grundy[j] = x;
        }
        if(x == 0)x++;
        x++;
    }
    for(;i<=limit;i++)
    {
        if(grundy[i] == -1)grundy[i] = x++;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cool_sieve();
    int T;
    cin>>T;
    for(;T--;)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];

        int xor_sum = 0;
        for(int i=0;i<n;i++)
        {
            xor_sum ^= (grundy[(v[i])]);
        }
        cout(xor_sum == 0);
    }
}