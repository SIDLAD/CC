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

int totcnt = 0;

int minsum(vector<int> a)
{
    int n = a.size();
    vector<vector<int>> pref(n + 1,vector<int>(totcnt,0));
    for(int k=1;k<=n;k++)
    {
        pref[k] = pref[k-1];
        pref[k][a[k-1]]++;
    }
    vector<int> sublim(totcnt);
    sublim = pref.back();
    for(auto& ele:sublim)ele--;
    int maxcut = 0;
    for(int k=1;k<=n;k++)
    {
        int ll = k - 1;
        int ul = n;
        while(ul - ll > 1)
        {
            int mid = ll + ul >> 1;
            vector<int> diff(totcnt);
            for(int x=0;x<totcnt;x++)
            {
                diff[x] = pref[mid][x] - pref[k-1][x];
            }
            bool check=true;
            for(int x=0;x<totcnt;x++)
            {
                if(diff[x] > sublim[x])
                {
                    check = false;
                    break;
                }
            }
            if(check)ll = mid;
            else ul = mid;
        }

        maxcut = max(maxcut,ll - k + 1);
    }

    return a.size() - maxcut;
}

vector<int> getvector(vector<int>& a, int i, int j)
{
    vector<int> ans;
    for(int x=i;x<j;x++)ans.push_back(a[x]);
    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    map<string,int> mapping;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(mapping.count(s));
        else mapping[s] = totcnt++;
        v[i] = mapping[s];
    }

    vector<pair<int,int>> prs; // j is exclusive

    for(int i=0;i<n;i++)
    {
        set<int> st;
        int j;
        for(j=i;j<n and st.size() < totcnt;j++)
        {
            st.insert(v[j]);
        }
        if(st.size() == totcnt)
        {
            prs.push_back({i,j});
        }
    }
    int mnans = INF;

    for(auto [i,j]:prs)
    {
        mnans = min(mnans,minsum(getvector(v,i,j)));
    }
    cout<<mnans<<endl;
}