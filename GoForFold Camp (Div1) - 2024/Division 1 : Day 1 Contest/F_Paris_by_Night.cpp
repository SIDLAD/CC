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
#define PI (numbers::pi_v<double>)

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<double, double>, int>> a(n);
    for(int i = 0;i<n;i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    int ans = INF;
    for(int i =0;i<n;i++) {
        vector<pair<double, int>> temp;
        for(int j = 0;j<n;j++) {
            if(i == j)
            {
                continue;
            }
            temp.push_back({atan2((a[j].first.second - a[i].first.second), (a[j].first.first - a[i].first.first)), a[j].second});
        }
        sort(temp.begin(), temp.end());
        vector<double> tans, pref;
        for(int j = 0;j<temp.size();j++) {
            tans.push_back(temp[j].first);
            pref.push_back(temp[j].second);
        }
        partial_sum(all(pref),pref.begin());
        debug(i,tans,pref);
        for(int j = 0;j<n;j++) {
            if(i == j) continue;
            double ang1 = atan2((a[j].first.second - a[i].first.second), (a[j].first.first - a[i].first.first));
            double ang2;
            int tempAns1;
            int tempAns2;
            debug(i,j,ang1,ang2);
            if(ang1 > 0) {
                ang2 = ang1 - PI;
                int ind1 = lower_bound(tans.begin(), tans.end(), ang2) - tans.begin();
                int ind2 = upper_bound(tans.begin(), tans.end(), ang1) - tans.begin();
                tempAns1 = 0;
                if(ind2 > 0) tempAns1 += pref[ind2 - 1];
                if(ind1 > 0) tempAns1 -= pref[ind1 - 1];
                tempAns2 = pref.back() - tempAns1;
                tempAns1 -= a[j].second;
            }
            else {
                ang2 = ang1 + PI;
                int ind1 = lower_bound(tans.begin(), tans.end(), ang1) - tans.begin();
                int ind2 = upper_bound(tans.begin(), tans.end(), ang2) - tans.begin();
                tempAns1 = 0;
                if(ind2 > 0) tempAns1 += pref[ind2 - 1];
                if(ind1 > 0) tempAns1 -= pref[ind1 - 1];
                tempAns2 = pref.back() - tempAns1;
                tempAns1 -= a[j].second;
            }
            debug(i,j,tempAns1,tempAns2);
            ans = min(ans, abs(tempAns1 - tempAns2));
        }
            
    }
    cout << ans << "\n";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solve();
}4