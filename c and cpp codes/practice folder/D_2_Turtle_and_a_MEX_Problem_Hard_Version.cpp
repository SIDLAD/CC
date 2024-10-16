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
        vector<array<int,2>> mexs;
        for(int i=0;i<n;i++)
        {
            int l;
            cin>>l;
            vector<int> v(l);
            for(auto& x:v)cin>>x;
            sort(all(v));
            int mex1 = 0;
            for(int i=0;i<l;i++)
            {
                if(v[i] == mex1)mex1++;
            }
            int mex2 = mex1 + 1;
            for(int i=0;i<l;i++)
            {
                if(v[i] == mex2)mex2++;
            }
            mexs.push_back({mex1,mex2});
        }
        map<int,vector<int>> mp;
        set<int> nonpurestarts;
        set<int> starts;
        for(auto [s,e]:mexs)
        {
            mp[s].push_back(e);
            nonpurestarts.insert(e);
            starts.insert(s);
        }
        for(auto x: nonpurestarts)
        {
            starts.erase(x);
        }

        map<int,int> greatest_reachable;
        vector<int> singledegree, multipledegree;
        auto dfs = [&](auto self, int current)->void
        {
            if(greatest_reachable.count(current))return;
            int ans = current;
            for(auto child: mp[current])
            {
                self(self,child);
                ans = max(ans,greatest_reachable[child]);
            }
            if(mp[current].size() == 1)singledegree.push_back(current);
            else if (mp[current].size() > 1)multipledegree.push_back(current);
            greatest_reachable[current] = ans;
        };
        
        for(auto x: starts)
        {
            dfs(dfs,x);
        }
        int automax = -1;
        for(auto x: multipledegree)
        {
            automax = max(automax,greatest_reachable[x]);
        }

        for(auto x: singledegree)
        {
            automax = max(automax,x);
        }
        sort(all(singledegree));

        vector<int> presum(singledegree.size());
        for(int i=0;i<singledegree.size();i++)
        {
            presum[i] = max(greatest_reachable[singledegree[i]],automax);
        }
        partial_sum(all(presum),presum.begin());
        int lbi = upper_bound(all(singledegree),m) - singledegree.begin() - 1;

        int final_answer = 0;
        if(lbi < 0);
        else
        {
            final_answer += presum[lbi];
        }
        int greaterthanautomaxcount = max(m - automax,0ll);
        int lessthanautomaxcount = m + 1 - greaterthanautomaxcount - (lbi+1);

        final_answer += ((greaterthanautomaxcount) * automax + greaterthanautomaxcount*(greaterthanautomaxcount + 1) / 2);
        final_answer += ((lessthanautomaxcount) * automax);
        cout<<final_answer<<endl;
    }
}