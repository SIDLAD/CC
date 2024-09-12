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

vector<int> get_red_dp(multiset<int> init)
{
    vector<map<multiset<int>,int>> dp(19);
    vector<int> red_dp(19);
    int start = accumulate(all(init),0ll);
    dp[start][init] = 1;

    for(int cnt = start;cnt <=18;cnt++)
    {
        for(auto [st,dpc]: dp[cnt])
        {
            if(cnt!=18)
            {   
                for(auto ele: st)
                {
                    auto stc = st;
                    stc.erase(stc.find(ele));
                    stc.insert(ele+1);
                    dp[cnt+1][stc] += dpc;
                }
                auto stc = st;
                stc.insert(1);
                dp[cnt+1][stc] += (10 - stc.size() + 1) * dpc;
            }
            if(*(--st.end()) >= (cnt+1)/2)
            red_dp[cnt] += dpc;
        }
    }
    return red_dp;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("odometer.in","r",stdin);
    freopen("odometer.out","w",stdout);
    int l,r;
    cin>>l>>r;
    auto red_dp = get_red_dp({1});
    auto counter = [&](int ub)->int
    {
        int digcount = (int)log10(ub) + 1;
        
        int ans = 0;
        for(int i=1;i<digcount;i++)
        {
            ans += 9*(red_dp[i]);
        }
        
        int tmp = ub;
        vector<int> digs(digcount);
        for(int i=digcount-1;i>=0;i--)
        {
            digs[i] = ub%10;
            ub/=10;
        }
        vector<int> freq(10);
        for(int i=0;i<digcount;i++)
        {
            for(int j=(i==0);j<digs[i];j++)
            {
                freq[j]++;

                multiset<int> new_init;
                for(int i=0;i<10;i++)if(freq[i])new_init.insert(freq[i]);
                auto v = get_red_dp(new_init);
                ans += v[digcount];

                freq[j]--;
            }
            freq[digs[i]]++;
        }
        if(*max_element(all(freq)) >= (digcount+1)/2)ans++;
        return ans;
    };
    cout<<counter(r) - counter(l-1)<<endl;
}