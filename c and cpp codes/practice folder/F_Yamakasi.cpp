#include<bits/stdc++.h>
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
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n,s,x;
        cin >> n >> s >> x;
        vector<int> a(n);
        for(auto&e:a) cin >>e;
        vector<int> pre(n + 1);
        partial_sum(a.begin(), a.end(), pre.begin() + 1);
        map<int,vector<int>> occ;
        for(int i=0;i<=n;++i) occ[pre[i]].push_back(i);

        int ans = 0;

        int fstI = -1;
        for(int i=n-1;i>=0;--i) if(a[i] == x) fstI = i;
        int lef = fstI;
        while(lef >= 0 && a[lef] <= x) --lef; ++ lef;
        int rit = lef;
        if(fstI != -1)
        for(int i=fstI;i<n;++i) {
            int tgt = pre[i + 1] - s;
            if(a[i] > x) {lef = i + 1; continue;}
            if(a[i] == x) {rit = i;}
            if(occ.contains(tgt)); else continue;
            debug(lef, occ[tgt]);
            int cnt = upper_bound(occ[tgt].begin(), occ[tgt].end(), rit) - lower_bound(occ[tgt].begin(), occ[tgt].end(), lef);
            ans += max(0ll, cnt);
        }
        cout << ans << endl;
    }
}