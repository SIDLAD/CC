#include <bits/stdc++.h>
#pragma optimize("Ofast");
const long double EPS = 1e-7;
const long long int INF = INT_MAX/2;
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

#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
int slen,m,k;
string s;

int toint(char x)
{
    return x - 'a';
}

map<int,int> idx;

struct T
{
    int matrix[10][10] = {};
    int start=-1;
    int end=-1;
};

struct segtree
{
    int n;
    vector<T> tree;
    vector<int> lazy;
    T zero; // Change according to QUERY operation
    int lazy_zero = -1; // Change according to MODIFY operation

    segtree():n(slen)
    {
        zero = initial();
        tree.clear();
        lazy.clear();
        tree.resize(4 * n + 1, zero);
        lazy.resize(4 * n + 1, lazy_zero);
    }

    T initial(int ch = -1)
    {
        T a;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                a.matrix[i][j] = 0;
        a.start = a.end = ch;
        return a;
    }

    void init(T& a, int ch = -1)
    {
        for(int i=0;i<k;i++)for(int j=0;j<k;j++)a.matrix[i][j] = 0;
        a.start = a.end = ch;
    }

    T combine(T& a, T& b)
    {
        if(a.start == -1)return b;
        if(b.start == -1)return a;
        T c = initial();
        
        c.start = a.start;
        c.end = b.end;

        for(int i=0;i<k;i++)for(int j=0;j<k;j++)
        {
            c.matrix[i][j]=0;
            c.matrix[i][j] += a.matrix[i][j] + b.matrix[i][j];
        }
        c.matrix[a.end][b.start]++;

        return c;
    }

    void combine_in_place(T& a, T& b, T& dest)
    {
        if(b.start == -1)swap(a,b);
        if(a.start == -1)
        {
            dest = a;
            return;
        }

        dest.start = a.start;
        dest.end = b.end;
        for(int i=0;i<k;i++)for(int j=0;j<k;j++)
        {
            dest.matrix[i][j] = 0;
            dest.matrix[i][j] += a.matrix[i][j] + b.matrix[i][j];
        }
        dest.matrix[a.end][b.start]++;
    }

    void build(int id, int segl, int segr)
    {
        if (segl == segr)
        {
            init(tree[id] , toint(s[segl]));
            return;
        }
        int mid = (segl + segr) / 2;
        build(2 * id + 1, segl, mid);
        build(2 * id + 2, mid + 1, segr);
        combine_in_place( tree[2 * id + 1], tree[2 * id + 2], tree[id]);
    }

    void build()
    {
        build(0, 0, n - 1);
    }

    void propagate(int id, int segl, int segr)
    { // Change according to MODIFY operation
        if(lazy[id] == lazy_zero)return;
        int mid = (segl + segr) / 2;
        init(tree[2 * id + 1] , lazy[id]);
        tree[2 * id + 1].matrix[lazy[id]][lazy[id]] = mid - segl;
        lazy[2 * id + 1] = lazy[id];
        init(tree[2 * id + 2] , lazy[id]);
        tree[2 * id + 2].matrix[lazy[id]][lazy[id]] = segr - mid - 1;
        lazy[2 * id + 2] = lazy[id];
        lazy[id] = lazy_zero;
    }

    void modify(int l, int r, int val, int id = 0, int segl = 0, int segr = INF)
    {
        if(segr == INF)segr = n-1;
        if (l > segr || segl > r)
        {
            return;
        }
        if (segl >= l && segr <= r)
        {
            init(tree[id] , val);
            tree[id].matrix[val][val] = segr - segl;
            lazy[id] = val; // Change according to MODIFY operation
            return;
        }
        propagate(id, segl, segr);
        int mid = (segl + segr) / 2;
        modify(l, r, val, 2 * id + 1, segl, mid);
        modify(l, r, val, 2 * id + 2, mid + 1, segr);
        combine_in_place(tree[2 * id + 1], tree[2 * id + 2], tree[id]);
    }

    void modify(int idx, auto val)
    {
        modify(idx, idx, val);
    }

    T query(int l, int r, int id = 0, int segl = 0, int segr = INF)
    {
        if(segr == INF)segr = n-1;
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
    
    int solve()
    {
        int count = 1;
        auto mat = query(0,n-1);

        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(idx[i] >= idx[j])count+= mat.matrix[i][j];
            }
        }
        return count;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>slen>>m>>k;
    cin>>s;
    segtree st;
    st.build();
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(x == 1)
        {
            int a,b;
            char c;
            cin>>a>>b>>c;
            st.modify(a-1,b-1,toint(c));
        }
        else
        {
            string cipher;
            cin>>cipher;
            idx.clear();
            for(int i=0;i<k;i++)idx[toint(cipher[i])] = i;
            cout<<st.solve()<<endl;
        }
    }
}