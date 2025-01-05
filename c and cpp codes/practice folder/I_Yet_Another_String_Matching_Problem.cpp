#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

vi conv(vi a, vi b)
{
    vd a1(all(a)),b1(all(b));
    auto res = conv(a1,b1);
    for(auto& ele: res)ele += (ele > 0 ? + 0.5 : - 0.5);
    return vi(all(res));
}

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
    int opcount = 0;
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        opcount ++;
		return true;
	}
};

int main()
{
    string s,t;
    cin>>s>>t;

    int n = s.length();
    int m = t.length();
    int anslen = n -m  +1;

    vector<UF> dsus(anslen,6);

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            char c1 = i + 'a';
            char c2 = j + 'a';
            cerr<<c1<<" "<<c2<<" "<<endl;

            vector<int> a(n);
            vector<int> b(m);

            for(int i=0;i<n;i++)if(s[i] == c1)a[i] = 1;
            for(int i=0;i<m;i++)if(t[i] == c2)b[i] = 1;
            reverse(all(b));
            auto res = conv(a,b);
            //shift is by m - 1;
            for(int k=0;k<anslen;k++)if(res[m - 1 + k] > 0)
            {
                dsus[k].join(i,j);
            }
        }
    }

    for(auto dsu: dsus)cout<<dsu.opcount<<" ";
    cout<<endl;
}