#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

//insert randnum here

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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int q;
    cin>>q;
    int cnt = 0;
    set<pair<int,int>> st;
    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if(k == 2)
        {
            if(st.size() == 0)
            {
                42;
            }
            else
            {
                auto it1 = st.lower_bound({l,0});
                if(st.begin() != it1)
                {
                    auto itc = it1;
                    if((--itc)->second >= l)--it1;
                }

                auto it2 = st.lower_bound({r,INF});
                
                vector<pair<int,int>> rempairs;
                vector<pair<int,int>> insertpairs;
                for(;it1!=it2;it1++)
                {
                    auto [prevstart,prevend] = *it1;
                    auto newstart = max(prevstart,l);
                    auto newend = min(prevend,r);
                    rempairs.push_back({prevstart,prevend});
                    cnt -= prevend - prevstart +1;
                    if(newstart != prevstart)
                    {
                        insertpairs.push_back({prevstart,newstart - 1});
                        cnt += newstart - prevstart;
                    }
                    if(newend != prevend)
                    {
                        insertpairs.push_back({newend + 1,prevend});
                        cnt += prevend - newend;
                    }
                }

                for(auto pr:rempairs)
                {
                    st.erase(pr);
                }
                for(auto pr:insertpairs)
                {
                    st.insert(pr);
                }
            }
        }
        else
        {
            if(st.size() == 0)
            {
                st.insert({l,r});
                cnt += r - l + 1;
            }
            else
            {
                auto it1 = st.lower_bound({l,0});
                if(st.begin() != it1)
                {
                    auto itc = it1;
                    if((--itc)->second >= l)--it1;
                }

                auto it2 = st.lower_bound({r,INF});
                int newl = l,newr = r;
                vector<pair<int,int>> rempairs;
                
                for(;it1!=it2;it1++)
                {
                    rempairs.push_back(*it1);
                    newl = min(newl,it1->first);
                    newr = max(newr,it1->second);
                    cnt -= it1->second - it1->first + 1;
                }
                for(auto pr:rempairs)
                {
                    st.erase(pr);
                }
                cnt += newr - newl + 1;
                st.insert({newl,newr});
            }
        }

        cout<<n - cnt<<endl;
        debug(st);
    }
}

// #include <bits/stdc++.h>
// const long double EPS = 1e-7;
// const long long int M = (long long int) 1e9 + 7;//998'244'353;
// using namespace std;
// //insert policy here

// //insert mintcode here

// //insert randnum here

// #if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
//     void _exe() {}
//     template <typename T, typename... V>
//     const T& _exe(const T &t,const V&... v) {return t;}
//     template <typename T, typename... V>
//     T& _exe(T &t,V&... v) {return t;}
//     #define debug(x...) (_exe(x))
    
//     class CNothing {} cnothing;
//     template <typename T>
//     const CNothing& operator<<(const CNothing& proxy, const T&) {return proxy;}
//     const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&)) {return proxy;}
//     #define cerr cnothing
// #else
//     #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
// #endif

// #define all(x) (x).begin(),(x).end()
// #define endl '\n' //comment out for interactive problems
// #define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
// #define range(it, start, end) for (auto it = start; it < end; it++)
// #define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
// #define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

// const int INF =
// #ifdef int
//     LONG_LONG_MAX/2
// #else
//     INT_MAX/2
// #endif
// ;

// struct Node
// {
//     int freq ;
//     int lazy ;
//     int left ;
//     int right ;
//     Node():freq(0),lazy(-1),left(-1),right(-1){}
// } nodes[15000000];

// int curnodeid = 1;

// int n;

// class SparseSegtree {
//   private:
// 	int comb(int a, int b) { return a + b; }

// 	void apply(Node& cur, int len, int val) {
//         (cur.lazy) = val;
//         (cur.freq) = len * val;
// 	}

//     int getnewid()
//     {
//         return curnodeid++;
//     }

// 	void push_down(int curid, int l, int r) {
// 		if (nodes[curid].left == -1) {
//             nodes[curid].left = getnewid();
//         }
// 		if (nodes[curid].right == -1) {
//             nodes[curid].right = getnewid();
//         }
// 		int m = (l + r) / 2;
//         if(nodes[curid].lazy != -1)
//         {
//             apply(nodes[nodes[curid].left], m - l + 1, nodes[curid].lazy);
//             apply(nodes[nodes[curid].right], r - m, nodes[curid].lazy);
//             nodes[curid].lazy = -1;
//         }
// 	}

// 	void range_set(int curid, int l, int r, int ql, int qr, int val) {
// 		if (qr < l || ql > r) { return; }
// 		if (ql <= l && r <= qr) {
// 			apply(nodes[curid], r - l + 1, val);
// 		} else {
// 			push_down(curid, l, r);
// 			int m = (l + r) / 2;
// 			range_set(nodes[curid].left, l, m, ql, qr, val);
// 			range_set(nodes[curid].right, m + 1, r, ql, qr, val);
// 			nodes[curid].freq = comb(nodes[nodes[curid].left].freq, nodes[nodes[curid].right].freq);
// 		}
// 	}

// 	int range_sum(int curid, int l, int r, int ql, int qr) {
// 		if (qr < l || ql > r) { return 0; }
// 		if (ql <= l && r <= qr) { return nodes[curid].freq; }
// 		push_down(curid, l, r);
// 		int m = (l + r) / 2;
// 		return comb(range_sum(nodes[curid].left, l, m, ql, qr),
// 		            range_sum(nodes[curid].right, m + 1, r, ql, qr));
// 	}

//   public:

// 	void range_set(int ql, int qr, int val) { range_set(0, 0, n - 1, ql, qr, val); }

// 	int range_sum(int ql, int qr) { return range_sum(0, 0, n - 1, ql, qr); }
// };

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     cout.precision(numeric_limits<double>::max_digits10);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     cin>>n;
//     int q;
//     cin>>q;
//     SparseSegtree st;
//     while(q--)
//     {
//         int l,r,k;
//         cin>>l>>r>>k;
//         if(k == 1) st.range_set(l-1,r-1,1);
//         else st.range_set(l-1,r-1,0);

//         cout<<n - st.range_sum(0,n-1)<<endl;
//     }
// }