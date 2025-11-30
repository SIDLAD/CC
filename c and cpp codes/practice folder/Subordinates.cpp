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
    LLONG_MAX/2
#else
    INT_MAX/2
#endif
;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int x;
constexpr int MAXN = (int)2e5 + 1;
constexpr int concurrency = 4;
vector<int> edges[MAXN];
int parent[MAXN];
int subtree[MAXN];

int indegree[MAXN];
mutex indegreeMu[MAXN];

bool stopFlag = false;

condition_variable qNotEmpty;
latch* processingComplete;

queue<int> q;
mutex qMu;

void initQ(int i) {
    for(int node= i * n / concurrency + 1; node <= (i + 1) * n / concurrency; ++node) {
        if(edges[node].size() == 0) {
            lock_guard lock(qMu);
            q.push(node);
        }
    }
}

void processQ() {
    int node;
    unique_lock lock(qMu);
    while(!stopFlag) {
        if(q.empty()) {
            qNotEmpty.wait(lock, []() {
                return q.size() || stopFlag;
            });
        }
        if(stopFlag)
            return;
        node = q.front();
        q.pop();
        lock.unlock();

        subtree[node] = 1;
        for(auto child: edges[node]) {
            subtree[node] += subtree[child];
        }
        processingComplete->count_down();
        if(parent[node])
        {
            lock_guard lock(indegreeMu[parent[node]]);
            --indegree[parent[node]];
        }
        if(parent[node] && !indegree[parent[node]]) {
            lock_guard lock(qMu);
            q.push(parent[node]);
            qNotEmpty.notify_one();
        }

        lock.lock();
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    for(int i=2;i<=n;++i) {
        cin >> x;
        edges[x].push_back(i);
        parent[i] = x;
        indegree[x]++;
    }

    vector<thread> threads(concurrency);
    for(int i=0;i<concurrency;++i) {
        threads[i] = thread{initQ, i};
    }
    for(auto& t: threads) t.join();

    processingComplete = new latch{n};
    for(int i=0;i<concurrency;++i) {
        thread{processQ}.detach();
    }
    processingComplete->wait();
    {
        lock_guard lock(qMu);
        stopFlag = true;
        qNotEmpty.notify_all();
    }
    for(int i=1;i<=n;++i) {
        cout << subtree[i] - 1 << " ";
    }
    delete processingComplete;
}