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

map<string,int> mp;
vector<vector<int>> compNumber;
int totlen = 0;

int getstringid(string a)
{
    string ans = "";
    for(int i=0;i<a.size();i++)
    {
        if(a[i] >= 'a' and a[i] <= 'z')
        {
            ans.push_back(a[i]);
        }
        else if(a[i] >= 'A' and a[i] <= 'Z')
        {
            ans.push_back(tolower(a[i]));
        }
    }
    debug(ans);
    if(ans.size() == 0)return -1;
    if(mp.count(ans));
    else 
    {
        mp[ans] = totlen++;
    }
    return mp[ans];
}

int currComp = -1;
int n, m;

int getanswer(vector<vector<int>>& boxes)
{
    n = boxes.size();
    int mn = INF;
    assert(n >= 3);
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    for(int k=j+1;k<n;k++)
    {
        set<int> st;
        for(auto ele: boxes[i])st.insert(ele);
        for(auto ele: boxes[j])st.insert(ele);
        for(auto ele: boxes[k])st.insert(ele);


        mn = min(mn,(int)st.size());
    }
    return mn;
}


void solve() {
    vector<string> a;
    string s;
    while(getline(cin, s)) {
        a.push_back(s);
        if(s.back() == '+' && a.size() != 1) break;
    }
    // while((cin >> c)) {
    //     string s = "";
    //     while(cin >> c) {
    //         if(c == '\n') {
    //             s.pop_back();
    //             a.push_back(s);
    //             s = "";
    //         } 
    //         else {
    //             s.push_back(c);
    //         }
    //     }
    // }
    n = a.size();
    m = a[0].size();
    debug(n, m);
    for(int i=0;i<a.size();i++)
    {
        debug(a[i]);
    }
    compNumber.assign(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    range(i,1,n - 1) {
        range(j,1,m - 1) {
            if(visited[i][j]) continue;
            if(a[i][j] == '+') {
                debug(i,j);
                visited[i][j] = true;
                compNumber[i][j] = ++currComp;
                int currI = i, currJ = j + 1;
                while(currJ < m && a[currI][currJ] != '+') {
                    visited[currI][currJ] = true;
                    compNumber[currI][currJ] = currComp;
                    currJ++;
                }
                visited[currI][currJ] = true;

                currI++;
                while(currI < n && a[currI][currJ] != '+') {
                    visited[currI][currJ] = true;
                    compNumber[currI][currJ] = currComp;
                    currI++;
                }
                visited[currI][currJ] = true;

                currJ--;
                while(currJ >= 0 && a[currI][currJ] != '+') {
                    visited[currI][currJ] = true;
                    compNumber[currI][currJ] = currComp;
                    currJ--;
                }
                visited[currI][currJ] = true;

                currI--;
                while(currI >= 0 && a[currI][currJ] != '+') {
                    visited[currI][currJ] = true;
                    compNumber[currI][currJ] = currComp;
                    currI--;
                }
                visited[currI][currJ] = true;

            }
            
        }
    }
    vector<vector<int>> blocks;
    debug(currComp);
    blocks.resize(currComp + 1);
    //.
    range(i,1,n-1) {
        string temp = "";
        bool start = false;
        range(j,1,m-1) {
            if(a[i][j] == '|') {
                if(start and temp.size() > 0) {
                    int _tmp = getstringid(temp);
                    if(_tmp != -1)
                    blocks[compNumber[i][j]].push_back(_tmp);
                    temp = "";
                }
                start ^= true;
            }
            else {
                if(start) {
                    temp.push_back(a[i][j]);
                }
            }
        }
    }
    debug(blocks);

    cout<<getanswer(blocks)<<endl;
}



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}