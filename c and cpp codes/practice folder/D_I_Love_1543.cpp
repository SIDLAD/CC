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
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,m;
        cin>>n>>m;
        vector<string> v(n);
        vector<vector<int>> visited(n,vector<int>(m));
        arrPut(v);
        int anscnt = 0;
        int cnt = 0;
        int posx = 0;
        int posy = 0;
        while(cnt < n * m)
        {
            string tmp;
            for(;posx<m and (!visited[posy][posx]);posx++)
            {
                tmp += v[posy][posx];
                cnt++;
                visited[posy][posx] = true;
            }
            posx--;
            posy++;
            for(;posy<n and (!visited[posy][posx]);posy++)
            {
                tmp += v[posy][posx];
                cnt++;
                visited[posy][posx] = true;
            }
            posy--;
            posx--;
            for(;posx>=0 and (!visited[posy][posx]);posx--)
            {
                tmp += v[posy][posx];
                cnt++;
                visited[posy][posx] = true;
            }
            posx++;
            posy--;
            for(;posy >=0 and (!visited[posy][posx]);posy--)
            {
                tmp += v[posy][posx];
                cnt++;
                visited[posy][posx] = true;
            }
            posy++;
            posx++;

            tmp.insert(tmp.end(),tmp.begin(),tmp.begin() + 3);
            for(int i=0;i + 4<=tmp.size();i++)
            {
                if("1543" == tmp.substr(i,4))anscnt++;
            }
            // debug(tmp);
        }
        cout<<anscnt<<endl;
    }
}