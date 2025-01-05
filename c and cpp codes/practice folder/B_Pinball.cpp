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
    
    class CNothing {} cnothing;
    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl '\n' //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

template <typename T = int, typename V = T>
struct segtree
{
    int n;
    vector<T> tree;
    // vector<V> lazy;
    T zero = 0; // Change according to QUERY operation
    // V lazy_zero = 0; // Change according to MODIFY operation

    segtree(int sz)
    {
        n = sz;
        tree.clear();
        // lazy.clear();
        tree.resize(2 * sz - 1, zero);
        // lazy.resize(2 * sz - 1, lazy_zero);
    }

    template <typename U>
    segtree(vector<U> &v) : segtree(v.size())
    {
        build(v);
    }

    T combine(T a, T b)
    {
        // Change according to QUERY operation
        return a + b;
    }

    template <typename U>
    void build(vector<U> &v, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (segl == segr)
        {
            tree[id] = v[segl];  // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        build(v, id + 1, segl, mid);
        build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }

    // void propagate(int id, int segl, int segr)
    // {
        // if(lazy[id] == lazy_zero)return;
        // if(segl != segr)
        // {
            // int mid = (segl + segr) / 2;
            // array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
            // for(auto child : children)
            // {
                // tree[child] = lazy[id];  // Change according to MODIFY operation
                // lazy[child] = lazy[id];  // Change according to MODIFY operation
            // }
        // }
        // lazy[id] = lazy_zero;
    // }

    template <typename U>
    void modify(U val, int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            tree[id] = val; // Change according to MODIFY operation
            // lazy[id] = val; // Change according to MODIFY operation
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, index_l, index_r, id + 1, segl, mid);
        modify(val, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
    }
    template <typename U>
    auto modify(U val, int index) { return modify(val, index, index); }

    T query(int index_l, int index_r, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)segr = n - 1;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return zero;
        }
        // propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            return tree[id];
        }
        int mid = (segl + segr) / 2;
        T leftVal = query(index_l, index_r, id + 1, segl, mid);
        T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return combine(leftVal, rightVal);
    }
    auto query(int index) { return query(index, index); }
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
        string s;
        cin>>s;
        segtree left(n),right(n);
        for(int i=0;i<n;i++)
        {
            if(s[i] == '<')left.modify(1,i);
            else right.modify(1,i);
        }

        vector<int> leftidx;
        vector<int> rightidx;
        vector<int> preleftidx;
        vector<int> prerightidx;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '<')leftidx.push_back(i);
            else rightidx.push_back(i);
        }
        preleftidx.assign(leftidx.size(),0ll);
        prerightidx.assign(rightidx.size(),0ll);
        partial_sum(all(leftidx),preleftidx.begin());
        partial_sum(all(rightidx),prerightidx.begin());

        for(int i=0;i<n;i++)
        {
            int leftcnt = right.query(0,i-1);
            int rightcnt = left.query(i + 1,n - 1);

            if(s[i] == '<')
            {
                if(rightcnt >= leftcnt)
                {
                    int ans = i + 1;
                    rightcnt = leftcnt;

                    int nearestleft = (lower_bound(all(rightidx),i) - 1 - rightidx.begin());
                    int farthestleft = nearestleft - leftcnt;
                    ans += (leftcnt * i - (nearestleft < 0 ? 0 : prerightidx[nearestleft]) + (farthestleft < 0 ? 0 : prerightidx[farthestleft])) * 2;

                    int nearestright = upper_bound(all(leftidx),i) - leftidx.begin() - 1;
                    int farthestright = nearestright + rightcnt;

                    ans += ((farthestright < 0 ? 0 : preleftidx[farthestright]) - (nearestright < 0 ? 0 : preleftidx[nearestright]) - rightcnt*i) * 2;

                    cout<<ans<<" ";
                    continue;
                }
                else
                {
                    int ans = n - i;
                    leftcnt = rightcnt + 1;
                    int nearestleft = (lower_bound(all(rightidx),i) - 1 - rightidx.begin());
                    int farthestleft = nearestleft - leftcnt;
                    ans += (leftcnt * i - (nearestleft < 0 ? 0 : prerightidx[nearestleft]) + (farthestleft < 0 ? 0 : prerightidx[farthestleft])) * 2;

                    int nearestright = upper_bound(all(leftidx),i) - leftidx.begin() - 1;
                    int farthestright = nearestright + rightcnt;

                    ans += ((farthestright < 0 ? 0 : preleftidx[farthestright]) - (nearestright < 0 ? 0 : preleftidx[nearestright]) - rightcnt*i) * 2;

                    cout<<ans<<" ";
                    continue;
                }
            }
            else
            {
                if(leftcnt >= rightcnt)
                {
                    int ans = n - i;
                    leftcnt = rightcnt;
                    int nearestleft = (lower_bound(all(rightidx),i) - 1 - rightidx.begin());
                    int farthestleft = nearestleft - leftcnt;
                    ans += (leftcnt * i - (nearestleft < 0 ? 0 : prerightidx[nearestleft]) + (farthestleft < 0 ? 0 : prerightidx[farthestleft])) * 2;

                    int nearestright = upper_bound(all(leftidx),i) - leftidx.begin() - 1;
                    int farthestright = nearestright + rightcnt;

                    ans += ((farthestright < 0 ? 0 : preleftidx[farthestright]) - (nearestright < 0 ? 0 : preleftidx[nearestright]) - rightcnt*i) * 2;

                    cout<<ans<<" ";
                    continue;
                }
                else
                {
                    int ans = i + 1;
                    rightcnt = leftcnt + 1;
                    int nearestleft = (lower_bound(all(rightidx),i) - 1 - rightidx.begin());
                    int farthestleft = nearestleft - leftcnt;
                    ans += (leftcnt * i - (nearestleft < 0 ? 0 : prerightidx[nearestleft]) + (farthestleft < 0 ? 0 : prerightidx[farthestleft])) * 2;

                    int nearestright = upper_bound(all(leftidx),i) - leftidx.begin() - 1;
                    int farthestright = nearestright + rightcnt;

                    ans += ((farthestright < 0 ? 0 : preleftidx[farthestright]) - (nearestright < 0 ? 0 : preleftidx[nearestright]) - rightcnt*i) * 2;

                    cout<<ans<<" ";
                    continue;
                }
            }
        }
        cout<<endl;
    }
}