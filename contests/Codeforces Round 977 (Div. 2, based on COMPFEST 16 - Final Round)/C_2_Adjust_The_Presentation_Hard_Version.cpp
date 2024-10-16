#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

#if defined (ONLINE_JUDGE)
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
#define cout(x) x?cout<<"YA"<<endl:cout<<"TIDAK"<<endl

using T = array<int,3>; //third value is messed up or not
struct segtree
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero = {INF,INF,0}; // Change according to QUERY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, 0); // Change according to MODIFY operation
    }

    void resize(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, 0);
    }

    T combine(T a, T b)
    {
        if(a == zero)return b;
        if(b == zero)return a;
        // debug(a,b,(T){min(a[0],b[0]),max(a[1],b[1]),(a[1] > b[0])||a[2]||b[2]});
        return {a[0],b[1],(a[1] +1 != b[0] and a[1] != b[0])||a[2]||b[2]}; // Change according to QUERY operation
    }

    // void build(int id, int segl, int segr, vector<int> &v)
    // {
    //     if (segl == segr)
    //     {
    //         tree[id] = {v[segl],v[segl],0};
    //         return;
    //     }
    //     int mid = (segl + segr) / 2;
    //     build(2 * id + 1, segl, mid, v);
    //     build(2 * id + 2, mid + 1, segr, v);
    //     tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    // }

    // void build(vector<int> &v)
    // {
    //     build(0, 0, n - 1, v);
    // }

    void propagate(int id, int segl, int segr)
    { // Change according to MODIFY operation
        // int mid = (segl + segr) / 2;
        // tree[2 * id + 1] += lazy[id];
        // lazy[2 * id + 1] += lazy[id];
        // tree[2 * id + 2] += lazy[id];
        // lazy[2 * id + 2] += lazy[id];
        // lazy[id] = 0;
    }
    void modify(int l, int r, int val, int id, int segl, int segr)
    {
        if (l > segr || segl > r)
        {
            return;
        }
        if (segl >= l && segr <= r)
        {
            tree[id] = {val,val,0};
            // lazy[id] += val; // Change according to MODIFY operation
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(l, r, val, 2 * id + 1, segl, mid);
        modify(l, r, val, 2 * id + 2, mid + 1, segr);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void modify(int l, int r, int val)
    {
        modify(l, r, val, 0, 0, n - 1);
    }

    void modify(int index, int val)
    {
        modify(index, index, val);
    }

    // T query(int l, int r, int id, int segl, int segr)
    // {
    //     if (l > segr || segl > r)
    //     {
    //         return zero;
    //     }
    //     if (segl >= l && segr <= r)
    //     {
    //         return tree[id];
    //     }
    //     propagate(id, segl, segr);
    //     int mid = (segl + segr) / 2;
    //     T leftVal = query(l, r, 2 * id + 1, segl, mid);
    //     T rightVal = query(l, r, 2 * id + 2, mid + 1, segr);
    //     return combine(leftVal, rightVal);
    // }

    // T query(int l, int r)
    // {
    //     return query(l, r, 0, 0, n - 1);
    // }
    bool check()
    {
        return (!tree[0][2]) and tree[0][0] == 1;
    }
};

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
        int n,m,q;
        cin>>n>>m>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int> b(m);
        for(int i=0;i<m;i++)cin>>b[i];
        map<int,int> mapping;
        for(int i=0;i<n;i++)
        {
            mapping[a[i]] = i+1;
        }
        for(int i=0;i<m;i++)
        {
            b[i] = mapping[b[i]];
        }
        debug(b);debug(mapping);
        segtree st(2* m);
        vector<set<int>> vst(n+1);
        for(int i=0;i<m;i++)
        {
            vst[b[i]].insert(i);
        }
        for(int i=1;i<=n;i++)
        {
            if(vst[i].size() == 0)continue;
            st.modify(*vst[i].begin(),i);
        }
        debug(vst);
        cout(st.check());
        for(int i=0;i<q;i++)
        {
            debug(i);
            int idx,per;
            cin>>idx>>per;
            idx--;
            per = mapping[per];
            // if(per == b[idx])goto ender;
            st.modify(*vst[b[idx]].begin(),INF);
            if(vst[per].size())
            {
                st.modify(*vst[per].begin(),INF);
            }
            vst[b[idx]].erase(idx);
            vst[per].insert(idx);

            if(vst[b[idx]].size())
            {
                st.modify(*vst[b[idx]].begin(),b[idx]);
            }
            st.modify(*vst[per].begin(),per);
            b[idx] = per;
            cout(st.check());
            debug(vst,i+1);
        }
    }
}