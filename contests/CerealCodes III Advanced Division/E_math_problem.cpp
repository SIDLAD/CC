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
int n, q;
int a[(int)2e5 + 1];
int b[(int)2e5 + 1];
vector<int> edges[(int)2e5 + 1];
int type;
int i, x;
int diff;

stack<pair<int,int>> st;

int mobius[(int)2e5 + 1];
void precompute() {
    mobius[1] = -1;
    for(int i = 1;i <= 2e5; i++) {
        mobius[i] *= -1;
        for(int j=2 * i;j <= 2e5;j+= i) {
            mobius[j] += mobius[i];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    precompute();
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i];
        int j;
        if(i!=1) edges[i].push_back(1);
        for(j=2;j*j < i;j++) if(i%j==0) edges[i].push_back(j),edges[i].push_back(i/j);
        if(j*j == i)edges[i].push_back(j);
    }

    for(int i=n;i>=1;i--) for(auto div: edges[i])b[div] -= b[i];

    while(q--) {
        cin >> type;
        switch(type) {
            case 2:
                cin >> i;
                cout << b[i] << endl;
                break;
            case 1:
                cin >> i >> x;
                diff = x - a[i];
                a[i] = x;
                b[i] += diff;
                for(auto div: edges[i]) {
                    b[div] += mobius[i/div] * diff;
                }
        }
    }
}