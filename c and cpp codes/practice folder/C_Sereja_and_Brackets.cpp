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

using T = array<int,3>;

class SegTree {
public:
    vector<T> tree;
    T zero = {0,0,0}; // Neutral element

    SegTree (int sz) {
        tree.resize(4*sz+1);
    }

    T combine (T &a, T &b) {
        T x;
        int temp = min(a[1],b[2]);
        x[0] = a[0] + b[0] + 2*temp;
        x[1] = a[1] + b[1] - temp;
        x[2] = a[2] + b[2] - temp;
        return x; // Combine function
    }

    void build (int id, int segl, int segr, string &v) {
        if (segl == segr) {
            tree[id] = T({0,v[segl] == '(',v[segl] == ')'});
            return;
        }
        int mid = (segl + segr)/2;
        build(2*id + 1, segl, mid, v);
        build(2*id + 2, mid+1, segr, v);
        tree[id] = combine(tree[2*id+1], tree[2*id+2]);
    }

    void modify (int pos, T val, int id, int segl, int segr) {
        if (segl == segr) {
            tree[id] = val;
            return;
        }
        int mid = (segl + segr)/2;
        if (pos>mid) {
            modify(pos, val, 2*id+2, mid+1, segr);
        }
        else {
            modify(pos, val, 2*id+1, segl, mid);
        }
        tree[id] = combine(tree[2*id+1], tree[2*id+2]);
    }

    T query (int l, int r, int id, int segl, int segr) {
        if (l>segr || segl>r) {
            return zero;
        }
        if (segl>=l && segr<=r) {
            return tree[id];
        }
        int mid = (segl + segr)/2;
        T leftVal = query(l, r, 2*id+1, segl, mid);
        T rightVal = query(l, r, 2*id+2, mid+1, segr);
        return combine(leftVal, rightVal);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    int n;
    cin>>n;
    SegTree st(s.size());
    st.build(0,0,s.size() - 1,s);
    // debug(s);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<st.query(a-1,b-1,0,0,s.size()-1)[0]<<endl;
        debug();
    }
    // debug(st.tree);
}