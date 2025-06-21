#include <bits/stdc++.h>
const long double EPS = 1e-7;
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

struct TestResult {
    string testName, result, unit, flag;
    TestResult(string testName, string result, string unit, string flag): testName(testName), result(result), unit(unit), flag(flag) {}
};

struct Patient{
    string name;
    vector<TestResult*> results;

    Patient(string name): name(name) {}

    void addResult(TestResult* tr) {
        results.push_back(tr);
    }
};

struct Test1{
    string name;
    string unit;
    int lo, hi;
    int op;

    void calcOp(string s) {
        if(s[0] == ')' || s[0] == '(' || s[0] == '[' || s[0] == ']' || find(s.begin(), s.end(), '~') != s.end()) {

        }
        else {
            string num = "";
            range(i,0,s.size()) {
                if(s[i] >= '0' && s[i] <= '9') num.push_back(s[i]);
            }
            int num1 = stoi(num);
            if(s[0] == '<' && s[1] == '=') {
                op = 1;
                hi = num1;
            }
            else if(s[0] == '<') {
                op = 2;
                hi = num1;
            }
            else if(s[0] == '>' && s[1] == '=') {
                op = 3;
                lo = num1;
            }
            else if(s[0] == '>') {
                op = 4;
                lo = num1;
            }
        }
    }

    string getDisease(int res) {

    }

}

void solve() {
    string store;
    TestResult* newRes;
    Test1* newTest1;
    int ct = 0;
    unordered_set<string> diffDis;
    while((cin >> store)) {
        if(store[0] == '-') {

        }
        else if(store[0] == '=') {
            break;
        }
    }
    while(cin >> store) {
        string patName;
        cin >> patName;
        while(cin >> store) {
            if(store[0] == '=') {
                break;
            }
            string testName, testR;
            string temp = "";
            int n1 = store.size();
            int currI = 0;
            while(currI < n1) {
                temp.push_back(store[currI++]);
                if(diffDis.find(temp) == diffDis.end()) continue;
                testName = temp;
                break;
            }
            while(currI < n1 && store[currI] == ' ') currI++;
            temp = "";
            while(currI < n1) temp.push_back(store[currI++]);
            testR = temp;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}