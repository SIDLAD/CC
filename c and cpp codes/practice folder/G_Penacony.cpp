#include<bits/stdc++.h>
#define INF INT_MAX
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

class lazy_segtree
{
    public:
    #define firstchild(n) 2*n + 1
    #define secondchild(n) 2*n + 2 
    vector<pair<int,int>> tree;
    vector<int> lazy;
    int n;
    lazy_segtree(int n):n(n)
    {
        lazy.resize(4*n);
        tree.resize(4*n);
        build();
    }
    void build(int si, int ss, int se)
    {
        if(ss == se)
        {
            tree[si] = {0,1};
            return;
        }
        int mid = ss + se>>1;
        build(firstchild(si),ss,mid);
        build(secondchild(si),mid + 1,se);
        tree[si] = combine(firstchild(si),secondchild(si));
    }

    void build()
    {
        build(0,0,n-1);
    }

    void propagate(int si)
    {
        int inc = lazy[si];
        lazy[si] = 0;
        lazy[firstchild(si)] += inc;
        tree[firstchild(si)].first += inc;
        lazy[secondchild(si)] += inc;
        tree[secondchild(si)].first += inc;
    }

    pair<int,int> combine(int idx1,int idx2)
    {
        pair<int,int> ans;
        ans.first = min(tree[idx1].first,tree[idx2].first);
        if(tree[idx1].first == tree[idx2].first)
            ans.second = tree[idx1].second + tree[idx2].second;
        else if(tree[idx1].first < tree[idx2].first)
            ans.second = tree[idx1].second;
        else ans.second = tree[idx2].second;
        return ans;
    }

    pair<int,int> combine(pair<int,int> ele1,pair<int,int> ele2)
    {
        pair<int,int> ans;
        ans.first = min(ele1.first,ele2.first);
        if(ele1.first == ele2.first)
            ans.second = ele1.second + ele2.second;
        else if(ele1.first < ele2.first)
            ans.second = ele1.second;
        else ans.second = ele2.second;
        return ans;
    }

    void addtorange(int l,int r,int val, int si, int ss, int se)
    {
        if(l > se or r < ss)return;
        if(l<=ss and r >= se)
        {
            lazy[si] += val;
            tree[si].first += val;
            return;
        }
        int mid = ss + se >> 1;
        propagate(si);
        addtorange(l,r,val,firstchild(si),ss, mid);
        addtorange(l,r,val,secondchild(si),mid+1,se);
        tree[si] = combine(firstchild(si),secondchild(si));
    }

    void addtorange(int l,int r, int val)
    {
        addtorange(l,r,val,0,0,n-1);
    }

    pair<int,int> query(int l,int r, int si, int ss,int se)
    {
        if(l > se or r < ss) return {INF,0};
        if(l<=ss and r >= se)return tree[si];
        int mid = ss + se>>1;
        propagate(si);
        return combine(query(l,r,firstchild(si),ss,mid), query(l,r,secondchild(si),mid+1,se));
    }

    pair<int,int> query(int l,int r)
    {
        return query(l,r,0,0,n-1);
    }
};

int main()
{
    #define int long long
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        lazy_segtree ls((int)2*n);
        vector<vector<int>> edges(n,vector<int>(0));
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            if(a>b)swap(a,b);
            edges[a].push_back(b);
            ls.addtorange(a,b-1,1);
        }
        auto tmp = ls.query(0,n-2);
        int curans = 1;
        debug(tmp);
        if(tmp.first == 0)
        {
            curans = 1 + tmp.second;
        }

        for(int i=0;i<n-1;i++)
        {
            vector<pair<int,int>> add_edge;
            for(auto edge: edges[i])
            {
                ls.addtorange(i,edge-1,-1);

                ls.addtorange(edge,i + n - 1,1);
                if(edge < n)
                    add_edge.push_back({edge,i + n - 1});

            }
            edges[i].clear();
            for(auto pair:add_edge)
            {
                auto [f,s] = pair;
                edges[f].push_back(s);
            }

            auto tmp = ls.query(i+1,n-1 + i);
            debug(tmp);
            if(tmp.first == 0)
            {
                curans = max(curans,(long long)(1 + tmp.second));
                // debug(curans,i);
            }
        }

        cout<<n-curans<<endl;
        debug(ls.tree,ls.lazy);
        debug(edges);
    }
}