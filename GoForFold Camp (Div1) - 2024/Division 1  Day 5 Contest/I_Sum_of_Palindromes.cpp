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

vector<int> subtract(vector<int> a, vector<int> b) { // a - b
    vector<int> bdash;
    for(int i=0;i<a.size() -b.size();i++)bdash.push_back(0);
    bdash.insert(bdash.end(), all(b));
    int n = a.size();
    debug(a,bdash);
    for(int i=n-1;i>=0;i--)
    {
        a[i] -= bdash[i];
        if(a[i] < 0)
        {
            a[i] += 10;
            // assert(i > 0);
            a[i-1]--;
        }
    }
    assert(*min_element(all(a)) >= 0);

    int firstindex = 0;
    for(;firstindex != n and a[firstindex] == 0;firstindex++);
    vector<int> c(firstindex + all(a));
    return c;
}

vector<int> generatenextpalindrome(vector<int> a)
{

    int n = a.size();

    if(n == 1)
    {
        return a;
    }
    if(n == 2)
    {
        if(a[0] == 1 and a[1] == 0)//10
        {
            vector<int> b = {9};
            return b;
        }
        else
        {
            int num = a[0] * 10 + a[1];
            int lowestmultipleof11 = num / 11;
            vector<int> b = {lowestmultipleof11,lowestmultipleof11};
            return b;
        }
    }


    vector<int> b((n + 1)/2);
    for(int i=0;i<b.size();i++)b[i] = a[i];
    b.back()--;
    int curid = b.size() - 1;
    while(b[curid] < 0)
    {
        assert(curid > 0);
        b[curid] += 10;
        b[curid - 1] -= 1;
        curid --;
    }
    b.resize(a.size());

    
    for(int i = n - 1; i >= (n + 1)/2;i--)
    {
        b[i] = b[b.size() - 1 - i];
    }
    if(b[0] == 0)b.back() = 9;
    int firstindex = 0;
    for(;firstindex < b.size() and b[firstindex] == 0;firstindex++);
    vector<int> bc(firstindex + all(b));
    b = bc;
    debug(b);
    return b;
}

string getstring(vector<int>& a)
{
    string s = "";
    for(auto ele:a)s += '0' + ele;
    return s;
}


void solve() {
    string s;
    cin >> s;
    debug(s);
    int n = s.size();
    vector<int> ss(n);
    for(int i=0;i<n;i++)
    {
        ss[i] = s[i] - '0';
    }
    vector<vector<int>> ans;
    while(ss.size())
    {
        ans.push_back(generatenextpalindrome(ss));
        ss = subtract(ss,ans.back());
        debug(ans.back(),ss);
    }
    assert(ans.size() <= 25);
    cout<<ans.size()<<endl;

    range(i,0,ans.size())
    {
        cout<<getstring(ans[i])<<endl;
    }
}

// void solve(int x) {
//     string s = to_string(x);
//     int n = s.size();
//     vector<int> ss(n);
//     for(int i=0;i<n;i++)
//     {
//         ss[i] = s[i] - '0';
//     }
//     vector<vector<int>> ans;
//     while(ss.size())
//     {
//         ans.push_back(generatenextpalindrome(ss));
//         ss = subtract(ss,ans.back());
//         debug(ans.back(),ss);
//     }
//     cout<<ans.size()<<endl;

//     range(i,0,ans.size())
//     {
//         cout<<getstring(ans[i])<<endl;
//     }
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    // for(int i =1;i<=1e6;i++)
    // {
    //     solve(i);
    // }
}