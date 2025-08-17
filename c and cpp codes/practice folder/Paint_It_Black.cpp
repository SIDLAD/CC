#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define cout(x) (x?cout<<"Yes"<<endl:cout<<"No"<<endl)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define in(a, b) for (ll i = (a); i <= (b); i++)                // in using i
#define inj(a, b) for (ll j = (a); j <= (b); j++)               // in using j
#define inv(vec,n) vector<ll> vec(n+1); vec[0]=0; in(1,n) cin>>vec[i]; // input vector of n elements

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
// #define double long double

const int INF =
#ifdef int
    LLONG_MAX/3
#else
    INT_MAX/3
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void show() {
    std::cout <<'\n';
}

// Variadic template function
template<typename T, typename... Args>
void show(T first, Args... args) {
    std::cout << first << " "; // Print the first argument
    show(args...);        // Recursive
}

int n,m,k;
vector<vector<int>> color;
vector<vector<int>> prepre;
vector<pair<int,int>> topLeft, topRight, bottomLeft, bottomRight;


void getCorners() {
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(color[i][j]){
        if(i == 0 || color[i-1][j] == 0) {
            if(j == 0 || color[i][j-1] == 0) topLeft.emplace_back(i,j);
            if(j == m - 1 || color[i][j + 1] == 0) topRight.emplace_back(i,j);
        }
        if(i == n - 1 || color[i + 1][j] == 0) {
            if(j == 0 || color[i][j-1] == 0) bottomLeft.emplace_back(i,j);
            if(j == m - 1 || color[i][j + 1] == 0) bottomRight.emplace_back(i,j);
        }
    }
}

void get2dprefix () {
    prepre[0][0] = color[0][0];
    for(int i=1;i<n;++i) prepre[i][0] = prepre[i-1][0] + color[i][0];
    for(int j=1;j<m;++j) prepre[0][j] = prepre[0][j-1] + color[0][j];
    for(int i=1;i<n;++i) for(int j=1;j<m;++j)
    prepre[i][j] = prepre[i-1][j] + prepre[i][j-1] - prepre[i-1][j-1] + color[i][j];
}

int getPre(pii x) {
    if(x.first < 0 || x.second < 0) return 0;
    return prepre[x.first][x.second];
}

int getbw(pii x, pii y) { // x <= y ie y - x
    --x.first, --x.second;
    auto ret =  getPre(y) + getPre(x) - getPre({y.first, x.second}) - getPre({x.first, y.second});
    return ret;
}

bool isPoss(pii a, pii b) {
    pii c = {min(a.first, b.first), min(a.second, b.second)};
    pii d = {max(a.first, b.first), max(a.second, b.second)};
    return (debug(getbw(c,d)) == (d.first - c.first + 1) * (d.second - c.second + 1));
}
struct rect {
    int imin;
    int imax;
    int jmin;
    int jmax;

    rect(int imin, int imax, int jmin, int jmax) : imin(imin), imax(imax), jmin(jmin), jmax(jmax) {}
};

vector<rect> boxListSame(vector<vector<int>>& startL, vector<vector<int>>& startR) {
    vector<rect> ret;
    vector<int> base(m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
        if(!color[i][j]) base[j] = 0;
        else base[j]++;

        vector<int> fstk;
        vector<int> rstk;
        vector<pii> lrless(m);
        for(int j=0;j<m;++j) {
            if(sz(fstk) && base[fstk.back()] >= base[j]) fstk.pop_back();
            lrless[j].first = !sz(fstk) ? 0 : fstk.back() + 1;
            fstk.push_back(j);
        }
        for(int j=m-1;j>=0;--j) {
            if(sz(rstk) && base[rstk.back()] >= base[j]) rstk.pop_back();
            lrless[j].second = !sz(rstk) ? m - 1 : rstk.back() - 1;
            rstk.push_back(j);
        }
        for(auto indL: startL[i]) {
            rect nw(i - base[indL] + 1, i, indL, lrless[indL].second);
            ret.push_back(nw);
        }
        for(auto indR: startR[i]) {
            rect nw(i - base[indR] + 1, i, lrless[indR].first, indR);
            ret.push_back(nw);
        }
    }
    return ret;
}

vector<rect> getSameLineRect() {
    vector<vector<int>> leftPairs(n), rightPairs(n);
    for(auto tl : topLeft) for(auto bl: bottomLeft) {
        if(tl.second == bl.second && isPoss(tl, bl)) {
            leftPairs[bl.first].push_back(tl.second);
        } 
    }
    for(auto tr: topRight) for(auto br: bottomRight) {
        if(tr.second == br.second && isPoss(tr, br)) {
            rightPairs[br.first].push_back(tr.second);
        }
    }
    return boxListSame(leftPairs, rightPairs);
}

vector<rect> getDiffLineRect() {
    vector<rect> ret;
    for(auto tl: topLeft) for(auto br: bottomRight) if(isPoss(tl, br)){
        ret.push_back(rect(tl.first, br.first, tl.second, br.second));
    }
    for(auto tr: topRight) for(auto bl: bottomLeft) if(isPoss(tr, bl)){
        ret.push_back(rect(tr.first, bl.first, bl.second, tr.second));
    }

    return ret;
}

int getOverlapArea(vector<rect> vr) {
    int mnl = -INF;
    int mxl = INF;
    int mnr = -INF;
    int mxr = INF;
    for(auto r: vr) {
        mnl = max(mnl, r.jmin);
        mxl = min(mxl, r.jmax);
        mnr = max(mnr, r.imin);
        mxr = min(mxr, r.imax);
    }
    if(mxl - mnl + 1 < 0 || mxr - mnr + 1 < 0) return 0;
    return (mxl - mnl + 1) * (mxr - mnr + 1);
}

