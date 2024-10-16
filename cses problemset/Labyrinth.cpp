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
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

vector<pair<int,int>> dxy = {{-1,0},{1,0},{0,1},{0,-1}};


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    map<pair<int,int>,char> mp;
    mp[{0,1}] = 'R';
    mp[{0,-1}] = 'L';
    mp[{1,0}] = 'D';
    mp[{-1,0}] = 'U';
    int T=1;
    // cin>>T;
    for(;T--;)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> v(n,vector<char> (m));
        pair<int,int> a,b;
        for(auto&x:v)for(auto&y:x){cin>>y;}
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        {
            if(v[i][j] == 'A')a = {i,j};
            else if(v[i][j] == 'B') b = {i,j};
        }
        queue<pair<pair<int,int>,int>> q;
        q.push({a,0});
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
        parent[a.first][a.second] = {a.first,a.second};
        int ans = -1;
        while(q.size())
        {
            int i,j;
            auto [p,d] = q.front();
            q.pop();
            tie(i,j) = p;
            debug(p,d);
            for(auto [dx,dy]:dxy)
            {
                int idx = i + dx;
                int jdy = j + dy;
                if(idx!=-1 and idx != n and jdy!=-1 and jdy!=m and v[idx][jdy] != '#')
                {
                    if(parent[idx][jdy] == make_pair(-1ll,-1ll))
                    {
                        parent[idx][jdy] = {i,j};
                        q.push({{idx,jdy},d+1});
                    }
                    if(make_pair(idx,jdy) == b)
                    {
                        ans = d+1;
                        goto outer;
                    }
                }
            }
        }
        outer:
        42;
        if(ans == -1)cout(false);
        else 
        {
            cout(true);
            cout<<ans<<endl;
            stack<char> s;
            pair<int,int> cur = b;
            while(true)
            {
                auto [i,j] = cur;
                auto [pi,pj] = parent[i][j];
                if(i == pi and pj == j)break;
                else s.push(mp[{i-pi,j-pj}]);
                cur = make_pair(pi,pj);
            }

            while(s.size())
            {
                cout<<s.top();
                s.pop();
            }
        }
    }
}