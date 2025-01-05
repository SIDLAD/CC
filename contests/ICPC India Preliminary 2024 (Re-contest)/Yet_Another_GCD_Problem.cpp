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

vector<int> primes;
int LIM = 2e6;

void precompute()
{
    vector<int> isprime(LIM + 1,1);
    for(int i=2;i<=LIM;i++)
    {
        if(isprime[i] and i!=2)primes.push_back(i);
        for(int j=i*i;j <= LIM;j+=i)
        {
            isprime[j] = false;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    precompute();

    debug(primes.size());
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,k;
        cin>>n>>k;
        int kc = k;


        if(k > n * (n - 1) >> 1)
        {
            cout<<-1<<endl;
            continue;
        }

        vector<int> v(n,2);
        int cur = 0;

        while(k > 0)
        {
            v[cur] = primes[cur];
            k -= n - cur - 1;
            cur++;
        }

        int ind = cur;
        while(k < 0)
        {
            v[ind] *= primes[cur - 1];
            ind++;
            k++;
        }
        arrPrint(v);

        // #ifndef cerr
        // int cnt = 0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     if(gcd(v[i],v[j]) == 1)cnt++;
        // }
        // debug(cnt);
        // assert(kc == cnt);
        // assert(*max_element(all(v)) <= 2e6);
        // #endif
    }
}