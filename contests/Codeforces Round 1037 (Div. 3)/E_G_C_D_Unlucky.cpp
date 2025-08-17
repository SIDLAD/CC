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
#define sz(x) (int)(x).size()
#define endl '\n' //comment out for interactive problems
#define cout(x) cout << ((x) ? "YES" : "NO") << endl
#define rep(it, start, end) for (auto it = start; it != end; ++it)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool initialCheck(vi& v) {
    for(int i=1;i<sz(v);++i) {
        if(v[i-1] % v[i] != 0) return false;
    }
    return true;
}

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

ull pollard(ull n) {
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	auto f = [&](ull x) { return modmul(x, x, n) + i; };
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    assert(n != 0);
	if (n == 1) return {};
	if (isPrime(n)) return {n};
	ull x = pollard(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), all(r));
	return l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T = 1;
    cin >> T;
    
    for(int TT = 1; TT <= T; ++TT)
    {
        int n;
        cin >> n;
        vi p(n), s(n);
        arrput(p) arrput(s);
        if(p.back() != s.front()) {cout(false); continue;}
        vi sc = s; reverse(all(sc));
        if(!initialCheck(p) || !initialCheck(sc)) {cout(false); continue;}

        bool ch = true;

        for(int i=0;i<n;i++) {
            debug(i);
            if(i && p[i] != p[i-1]) {
                debug(p[i - 1] / p[i]);
                auto facts = factor(p[i - 1] / p[i]);
                sort(all(facts));
                facts.erase(unique(all(facts)), facts.end());
                debug(facts);

                for(auto f: facts) {
                    int pc = p[i];
                    int sc = s[i];
                    int cnt = 0;
                    while(pc % f == 0) pc /= f, cnt++;
                    while(sc % f == 0) sc /= f, cnt--;
                    if(cnt < 0) {ch = false; goto outer;}
                }
            }
            if(i != n- 1 && s[i] != s[i + 1]) {
                auto facts = factor(s[i + 1]/ s[i]);
                sort(all(facts));
                facts.erase(unique(all(facts)), facts.end());
                debug(s[i + 1] / s[i]);
                debug(facts);

                for(auto f: facts) {
                    int pc = p[i];
                    int sc = s[i];
                    int cnt = 0;
                    while(pc % f == 0) pc /= f, cnt++;
                    while(sc % f == 0) sc /= f, cnt--;
                    debug(p,s);
                    debug(f, i, p[i], s[i], cnt);
                    if(cnt > 0) {ch = false; goto outer;}
                }
            }
        }
        outer: cout(ch);
        debug();
    }
}