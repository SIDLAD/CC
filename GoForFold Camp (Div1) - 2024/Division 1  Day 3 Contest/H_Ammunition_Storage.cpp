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

static int ar[750][750];
static int tree[4 * 750][4* 750];
int n,m;

struct segtree2d
{

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
                tree[idi][idj] = max(tree[2*idi + 1][idj] , tree[2*idi + 2][idj]);
            }
        }
        else
        {
            int segjmid = segjl + segjr >> 1;
            buildcolumn(idi,2*idj + 1, segil,segir, segjl, segjmid);
            buildcolumn(idi,2*idj + 2, segil,segir, segjmid + 1, segjr);
            tree[idi][idj] = max(tree[idi][2*idj + 1] , tree[idi][2*idj + 2]);
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

    segtree2d()
    {
        buildrow(0,0,n-1);
    }

    int querycolumn(int jl, int jr, int idi, int idj, int segjl, int segjr)
    {
        if(jr < jl or segjl > jr or segjr < jl)return -INF;
        if(segjl >= jl and segjr <= jr)return tree[idi][idj];

        int segjmid = segjl + segjr >> 1;
        return max(querycolumn(jl,jr,idi,2*idj + 1, segjl, segjmid) , querycolumn(jl,jr,idi,2*idj + 2, segjmid + 1, segjr));
    }

    int queryrow(int il, int ir, int jl, int jr, int idi = 0, int segil = 0, int segir = -1)
    {
        if(segir == -1)segir += n;
        if(ir < il or segil > ir or segir < il)return -INF;
        if(segil >= il  and segir <= ir)return querycolumn(jl,jr,idi,0,0,m-1);

        int segimid = segil + segir >> 1;
        return max (queryrow(il,ir,jl,jr,2*idi + 1,segil,segimid) , queryrow(il,ir,jl,jr,2*idi + 2,segimid + 1,segir));
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n>>m;
    range(i,0,n)range(j,0,m)cin>>ar[i][j];
    segtree2d st;

    int ans = 0;

    vector<vector<int>> previ(n,vector<int>(m,-1)), nexti(n,vector<int>(m,-1));
    vector<vector<int>> prevj(n,vector<int>(m,-1)), nextj(n,vector<int>(m,-1));

    range(i,0,n)
    {
        stack<int> st;
        range(j,0,m)
        {
            while(st.size() and ar[i][st.top()] < ar[i][j])st.pop();
            if(st.size()) prevj[i][j] = st.top();
            st.push(j);
        }
        while(st.size())st.pop();
        for(int j=m-1;j>=0;j--)
        {
            while(st.size() and ar[i][st.top()] < ar[i][j])st.pop();
            if(st.size()) nextj[i][j] = st.top();
            st.push(j);
        }
    }

    range(j,0,m)
    {
        stack<int> st;
        range(i,0,n)
        {
            while(st.size() and ar[st.top()][j] < ar[i][j])st.pop();
            if(st.size()) previ[i][j] = st.top();
            st.push(i);
        }
        while(st.size())st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() and ar[st.top()][j] < ar[i][j])st.pop();
            if(st.size()) nexti[i][j] = st.top();
            st.push(i);
        }
    }

    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        vector<int> otheri,otherj;
        if(nexti[i][j] != -1)otheri.push_back(nexti[i][j]);
        if(previ[i][j] != -1)otheri.push_back(previ[i][j]);
        if(nextj[i][j] != -1)otherj.push_back(nextj[i][j]);
        if(prevj[i][j] != -1)otherj.push_back(prevj[i][j]);

        int cntij = 0;
        for(int cpyi: otheri)for(int cpyj: otherj)
        {
            int nxti = cpyi,nxtj = cpyj;
            auto [oi,oj] = make_pair(nxti,nxtj);
            int prvi = i,prvj = j;
            if(prvi > nxti)swap(prvi,nxti);
            if(prvj > nxtj)swap(prvj,nxtj);

            {
                int mn = min({ar[prvi][prvj],ar[prvi][nxtj],ar[nxti][prvj],ar[nxti][nxtj]});
                assert(mn == ar[i][j] || mn == ar[oi][oj]);
                if(mn != ar[i][j])continue;
                auto val = max({
                    st.queryrow(prvi + 1,nxti - 1,prvj + 1,nxtj - 1),
                    st.queryrow(prvi + 1, nxti - 1 , prvj , prvj),
                    st.queryrow(prvi, prvi , prvj + 1,nxtj - 1),
                    st.queryrow(nxti,nxti,prvj + 1,nxtj - 1),
                    st.queryrow(prvi + 1,nxti - 1,nxtj,nxtj)
                });

                if(val < mn)ans++,cntij++;
            }
        }
        debug(i,j,cntij);

    }
    cout<<ans<<endl;
}