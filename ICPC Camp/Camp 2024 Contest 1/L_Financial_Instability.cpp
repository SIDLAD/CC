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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

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
    string s;
    cin>>s;
    vector<int> pre1(s.length());
    vector<int> pre2(s.length());
    for(int i=0;i<s.length();i++)if(s[i] == 'A')pre1[i] = 1;else pre2[i] = 1;
    partial_sum(all(pre1),pre1.begin());
    partial_sum(all(pre2),pre2.begin());
    debug(pre1,pre2);
    int s1 = - 1,e1 = -1;
    if(pre1.back()&1 or pre2.back()&1)cout<<"NO"<<endl;
    else
    {
        int hf = s.length()/2;
        for(int i=0;i<s.length()/2;i++)
        {
            debug(pre1[i + hf - 1] - (i==0?0:pre1[i-1]),pre2[i + hf - 1] - (i==0?0:pre2[i-1]),i);
            if(pre1[i + hf - 1] - (i==0?0:pre1[i-1]) == pre1.back()/2)
            if(pre2[i + hf - 1] - (i==0?0:pre2[i-1]) == pre2.back()/2)
            {
                s1 = i,e1 = i + hf;
                break;
            }
        }
        if(s1 == -1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<s1 + 1<<" "<<e1 + 1;
        }
    }
}