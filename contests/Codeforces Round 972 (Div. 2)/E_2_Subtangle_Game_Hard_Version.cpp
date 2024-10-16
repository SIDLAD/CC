//TLE coz of log n log m query factor

#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order

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

#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
#define cout(x) x?cout<<"T"<<endl:cout<<"N"<<endl
int t[4 * 1500 + 1][4 * 1500 + 1];
int n,m;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = INF;
        else
            t[vx][vy] = min(t[vx*2][vy] , t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = min(t[vx][vy*2] , t[vx][vy*2+1]);
    }
}


void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}

int min_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return INF;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return min(min_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
          ,min_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
}

int min_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return INF;
    if (lx == tlx && trx == rx)
        return min_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return min(min_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
            , min_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = min(t[vx*2][vy] , t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = min(t[vx][vy*2] , t[vx][vy*2+1]);
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;){
        int l;
        cin>>l>>n>>m;
        
        umap<int,int> mp;
        int tmp;
        bool check = true;
        for(int i=0;i<l;i++)
        {
            cin>>tmp;
            if(check and mp.find(tmp) == mp.end())
            {
                mp[tmp] = i;
            }else check = false;
        }

        vector<vector<int>> mat(n,vector<int>(m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }

        build_x(1,0,n-1);
        for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--)
        {
            if(mp.find(mat[i][j]) != mp.end())
            {
                int idx = mp[mat[i][j]];
                if(min_x(1,0,n-1,i+1,n-1,j+1,m-1) != idx+1)
                update_x(1,0,n-1,i,j,idx);
            }
        }
        cout((min_x(1,0,n-1,0,n-1,0,m-1)) == 0);
    }
}