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

using T = int;
struct segtree
{
    int n;
    vector<T> tree;
    // vector<T> lazy;
    T zero = INF; // Change according to QUERY operation

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
        return query(l, r, 0, 0, n - 1);
    }
    T query(int l)
    {
        return query(l, n-1);
    }

    vector<pair<int,int>> history;

    void update(int index, T val)
    {
        int prev_val = query(index,index);
        history.push_back({index,prev_val});
        modify(index,val);
    }

    void rollback_all()
    {
        while(history.size())
        {
            auto [index,val] = history.back();
            history.pop_back();
            modify(index,val);
        }
    }
};

int N = 4e6 + 1;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    segtree st(N + 1);
    for(;T--;)
    {
        st.rollback_all();
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        v.push_back(0);
        v.push_back(N);
        sort(all(v));
        set<pair<int,int>> range; //start, rangelen
        map<int,set<int>> rangestarts;
        for(int i=0;i<v.size()-1;i++)
        {
            int rangestart = v[i];
            int rangend = v[i + 1];
            range.insert({rangestart + 1, rangend - rangestart - 1});
            rangestarts[rangend - rangestart - 1].insert(rangestart + 1);
            st.update(rangend - rangestart - 1,*rangestarts[rangend - rangestart - 1].begin());
        }

        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            char a;
            int b;
            cin>>a>>b;
            switch(a)
            {
                case '-':
                    {
                        auto itl = range.lower_bound({b+1,0});
                        auto itu = itl--;
                        auto [rangestart1,rangesize1] = *itl;
                        auto [rangestart2,rangesize2] = *itu;

                        range.erase(itl),range.erase(itu);
                        range.insert({rangestart1, rangesize1 + rangesize2 + 1});
                        vector<int> updates = {rangesize1,rangesize2,rangesize1 + rangesize2 + 1};
                        rangestarts[rangesize1].erase(rangestart1);
                        rangestarts[rangesize2].erase(rangestart2);
                        rangestarts[rangesize1 + rangesize2 + 1].insert(rangestart1);

                        for(auto sz: updates)
                        {
                            if(rangestarts.count(sz) == 0 or rangestarts[sz].size() == 0)
                            {
                                rangestarts.erase(sz);
                                st.update(sz, INF);
                                continue;
                            }
                            st.update(sz,*rangestarts[sz].begin());
                        }
                    }
                    break;
                case '+':
                    {
                        auto it = --range.upper_bound({b+1,0});
                        auto [rangestarto,rangesizeo] = *it;
                        pair<int,int> range1 = {rangestarto, b - rangestarto};
                        pair<int,int> range2 = {b + 1, rangestarto + rangesizeo - 1 - b};
                        range.erase(it);
                        range.insert(range1),range.insert(range2);

                        rangestarts[rangesizeo].erase(rangestarto);
                        rangestarts[range1.second].insert(range1.first);
                        rangestarts[range2.second].insert(range2.first);

                        vector<int> updates = {rangesizeo,range1.second,range2.second};
                        for(auto sz: updates)
                        {
                            if(rangestarts.count(sz) == 0 or rangestarts[sz].size() == 0)
                            {
                                rangestarts.erase(sz);
                                st.update(sz, INF);
                                continue;
                            }
                            st.update(sz,*rangestarts[sz].begin());
                        }
                    }
                    break;
                default:
                    debug(range,b);
                    cout<<st.query(b)<<" ";
            }
        }
        cout<<endl;

    }
}