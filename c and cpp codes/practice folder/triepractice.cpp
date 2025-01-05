#include <bits/stdc++.h>
const long double EPS = 1e-10;
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

template<int L = 30>
struct BinaryTrie{
    struct Node{
        int c[2];
        int cnt;
        Node(){c[0] = c[1] = -1; cnt = 0;}
    };
    vector<Node> nodes{Node()};
    int root = 0;

    int createNode(){
        nodes.push_back(Node());
        return nodes.size() - 1;
    }

    void insert(int x, int amt = 1){
        int v = root;
        bool cntinue = false;
        for(int i=L;i>=0;i--){
            int b = (x >> i) & 1;
            if(nodes[v].c[b] == -1 or nodes[nodes[v].c[b]].cnt == 0){cntinue = true;break;}
            v = nodes[v].c[b];
        }
        if(!cntinue)return;
        v = root;
        for(int i = L; i>=0; i--){
            nodes[v].cnt += amt;
            int b = (x >> i) & 1;
            if(nodes[v].c[b] == -1){nodes[v].c[b] = createNode();}
            v = nodes[v].c[b];
        }
        nodes[v].cnt += amt;
    }

    void del(int x, int amt = 1){
        int v = root;
        for(int i=L;i>=0;i--){
            int b = (x >> i) & 1;
            if(nodes[v].c[b] == -1 or nodes[nodes[v].c[b]].cnt == 0){return;}
            v = nodes[v].c[b];
        }
        v = root;
        for(int i=L;i>=0;i--){
            nodes[v].cnt -= amt;
            int b = (x >> i) & 1;
            assert(nodes[v].c[b] != -1);
            v = nodes[v].c[b];
        }
        nodes[v].cnt -= amt;
    }

    int minxor(int x){
        int v = root;
        assert(nodes[v].cnt != 0);
        int xorval = 0;
        for(int i=L;i>=0;i--){
            int b = (x>>i)&1;
            if(nodes[v].c[b] != -1 and nodes[nodes[v].c[b]].cnt != 0)v = nodes[v].c[b];
            else{
                assert(nodes[v].c[1^b] != -1 and nodes[nodes[v].c[1^b]].cnt !=0);
                xorval += (1<<i);
                v = nodes[v].c[1 ^ b];
            }
        }
        return xorval;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int q;
    cin >> q;
    BinaryTrie bt;
    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if(c == '0')bt.insert(x);
        else if(c == '1')bt.del(x);
        else cout << bt.minxor(x) << endl;
    }
}