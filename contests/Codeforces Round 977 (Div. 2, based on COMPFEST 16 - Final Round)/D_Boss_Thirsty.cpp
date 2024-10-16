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
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];

        vector<vector<int>> dpL(n+1,vector<int>(m+1,-INF)),dpR(n+1,vector<int>(m+1,-INF));
        dpL[0].assign(m+1,0),dpR[0].assign(m+1,0);
        dpL[0][m] = dpR[0][0] = -INF;
        for(int i=1;i<=n;i++)
        {
            vector<int> pre(m+1);
            partial_sum(all(a[i-1]),pre.begin() + 1);
            vector<int> minuspreLmax(m+1);
            vector<int> minuspreLmaxplusmaxdpldprp(m+1);
            // vector<int> maxdpldprp(m+1);
            minuspreLmaxplusmaxdpldprp[0] = -INF;
            for(int j=1;j<=m;j++)
            {
                minuspreLmax[j] = max(minuspreLmax[j-1],-pre[j]);
                // maxdpldprp[j] = max({dpL[i-1][j],dpR[i-1][j],maxdpldprp[j-1]});
                minuspreLmaxplusmaxdpldprp[j] = max(max(dpL[i-1][j],dpR[i-1][j]) + minuspreLmax[j-1],minuspreLmaxplusmaxdpldprp[j-1]);
            }
            if(i==2)
            {
                debug(minuspreLmaxplusmaxdpldprp);
                debug(minuspreLmax);
            }
            for(int r = 1 ; r<=m;r++)
            {
                if(r!=1)
                dpR[i][r] = pre[r] + minuspreLmaxplusmaxdpldprp[r-1];
                if(i==1)
                {
                    dpR[i][r] = max(dpR[i][r],a[0][r-1]);
                }
            }

            vector<int> preRmax(m+1);
            preRmax[m] = pre[m];
            vector<int> preRmaxplusmaxdpldprp(m+1);
            preRmaxplusmaxdpldprp[m] = -INF;
            for(int j=m-1;j>=0;j--)
            {
                preRmax[j] = max(preRmax[j+1],pre[j]);
                // maxdpldprp[j] = max({dpL[i-1][j],dpR[i-1][j],maxdpldprp[j+1]});
                preRmaxplusmaxdpldprp[j] =  max(max(dpL[i-1][j],dpR[i-1][j]) + preRmax[j+1],preRmaxplusmaxdpldprp[j+1]);
            }
            for(int l = m-1; l>=0;l--)
            {
                if(l!=m-1)
                dpL[i][l] = -pre[l] + preRmaxplusmaxdpldprp[l + 1];
                if(i == 1)
                {
                    dpL[i][l] = max(dpL[i][l],a[0][l]);
                }
            }
            if(i==2)
            {   
                debug();
                debug(preRmaxplusmaxdpldprp);
                // debug(maxdpldprp);
                debug(preRmax);
                debug();
                debug(pre);debug();
            }
        }
        debug(dpL);
        debug(dpR);
        cout<<max(*max_element(all(dpL[n])),*max_element(all(dpR[n])))<<endl;
    }
}