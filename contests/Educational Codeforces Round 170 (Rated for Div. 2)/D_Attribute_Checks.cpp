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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

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
    int n,m;
    cin>>n>>m;
    vector<int> r(n);
    for(int i=0;i<n;i++)cin>>r[i];

    vector<int> spaces;
    vector<pair<vector<int>,vector<int>>> islands;

    int spacecount = 0;
    for(int i=0;i<n;i++)
    {
        if(r[i] == 0)
        spacecount++;
        else
        {
            spaces.push_back(spacecount);
            spacecount = 0;
            islands.push_back({});
            while(i < n and r[i] != 0)
            {
                if(r[i] < 0)
                {islands.back().second.push_back(-r[i]);}
                else{islands.back().first.push_back(r[i]);}
                i++;
            }
            i--;
            sort(all(islands.back().first));
            sort(all(islands.back().second));
        }
    }

    assert(spaces.size() == islands.size());


    spacecount = 0;
    vector<vector<int>> v(islands.size() + 1, vector<int>(m + 1,-INF));
    v[0][0] = 0;
    for(int i=0;i<islands.size();i++)
    {
        spacecount += spaces[i];
        for(int strength=0;strength<=spacecount;strength++)
        {
            int intelligence = spacecount - strength;
            int mx = -INF;
            for(int j = max(0ll,strength-spaces[i]);j <= strength;j++)
            {
                mx = max(mx,v[i][j]);
            }
            if(mx < 0)continue;

            int update = upper_bound(all(islands[i].first),strength) - islands[i].first.begin();
            update += upper_bound(all(islands[i].second),intelligence) - islands[i].second.begin();
            v[i+1][strength] = update + mx;
        }
    }
    cout<<*max_element(all(v.back()))<<endl;
}