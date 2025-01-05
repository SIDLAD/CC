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

// #define int long long
// #define double long double
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

struct NodeInfo
{
    set<int>* data[2];
    bool def;

    static NodeInfo* createNode(bool bit = 0, int childid = -1)
    {
        NodeInfo* node = new NodeInfo;
        node->def = bit;
        node->data[0] = new set<int>;
        node->data[1] = new set<int>;
        if(childid == -1)return node;

        node->data[!bit]->insert(childid);
        return node;
    }

    static NodeInfo* NOT(NodeInfo* a)
    {
        a->def ^= 1;
        swap(a->data[0],a->data[1]);
        return a;
    }

    static set<int>* mergeset(set<int>* a, set<int>* b)
    {
        if(a->size() < b->size())swap(a,b);
        a->insert(b->begin(),b->end());
        delete b;
        return a;
    }

    static NodeInfo* BINFUN(NodeInfo* a, NodeInfo* b, function<bool(bool,bool)> fun)
    {
        NodeInfo* ret = createNode();
        ret->def = fun(a->def,b->def);

        vector<int> aflip(2), bflip(2);
        aflip[0] = fun(0,b->def);
        aflip[1] = fun(1,b->def);
        bflip[0] = fun(0,a->def);
        bflip[1] = fun(1,a->def);
        set<int>* tmp1,tmp2;
        for(int i=0;i<2;i++)ret->data[aflip[i]] = mergeset(a->data[i],ret->data[aflip[i]]);
        for(int i=0;i<2;i++)ret->data[bflip[i]] = mergeset(b->data[i],ret->data[bflip[i]]);
        delete a;
        delete b;

        return ret;
    }

    static NodeInfo* AND(NodeInfo* a, NodeInfo* b)
    {
        return BINFUN(a,b,[](bool a, bool b){return(a&b);});
    }
    static NodeInfo* XOR(NodeInfo* a, NodeInfo* b)
    {
        return BINFUN(a,b,[](bool a, bool b){return(a^b);});
    }
    static NodeInfo* OR(NodeInfo* a, NodeInfo* b)
    {
        return BINFUN(a,b,[](bool a, bool b){return(a|b);});
    }

};


int n;
vector<int> fnode;
vector<int> val;
vector<vector<int>> edges;

NodeInfo* dfs(int node)
{
    debug(node);
    if(fnode[node] == 4)
    {
        return NodeInfo::createNode(val[node],node);
    }

    if(fnode[node] == 0)
    {
        NodeInfo* a = dfs(edges[node][0]);
        NodeInfo* b = dfs(edges[node][1]);
        return NodeInfo::AND(a,b);
    }
    else if(fnode[node] == 1)
    {
        NodeInfo* a = dfs(edges[node][0]);
        NodeInfo* b = dfs(edges[node][1]);
        return NodeInfo::OR(a,b);
    }
    else if(fnode[node] == 2)
    {
        NodeInfo* a = dfs(edges[node][0]);
        NodeInfo* b = dfs(edges[node][1]);
        return NodeInfo::XOR(a,b);
    }
    else
    {
        NodeInfo* a = dfs(edges[node][0]);
        return NodeInfo::NOT(a);
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n;
    fnode.resize(n + 1);
    val.resize(n + 1, -1);
    edges.resize(n + 1);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        if(s == "AND")
        {
            fnode[i] = 0;
        }
        else if(s == "OR")
        {
            fnode[i] = 1;
        }
        else if(s == "XOR")
        {
            fnode[i] = 2;
        }
        else if(s == "NOT")
        {
            fnode[i] = 3;
            int a;
            cin>>a;
            edges[i].push_back(a);
            continue;
        }
        else{ 
            fnode[i] = 4;
            int a;
            cin>>a;
            val[i] = a;
            continue;
        }

        int a,b;
        cin>>a>>b;
        debug(a,b);
        edges[i].push_back(a);
        edges[i].push_back(b);
    }

    NodeInfo* ret = dfs(1);
    map<int,int> ans;
    for(auto ele:*(ret->data[0]))ans[ele] = 0;
    for(auto ele:*(ret->data[1]))ans[ele] = 1;

    delete ret->data[0];
    delete ret->data[1];
    delete ret;

    for(auto [_,ele]:ans)cout<<(char)(ele+'0');
}