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

bool check(vector<int>& v)
{
    int n = v.size();
    vector<pair<double,double>> ranges(n);
    for(int i=0;i<n;i++)
    {
        ranges[i].first = max(0.0l,v[i] * 1.0l - 0.5l);
        ranges[i].second = min(100.0l,v[i] * 1.0l + 0.49l);
    }

    double mn = 0;
    double mx = 0;
    for(int i=0;i<n;i++)
    {
        mn += ranges[i].first;
        mx += ranges[i].second;
    }

    if(mn - 100 <= EPS and mx - 100 >= -EPS)return true;
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cout<<fixed<<setprecision(2);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<string> a(n);
    vector<int> v(n);
    int zc = 0;
    int hc = 0;
    range(i,0,n)
    {
        cin>>a[i]>>v[i];
        if(v[i] == 0)zc++;
        if(v[i] == 100)hc++;
    }

    if(check(v) == false)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }


    int sum = accumulate(all(v),0ll);
    vector<pair<double,double>> ans(n);
    for(int i=0;i<n;i++)
    {
        double excesspercent = (n - 1 - hc + (v[i] == 100)) * 0.49l;
        double tot = excesspercent + sum;
        excesspercent = tot - 100.0l;

        debug(tot);
        debug(excesspercent);

        if(excesspercent - 0.5l >= -EPS)
        {
            ans[i].first = v[i] * 1.0l - 0.5l;
        }
        else
        {
            assert(excesspercent + 0.49l >= -EPS);
            ans[i].first = v[i] * 1.0l - excesspercent;
        }


        double compexcesspercent = (n - 1 - zc + (v[i] == 0)) * 0.50l;
        tot = sum - compexcesspercent;
        compexcesspercent = 100 - tot;

        if(compexcesspercent - 0.49l >= -EPS)
        {
            ans[i].second = v[i] * 1.0l + 0.49l;
        }
        else
        {
            assert(compexcesspercent  + 0.5l >= -EPS);
            ans[i].second = v[i]*1.0l + compexcesspercent;
        }

        if(v[i] == 100)
        {
            assert(ans[i].first - 100 <=  EPS);
            ans[i].second = min(ans[i].second,100.0l);
        }
        if(v[i] == 0)
        {
            assert(ans[i].second >= -EPS);
            ans[i].first = max(ans[i].first, 0.0l);
        }

    }


    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" "<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}