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
        cin>>n;
        vector<int> v(n);
        arrPut(v);
        vector<int> fin(n);
        arrPut(fin);
        map<int,int> mp;
        for(int i=0;i<n;i++)mp[v[i]] = i;

        vector<pair<int,int>> answer;

        auto swapper = [&](int i, int j){
            mp[v[i]] = j,mp[v[j]] = i;
            swap(v[i],v[j]);
            answer.emplace_back(i,j);
        };
        for(int i = 0;i < n;i ++){
            int cur = fin[i];
            int curido = mp[cur];

            vector<int> st;
            for(int j=curido - 1;j>=i;j--){
                if(v[j] <= v[curido])continue;

                while(st.size() and v[st.back()] > v[j])st.pop_back();
                st.push_back(j);
            }
            reverse(all(st));
            while(st.size()){
                swapper(st.back(),curido);
                curido = st.back();
                st.pop_back();
            }
            if(v[i] != fin[i]){
                cout<<-1<<endl;
                goto skipper;
            }
        }
        
        cout<<answer.size()<<endl;
        for(auto [f,s]: answer){
            cout<<f + 1<<" "<<s + 1<<endl;
        }

        skipper:42;
    }
}