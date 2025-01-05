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
#define UNDEF LONG_LONG_MIN

struct range_info
{
    int start;
    int end;
    int mx;
    int slope;
    int end_elevation;

    void set_slope(int slp)
    {
        slope = slp;
        end_elevation = mx = slope * (end - start);
    }
};

using T=range_info;

struct SegTree
{
    int tot;
    int n;
    vector<T> tree;
    vector<int> lazy;
    T undef = {UNDEF,UNDEF,UNDEF,UNDEF,UNDEF}; // Change according to QUERY operation

    SegTree(int tot, int sz = 0): tot(tot)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(4 * sz + 1, undef);
        lazy.resize(4 * sz + 1, UNDEF); // Change according to MODIFY operation
    }

    void resize(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(4 * sz + 1, undef);
        lazy.resize(4 * sz + 1, UNDEF);
    }

    T combine(T a, T b)
    {
        // #ifndef cerr
        // cerr<<a.start<<" "<<a.end<<" "<<b.start<<" "<<b.end<<endl;
        // #endif
        a.mx = max(a.mx,a.end_elevation + b.mx);
        a.end_elevation = a.end_elevation + b.end_elevation;
        a.end = b.end;
        if(a.slope == b.slope);
        else a.slope = UNDEF;
        debug(a.start,a.end);
        return a;
    }

    void build(int id, int segl, int segr, vector<T> &ranges)
    {
        if (segl == segr)
        {
            tree[id] = ranges[segl];
            return;
        }
        int mid = (segl + segr) / 2;
        build(2 * id + 1, segl, mid, ranges);
        build(2 * id + 2, mid + 1, segr, ranges);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
        // #ifndef cerr
        // cerr<<id<<" "<<tree[id].start<<" "<<tree[id].end<<endl;
        // #endif
    }

    void build(vector<int> &v)
    {
        vector<T> ranges;
        for(int i=1;i<v.size();i++)
        {
            ranges.push_back({v[i-1],v[i],0,0,0});
            // #ifndef cerr
            // cerr<<ranges.back().start<<" "<<ranges.back().end<<endl;
            // #endif
        }
        resize(ranges.size());
        build(0, 0, n - 1, ranges);
    }

    void propagate(int id)
    { // Change according to MODIFY operation
        if(lazy[id] == UNDEF)return;

        if(2 * id + 2 >= 4 * n + 1);
        else{
        // tree[2 * id + 1] += lazy[id];
        lazy[2 * id + 1] = lazy[id];
        // tree[2 * id + 2] += lazy[id];
        lazy[2 * id + 2] = lazy[id];

        tree[2 * id + 1].set_slope(lazy[id]);

        tree[2 * id + 2].set_slope(lazy[id]);}

        lazy[id] = UNDEF;
    }

    void modify(int l, int r, int slope, int id)
    {
        // debug(l,r);
        if (l >= tree[id].end || tree[id].start >= r)
        {
            return;
        }
        if (tree[id].start >= l && tree[id].end <= r)
        {
            tree[id].set_slope(slope);
            lazy[id] = slope; // Change according to MODIFY operation
            return;
        }
        propagate(id);
        modify(l, r, slope, 2 * id + 1);
        modify(l, r, slope, 2 * id + 2);
        debug(l,r,id, 2*id + 1,2 * id + 2, tree[id].start, tree[id].end);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void modify(int l, int r, int slope)
    {
        modify(l - 1, r, slope, 0);
    }

    void modify(int index, int slope)
    {
        modify(index, index, slope);
    }

    int query(int h, int id)
    {
        // if (l > segr || segl > r)
        // {
        //     return zero;
        // }
        // if (segl >= l && segr <= r)
        // {
        //     return tree[id];
        // }
        // propagate(id, segl, segr);
        // int mid = (segl + segr) / 2;
        // T leftVal = query(l, r, 2 * id + 1, segl, mid);
        // T rightVal = query(l, r, 2 * id + 2, mid + 1, segr);
        // return combine(leftVal, rightVal);

        if(h >= tree[id].mx)throw exception();

        propagate(id);

        if(tree[id].slope != UNDEF)
        {
            int start = tree[id].start;
            int slope = tree[id].slope;

            return start + h/slope;
        }

        if(tree[2 * id + 1].mx > h)
        {
            return query(h, 2 * id + 1);
        }
        else
        {
            return query(h - tree[2 * id + 1].end_elevation, 2 * id + 2);
        }
    }

    int query(int max_height)
    {
        if(max_height >= tree[0].mx)
        return tot;
        return query(max_height, 0);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    char c;
    vector<pair<char,vector<int>>> inputs;
    vector<int> v;
    while(true)
    {
        cin>>c;
        if(c == 'E')break;
        if(c == 'I')
        {
            int a,b,d;
            cin>>a>>b>>d;
            inputs.push_back({c,{a,b,d}});
            v.push_back(a-1);
            v.push_back(b);
        }
        else
        {
            int h;
            cin>>h;
            inputs.push_back({c,{h}});
        }
    }
    sort(all(v));
    SegTree st(n);
    st.build(v);
    int x = 0;
    for(auto [c,inp_v]: inputs)
    {
        #ifndef cerr
        if(c != 'I')
        for(int i=0;i<st.lazy.size();i++)
        {
            // int i=0;
            cerr<<"Start: "<<(st.tree[i].start==UNDEF?-100:st.tree[i].start)<<endl;
            cerr<<"End: "<<(st.tree[i].end==UNDEF?-100:st.tree[i].end)<<endl;
            cerr<<"Lazy? "<<(st.lazy[i]==UNDEF?-100:st.lazy[i])<<endl;
            cerr<<"mx: "<<(st.tree[i].mx==UNDEF?-100:st.tree[i].mx)<<endl;
            cerr<<"end_elevation: "<<(st.tree[i].end_elevation==UNDEF?-100:st.tree[i].end_elevation)<<endl;
            cerr<<"Slope:"<<(st.tree[i].slope==UNDEF?-100:st.tree[i].slope)<<endl;
            cerr<<endl;
        }
        if(c!='I')
        cerr<<"Done "<<x<<endl<<endl<<endl;
        #endif
        if(c == 'I')
        {
            int a = inp_v[0],b = inp_v[1], d= inp_v[2];
            st.modify(a,b,d);
        }
        else
        {
            x++;
            cout<<st.query(inp_v[0])<<endl;
        }
    }
}