bool check(vector<vector<int>> sets, vector<rect> boxes, int tot) {
    for(auto st: sets) {
        int cur = 0;
        for(int i=0;i<sz(st); ++i){
            cur += getOverlapArea({boxes[st[i]]});
        } 
        for(int i=0;i<sz(st); ++i) for(int j=i + 1;j<sz(st); ++j){
            cur -= getOverlapArea({boxes[st[i]], boxes[st[j]]});
        } 
        rep(i,0,sz(st)) rep(j,i + 1, sz(st)) rep(k,j + 1, sz(st))
            cur += getOverlapArea({boxes[st[i]], boxes[st[j]], boxes[st[k]]});
        rep(i,0,sz(st)) rep(j,i + 1, sz(st)) rep(k,j + 1, sz(st)) rep(l, k + 1, sz(st))
            cur -= getOverlapArea({boxes[st[i]], boxes[st[j]], boxes[st[k]], boxes[st[l]]});
        if(cur == tot) {
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m >> k;
    int totb = 0;
    color.assign(n, vector<int>(m));
    prepre.assign(n, vector<int>(m));
    for(int i=0;i<n;++i) {
        string s;
        cin >> s;
        for(int j=0;j<m;++j) color[i][j] = (s[j] == '1'), totb+= color[i][j];
    }
    get2dprefix();
    getCorners();
    if(max({sz(topLeft), sz(topRight), sz(bottomLeft), sz(bottomRight)}) > k) {
        cout(0);
        return;
    }

    vector<rect> boxes;
    auto ret1 = getSameLineRect();
    auto ret2 = getDiffLineRect();
    for(auto ret: ret1) boxes.push_back(ret);
    for(auto ret: ret2) boxes.push_back(ret);
    vector<vector<int>> sets;
    if(k >= 1) {
        for(int i=0;i<sz(boxes);++i) sets.push_back({i});
    }
    if(k >= 2) {
        for(int i=0;i<sz(boxes);++i) for(int j=i + 1;j<sz(boxes);j++)
        sets.push_back({i,j});
    }
    if(k >= 3) {
        for(int i=0;i<sz(boxes);++i) for(int j=i + 1;j<sz(boxes);j++) for(int k=j + 1;k<sz(boxes);k++)
        sets.push_back({i,j,k});
    }
    if(k >= 4) {
        for(int i=0;i<sz(boxes);++i) for(int j=i + 1;j<sz(boxes);j++) for(int k=j + 1;k<sz(boxes);k++) for(int l = k + 1; l <sz(boxes);l++)
        sets.push_back({i,j,k,l});
    }
    assert(k <= 4);
    cout(check(sets,boxes, totb));
}
// void tester();
signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int testcase = 1;
    // cin>>testcase;
    while(testcase--){
        solve();
        // tester();
    }
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
}


// #define RANDOM_GEN_MACRO

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());


// int selectRandom(int ll, int rr) {
//     return rngl() % (rr - ll + 1) + ll;
// }

// void tester() {
//     k = selectRandom(1,4);
//     vector<rect> a(k,{0,0,0,0});
//     int totb = 0;

//     n = 10;
//     m = 10;
//     for(int i=0;i<k;++i) {
//         a[i].imin = selectRandom(1,n);
//         a[i].imax = selectRandom(a[i].imin, n);
//         a[i].jmin = selectRandom(1,m);
//         a[i].jmax = selectRandom(a[i].jmin, m);
//     }

//     auto inCheck = [](int x, int y, rect a) ->bool{
//         return (a.imin <= x && x <= a.imax
//         && a.jmin <= x && x <= a.jmax);
//     };
//     color.assign(n, vector<int>(m));
//     prepre.assign(n, vector<int>(m));
//     for(int i=0;i<n;++i) {
//         for(int j=0;j<m;++j) {
//             for(int l=0;l<k;++l) {
//                 if(inCheck(i,j, a[k])) {
//                     color[i][j] = 1;
//                     totb++;
//                     break;
//                 }
//             }
//         }
//     }
//     get2dprefix();
//     getCorners();
//     if(max({sz(topLeft), sz(topRight), sz(bottomLeft), sz(bottomRight)}) > k) {
//         cout(0);
//         return;
//     }

//     vector<rect> boxes;
//     auto ret1 = getSameLineRect();
//     auto ret2 = getDiffLineRect();
//     for(auto ret: ret1) boxes.push_back(ret);
//     for(auto ret: ret2) boxes.push_back(ret);
//     vector<vector<int>> sets;
//     if(k >= 1) {
//         for(int i=0;i<sz(boxes);++i) sets.push_back({i});
//     }
//     if(k >= 2) {
//         for(int i=0;i<sz(boxes);++i) for(int j=i + 1;j<sz(boxes);j++)
//         sets.push_back({i,j});
//     }
//     if(k >= 3) {
//         for(int i=0;i<sz(boxes);++i) for(int j=i + 1;j<sz(boxes);j++) for(int k=j + 1;k<sz(boxes);k++)
//         sets.push_back({i,j,k});
//     }
//     if(k >= 4) {
//         for(int i=0;i<sz(boxes);++i) for(int j=i + 1;j<sz(boxes);j++) for(int k=j + 1;k<sz(boxes);k++) for(int l = k + 1; l <sz(boxes);l++)
//         sets.push_back({i,j,k,l});
//     }
//     assert(k <= 4);
//     if(!check(sets,boxes, totb)){
//         cout << k << endl;
//         for(int i=0;i<n;++i) {
//             for(int j=0;j<m;++j) {
//                 cout << color[i][j];
//             }
//             cout << endl;
//         }
//     }
//     topLeft.clear(), topRight.clear(), bottomLeft.clear(), bottomRight.clear();
// }