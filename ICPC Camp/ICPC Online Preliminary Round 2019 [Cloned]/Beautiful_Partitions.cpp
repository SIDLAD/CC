// #include <bits/stdc++.h>
// const long double EPS = 1e-7;
// const long long int M = (long long int)1e9 + 7; // 998'244'353;
// using namespace std;
// // insert policy here

// // insert mintcode here

// #if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
// void _exe() {}
// template <typename T, typename... V>
// const T &_exe(const T &t, const V &...v) { return t; }
// template <typename T, typename... V>
// T &_exe(T &t, V &...v) { return t; }

// #define debug(x...) (_exe(x))

// class CNothing
// {
// };

// template <typename T>
// const CNothing &operator<<(const CNothing &proxy, const T &)
// {
//     return proxy;
// }

// const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &))
// {
//     return proxy;
// }
// CNothing cnothing;
// #define cerr cnothing
// #else
// #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
// #endif

// #define int long long
// #define double long double
// #define all(x) (x).begin(), (x).end()
// #define endl "\n" // comment out for interactive problems
// #define cout(x) (x ? cout << "YES" << endl : cout << "NO" << endl)
// #define range(it, start, end) for (auto it = start; it < end; it++)
// #define arrPut(var)         \
//     for (auto &inVar : var) \
//     {                       \
//         cin >> inVar;       \
//     }
// #define arrPrint(var)          \
//     for (auto outVar : var)    \
//     {                          \
//         cout << outVar << ' '; \
//     }                          \
//     cout << '\n'

// const int INF =
// #ifdef int
//     LONG_LONG_MAX / 2
// #else
//     INT_MAX / 2
// #endif
//     ;

// vector<int> a;
// template <typename T = set<int>, typename V = T>
// struct segtree
// {
//     int n;
//     vector<T> tree;
//     // vector<V> lazy;
//     T zero = set<int>(); // Change according to QUERY operation
//     // V lazy_zero; // Change according to MODIFY operation

//     segtree(int sz)
//     {
//         n = sz;
//         tree.clear();
//         // lazy.clear();
//         tree.resize(2 * sz - 1, zero);
//         // lazy.resize(2 * sz - 1, lazy_zero);
//     }

//     T combine(T a, T b)
//     {
//         // Change according to QUERY operation
//         for (auto ele : b)
//             a.insert(ele);
//         return a;
//     }

//     void build(vector<int> &v, int id = 0, int segl = 0, int segr = -1)
//     {
//         if (segr == -1)
//             segr = n - 1;
//         if (segl == segr)
//         {
//             tree[id].insert(v[segl]);
//             return;
//         }
//         int mid = (segl + segr) / 2;
//         build(v, id + 1, segl, mid);
//         build(v, id + 2 * (mid - segl + 1), mid + 1, segr);
//         tree[id] = combine(tree[id + 1], tree[id + 2 * (mid - segl + 1)]);
//     }

//     // void propagate(int id, int segl, int segr)
//     // {
//     // if(lazy[id] == lazy_zero)return;
//     // if(segl != segr)
//     // {
//     // int mid = (segl + segr) / 2;
//     // array<int , 2> children= {id + 1, id + 2 * (mid - segl + 1)};
//     // for(auto child : children)
//     // {
//     // tree[child] = lazy[id];  // Change according to MODIFY operation
//     // lazy[child] = lazy[id];  // Change according to MODIFY operation
//     // }
//     // }
//     // lazy[id] = lazy_zero;
//     // }

//     int query(int k, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
//     {
//         if (segr == -1)
//             segr = n - 1;
//         if (index_r == -1)
//             index_r = index_l;
//         if (index_l > index_r || index_l > segr || segl > index_r)
//         {
//             return -1;
//         }
//         // propagate(id, segl, segr);

//         if (*--tree[id].end() <= k)
//             return -1;

//         if (segl == segr)
//         {
//             return segl;
//         }
//         int mid = (segl + segr) / 2;

