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
// #define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

using T = int;
struct segtree
{
    int n;
    vector<T> tree;
    vector<T> lazy;
    T zero=INF; // Change according to QUERY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(4 * sz + 1, zero);
        lazy.resize(4 * sz + 1, zero); // Change according to MODIFY operation
    }

    void resize(int sz)
    {
        n = sz;
        tree.clear();
        lazy.clear();
        tree.resize(4 * sz + 1, zero);
        lazy.resize(4 * sz + 1, zero);
    }

    T combine(T a, T b)
    {
        return min(a,b); // Change according to QUERY operation
    }

    void build(int id, int segl, int segr, vector<T> &v)
    {
        if (segl == segr)
        {
            tree[id] = v[segl];
            return;
        }
        int mid = (segl + segr) / 2;
        build(2 * id + 1, segl, mid, v);
        build(2 * id + 2, mid + 1, segr, v);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void build(vector<int> &v)
    {
        build(0, 0, n - 1, v);
    }

    void propagate(int id, int segl, int segr)
    { // Change according to MODIFY operation
        // int mid = (segl + segr) / 2;
        // tree[2 * id + 1] += lazy[id];
        // lazy[2 * id + 1] += lazy[id];
        // tree[2 * id + 2] += lazy[id];
        // lazy[2 * id + 2] += lazy[id];
        // lazy[id] = 0;
    }

    void modify(int l, int r, T val, int id, int segl, int segr)
    {
        if (l > segr || segl > r)
        {
            return;
        }
        if (segl >= l && segr <= r)
        {
            tree[id] = val;
            // lazy[id] += val; // Change according to MODIFY operation
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(l, r, val, 2 * id + 1, segl, mid);
        modify(l, r, val, 2 * id + 2, mid + 1, segr);
        tree[id] = combine(tree[2 * id + 1], tree[2 * id + 2]);
    }

    void modify(int l, int r, T val)
    {
        modify(l, r, val, 0, 0, n - 1);
    }

    void modify(int index, T val)
    {
        modify(index, index, val);
    }

    T valueat(int idx, int id, int segl,int segr)
    {
        if(segl == segr)return tree[id];
        int mid = segl + segr>>1;
        if(idx <= mid)return valueat(idx,id * 2 + 1, segl, mid);
        else return valueat(idx,id * 2 + 2, mid + 1, segr);
    }

    T query1(int val, int id, int segl, int segr)
    {
        if(segl == segr)
        {
            return segl;
        }

        int mid = segl + segr>>1;
        int i1 = 2*id + 1;
        int i2 = 2*id + 2;

        if(tree[i1] <= val)return query1(val,i1,segl,mid);
        else return query1(val,i2,mid + 1,segr);
    }

    T query1(int val)
    {
        return query1(val, 0, 0, n - 1);
    }

    T query2(int val, int id, int segl, int segr)
    {
        if(segl == segr)
        {
            return segl;
        }

        int mid = segl + segr>>1;
        int i1 = 2*id + 1;
        int i2 = 2*id + 2;

        if(tree[i2] <= val)return query2(val,i2,mid+1,segr);
        else return query2(val,i1,segl,mid);
    }

    T query2(int val)
    {
        return query2(val, 0, 0, n - 1);
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
        int n;
        cin>>n;
        vector<int> v(n);
        set<int> uniques;
        vector<vector<int>> indices(n + 1);
        vector<int> first_occurence(n+1,INF);
        for(int i=0;i<n;i++){cin>>v[i];uniques.insert(v[i]);indices[v[i]].push_back(i);}
        
        int len = (uniques.size());
        multiset<int> last_occurence;
        for(int i=0;i<n+1;i++)
        {
            if(indices[i].size())
            last_occurence.insert(indices[i].back());
            first_occurence[i] = (indices[i].size())?indices[i].front():INF;
        }
        segtree st(n + 1);
        st.build(first_occurence);
        debug(indices);
        int cur_index = 0;

        vector<int> ptrs(n+1);

        cout<<debug(len)<<endl;
        for(int i=0;i<len;i++)
        {
            int least_last = *last_occurence.begin();
            int next_num;
            if(i&1) next_num = st.query1(least_last);
            else next_num = st.query2(least_last);
            int next_num_index = indices[next_num][ptrs[next_num]];
            while(cur_index < next_num_index)
            {
                if((st.valueat(v[cur_index],0,0,n)!=INF))
                st.modify(v[cur_index],indices[v[cur_index]][++ptrs[v[cur_index]]]);
                cur_index++;
            }

            

            last_occurence.erase(last_occurence.find(indices[next_num].back()));
            st.modify(v[cur_index++],INF);
            
            cout<<next_num<<" ";

            #ifndef cerr
            // debug(next_num,next_num_index,least_last,cur_index);
            for(int i=1;i<=n;i++)
            {
                cerr<<i<<" "<<st.valueat(i,0,0,n)<<endl;
            }
            debug(last_occurence);
            debug(next_num,cur_index);
            #endif
        }
        cout<<endl;
    }
}
//2 2 8 7 7 9 8 1 9 6