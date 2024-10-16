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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    array<int,3> pos;
    queue<array<int,3>> q;
    vector<vector<char>> p(n,vector<char>(m,' '));
    vector<vector<int>> monstervisit(n,vector<int>(m,0));
    pair<int,int> fin = {-1,-1};
    for(int i=0;i<n;i++)for(int j = 0;j<m;j++){
        cin>>v[i][j];
        if(v[i][j] == 'A')pos = {i,j,1},p[i][j] = '$';
        else if(v[i][j] == 'M')q.push({i,j,0}),monstervisit[i][j] = 1;
    }

    q.push(pos);
    while(q.front()[2] == 0)q.push(q.front()),q.pop();
    vector<array<int,2>> delta = {{0,-1},{0,1},{-1,0},{1,0}};
    string turn = "LRUD";
    debug(fin);
    while(q.size())
    {
        auto currentpos = q.front();
        q.pop();
        debug(currentpos);
        if(currentpos[2] and monstervisit[currentpos[0]][currentpos[1]])continue;
        if(currentpos[2] and (currentpos[0] == 0 or currentpos[1] == 0 or currentpos[0] == n-1 or currentpos[1] == m-1))
        {
            fin = {currentpos[0],currentpos[1]};
            break;
        }
        for(int i = 0;i<4;i++)
        {
            int in = currentpos[0] + delta[i][0];
            int jn = currentpos[1] + delta[i][1];
            if(in < 0 or in >=n or jn <0 or jn >=m)continue; // only valid for monsters
            if(v[in][jn] == '#')continue;
            if(monstervisit[in][jn])continue;
            if(currentpos[2] and p[in][jn] != ' ')continue;
            if(currentpos[2])p[in][jn] = turn[i];
            else monstervisit[in][jn] = 1;
            q.push({in,jn,currentpos[2]});
        }
    }
    debug(fin);
    debug(p);
    cout(fin.first != -1);
    if(fin.first == -1){return 0;}
    stack<char> s;
    while(p[fin.first][fin.second]!='$')
    {
        s.push(p[fin.first][fin.second]);
        auto [dx,dy] = delta[turn.find(p[fin.first][fin.second])];
        fin.first -=dx,fin.second -= dy;
    }
    cout<<s.size()<<endl;
    while(s.size())
    {
        cout<<s.top();
        s.pop();
    }
}