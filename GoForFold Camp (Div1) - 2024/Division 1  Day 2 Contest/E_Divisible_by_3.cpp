#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    #define debug(x...) (_exe(x))
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

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

    // map<pair<int,int>,int> premap;
    // premap[{0,0}] = 0; 
    // premap[{0,1}] = 0; 
    // premap[{0,2}] = 1; 
    // premap[{1,0}] = 0; 
    // premap[{1,1}] = 2; 
    // premap[{1,2}] = 2; 
    // premap[{2,0}] = 1; 
    // premap[{2,1}] = 2; 
    // premap[{2,2}] = 1; 


    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    range(i,0,n)
    {
        int x;
        cin>>x;
        v[i] = x % 3;
    }
    debug(v);
    pair<int,int> curab;
    curab = {0,0};
    map<pair<int,int>,int> freq;
    freq[{0,0}] = 1;
    int ans = 0;
    range(i,0,n)
    {
        if(v[i] == 0);
        else if(v[i] == 2 )curab.first++;
        else curab.second++;
        curab.first%=3;
        curab.second%=3;

        for(int k=0;k<3;k++)for(int j=0;j<3;j++)
        {
            pair<int,int> cpy = {k,j};
            pair<int,int> diff = {(curab.first - cpy.first + 3)%3,(curab.second - cpy.second + 3)%3};

            if(max(diff.first,diff.second) <= 1 and min(diff.first,diff.second) != 1)
            {
                debug(i,curab,cpy,freq[cpy]);

                ans += freq[cpy];
            }
        }

        freq[curab]++;
    }
    cout<<ans<<endl;
}