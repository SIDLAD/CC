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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;
int n;
vector<vector<char>> grid,ansgrid;
vector<string> inp;
bitset<8> mask;

void printgrid()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        if(ansgrid[i][j] == 0)
        cout<<'A';
        else cout<<ansgrid[i][j];
        cout<<endl;
    }
    cout<<endl;
}

void printfalse(){cout<<"grid\nsnot\nposs\nible\n\n";}

void updateans(){

    for(int i=0;i<4;i++)for(int j=0;j<4;j++)
    {
        if(ansgrid[i][j] == 0 and grid[i][j] == 'A' or ansgrid[i][j] == 'A' and grid[i][j] == 0)continue;
        if(ansgrid[i][j] == grid[i][j])continue;
        if(ansgrid[i][j] > grid[i][j])
        {
            ansgrid = grid;
            goto out;
        }
        else goto out;
    }
    out:42;
}

bool dfs(int index = 0)
{
    bool check = false;
    if(index == n)
    {
        check |= true;
        updateans();
    }

    else
    for(int i=0;i<8;i++)if(!mask[i])
    {
        mask[i] = 1;
        vector<string> strs = {inp[index],inp[index]};
        reverse(all(strs.back()));
        for(auto str: strs)
        {
            if(i < 4)
            {
                //row
                bool subcheck = true;
                for(int j=0;j<4;j++)
                {
                    if(grid[i][j] == 0 or grid[i][j] == str[j]);
                    else{subcheck = false;break;}
                }

                if(subcheck)
                {
                    vector<pair<char&,char>> revert;
                    for(int j=0;j<4;j++)
                    {
                        if(grid[i][j] == 0)
                        {
                            grid[i][j] = str[j];
                            revert.push_back({grid[i][j],0});
                        }
                    }
                    check |= dfs(index + 1);
                    while(revert.size())
                    {
                        revert.back().first = revert.back().second;
                        revert.pop_back();
                    }
                }
            }
            else
            {
                //column
                int newi = i - 4;
                bool subcheck = true;
                for(int j=0;j<4;j++)
                {
                    if(grid[j][newi] == 0 or grid[j][newi] == str[j]);
                    else{subcheck = false;break;}
                }

                if(subcheck)
                {
                    vector<pair<char&,char>> revert;
                    for(int j=0;j<4;j++)
                    {
                        if(grid[j][newi] == 0)
                        {
                            grid[j][newi] = str[j];
                            revert.push_back({grid[j][newi],0});
                        }
                    }
                    check |= dfs(index + 1);
                    while(revert.size())
                    {
                        revert.back().first = revert.back().second;
                        revert.pop_back();
                    }
                }
            }
        }
        mask[i] = 0;
    }
    return check;
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
        cin>>n;
        set<string> sortwords;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            string s2 = s;
            reverse(all(s2));
            sortwords.insert(min(s,s2));
        }
        n = sortwords.size();
        grid.assign(4,vector<char>(4,0));
        ansgrid.assign(4,vector<char>(4,127));
        mask = 0;

        if(sortwords.size() > 8)printfalse();
        else
        {
            inp.clear();
            inp.insert(inp.end(),all(sortwords));
            if(dfs())printgrid();
            else printfalse();
        }
    }
}