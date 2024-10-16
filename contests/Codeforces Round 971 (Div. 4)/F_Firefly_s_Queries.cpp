#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX / 2;
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
#define cout(x) x ? cout << "Yes" << endl : cout << "No" << endl

int solve(int r,vector<int>& roundsum,vector<int>& pre,vector<int>& v,vector<int>& prev)
{
    if(r == 0)return 0;

    int n = v.size();
    if(r == n * n)
    return n * prev[n-1];

    if(r <= n)
    {
        return prev[r-1];
    }
    int sum = prev[n-1];
    r -= n + 1;
    int q = r/(n-1);
    debug(sum);
    sum += prev[n-1] * q - (q == 0?0:prev[q-1]);
    debug(r,sum);
    int rem = r % (n-1);
    debug(rem,q);
    if(rem < q)
    {
        sum += prev[rem];
        return sum;
    }

    else
    {
        sum += debug(prev[rem + 1] ) - debug(v[q]);
        return sum;
    }
}

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
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int tot = accumulate(all(v),0ll);
        vector<int> roundsum(n);
        for(int i=0;i<n;i++)roundsum[i] = tot - v[i];

        vector<int> pre(n);
        vector<int> prev(n);
        partial_sum(all(v),prev.begin());
        partial_sum(all(roundsum),pre.begin());
        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;
            cout<<solve(r,roundsum,pre,v,prev) - solve(l-1,roundsum,pre,v,prev)<<endl;
            debug(r,solve(r,roundsum,pre,v,prev));
            debug(l-1,solve(l-1,roundsum,pre,v,prev));
        }
    }
}