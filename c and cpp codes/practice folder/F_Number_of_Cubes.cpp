#include <bits/stdc++.h>
const long double EPS = 1e-10;
const long long int M = (long long int)998'244'353;
using namespace std;
// insert policy here

#define MINT_MACRO

template <int _MOD = M>
struct Mint
{
    int val;
    int MOD = _MOD;
    Mint(long long v = 0, int MOD = _MOD) : MOD(MOD)
    {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
    Mint &operator=(long long v)
    {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
        return *this;
    }
    static int mod_inv(int a, int m)
    {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0)
            q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    }
    explicit operator int() const { return val; }
    explicit operator bool() const { return val; }
    Mint &operator+=(const Mint &o)
    {
        val += o.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    Mint &operator-=(const Mint &o)
    {
        val -= o.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m)
    {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        unsigned x_high = x >> 32, x_low = (unsigned)x;
        unsigned quot, rem;
        asm("divl %4\n" : "=a"(quot), "=d"(rem) : "d"(x_high), "a"(x_low), "r"(m));
        return rem;
    }
    Mint &operator*=(const Mint &other)
    {
        val = fast_mod((uint64_t)val * other.val, MOD);
        return *this;
    }
    Mint &operator/=(const Mint &other) { return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    template <typename T>
    friend Mint operator+(const T &a, const Mint &b) { return Mint(a, b.MOD) += b; }
    template <typename T>
    friend Mint operator-(const T &a, const Mint &b) { return Mint(a, b.MOD) -= b; }
    template <typename T>
    friend Mint operator*(const T &a, const Mint &b) { return Mint(a, b.MOD) *= b; }
    template <typename T>
    friend Mint operator/(const T &a, const Mint &b) { return Mint(a, b.MOD) /= b; }
    Mint &operator++()
    {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint &operator--()
    {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t)
    {
        Mint before = *this;
        ++*this;
        return before;
    }
    Mint operator--(int32_t)
    {
        Mint before = *this;
        --*this;
        return before;
    }
    Mint operator-() const { return val == 0 ? 0 : MOD - val; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const { return mod_inv(val, MOD); }
    Mint operator[](long long p)
    {
        assert(p >= 0);
        Mint a = *this, res(1, this->MOD);
        while (p > 0)
        {
            if (p & 1)
                res *= a;
            a *= a, p >>= 1;
        }
        return res;
    }
    friend ostream &operator<<(ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream &operator>>(istream &stream, Mint &m) { return stream >> m.val; }
};

using mint = Mint<>;

// insert randnum here

#if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
void _exe() {}
template <typename T, typename... V>
const T &_exe(const T &t, const V &...v) { return t; }
template <typename T, typename... V>
T &_exe(T &t, V &...v) { return t; }
#define debug(x...) (_exe(x))

class CNothing
{
} cnothing;
template <typename T>
const CNothing &operator<<(const CNothing &proxy, const T &) { return proxy; }
const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &)) { return proxy; }
#define cerr cnothing
#else
#include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define endl '\n' // comment out for interactive problems
#define cout(x) (x ? cout << "YES" << endl : cout << "NO" << endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var)         \
    for (auto &inVar : var) \
    {                       \
        cin >> inVar;       \
    }
#define arrPrint(var)          \
    for (auto outVar : var)    \
    {                          \
        cout << outVar << ' '; \
    }                          \
    cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
    ;

vector<int> getdivisors(int a)
{
    vector<int> v;
    for (int i = 1; i * i <= a; i++)
        if (a % i == 0)
        {
            v.push_back(i);
            if (i * i != a)
                v.push_back(a / i);
        }
    return v;
}

mint factorial(int n)
{
    static mint fact[(int)3e6 + 1];
    if (fact[0] == 0)
    {
        fact[0] = 1;
        for (int i = 1; i <= 3e6; i++)
        {
            fact[i] = i * fact[i - 1];
        }
    }

    return fact[n];
}
mint factorialinv(int n)
{
    static mint rfact[(int)3e6 + 1];
    if (rfact[0] == 0)
    {
        for (int i = 0; i <= 3e6; i++)
        {
            rfact[i] = factorial(i).inv();
        }
    }
    return rfact[n];
}

mint getmultinomial(vector<int> &v, int div = 1)
{
    mint ans = 1;
    int tot = 0;
    for (int i = 0; i < v.size(); i++)
    {
        assert(v[i] % div == 0);
        ans *= factorialinv(v[i] / div);
        tot += v[i] / div;
    }
    ans *= factorial(tot);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    vector<int> phi((int)3e6 + 1);
    iota(all(phi), 0ll);
    for (int i = 2; i <= (int)3e6; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= (int)3e6; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b, c, k;
        cin >> a >> b >> c >> k;

        vector<int> v(k);
        arrPut(v);

        int g = 0;
        for (auto ele : v)
            g = gcd(g, ele);

        auto divsa = getdivisors(a), divsb = getdivisors(b), divsc = getdivisors(c);

        int symcnt = a * b * c;

        map<int, int> freq;
        for (auto ax : divsa)
            for (auto bx : divsb)
                for (auto cx : divsc)
                {
                    int cnt = phi[ax] * phi[bx] * phi[cx];
                    int l = lcm(ax, lcm(bx, cx));
                    if (g % l == 0)
                        freq[l] += cnt;
                }

        mint numerator = 0;
        for (auto [ele, f] : freq)
        {
            numerator += f * getmultinomial(v, ele);
        }

        cout << numerator / symcnt << endl;
    }
}