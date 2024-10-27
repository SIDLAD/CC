#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
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
        int n,m;
        cin>>n>>m;
        vector<int> v(n);
        vector<int> freq(m + 1);
        vector<int> anyind(m + 1,-1);
        for(int i=0;i<n;i++)cin>>v[i],freq[v[i]]++,anyind[v[i]] = i;
        vector<int> c(m + 1);
        vector<int> cid(m + 1,-1);
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=m;j+=i)
            {
                if(freq[j] == 0)continue;
                c[i] += freq[j];
                cid[i] = anyind[j];
            }
        }
        debug(c,cid);
        int ll = 1;
        int ul = m + 2;
        while(ul - ll > 1)
        {
            int mid = ll + ul >> 1;
            int totmult = 1;
            vector<int> lcmvals(n,1);

            for(int i=1;i<mid;i++){
                if(c[i] == 0)totmult = lcm(totmult,i);
                if(totmult > m){break;}
                if(c[i] == 1){
                    assert(cid[i] != -1);
                    lcmvals[cid[i]] = lcm(lcmvals[cid[i]],i);
                    assert(lcmvals[cid[i]] <= m);
                }
            }
            int mnval = *min_element(all(lcmvals));

            if(lcm(mnval,totmult) <= m)ll = mid;
            else ul = mid;
        }
        
        cout<<ll<<endl;
    }
}