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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
#define endl "\n" //comment out for interactive problems

bool are_attacking(int i, int j)
{
    if(i/8 == j/8)return true;
    if(i%8 == j%8)return true;
    if(i/8 + i%8 == j/8 + j%8)return true;
    if(i/8 + j%8 == j/8 + i%8)return true;
    return false;
}

bool is_valid_pos(vector<int>& v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(are_attacking(v[i],v[j]))return false;
        }
    }
    if(v.size() == 8)debug(v);

    return true;
}

int count_positions(int remaining_queens, int cur_square, vector<int>& current_queen_positions,vector<vector<char>>& v)
{
    if(remaining_queens == 0)return 1;
    int ans = 0;
    for(int i=cur_square;i<64;i++)
    {
        if(v[i/8][i%8] == '*')continue;
        vector<int> copy = current_queen_positions;
        copy.push_back(i);
        if(is_valid_pos(copy))ans += count_positions(remaining_queens - 1, i + 1, copy, v);
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    vector<vector<char>> v(8,vector<char>(8));
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)
    {
        cin>>v[i][j];
    }
    debug(v[7][4], 7*8 + 4);
    vector<int> empty ={};
    cout<<count_positions(8,0,empty,v)<<endl;
}