#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int M = (long long int)1e9 + 7; // 998'244'353;
using namespace std;
// insert policy here

// insert mintcode here

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
#define arrPut(var)       \
  for (auto &inVar : var) \
  {                       \
    cin >> inVar;         \
  }
#define arrPrint(var)      \
  for (auto outVar : var)  \
  {                        \
    cout << outVar << ' '; \
  }                        \
  cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX / 2
#else
    INT_MAX / 2
#endif
    ;

int k, n;

struct Hash
{
  static const uint64_t md = (1LL << 61) - 1;
  static uint64_t step;
  static vector<uint64_t> pw;

  uint64_t addmod(uint64_t a, uint64_t b) const
  {
    a += b;
    if (a >= md)
      a -= md;
    return a;
  }

  uint64_t submod(uint64_t a, uint64_t b) const
  {
    a += md - b;
    if (a >= md)
      a -= md;
    return a;
  }

  uint64_t mulmod(uint64_t a, uint64_t b) const
  {
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret =
        (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & md) + (ret >> 61);
    ret = (ret & md) + (ret >> 61);
    return ret - 1;
  }

  void ensure_pw(int sz)
  {
    int cur = (int)pw.size();
    if (cur < sz)
    {
      pw.resize(sz);
      for (int i = cur; i < sz; i++)
      {
        pw[i] = mulmod(pw[i - 1], step);
      }
    }
  }

  vector<uint64_t> pref;
  int n;

  template <typename T>
  Hash(const T &s)
  {
    n = (int)s.size();
    ensure_pw(n + 1);
    pref.resize(n + 1);
    pref[0] = 1;
    for (int i = 0; i < n; i++)
    {
      pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
    }
  }

  inline uint64_t operator()(const int from, const int to) const
  {
    assert(0 <= from && from <= to && to <= n - 1);
    return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
  }
};
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
uint64_t Hash::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> Hash::pw = vector<uint64_t>(1, 1);

map<int, string> getstringfromhash;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(numeric_limits<double>::max_digits10);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  cin >> k >> n;

  vector<pair<int, int>> logs; // left side is winner

  for (int i = 1; i < (1 << k); i++)
  {
    string a, b;
    cin >> a;
    int ahash = Hash(a)(0, a.size() - 1);
    getstringfromhash[ahash] = a;
    string resl, resr, _;
    int resintl, resintr;
    cin >> resl >> _ >> resr;
    if (resl.find('(') != resl.npos)
    {
      resintl = stoi((resl.substr(resl.find('(') + 1, resl.size() - 1 - resl.find('(') - 1)));
      resintr = stoi((resr.substr(resr.find('(') + 1, resr.size() - 1 - resr.find('(') - 1)));
    }
    else
    {
      resintl = stoi(resl);
      resintr = stoi(resr);
    }

    cin >> b;
    int bhash = Hash(b)(0, b.size() - 1);
    getstringfromhash[bhash] = b;

    if (resintl > resintr)
      logs.push_back({ahash, bhash});
    else
      logs.push_back({bhash, ahash});
  }
  debug(getstringfromhash);
  map<int, int> wincount;
  map<int, int> lostto;

  for (auto [winner, loser] : logs)
  {
    wincount[loser] += 0;
    wincount[winner]++;
    lostto[loser] = winner;
  }

  vector<pair<int, int>> sortedwinners;
  for (auto pr : wincount)
  {
    sortedwinners.push_back({-pr.second, pr.first});
  }

  sort(all(sortedwinners));
  debug(sortedwinners);

  vector<int> finalarray((1ll << k) + 1);
  map<int, int> posmapping;

  for (auto [_, player] : sortedwinners)
  {
    // debug(getstringfromhash[player], lostto[player],wincount[player]);
    if (lostto.count(player) == 0)
    {
      finalarray[(1ll << k)] = player;
      posmapping[player] = (1ll << k);
    }
    else
    {
      int wincnt = wincount[player];
      int lostagainst = posmapping[lostto[player]];
      int arrpos = lostagainst - (1ll << wincnt);
      finalarray[arrpos] = player;
      posmapping[player] = arrpos;
    }
  }

  debug(posmapping);
  
  int N = 1LL <<k;
  auto solve = [&](auto self,int a, int b, int l = 1, int r = -1, int depth = -1)->int
  {
    if(depth == -1)depth = k;
      if(r == -1)r = N;
      int mid = l + r >> 1;
      if(a <= mid and b > mid)
      {
        return depth;
      }
      else if(a <= mid)return self(self,a,b,l,mid,depth - 1);
      else return self(self,a,b,mid + 1,r,depth -1);
  };

  range(i, 0, n)
  {
    string s1, s2;
    cin >> s1 >> s2;
    debug(s1, s2);
    int s1hash = Hash(s1)(0, s1.size() - 1);
    int s2hash = Hash(s2)(0, s2.size() - 1);
    debug(s1hash, s2hash);
    if (posmapping[s1hash] > posmapping[s2hash])
      swap(s1hash, s2hash);
    debug(posmapping[s1hash], posmapping[s2hash]);
    cout << solve(solve,posmapping[s1hash],posmapping[s2hash]) << endl;
  }
}