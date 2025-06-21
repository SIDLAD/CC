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

vector<int> marked;
int a,b,c,d;

bool solve(vector<string>& words) {
    for(int i=0;i<words.size();i++) {
        auto& word = words[i];

        if(word.length() == 1) {
            if(word[0] == 'A') a--;
            else b--;
            if(min(a,b) < 0) return false;
            marked[i] = true;
        }

        if(word.length() % 2 == 0) {
            if(word[0] == 'A' and word.length() / 2 <= c) {
                c -= word.length() / 2;
                marked[i] = true;
            }
            if(word[0] == 'B' and word.length() / 2 <= d) {
                d -= word.length() / 2;
                marked[i] = true;
            }
        }
    }
    int cd = c + d;
    debug(a,b,c,d);
    debug(marked);
    for(int i=0;i<words.size();i++) {
        auto& word = words[i];
        if(!marked[i]) {
            int l = word.length();
            if(word.length() % 2) (word[0] == 'A' ? a-- : b--), l--;
            else l -= 2, a--, b--;
            debug(a,b);
            int q = min(cd, l/2);
            l -= q * 2;
            cd -= q;
            a -= l/2;
            b -= l/2;
            debug();
            if(min(a,b) < 0) return false;
        }
    }
    return true;
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
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int n = s.length();
        int act = 0, bct = 0;
        for(auto c : s) c == 'A' ? act++ : bct++;
        debug(act, bct);
        if(a + c + d != act and b + c + d != bct) {cout(false); continue;}
        debug(a,b,c,d);
        vector<string> words;
        int x = 0;
        for(int i=0;i<n-1;i++) {
            if(s[i] == s[i+1]) {
                words.push_back(s.substr(x,i+1 - x));
                x = i+1;
            }
        }
        words.push_back(s.substr(x,n - x));
        sort(all(words), [&](auto a, auto b){return a.length() < b.length();});
        debug(words);
        marked.assign(words.size(),0);
        cout(solve(words));
    }
}