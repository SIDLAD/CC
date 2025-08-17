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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int n,m;
using pii = pair<int,int>;

map<pair<int,int>,int> mp = {
    {{0, 0}, 0},
    {{1, 0}, 1},
    {{0, 1}, 2},
    {{1, 1}, 3},
    {{1, -1}, 4}
};

pair<int,int> getMid() {
    return make_pair(n + 1 >> 1, m + 1 >> 1);
}
pair<int,int> getDiff(auto a) {
    auto b = getMid();
    return make_pair(a.first - b.first, a.second - b.second);
}

int chessD(auto a) {
    auto b = getMid();
    return max(abs(a.first - b.first), abs(a.second - b.second));
}

int manhatD(auto a) {
    auto b = getMid();
    return abs(a.first - b.first) +  abs(a.second - b.second);
}

pair<int,int> opp(auto a) {
    return make_pair(n + 1 - a.first, m + 1 - a.second);
}

int customD(auto a) { // gives side / corner label
    auto b = getMid();
    if(abs(a.first - b.first) > abs(a.second - b.second)) return 1;
    else if(abs(a.first - b.first) > abs(a.second - b.second)) return 2;
    else return 3;
}

bool compare(pii a, pii b) {
    auto a1 = getDiff(a), b1 = getDiff(b);
    if(mp.contains(a1)) {
        if(mp.contains(b1)) return mp[a1] < mp[b1];
        else return true;
    }
    else if(mp.contains(b)) return false;
    if(chessD(a) != chessD(b)) return chessD(a) < chessD(b);
    if(customD(a) != customD(b)) return customD(a) < customD(b);
    return manhatD(a) < manhatD(b);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        cin >> n >> m;
        vector<pair<int,int>> cells;
        rep(i,1,n + 1) rep(j,1,m + 1)
        cells.emplace_back(i,j);
        set<pair<int,int>> st;
        sort(all(cells), compare);
        
        for(auto cell: cells) {
            auto oppC = opp(cell);
            if(st.contains(cell)) continue;
            cout << cell.first << " " << cell.second << endl;
            st.insert(cell);
            if(st.contains(oppC)) continue;
            cout << oppC.first << " " << oppC.second << endl;
            st.insert(oppC);
        }
        cout << endl;
    }
}