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

struct segtree2d
{
    vector<vector<int>>& ar;
    vector<vector<int>> tree;
    int n,m;

    void buildcolumn(int idi, int idj, int segil, int segir, int segjl, int segjr)
    {
        if(segjl == segjr)
        {
            if(segil == segir)
            {
                tree[idi][idj] = ar[segil][segjl];
            }
            else
            {
                tree[idi][idj] = tree[2*idi + 1][idj] + tree[2*idi + 2][idj];
            }
        }
        else
        {
            int segjmid = segjl + segjr >> 1;
            buildcolumn(idi,2*idj + 1, segil,segir, segjl, segjmid);
            buildcolumn(idi,2*idj + 2, segil,segir, segjmid + 1, segjr);
            tree[idi][idj] = tree[idi][2*idj + 1] + tree[idi][2*idj + 2];
        }
    }

    void buildrow(int idi, int segil, int segir)
    {
        if(segil != segir)
        {
            int segimid = segil + segir >> 1;
            buildrow(2*idi + 1,segil,segimid);
            buildrow(2*idi + 2,segimid + 1,segir);
        }

        buildcolumn(idi,0,segil,segir,0,m-1);
    }

    segtree2d(vector<vector<int>>& ar) : ar(ar)
    {
        n = ar.size();
        m = ar[0].size();
        tree.resize(4 * n,vector<int>(4 * m));
        buildrow(0,0,n-1);
    }

    int querycolumn(int jl, int jr, int idi, int idj, int segjl, int segjr)
    {
        if(min(segjr,jr) < max(segjl,jl))return 0;
        if(segjl >= jl and segjr <= jr)return tree[idi][idj];

        int segjmid = segjl + segjr >> 1;
        return querycolumn(jl,jr,idi,2*idj + 1, segjl, segjmid) + querycolumn(jl,jr,idi,2*idj + 2, segjmid + 1, segjr);
    }

    int queryrow(int il, int ir, int jl, int jr, int idi = 0, int segil = 0, int segir = -1)
    {
        if(segir == -1)segir += n;
        if(min(segir,ir) < max(segil,il))return 0;
        if(segil >= il  and segir <= ir)return querycolumn(jl,jr,idi,0,0,m-1);

        int segimid = segil + segir >> 1;
        return queryrow(il,ir,jl,jr,2*idi + 1,segil,segimid) + queryrow(il,ir,jl,jr,2*idi + 2,segimid + 1,segir);
    }

    void modifycolumn(int i, int j, int idi, int idj, int segil, int segir, int segjl, int segjr)
    {
        if(min(segjr,j) < max(segjl,j))return;
        if(segjl == segjr)
        {
            if(segil == segir)
            {
                assert(i == segil and j == segjl);
                ar[i][j] ^= 1;
                tree[idi][idj] = ar[i][j];
            }
            else
            {
                tree[idi][idj] = tree[2*idi + 1][idj] + tree[2*idi + 2][idj];
            }
        }
        else
        {
            int segjmid = segjl + segjr >> 1;
            modifycolumn(i,j,idi,2*idj + 1, segil,segir, segjl,segjmid);
            modifycolumn(i,j,idi,2*idj +  2,segil,segir,segjmid + 1,segjr);
            tree[idi][idj] = tree[idi][2*idj + 1] + tree[idi][2*idj + 2];
        }
    }

    void modifyrow(int i, int j, int idi = 0, int segil = 0, int segir = -1)
    {
        if(segir == -1)segir += n;
        if(min(segir,i) < max(segil,i))return;
        if(segil != segir)
        {
            int segimid = segil + segir >> 1;
            modifyrow(i,j,2*idi + 1,segil,segimid);
            modifyrow(i,j,2*idi + 2,segimid + 1, segir);
        }
        
        modifycolumn(i,j,idi,0,segil,segir,0,m-1);
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,q;
    cin>>n>>q;

    vector<vector<int>> a(n,vector<int>(n));
    range(i,0,n)range(j,0,n)
    {
        char c;
        cin>>c;
        if(c == '*')a[i][j] = 1;
    }
    segtree2d st(a);
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            int y,x;
            cin>>y>>x;
            st.modifyrow(y - 1,x - 1);
        }
        else
        {
            int y1,x1,y2,x2;
            cin>>y1>>x1>>y2>>x2;
            cout<<st.queryrow(y1 - 1,y2 - 1,x1 - 1,x2 - 1)<<endl;
        }
    }
}