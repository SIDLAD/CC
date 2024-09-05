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

void assign(array<int,2>& twoindex, int val)
{
    if(twoindex[0] == -1)twoindex[0] = val;
    twoindex[1] = val;
}


void dfs(int node, int p, int& curpath_start, int& curpath_count, vector<vector<int>>& edges, vector<array<int,2>>& twoindices, vector<int>& path_lengths)
{
    if(curpath_start != -1)
    {
        path_lengths[curpath_start] = curpath_count;
    }
    curpath_start = node;
    curpath_count = 0;
    for(auto child: edges[node])
    {
        assign(twoindices[child], curpath_start);
        dfs(child, node, curpath_start, ++curpath_count, edges,twoindices, path_lengths);
        ++curpath_count;
        assign(twoindices[child], curpath_start);  
    }
    if(node == 0)path_lengths[curpath_start] = curpath_count;
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
        int n,totrem;
        cin>>n>>totrem;
        int w = totrem;
        vector<int> p(n);
        p[0] = -1;
        vector<int> t(n);
        vector<int> ans(n);

        int mult_totrem = n;

        vector<array<int,2>> twoindices(n);
        for(int i=1;i<n;i++)twoindices[i][0] = twoindices[i][1] = -1;
        vector<int> path_lengths(n,-1);

        vector<vector<int>> edges(n);
        for(int i=1;i<n;i++)
        {
            cin>>p[i];
            p[i]--;
            edges[p[i]].push_back(i);
        }
        int tmp1 = -1;
        int tmp2 = -1;
        dfs(0,-1,tmp1,tmp2,edges,twoindices,path_lengths);

        debug(p);
        debug(edges,n);
        debug(path_lengths,twoindices);
        int node,totsub;
        vector<int> cur_path_lengths(n);

        int cursum = 0;
        for(int i=0;i<n-3;i++)
        {
            cin>>node>>totsub;
            --node;
            debug(node,twoindices[node]);
            t[twoindices[node][0]] += totsub;
            t[twoindices[node][1]] += totsub;
            cur_path_lengths[twoindices[node][0]]++;
            cur_path_lengths[twoindices[node][1]]++;
            if(cur_path_lengths[twoindices[node][0]] == path_lengths[twoindices[node][0]])
            mult_totrem--;
            if(cur_path_lengths[twoindices[node][1]] == path_lengths[twoindices[node][1]])
            mult_totrem--;
            totrem -= totsub;
            cursum += 2*totsub;
            cout<<cursum + mult_totrem*totrem<<" ";          
        }
        cin>>node>>totsub;
        cout<<2*w<<" ";
        if(n>2)
        {
            cin>>node>>totsub;
            cout<<2*w<<" ";
        }
        cout<<endl;
    }
}