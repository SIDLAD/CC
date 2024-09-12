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

using T =int;
struct segtree
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero = -INF; // Change according to QUERY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, zero); // Change according to MODIFY operation
    }

    void resize(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(4 * sz + 1, zero);
        // lazy.resize(4 * sz + 1, zero);
    }

    T combine(T a, T b)
    {
        return max(a,b); // Change according to QUERY operation
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

    void build(vector<T> &v)
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
            tree[id] += val;
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

    T query(int l, int r, int id, int segl, int segr)
    {
        if (l > segr || segl > r)
        {
            return zero;
        }
        if (segl >= l && segr <= r)
        {
            return tree[id];
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        T leftVal = query(l, r, 2 * id + 1, segl, mid);
        T rightVal = query(l, r, 2 * id + 2, mid + 1, segr);
        return combine(leftVal, rightVal);
    }

    T query(int l, int r)
    {
        if(l>r)return zero;
        return query(l, r, 0, 0, n - 1);
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
        string s;
        cin>>s;
        int n  =s.length();
        vector<int> cur(n);
        cur[0] = ((s[0] == '(')?1:-1);
        for(int i=1;i<n;i++)
        {
            cur[i] = cur[i-1] +  ((s[i] == '(')?1:-1);
        }
        // debug(cur);
        segtree st(n);
        st.build(cur);

        vector<vector<int>> indices(n);
        indices[0] = {-1};
        for(int i=0;i<n;i++)
        {
            indices[cur[i]].push_back(i);
        }

        // debug(indices);

        int ans = 0;
        for(int i=0;i<indices.size();i++)
        {
            if(indices[i].size() == 0)break;

            for(int j=0;j<indices[i].size();j++)
            {
                int index = indices[i][j];
                if(st.query(indices[i][j]+1,indices[i].back()) <= 2*i){ans += indices[i].size() - j - 1;continue;}

                int ll = j;//satisfies
                int ul = indices[i].size() - 1;//doesnt satsify
                while(ul-ll>1)
                {
                    int mid = ll + ul >>1;
                    if(st.query(index + 1,indices[i][mid])<= 2*i)
                    ll = mid;
                    else ul = mid;
                }
                ans += ll - j;
            }
        }
        debug();
        cout<<ans<<endl;
    }
}