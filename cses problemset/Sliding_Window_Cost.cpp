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

struct meddif
{
    multiset<int> s1,s2;
    int sum1 = 0;
    int sum2 = 0;
    void enter(int x)
    {
        if(s1.empty())
        {
            sum1 = x;
            s1.insert(x);
            return;
        }
        int med = *s1.rbegin();
        if(x <= med)
        {
            s1.insert(x);
            sum1 += x;
            if(s1.size() - 1 > s2.size())
            {
                s1.erase(s1.find(med));
                sum1 -= med;
                s2.insert(med);
                sum2 += med;
            }
        }
        else
        {
            s2.insert(x);
            sum2 += x;
            if(s2.size() > s1.size())
            {
                int tmp = *s2.begin();
                s1.insert(tmp);
                sum1 += tmp;
                s2.erase(s2.begin());
                sum2 -= tmp;
            }
        }
    }

    void remove(int x)
    {
        if(s1.count(x))
        {
            s1.erase(s1.find(x));
            sum1 -= x;
            if(s1.size() < s2.size())
            {
                int tmp = *s2.begin();
                s1.insert(tmp);
                sum1 += tmp;
                s2.erase(s2.begin());
                sum2 -= tmp;
            }
        }
        else
        {
            s2.erase(s2.find(x));
            sum2 -= x;
            if(s2.size() < s1.size() - 1)
            {
                int tmp = *s1.rbegin();
                s1.erase(s1.find(tmp));
                sum1 -= tmp;
                s2.insert(tmp);
                sum2 += tmp;
            }
        }
    }

    int getcost()
    {
        if(s1.size() == 0)return 0;
        int med = *s1.rbegin();
        return med * s1.size() - sum1 + sum2 - med * s2.size();
    }
};

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
    meddif s;
    for(int i=0;i<k;i++)
    {
        s.enter(v[i]);
    }
    cout<<s.getcost()<<" ";
    for(int i=k;i<n;i++)
    {
        s.remove(v[i-k]);
        s.enter(v[i]);
        cout<<s.getcost()<<" ";
    
    }
    cout<<endl;
}