#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

#define MINT_MACRO

template <int _MOD = 998244353>
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

const int INF = LONG_LONG_MAX >> 2;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i].first, a[i].second = i;
        for (int i = 0; i < n; i++)
            cin >> b[i].first, b[i].second = i;

        sort(all(a)), sort(all(b));


        map<int, int> mappinga, mappingb;
        for (int i = 0; i < n; i++)
        {
            mappinga[a[i].second] = i;
            mappingb[b[i].second] = i;
        }

        mint P = 1;
        for (int i = 0; i < n; i++){
            P *= min(a[i].first, b[i].first);
        }

        cout << P << " ";

        auto swapper = [&](int i, int j, vector<pair<int,int>>& a, vector<pair<int,int>>& b, map<int,int>& mappinga){
            assert(i <= j);
            assert(a[i].first == a[j].first);

            P /= min(a[i].first,b[i].first);
            if(i != j)
            P /= min(a[j].first,b[j].first);

            a[i].first ++ ;
            if(i != j);
            swap(a[i],a[j]);
            mappinga[a[i].second] = i;
            mappinga[a[j].second] = j;
            
            P *= min(a[i].first,b[i].first);
            if(i != j)
            P *= min(a[j].first,b[j].first);
        };
        
        while (q--){
            int o, x;
            cin >> o >> x;
            x --;
            if(o == 1)
            x = mappinga[x];
            else
            x = mappingb[x];
            cerr<<endl;
            cerr<<x<<endl;
            if(o == 1){
                int ll = x;
                int ul = n;
                while(ul - ll > 1){
                    int mid = ll + ul >> 1;
                    if(a[mid].first == a[x].first) ll = mid;
                    else ul = mid;
                }
                swapper(x,ll,a,b,mappinga);
            }
            if(o == 2){
                int ll = x;
                int ul = n;
                while(ul - ll > 1){
                    int mid = ll + ul >> 1;
                    if(b[mid].first == b[x].first) ll = mid;
                    else ul = mid;
                }
                swapper(x,ll,b,a,mappingb);
            }

            cout << P << " ";
        }
        cout << endl;
    }
}