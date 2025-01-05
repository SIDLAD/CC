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

vector<pair<int,int>> pairs;
// set<int> st;
// int addnext(int n)
// {
//     for(int i=0;n - 2*i > 0;i ++)
//     {
//         if(i* i % (n - 2*i) == 0)
//         {
//             st.insert(i * i / (n - 2*i));
//         }
//     }
//     debug(n,st);
//     return *st.rbegin() + 1;
// }

void display(vector<int> partition)
{
    int dn = 0;
    int x = 1,y = 1;
    for(auto part:partition)
    {
        while(part--)
        {
            cout<<x<<" "<<y<<endl;
            pairs.emplace_back(x,y);
            x++,y++;
        }
        dn++;
        y += 907;
        x += 906;
    }
    cout<<-1<<endl;
}

int checksqr(int x)
{
    int i = (int)sqrtl(x);
    if(i*i == x or (i - 1)*(i-1) == x or (i + 1)*(i + 1) == x)return true;
    return false;
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
        // st.clear();
        pairs.clear();
        int k;
        cin>>k;
        int kc = k;
        vector<int> partition;
        int tot = 0;
        while(k > 0)
        {
            int ll = 0;
            int ul = 2*k + 1;
            while(ul - ll > 1)
            {
                int mid = ll + ul >> 1;
                if(mid*(mid-1)/2 <= k)ll = mid;
                else ul = mid;
            }
            partition.push_back(ll);
            tot += ll;
            k -= (ll) * (ll - 1)/2;
        }
        assert(tot <= 2023);
        while(tot <2023)
        {
            partition.push_back(1);
            tot++;
        }
        // debug(partition);
        display(partition);

        #ifndef cerr
        int cnt = 0;
        for(int i=0;i<pairs.size();i++)
        {
            for(int j=i + 1;j<pairs.size();j++)
            {
                if(checksqr(abs(pairs[i].first - pairs[j].first) * abs(pairs[i].second - pairs[j].second)))
                cnt++;
            }
        }
        debug(cnt,kc);
        debug();
        #endif
    }
}