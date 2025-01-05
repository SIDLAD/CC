#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int)1e9 + 7; // 998'244'353;
using namespace std;
// insert policy here

// insert mintcode here

#if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
void _exe() {}
template <typename T, typename... V>
const T &_exe(const T &t, const V &...v) { return t; }
template <typename T, typename... V>
T &_exe(T &t, V &...v) { return t; }

#define debug(x...) (_exe(x))

class CNothing
{
};

template <typename T>
const CNothing &operator<<(const CNothing &proxy, const T &)
{
    return proxy;
}

const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &))
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
#define all(x) (x).begin(), (x).end()
#define endl "\n" // comment out for interactive problems
#define cout(x) x ? cout << "YES" << endl : cout << "NO" << endl
#define range(it, start, end) for (auto it = start; it != end; it++)
#define arrPut(var)         \
    for (auto &inVar : var) \
    {                       \
        cin >> inVar;       \
    }
#define arrPrint(var)          \
    for (auto outVar : var)    \
    {                          \
        cout << outVar << ' '; \
    }                          \
    cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
    ;

template<typename T = int,typename V = T>
struct segtree
{
    int n;
    vector<array<int, 3>> lazy;
    vector<int> &a;
    vector<int> pointupdate;
    array<int, 3> lazy_zero = {0, 0, 0}; // Change according to MODIFY operation

    segtree(vector<int> &v) : a(v)
    {
        n = v.size();
        lazy.clear();
        lazy.resize(2 * n - 1, lazy_zero);
        pointupdate.resize(n);
    }

    void lazy_combine(array<int, 3> &dest, array<int, 3> a)
    {
        dest[0] += a[0];
        dest[1] += a[1];
        dest[2] += a[2];
    }

    void propagate(int id, int segl, int segr)
    {
        if (lazy[id] == lazy_zero)
            return;
        if (segl != segr)
        {
            int mid = (segl + segr) / 2;
            array<int, 2> children = {id + 1, id + 2 * (mid - segl + 1)};
            for (int i = 0; i < 2; i++)
            {
                auto child = children[i];
                lazy_combine(lazy[child], lazy[id]);
            }
        }
        else
        {
            pointupdate[segl] += lazy[id][2];
            if (segl & 1)
                pointupdate[segl] += lazy[id][1];
            else
                pointupdate[segl] += lazy[id][0];
        }
        lazy[id] = lazy_zero;
    }

    void modify(int val, int updatetype, int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (index_r == -1)
            index_r = index_l;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return;
        }
        propagate(id, segl, segr);
        
        if (segl >= index_l && segr <= index_r)
        {
            lazy_combine(lazy[id], {updatetype == 0 ? val : 0, updatetype == 1 ? val : 0, updatetype == 2 ? val : 0});
            return;
        }
        int mid = (segl + segr) / 2;
        modify(val, updatetype, index_l, index_r, id + 1, segl, mid);
        modify(val, updatetype, index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
    }

    int query_update(int index_l, int index_r = -1, int id = 0, int segl = 0, int segr = -1)
    {
        if (segr == -1)
            segr = n - 1;
        if (index_r == -1)
            index_r = index_l;
        if (index_l > index_r || index_l > segr || segl > index_r)
        {
            return 0;
        }
        propagate(id, segl, segr);

        if (segl >= index_l && segr <= index_r)
        {
            return pointupdate[index_l];
        }
        int mid = (segl + segr) / 2;
        int leftVal = query_update(index_l, index_r, id + 1, segl, mid);
        int rightVal = query_update(index_l, index_r, id + 2 * (mid - segl + 1), mid + 1, segr);
        return leftVal + rightVal;
    }

    int query(int index)
    {
        return a[index] + query_update((index + 1) % n) + 2 * query_update(index) + query_update((index + n - 1) % n);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n;
        cin >> n;
        vector<int> tmp(n);
        arrPut(tmp);

        segtree st(tmp);

        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        st.modify(st.query(0) - st.query(n - 1), 2, n - 1);

        for (int i = 1; i < n / 2; i++)
        {
            int diff = st.query(n - i - 1) - st.query(i);
            st.modify(diff, i & 1, 0, i);
            st.modify(diff, ~i & 1, n - i - 1, n - 1);
        }

        for (int i = n / 2; i >= 1; i--)
        {
            int diff = st.query(i - 1) - st.query(i);
            st.modify(diff, i & 1, i, n - i - 1);
        }
        vector<int> ans(n);
        range(i, 0, n) ans[i] = st.query_update(i);
        int add = -*min_element(all(ans));
        range(i, 0, n) cout << ans[i] + add << " \n"[i==n-1];
    }
}