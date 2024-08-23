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
    int n,k;
    cin>>n>>k;
    int srt = (int)sqrt(n);

    int len = (n+srt-1)/srt;
    

    vector<vector<int>> v(len,vector<int>(0));

    for(int i=0,j=0,k=0;i<n;i++,j=(j+1)%srt,k = k + (j==0))
    {
        v[k].push_back(i+1);
    }
    
    int ptr1=0,ptr2=0;
    for(int i=n;i>0;i--)
    {
        int rem = (k)%i + 1;
        while(v[ptr1].size() - ptr2 < rem)
        {
            rem -= v[ptr1].size() - ptr2;
            ptr1 = (ptr1 + 1)%len;
            ptr2 = 0;
        }
        ptr2 += (rem - 1);

        cout<<v[ptr1][ptr2]<<" ";
        for(int k=ptr2;k<v[ptr1].size() - 1;k++)
        {
            v[ptr1][k] = v[ptr1][k + 1];
        }
        v[ptr1].pop_back();
    }
}