//         if(segl >= index_l)
//         {
//             if (*--tree[id + 1].end() <= k) return query(k, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
//             else if(*--tree[id + 2 * (mid - segl + 1)].end() <= k) return query(k, index_l, index_r, id + 1, segl, mid);
//             else
//             {
//                 if(*(tree[id + 1].upper_bound(k)) < *(tree[id + 2 * (mid - segl + 1)].upper_bound(k)))
//                 {
//                     return query(k, index_l, index_r, id + 1, segl, mid);
//                 }
//                 else
//                 {
//                     return query(k, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
//                 }
//             }
//             assert(false);
//             return -1;
//         }

//         auto left = query(k, index_l, index_r, id + 1, segl, mid);
//         auto right = query(k, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
//         if(left == -1 or right!= -1 and a[left] >= a[right])return right;
//         return left;

//         // if (segl >= index_l && segr <= index_r)
//         // {
//         //     return tree[id];
//         // }
//         // int mid = (segl + segr) / 2;
//         // T leftVal = query(index_l, index_r, id + 1, segl, mid);
//         // T rightVal = query(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
//         // return combine(leftVal, rightVal);
//     }
// };

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout.precision(numeric_limits<double>::max_digits10);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     int T;
//     cin >> T;
//     for (; T--;)
//     {
//         int n, k;
//         cin >> n >> k;
//         a.assign(n,0);
//         arrPut(a);
//         if(n == 1)
//         {
//             if(a[0] > 0)cout(true)<<1<<endl;
//             else cout(false);
//             continue;
//         }
//         partial_sum(all(a),a.begin());
//         segtree st(a.size());
//         st.build(a);
//         bool check = true;
//         vector<int> indices;
//         range(_,0,k-1)
//         {
//             int curst = indices.size() == 0?0:indices.back() + 1;
//             int curoff = indices.size() == 0?0:a[indices.back()];
//             int nextind = st.query(curoff,curst,n-1);
//             if(nextind == -1 or nextind >= n)
//             {
//                 debug(indices, curst, curoff);
//                 check = false;
//                 break;
//             }
//             indices.push_back(nextind);
//         }

//         if(!check){cout(false);continue;}
//         if(a.back() - (indices.size() == 0 ? 0 : a[indices.back()]) <= 0)
//         {
//             cout(false);
//             continue;
//         }
//         cout(true);
//         vector<int> ans;
//         range(i,0,indices.size())
//         {
//             auto index = indices[i];
//             ans.push_back(index - (i == 0 ? -1 : indices[i-1]));
//         }
//         ans.push_back(n-1 - (indices.size() == 0 ? -1 : indices.back()));
//         arrPrint(ans);
//     }
// }

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

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> p(n,-1);
        arrPut(a);
        partial_sum(all(a),a.begin());
        vector<int> lis;
        int mxk = -1;
        for(int i=0;i<n;i++)if(a[i] > 0)
        {
            auto it = lower_bound(all(lis),i,[&](auto i1, auto i2){return a[i1]<a[i2];});
            if(it == lis.end())
            {
                lis.push_back(i);
                it = lis.end() - 1;
            }
            else *it = i;
            if(it != lis.begin())p[i] = *(it-1);

            if(i == n -1)
            {
                mxk = it - lis.begin() + 1;
            }
        }

        if(mxk < k)
        {
            cout(false);
            continue;
        }      

        else
        {
            cout(true);
            vector<int> fin;
            fin.push_back(n-1);
            while(p[fin.back()] != -1)
            {
                fin.push_back(p[fin.back()]);
            }
            reverse(all(fin));
            while(fin.size() > k)fin.pop_back();
            fin.back() = n-1;
            for(int i=k-1;i>=0;i--)
            {
                fin[i] = fin[i] - (i==0?-1:fin[i-1]);
            }
            arrPrint(fin);
        }
    }
}