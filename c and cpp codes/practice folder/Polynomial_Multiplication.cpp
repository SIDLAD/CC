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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

// using C = complex<double>;



// template<typename T>
// vector<C> FFT(vector<T>& x, bool rev = false) {
//     auto w0 = polar(1.0l, 2 * acosl(-1) / x.size() * (rev?-1:1));
//     C w = 1;
//     int n = x.size(); // 2 power
//     if(n == 1) return {C(x[0])};
//     vector<T> x1; for(int i=0;i<n;i+=2)x1.push_back(x[i]);
//     vector<T> x2; for(int i=1;i<n;i+=2)x2.push_back(x[i]);
//     auto f1 = FFT(x1, rev);
//     auto f2 = FFT(x2, rev);
//     vector<C> f(n);
//     for(int i=0;i<n/2;i++) {
//         f[i] = f1[i] + w * f2[i];
//         f[i + n/2] = f1[i] - w*f2[i];
//         w *= w0;
//     }
//     return f;
// }

// vector<int> getC(vector<int>& a, vector<int>& b) {
//     int N = 1ll << (64 - __builtin_clzll(2*a.size() - 1));
//     a.resize(N); b.resize(N);
//     auto fa = FFT(a), fb = FFT(b);
//     vector<C> fc(fa.size());
//     for(int i=0;i<N;i++) fc[i] = fa[i] * fb[i];
//     auto c = FFT(fc,true);
//     for(auto& e: c)e/=N;
//     vector<int> cc(N);
//     for(int i=0;i<N;i++) {
//         cc[i] = (c[i].real()) + (c[i].real() > 0 ? 0.5 : -0.5);
//     }
//     return cc;
// }

// using cd = complex<double>;
// const double PI = acos(-1);

// void fft(vector<cd> & a, bool invert) {
//     int n = a.size();
//     if (n == 1)
//         return;

//     vector<cd> a0(n / 2), a1(n / 2);
//     for (int i = 0; 2 * i < n; i++) {
//         a0[i] = a[2*i];
//         a1[i] = a[2*i+1];
//     }
//     fft(a0, invert);
//     fft(a1, invert);

//     double ang = 2 * PI / n * (invert ? -1 : 1);
//     cd w(1), wn(cos(ang), sin(ang));
//     for (int i = 0; 2 * i < n; i++) {
//         a[i] = a0[i] + w * a1[i];
//         a[i + n/2] = a0[i] - w * a1[i];
//         if (invert) {
//             a[i] /= 2;
//             a[i + n/2] /= 2;
//         }
//         w *= wn;
//     }
// }

using cd = complex<double>;
const double PI = acos(-1);

int reverse(int num, int lg_n) {
    int res = 0;
    for (int i = 0; i < lg_n; i++) {
        if (num & (1 << i))
            res |= 1 << (lg_n - 1 - i);
    }
    return res;
}

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)
        lg_n++;

    for (int i = 0; i < n; i++) {
        if (i < reverse(i, lg_n))
            swap(a[i], a[reverse(i, lg_n)]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
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
        int n;
        cin >> n;
        n++;
        vector<int> a(n), b(n);
        arrPut(a) arrPut(b)
        auto c = multiply(a,b);
        for(int i=0;i<2*n-1;i++)cout << c[i] << " ";
        cout<<endl;
    }
}