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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

map<char,int> mapping;

void preprocess()
{
    map<char,int> ch_2_ind;
    ch_2_ind['a'] = 0;
    ch_2_ind['b'] = 0;
    ch_2_ind['c'] = 0;
    ch_2_ind['d'] = 1;
    ch_2_ind['e'] = 1;
    ch_2_ind['f'] = 1;
    ch_2_ind['g'] = 2;
    ch_2_ind['h'] = 2;
    ch_2_ind['i'] = 2;
    ch_2_ind['j'] = 3;
    ch_2_ind['k'] = 3;
    ch_2_ind['l'] = 3;
    ch_2_ind['m'] = 4;
    ch_2_ind['n'] = 4;
    ch_2_ind['o'] = 4;
    ch_2_ind['p'] = 5;
    ch_2_ind['q'] = 5;
    ch_2_ind['r'] = 5;
    ch_2_ind['s'] = 5;
    ch_2_ind['t'] = 6;
    ch_2_ind['u'] = 6;
    ch_2_ind['v'] = 6;
    ch_2_ind['w'] = 7;
    ch_2_ind['x'] = 7;
    ch_2_ind['y'] = 7;
    ch_2_ind['z'] = 7;
    mapping = ch_2_ind;
}

struct TrieNode
{
    int freq=0;
    unordered_map<int,TrieNode*> children;
};



void insert(TrieNode* cur, string& s, int index)
{
    if(index == s.length()){cur->freq++;return;}
    int i = mapping[s[index]];
    if(cur->children.count(i) == 0)
    {
        cur->children[i] = new TrieNode;
    }
    int prev = cur->children[i]->freq;
    insert(cur->children[i],s,index + 1);
    int nxt = cur->children[i]->freq;
    cur->freq += nxt - prev;
}

int getfreq(TrieNode* cur, string& s, int index)
{
    if(index == s.length()){return cur->freq;}
    int i = s[index] - '2';
    if(cur->children.count(i) == 0)return 0;
    return getfreq(cur->children[i],s,index + 1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    preprocess();
    int n,m;
    cin>>n>>m;

    TrieNode* root = new TrieNode;
    debug(sizeof(*root));
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        insert(root,s,0);
    }

    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        cout<<getfreq(root,s,0)<<endl;
    }
}