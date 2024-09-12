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
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

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
        string s;
        cin>>s;
        int n = s.length();

        int trailingzeros = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'a')trailingzeros++;
            else break;
        }

        if(s.size() == trailingzeros)
        {
            cout<<s.size()-1<<endl;
            continue;
        }

        n = s.size()-trailingzeros;

        vector<int> z(n);
        int l=0,r=0;
        for(int i=1;i<n;i++)
        {
            if(i < r) z[i] = min(z[i-l],r-i);
            while(i+z[i] < n and s[i+z[i]+trailingzeros] == s[z[i]+trailingzeros])
            {
                z[i]++;
            }
            if(i+z[i] > r)l=i,r = i + z[i];
        }
        long long ans = 0;
        vector<int> nonas;
        for(int i=0;i<n;i++)
        {
            if(s[i+trailingzeros] == 'a')continue;
            nonas.push_back(i);
        }
        for(int len = 1;len <= n; len++)
        {
            int mina = trailingzeros;
            bool check = true;
            int i;
            for(i=0;i<n;i += len)
            {
                if(i == 0)continue;
                int cur = 0;
                if(lower_bound(all(nonas),i) == nonas.end())break;
                int newi = *lower_bound(all(nonas),i);
                cur = newi - i;
                i = newi;
                mina = min(mina,cur);
                if(z[i] < len)
                {
                    check = false;
                    break;
                }
            }

            if(check)
            {
                ans +=(mina + 1);
            }
        }

        cout<<ans<<endl;
    }
}