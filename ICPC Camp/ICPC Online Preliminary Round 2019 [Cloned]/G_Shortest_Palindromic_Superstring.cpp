#include <bits/stdc++.h>
const long double EPS = 1e-7;

using namespace std;
//insert policy here

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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
string solve(string, string&,int);
string getshortpal(string& a, int flag)
{
    if(flag)return a;

    string ac = a;
    reverse(all(ac));
    string ans1 = solve(a,ac,1);
    string ans2 = solve(ac,a,1);
    if(ans1.size() > ans2.size())return ans2;
    return ans1;
}

string solve(string a, string& b, int flag = 0){
    vector<int> zbb(b.size());
    vector<int> zba(a.size());
    int l = 0,r = 0;
    for(int i=1;i<b.size();i++)
    {
        if(i < r)zbb[i] = min(r-i,zbb[i-l]);
        while(i + zbb[i] < b.size() and b[i + zbb[i]] == b[zbb[i]])zbb[i]++;
        if(zbb[i] + i > r)l = i,r = i + zbb[i];
    }

    l = 0,r = 0;
    bool alreadyin = false;
    int shorteststart = a.size();
    for(int i=0;i<a.size();i++)
    {
        if(i < r)zba[i] = min(r - i,zba[i-l]);
        while(zba[i] < b.size() and i + zba[i] < a.size() and a[i + zba[i]] == b[zba[i]])zba[i]++;
        if(zba[i] + i > r)l = i,r = i + zba[i];

        if(zba[i] == b.size())
        {
            alreadyin = true;
            break;
        }

        if(zba[i] + i == a.size())
        {
            shorteststart = i;
            break;
        }
    }

    if(alreadyin)
    {
        return getshortpal(a,flag);
    }
    a.insert(a.end(),a.size() - shorteststart + all(b));

    return getshortpal(a,flag);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        string s,t;
        cin>>s>>t;

        string solve1 = solve(s,t);
        reverse(all(t));
        string solve2 = solve(s,t);
        reverse(all(t));
        string solve3 = solve(t,s);
        reverse(all(t));
        string solve4 = solve(t,s);
        debug(solve1,solve2,solve3,solve4);
        cout<<min({solve1.size(),solve2.size(),solve3.size(),solve4.size()})<<endl;
    }
}