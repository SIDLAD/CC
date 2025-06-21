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

struct compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.second.first > b.second.first;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int x, k;
    cin >> x >> k;
    vector<vector<int>> lists(k);
    for(int i=0;i<k;i++) {
        int size;
        cin >> size;
        lists[i].resize(size);
        for(auto& ele:lists[i])cin >> ele;
    }

    vector<vector<pair<int,int>>> listreorder(k);
    for(int i=0;i<k;i++) {
        int cursum = 0;
        int curMin = 0;
        for(auto e: lists[i]) {
            cursum += e;
            if(cursum >= 0) {listreorder[i].emplace_back(-curMin, cursum); curMin = 0; cursum = 0; continue;}
            curMin = min(curMin, cursum);
        }
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pq;
    vector<int> ptrs(k);
    for(int i=0;i<k;i++) {
        if(ptrs[i] < listreorder[i].size()) {pq.push({i, listreorder[i][ptrs[i]++]});}
    }
    int curProfit = x;

    while(pq.size()) {
        auto [index, pr] = pq.top();
        pq.pop();
        if(pr.first > curProfit)break;
        curProfit += pr.second;
        if(ptrs[index] < listreorder[index].size()) {
            pq.push({index, listreorder[index][ptrs[index]++]});
        }
    }

    cout << curProfit << endl;
}