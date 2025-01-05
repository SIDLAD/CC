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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX/10
#else
    INT_MAX/2
#endif
;

int countcoll(vector<int>& a,vector<int>& b)
{
    set<int> st;
    for(int i=0;i<a.size();i++)st.insert(a[i]);
    int cnt = 0;
    for(int i=0;i < b.size();i++)if(st.count(b[i]))cnt++;
    return cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    arrPut(v);
    vector<vector<int>> c(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i];j++)
        {
            int x;
            cin>>x;
            c[i].push_back(x);
        }
    }

    // vector<int> dpleft(n);
    // vector<int> dpright(n);

    int _1[n + 10] = {};
    int _2[n + 10] = {};
    int _3[n + 10] = {};
    
    int* dpleftleft = _1 + 5;
    int* dpright = _2 + 5;
    int* dpleftright = _3 + 5;

    
    dpleftleft[0] = INF;
    dpleftleft[-1] = INF;
    dpleftleft[-2] = INF;
    dpleftright[0] = INF;
    dpleftright[-1] = INF;
    dpleftright[-2] = INF;


    for(int i=1;i<n;i++)
    {
        vector<int> tmp;
        int coll1back = countcoll(c[i],(i - 1 < 0? tmp : c[i-1]));
        int coll2back = countcoll(c[i],(i - 2 < 0? tmp:c[i-2]));
        int collprev2 = countcoll((i - 1 < 0? tmp : c[i-1]),(i - 2 < 0? tmp:c[i-2]));
        if(i == 1)collprev2 = INF;
        // int collsum = coll1 + coll2;
        // dpleft[i] = min(coll + (i==0?INF:dpright[i-1]),(i==0?0:dpleft[i-1]));
        // dpleft[i] = min({dpleft[i-2],dpright[i-2] + collprev2 + coll2back, dpright[i-2] + coll1back + coll2back, dpleft[i-2] + coll1back});
        dpleftleft[i] = min({dpleftleft[i-1], dpleftright[i-1] + coll2back});
        dpleftright[i] = min({dpright[i-2] + coll2back + coll1back,min(dpleftleft[i-2],dpleftright[i-2]) + coll2back});
        dpright[i] = min({dpleftleft[i-1],dpright[i-1],dpleftright[i-1]});
    }
    #ifndef cerr
    for(int i=0;i<n;i++)
    {
        debug(i,dpleftleft[i],dpleftright[i],dpright[i]);
    }
    #endif

    cout<<min({dpleftleft[n-1],dpleftright[n-1]})<<endl;
}