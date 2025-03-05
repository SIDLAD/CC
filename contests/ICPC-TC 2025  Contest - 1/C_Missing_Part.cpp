#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
#define SPEED std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define si set<int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vpi vector<pair<int, int> >
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define all(x) (x).begin(),(x).end()
    
const int M = 1e9 + 7;
const int N = 1e5 + 1;
    
void solve();
    
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                DON'T MAKE CHANGES BEFORE THIS LINE!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define sz(x) (int)(x).size()
typedef complex<double> C;
typedef vector<double> vd;
vi rev;

void fft(vector<C>& a) {
    static int n = sz(a);
    static int L = 31 - __builtin_clz(n);
    static vector<complex<double>> R(2,1);
    R.reserve(1e6);
    static vector<C> rt(2,1); // (^ 10% faster if double)
    rt.reserve(1e6);
    for(static int k = 2; k < n; k*= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0, acos(-1.0) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    rev.reserve(1e6);
    rev.assign(0,n);
    rep(i,0,n) rev[i] = (rev[i/2] | (i & 1) << L)/2;
    rep(i,0,n) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k=1;k<n;k*=2) 
    for(int i=0;i<n;i += 2*k) rep(j,0,k) {
        C z = rt[j + k] * a[i + j + k];
        a[i+j+k] = a[i + j] - z;
        a[i + j] += z;
    }
}

vi conv( const vi& a, const vi& b) {
    if(a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    static int L = 32 - __builtin_clz(sz(res)), n = 1<<L;
    static vector<C> in(n), out(n);
    in.assign(n,0),out.assign(n,0);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    for(C& x: in)x*=x;
    rep(i,0,n) out[i] = in[-i&(n-1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4*n);
    vi _res(sz(res));
    rep(i,0,sz(res)) _res[i] = (res[i] > 0 ? res[i] + .5 : res[i] - .5);
    return _res;
}

vi getMatch(vi binpattern, vi bintext) {
    bintext.insert(bintext.end(), all(bintext));
    reverse(all(binpattern));
    auto res = conv(binpattern,bintext);
    return vi(res.begin() + sz(binpattern) - 1, res.begin() + sz(binpattern) - 1 + sz(binpattern));
}

vi temp_pattern, temp_text;

string ori, text;
string new_str;
vector<int> ct;
string s = "abcde";

vector<int> matchVal[5][5];

void solve(){
    cin >> ori >> text;
    int nn = ori.size();
    temp_pattern.resize(nn);
    temp_text.resize(nn);
    int ans = INT_MAX;
    
    for(int l1=0;l1<5;l1++)for(int l2=0;l2<5;l2++) {
        rep(j,0,nn) {
            if(s[ori[j] - 'A'] - 'a' == l1) temp_pattern[j] = 1;
            else temp_pattern[j] = 0;
            if(text[j] - 'a' == l2) temp_text[j] = 1;
            else temp_text[j] = 0;
        }
        matchVal[l1][l2] = getMatch(temp_pattern, temp_text);
    }

    do {
        ct.assign(nn, 0);
        rep(i,0,5) {
            vi& temp_ct = matchVal[i][s[i] - 'a'];
            rep(j,0,text.size()) {
                ct[j] += temp_ct[j];
            }
        }
        rep(j,0,text.size()) {
            ans = min(ans, (int)text.size() - ct[j]);
        }
    } while(next_permutation(all(s)));
    cout << ans << "\n";

}
    
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                DON'T MAKE CHANGES AFTER THIS LINE!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
int32_t main()
{
    SPEED
    solve();
    return 0;
}