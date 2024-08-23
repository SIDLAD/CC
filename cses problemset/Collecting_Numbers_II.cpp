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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(n);
    vector<int> inp(n);
    for(int i=0;i<n;i++)cin>>v[i].first,inp[i]=v[i].first,v[i].second = i;
    sort(all(v));
    int ori_ans = 1;
    for(int i=1;i<n;i++){
        if(v[i-1].second  > v[i].second)ori_ans ++;
    }
    debug(ori_ans);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        int num1 = inp[a];
        int num2 = inp[b];

        swap(inp[a],inp[b]);

        v[num1 - 1].second = b;
        v[num2 - 1].second = a;
        if(num1 > 1)
        {
            if(a >= v[num1 - 1 - 1].second and v[num1 - 1 - 1].second > b)
            {
                ori_ans ++;
            }
            else if(a <= v[num1 - 1 - 1].second and v[num1 - 1 - 1].second < b)
            ori_ans--;
        }
        if(num2 > 1)
        {
            if(b >= v[num2 - 1 - 1].second and v[num2 - 1 - 1].second > a)
            {
                ori_ans ++;
            }
            else if(b <= v[num2 - 1 - 1].second and v[num2 - 1 - 1].second < a)
            ori_ans--;
        }

        if(num1 < n and num1 + 1 != num2)
        {
            if(a <= v[num1 + 1 - 1].second and v[num1 + 1 - 1].second < b)
            {
                ori_ans ++;
            }
            else if(a >= v[num1 + 1 - 1].second and v[num1 + 1 - 1].second > b)
            ori_ans--;
        }

        if(num2 < n and num2 + 1 != num1)
        {
            if(b <=v[num2 + 1 - 1].second and v[num2 + 1 - 1].second < a)
            {
                ori_ans ++;
            }
            else if(b >=v[num2 + 1 - 1].second and v[num2 + 1 - 1].second > a)
            ori_ans--;
        }

        
        cout<<ori_ans<<endl;
    }

}