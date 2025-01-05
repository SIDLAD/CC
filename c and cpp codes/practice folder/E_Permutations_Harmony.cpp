#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

int flag;
set<vector<int>> st;
void getnextpermutation(vector<vector<int>>& cur);
void append(vector<vector<int>>& dest, vector<vector<int>>& app)
{
    start:
    for(auto& v: app)
    {
        if(st.count(v))
        {
            getnextpermutation(app);
            if(flag)
            goto start;
        }
    }
    
    for(auto& v: app)
    {
        dest.push_back(v);
        st.insert(v);
    }
}

void getnextpermutation(vector<vector<int>>& cur)
{
    vector<vector<int>> transpose(cur[0].size(),vector<int>(cur.size()));
    for(int i=0;i<cur[0].size();i++)for(int j=0;j<cur.size();j++)
    {
        transpose[i][j] = cur[j][i];
    }

    if(!next_permutation(all(transpose))){flag = false;return;};

    for(int i=0;i<cur.size();i++)for(int j=0;j<cur[0].size();j++)
    {
        cur[i][j] = transpose[j][i];
    }

    for(auto& v:cur)
    {
        if(st.count(v))
        {
            getnextpermutation(cur);
            return;
        }
    }
}

vector<vector<int>> getthree(int n)
{
    vector<vector<int>> ans(3,vector<int>(n));
    iota(all(ans[0]),1ll);
    int startid = (n + 1) >> 1;
    // assert(startid < n);
    for(int i=0;i<n;i++, startid = (startid + 1)%n)
    {
        ans[1][startid] = i + 1;
    }

    int tgt = 3*(n + 1) >> 1;
    for(int i=0;i<n;i++)
    {
        ans[2][i] = tgt - ans[1][i] - ans[0][i];
    }
    return ans;
}

vector<vector<int>> gettwo(int n)
{
    vector<vector<int>> ans(2,vector<int>(n));
    iota(all(ans[0]),1ll);
    iota(ans[1].rbegin(),ans[1].rend(),1ll);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(int TT = 1;T--;TT++)
    {
        int n,k;
        cin>>n>>k;
        
        if(n == 1)
        {
            if(k != 1)
            {
                cout(false);
                continue;
            }
            cout(true);
            cout<<1<<endl;
            continue;
        }
        if(k == 1 or k*(n + 1) % 2 == 1)
        {
            cout(false);
            continue;
        }
        vector<vector<int>> ans;

        flag = true;
        st.clear();
        if(n & 1)
        {
            vector<vector<int>> two = gettwo(n);
            vector<vector<int>> three = getthree(n);
            if(k&1)
            {
                append(ans,three);
                k -= 3;
            }
            while(k > 0)
            {
                append(ans,two);
                k-=2;
            }
        }
        else
        {
            // assert(~k&1);
            vector<vector<int>> two = gettwo(n);
            while(k > 0)
            {
                append(ans,two);
                k-=2;
            }
        }
        if(flag == false)
        {
            cout(false);
            continue;
        }
        cout(true);
        range(i,0,ans.size())range(j,0,n)
        {
            cout<<ans[i][j]<<" \n"[j == n-1];
        }
    }
}