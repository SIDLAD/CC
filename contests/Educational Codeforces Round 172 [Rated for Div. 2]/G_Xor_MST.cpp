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

template <int L = 29>
struct BinaryTrie {
  struct Node {
    int cnt, dep;
    int c[2];
    Node() {
      cnt = dep = 0;
      c[0] = c[1] = -1;
    }
  };
  int root = 0, sz = 0;
  vector<Node> nodes{Node()};
  BinaryTrie() {}
  int create_node() {
    nodes.push_back(Node());
    return ++sz;
  }
  void insert(int x, int amt = 1) {
    int v = root;
    for (int i = L; i >= 0; i--) {
      nodes[v].cnt += amt;
      int b = (x >> i) & 1;
      if (nodes[v].c[b] == -1) {
        nodes[v].c[b] = create_node();
        nodes[nodes[v].c[b]].dep = nodes[v].dep + 1;
      }
      v = nodes[v].c[b];
    }
    nodes[v].cnt += amt;
  }
  // Assumes element exists
  void remove(int x, int amt = 1) {
    int v = root;
    for (int i = L; i >= 0; i--) {
      nodes[v].cnt -= amt;
      v = nodes[v].c[(x >> i) & 1];
    }
    nodes[v].cnt -= amt;
  }
  int minxor(int x) {
    int ans = 0;
    int v = root;
    for (int i = L; i >= 0; i--) {
      int b = (x >> i) & 1;
      if (nodes[v].c[b] != -1 && nodes[nodes[v].c[b]].cnt)
        v = nodes[v].c[b];
      else {
        ans |= 1 << i;
        v = nodes[v].c[b ^ 1];
      }
    }
    return ans;
  }
};

BinaryTrie bt;

vector<int> v;
int dfs(int l, int r, int b = 29)
{
    if(b == -1)return 0;
    int m = l;
    for(;m <= r and (v[m] & (1<<b)) == (v[l] & (1<<b));m++)
    {
        bt.insert(v[m]);
    }
    if(m == r + 1){
        for(int i=l;i<m;i++)
        {
            bt.remove(v[i]);
        }
        return dfs(l,r,b - 1);
    }
    int mnval = INF;
    for(int i=m;i<=r;i++)
    {
        int minxor = bt.minxor(v[i]);
        if(minxor < mnval)mnval = minxor;
    }
    for(int i=l;i<m;i++)
    {
        bt.remove(v[i]);
    }
    return dfs(l,m-1,b - 1) + dfs(m,r,b-1) + mnval;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    set<int> st;
    range(i,0,n)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    v.insert(v.begin(),all(st));
    cout<<dfs(0,v.size() - 1)<<endl;
}