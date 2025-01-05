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
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];   
        }
        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }

        vector<int> fsimul(n);
        vector<int> fsmaxpre(n);
        fsimul[0] = fsmaxpre[0] = 1;
        for(int i=1;i<n;i++)
        {
            fsimul[i] = fsimul[i-1];
            if(fsimul[i] < v[i])fsimul[i]++;
            else if(fsimul[i] > v[i])fsimul[i]--;
            fsmaxpre[i] = max(fsmaxpre[i-1],fsimul[i]);
        }

        auto getmaxtill = [&](int index)
        {
            if(index == -1)return 0ll;
            else return fsmaxpre[index];
        };

        int ll = 0;
        int ul = n;
        while(ul - ll > 1)
        {
            int mid = ll + ul >> 1;
            int curval = mid;
            bool check = (fsmaxpre[n-1] >= curval);
            if(!check)
            for(int i=n-1;i>=1;i--)
            {
                if(curval <= v[i])
                {
                    if(curval > 1)curval--;
                }
                else curval++;
                if(getmaxtill(i-1) >= curval)
                {
                    check=true;
                    break;
                }
            }
            if(check)ll = mid;
            else ul = mid;
        }
        cout<<ll<<endl;
    }
}