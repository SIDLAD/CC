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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> edges(n);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        edges[a].push_back({b,w});
        edges[b].push_back({a,w});
    }

    vector<bool> completed(n);
    set<pair<int,int>> cloud;
    vector<int> minans(n,INF);
    vector<int> minnbr(n,-1);
    minans[0] = 0;
    cloud.insert({0,0});
    while(cloud.size())
    {
        auto [dist, curnode] = *cloud.begin();
        cloud.erase(cloud.begin());
        completed[curnode] = true;
        for(auto [neighbour,wt]: edges[curnode])if(not completed[neighbour])
        {
            cloud.erase({minans[neighbour],neighbour});

            if(minans[neighbour] > minans[curnode] + wt){
                minans[neighbour] = minans[curnode] + wt;
                minnbr[neighbour] = curnode;
            }
            cloud.insert({minans[neighbour],neighbour});
        }
    }

    if(minans[n-1] == INF)
    {
        cout<<-1<<endl;
    }

    else
    {
        stack<int> s;
        s.push(n-1);
        while(minnbr[s.top()] != -1)s.push(minnbr[s.top()]);
        while(s.size())
        {
            cout<<s.top() + 1<<" ";
            s.pop();
        }

        cout<<endl;
    }
}