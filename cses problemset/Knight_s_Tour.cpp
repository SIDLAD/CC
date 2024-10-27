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
    int x,y;
    cin>>x>>y;
    x--,y--;
    vector<vector<int>> indegree(8,vector<int>(8));
    vector<int> dx = {1,1,-1,-1,2,2,-2,-2};
    vector<int> dy = {2,-2,2,-2,1,-1,1,-1};
    auto check = [&](int i, int j, int k)
    {
        if(i + dx[k] < 0 or i + dx[k] >= 8)return 0;
        if(j + dy[k] < 0 or j + dy[k] >= 8)return 0;
        return 1;
    }
    ;
    auto get = [&](int i, int j, int k)
    {
        return make_pair(i + dx[k],j + dy[k]);
    };
    vector<vector<int>> visited(8,vector<int>(8));
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)
    {
        for(int k=0;k<8;k++)
        {
            if(check(i,j,k))
            {
                auto [ni,nj] = get(i,j,k);
                indegree[ni][nj] ++;
            }
        }
    }
    int cnt = 1;
    int curx = x,cury = y;
    // do
    // {
    //     debug(curx,cury,cnt);
    //     visited[curx][cury] = cnt++;
    //     if(cnt > 64)break;
    //     vector<pair<int,pair<int,int>>> poss;
    //     for(int i=0;i<8;i++)
    //     {
    //         if(check(curx,cury,i))
    //         {
    //             auto [ni,nj] = get(curx,cury,i);
    //             if(!visited[ni][nj])
    //             poss.push_back({--indegree[ni][nj],{ni,nj}});
    //         }
    //     }
    //     sort(all(poss));
    //     auto [ni,nj] = poss[0].second;
    //     curx = ni,cury = nj;

    // }while(true);

    auto dfs = [&](auto self, int curx, int cury, int cnt)->bool
    {
        debug(curx,cury,cnt);
        visited[curx][cury] = cnt;
        if(cnt == 64)return true;
        vector<pair<int,pair<int,int>>> poss;
        for(int i=0;i<8;i++)
        {
            if(check(curx,cury,i))
            {
                auto [ni,nj] = get(curx,cury,i);
                if(!visited[ni][nj])
                poss.push_back({--indegree[ni][nj],{ni,nj}});
            }
        }
        sort(all(poss));
        for(auto [_,pr] : poss){
            auto [ni,nj] = pr;
            if(self(self,ni,nj,cnt + 1))return true;
        }

        visited[curx][cury] = 0;
        for(int i=0;i<8;i++)
        {
            if(check(curx,cury,i))
            {
                auto [ni,nj] = get(curx,cury,i);
                if(!visited[ni][nj])
                ++indegree[ni][nj];
            }
        }

        return false;
    };

    dfs(dfs,curx,cury,1);

    for(int j=0;j<8;j++)for(int i=0;i<8;i++)
    {
        cout<<visited[i][j]<<" \n"[i==7];
    }
}