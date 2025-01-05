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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl
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

int nc(int n)
{
    int x = bit_width((unsigned)n);
    int nc = ~n;
    nc += 1 << x;
    return nc;
}

int somenum(int nc)
{
    for (int i = 0;i<21;i++)
    {
        if(nc&(1<<i))
            continue;
        return nc | (1 << i);
    }
    assert(false);
    return -1;
}

void printans(vector<int>& v)
{
    int k = 0;
    range(i,0,v.size())
    {
        if(~i&1)
        {
            k &= v[i];
        }
        else
            k |= v[i];
    }
    cout << k << endl;
    arrPrint(v);
}

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
        cin >> n;
        int k = 0;
        if(n <=5)
        {
            vector<int> v(n);
            iota(all(v), 1ll);
            if(n>=2)
                swap(v[0], v[1]);
            printans(v);
            continue;
        }
        vector<int> v(n);
        if(n&1){
            v[n - 1] = n;
            n--;
        }
        set<int> st;
        range(i, 1, n + 1) st.insert(i);
        if (__builtin_popcountll(n) == 1)
        {
            v[n - 1] = n;
            v[n - 2] = n - 1;
            v[n - 3] = n - 2;
            v[n - 4] = 1;
            v[n - 5] = 3;
            st.erase(n), st.erase(n - 1), st.erase(n - 2), st.erase(1), st.erase(3);
            for (int i = 0; st.size();i++)
                v[i] = *st.begin(), st.erase(st.begin());
        }
        else
        {
            v[n - 1] = n;
            v[n - 2] = nc(n);
            v[n - 3] = somenum(nc(n));
            st.erase(n), st.erase(nc(n)), st.erase(somenum(nc(n)));
            for (int i = 0; st.size();i++)
                v[i] = *st.begin(), st.erase(st.begin());
        }
        printans(v);
    }
}