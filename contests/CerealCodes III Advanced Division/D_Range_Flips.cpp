#include <bits/stdc++.h>
const long double EPS = 1e-10;
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

int getTransform(int a, int b) {
    if(a == 6 and b == 6 || a == 19 and b == 19) return 4;
    if(a == 6 and b == 19 || a == 19 and b == 6) return 5;
    if(a == b)return 0;
    if((a + 13)%26 == b)return 1;
    if(25-a == b)return 2;
    if(25 - ((a + 13)%26) == b)return 3;
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> v1(n);
    for(int i = 0 ; i < n ; i++) {
        v1[i] = s[i] - 'a';
    }

    vector<int> v2(n);
    for(int i = 0 ; i < n ; i++) { 
        v2[i] = t[i] - 'a';
    }
    vector<int> transform(n);
    for(int i = 0 ; i < n ; i++) {
        transform[i] = getTransform(v1[i],v2[i]);
    }
    if(*min_element(all(transform)) == -1){ cout << -1 << endl; return 0;}
    debug(transform);
    int dp[4][n + 1];
    memset(dp,0x3F, sizeof(dp));
    dp[0][0] = 0;
    

    for(int i=0; i < n ; i++) {
        dp[0][i+1] = dp[1][i + 1] = dp[2][i + 1] = dp[3][i + 1] = INF;
        if(transform[i] < 4) { 
            for(int j=0;j < 4; j ++ ){
                dp[transform[i]][i + 1] = min(dp[transform[i]][i + 1], dp[j][i] + (int)__builtin_popcountll(transform[i] & ~j));
            }
        }
        else if(transform[i] == 4) { 
            vector<int> dest = {0,3};
            for(auto ti: dest)
            for(int j=0;j < 4; j ++) { 
                dp[ti][i + 1] = min(dp[ti][i + 1], dp[j][i] + (int)__builtin_popcountll(ti & ~j));
            }
        }
        else {
            vector<int> dest = {1,2};
            for(auto ti: dest)
            for(int j=0;j < 4; j ++) { 
                dp[ti][i + 1] = min(dp[ti][i + 1], dp[j][i] + (int)__builtin_popcountll(ti & ~j));
            }
        }
        debug(i + 1);
        debug(dp[0][i + 1], dp[1][i + 1] , dp[2][i + 1]  , dp[3][i + 1] );
    }

    cout << min({dp[0][n],dp[1][n],dp[2][n],dp[3][n]}) << endl;
}