#include<bits/stdc++.h>
using namespace std;

#define POLICY_MACRO
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename... T>
using umap = gp_hash_table<T...,custom_hash>;  //use for integral datatypes
template<typename T>
using uset = gp_hash_table<T,null_type,custom_hash>;  //use for integral datatypes

template<typename T>
using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key, find_by_order

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

// #define umap unordered_map

umap<int, vector<pair<int,int>>> edges;
uset<long long> visited;
typedef long long ll;

void dfs(pair<int,int> node, pair<int,int> prev, vector<pair<int,int>>& o) {
    visited.insert((ll)(node.first * (ll)1e6 + node.second) * (ll)1e7 +  prev.first * (ll)1e6 + prev.second);
    visited.insert((ll)(prev.first * (ll)1e6 + prev.second) * (ll)1e7 + node.first * (ll)1e6 + node.second); 
    while(edges[node.first *1e6 + node.second].size()) {
        auto nxt = edges[node.first *1e6 + node.second].back();
        edges[node.first *1e6 + node.second].pop_back();
        if(visited.find((ll)(node.first * (ll)1e6 + node.second) * (ll)1e7 +  nxt.first * (ll)1e6 + nxt.second) == visited.end()) {
            dfs(nxt, node, o);
        }
    }
    o.emplace_back(node);
} 

signed main() {
    int t;
    cin >> t;
    int TT = 1;
    while(t--) {
        edges.clear();
        visited.clear();
        int n;
        cin >> n;
        vector<pair<int,int>> vp;
        vector<int> vVals, pVals;
        for(int i=0;i<n;i++) {
            int a,b;
            cin >> a >> b;
            vp.emplace_back(a,b);
            vVals.push_back(a), pVals.push_back(b);
        }
        sort(vVals.begin(), vVals.end()), sort(pVals.begin(), pVals.end());
        vVals.erase(unique(vVals.begin(), vVals.end()), vVals.end());
        pVals.erase(unique(pVals.begin(), pVals.end()), pVals.end());
        umap<int,int> mpV, mpP;
        for(int i=0;i<vVals.size();++i) mpV[vVals[i]] = i + n;
        for(int i=0;i<pVals.size();++i) mpP[pVals[i]] = i + n;
        for(int i=0;i<n;++i) {
            edges[0 *1e6 + i].emplace_back(1,i);
            edges[1 *1e6 + i].emplace_back(0,i);
            edges[0 *1e6 + i].emplace_back(0,mpV[vp[i].first]);
            edges[0 *1e6 + mpV[vp[i].first]].emplace_back(0, i);
            edges[1 *1e6 + i].emplace_back(1, mpP[vp[i].second]);
            edges[1 *1e6 + mpP[vp[i].second]].emplace_back(1,i);
        }

        vector<int> oddOrder;
        for(auto [el,v] : edges) {
            if(v.size() & 1) oddOrder.emplace_back(el);
        }
        assert(~oddOrder.size() & 1);
        if(oddOrder.size() > 2) {
            cout << "NO" << endl;
            continue;
        }


        pair<int,int> start = {0,0};
        if(oddOrder.size()) start = {oddOrder[0] / (int)1e6, oddOrder[0] % (int) 1e6};

        vector<pair<int,int>> validOrdering;
        dfs(start, start, validOrdering);
        bool started = false;

        vector<int> ans;
        if(validOrdering.size())
        for(int i=0;i<validOrdering.size() - 1;i+=3) {
            if(!started && validOrdering[i].second != validOrdering[i + 1].second) {i -=2; continue;}
            started = 1;
            assert(validOrdering[i].second == validOrdering[i + 1].second);
            assert(validOrdering[i].first != validOrdering[i+1].first);
            ans.push_back(validOrdering[i].second + 1);
        }
        
        if(ans.size() != n) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for(auto e: ans) cout << e << " ";
            cout << endl;
        }
    }
}