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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

struct speed
{
    int val = 0;
    int delta = 0;
    speed operator+(const speed& delta) const
    {
        speed cpy = *this;
        cpy.val += cpy.delta + delta.val;
        cpy.delta += delta.delta;
        return cpy;
    }
    void operator+=(const speed& add)
    {
        val += add.val;
        delta += add.delta;
    };
};

vector<vector<int>> personx(vector<vector<int>>& v, int x)
{
    int n = v.size(),m = v[0].size();
    vector<speed> rowstart(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == x)
            {
                if(j >= i)
                {
                    rowstart[0] += {j,0};
                }
                else
                {
                    rowstart[0] += {i,-1};
                    rowstart[i-j] += {0,1};
                }
                if (j <= n - 1 - i)
                {
                    rowstart[i+j] += {0,1};
                }
            }
        }
    }
    partial_sum(all(rowstart),rowstart.begin());

    vector<int> respeed(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == x)
            {
                if(j == 0)
                {
                    respeed[i] += 1;
                    if(i!=n-1)respeed[i+1] += -1;
                    continue;
                }
                respeed[max(i-j+1,0ll)] += -1;
                if(i+j <n)
                respeed[i+j] += 1;
            }
        }
    }
    partial_sum(all(respeed),respeed.begin());

    for(int i=0;i<n;i++)rowstart[i].delta = respeed[i];

    vector<vector<int>> finscore(n,vector<int>(m));
    vector<vector<int>> delta1(n,vector<int>(m));
    vector<vector<int>> delta2(n,vector<int>(m));
    vector<vector<int>> delta3(n,vector<int>(m));
    vector<vector<int>> delta4(n,vector<int>(m));
    vector<vector<int>> deltatot(n,vector<int>(m));
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            delta1[i][j] += delta1[i-1][j-1];
            if(v[i-1][j-1] == x)
            {
                delta1[i][j] += 1;
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<m;j++)
        {
            delta2[i][j] += delta2[i+1][j-1];
            if(v[i+1][j-1] == x)
            delta2[i][j] +=  1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            delta3[i][j] += delta3[i+1][j+1];
            if(v[i+1][j+1] == x)
            delta3[i][j] += 1;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=m-2;j>=0;j--)
        {
            delta4[i][j] += delta4[i-1][j+1];
            if(v[i-1][j+1] == x)
            delta4[i][j] += 1;
        }
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        deltatot[i][j] = delta1[i][j] + delta2[i][j] + delta3[i][j] + delta4[i][j];
        if(v[i][j] == x)deltatot[i][j] += 2;
    }
    debug(deltatot);
    for(int i=0;i<n;i++)
    {
        finscore[i][0] = rowstart[i].val;
        speed cur = rowstart[i];
        cerr<<finscore[i][0]<<" ";
        for(int j=1;j<m;j++)
        {
            cur = cur + speed({0,deltatot[i][j]});
            finscore[i][j] = cur.val;
            cerr<<finscore[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<"____"<<endl;
    return finscore;
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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(m));

        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>v[i][j];
        vector<vector<int>> a = personx(v,1);
        vector<vector<int>> b = personx(v,2);
        for(int i=0;i<n;i++){for(int j=0;j<m;j++)
        {
            cout<<abs(a[i][j] - b[i][j])<<" ";
        }
        cout<<endl;
        }
    }
}