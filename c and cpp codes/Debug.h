//For debugging purposes
#include <bits/stdc++.h>
#define DEBUG_MACRO
using namespace std;

#ifdef MINT_MACRO
template<int MOD>
void __print(Mint<MOD> x) {cerr << x;}
#endif
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "1" : "0");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (const auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(const T &t,const V&... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template <typename T, typename... V>
const T& _dbg(const char *s, const T &t, const V&... v) {cerr << "[" << s << "] = ["; _print(t,v...);return t;}
template <typename T, typename... V>
T& _dbg(const char *s, T &t, V&... v) {cerr << "[" << s << "] = ["; _print(t,v...);return t;}
void _dbg(const char *s) {cerr << "\n";};

#define debug(x...) (_dbg(#x __VA_OPT__(,) x))