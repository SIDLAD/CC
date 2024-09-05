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

#define int long long
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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    multiset<int> s1,s2;
    for(int i=0;i<k;i++)
    {
        s1.insert(v[i]);
        if(s1.size() - 1 > s2.size())s2.insert(*s1.rbegin()),s1.erase(s1.find(*s1.rbegin()));
        else if(s2.size() and *s1.rbegin() > *s2.begin())
        {
            s1.insert(*s2.begin());
            s2.insert(*s1.rbegin());
            s2.erase(s2.begin());
            s1.erase(s1.find(*s1.rbegin()));
        }
    }
    cout<<*s1.rbegin()<<" ";

    for(int i=k;i<n;i++)
    {
        if(s1.count(v[i-k]))
        {
            s1.erase(s1.find(v[i-k]));
            if(s1.size()<s2.size())s1.insert(*s2.begin()),s2.erase(s2.begin());
        }
        else
        {
            s2.erase(s2.find(v[i-k]));
            if(s2.size() < s1.size() - 1)s2.insert(*s1.rbegin()),s1.erase(s1.find(*s1.rbegin()));
        }
        s1.insert(debug(v[i]));
        if(s1.size() - 1 > s2.size())s2.insert(*s1.rbegin()),s1.erase(s1.find(*s1.rbegin()));
        else if(s2.size() and *s1.rbegin() > *s2.begin())
        {
            s1.insert(*s2.begin());
            s2.insert(*s1.rbegin());
            s2.erase(s2.begin());
            s1.erase(s1.find(*s1.rbegin()));
        }

        cout<<*s1.rbegin()<<" ";
    }
    cout<<endl;
}