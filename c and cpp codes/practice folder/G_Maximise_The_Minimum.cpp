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
        cin>>n;
        string s;
        cin>>s;
        int ll = 0;
        int ul = n/2 + 1;

        int zeroc = 0,onec = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')zeroc++;
            else onec++;
        }
        char major;
        if(onec > zeroc) major = '1';
        else major = '0';
        while(ul - ll > 1)
        {
            int mid = ll + ul >> 1;
            vector<bool> taken(n);
            int takencount = 0;
            int nextstartind =0;

            if(major == '1')
            {
                for(int i=0;i<n and takencount < mid;i++)
                {
                    if(s[i] == '1')taken[i] = 1,takencount++;
                }
            }
            else
            {
                for(int i=n-1;i>=0 and takencount < mid;i--)
                {
                    if(s[i] == '0')taken[i] = 1,takencount++;
                }
            }
            
            if(takencount < mid)
            {
                assert(false);
            }

            vector<int> lis;
            for(int i=0;i<n;i++)if(!taken[i])
            {
                int index = upper_bound(all(lis),s[i]) - lis.begin();
                if(lis.size() == index)
                lis.push_back(s[i]);
                else lis[index] = s[i];
            }
            if(lis.size() < mid) ul = mid;
            else ll = mid,debug(taken);
        }
        cout<<ll<<endl;
    }
}