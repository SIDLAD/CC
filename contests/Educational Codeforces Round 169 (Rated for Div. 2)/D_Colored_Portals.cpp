#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

inline bool checkcommon(string& a, string& b)
{
    return (a[0] == b[0] or a[1] == b[1] or a[0] == b[1] or a[1] == b[0]);
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
        int n,q;
        cin>>n>>q;
        vector<string> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        map<string,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            if(not mp.count(v[i]))mp[v[i]] = vector<int>();
            mp[v[i]].push_back(i);
        }

        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            if(a>b)swap(a,b);
            if(checkcommon(v[a],v[b]))
            {
                cout<<(b-a)<<endl;
                continue;
            }
            int min_ans = INF;
            for(auto& [str,inds]: mp)
            {
                if(str==v[a] or str==v[b])continue;
                
                int between = upper_bound(all(inds),a) - inds.begin();
                if(between != inds.size() and inds[between] < b)min_ans = b-a;

                int lesser = lower_bound(all(inds), a) - inds.begin() - 1;
                if(lesser != -1)lesser = inds[lesser],min_ans = min(min_ans, a - lesser + b- lesser);
                int greater = upper_bound(all(inds), b) - inds.begin();
                if(greater != inds.size())greater = inds[greater],min_ans = min(min_ans, greater - b + greater - a);
            }
            if(min_ans == INF)
            {
                cout<<-1<<endl;
            }
            else cout<<min_ans<<endl;
        }
    }
}