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

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,k,x;
        cin >> n >> k >> x;
        vector<long long> v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        long long tot = accumulate(v.begin(),v.end(),0ll);

        long long ans = 0;
        ans += (x - 1)/tot * n;
        x -= ans/n * tot;
        while(x > v.back()) ++ans, x -= v.back(), assert(v.size()), v.pop_back();
        ans = max(k * n - ans, 0ll);
        cout << ans << endl;
    }
}