#include <bits/stdc++.h>
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

constexpr int INF = LLONG_MAX >> 2;

signed main() {
	// your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> children(n + 1);
        vector<int> parent(n + 1, -1);
        vector<int> parentToMeLeaky(n + 1, 1);
        for(int i=2;i<=n;++i) {
            cin >> parent[i];
            children[parent[i]].push_back(i);
        }
        
        for(int i=2;i<=n;++i) cin >> parentToMeLeaky[i];
        
        vector<int> oriWater(n + 1);
        
        auto dfs = [&](auto self, int node = 1, int ori = -1) -> void {
            if(ori == -1) ori = k;
            oriWater[node] = ori;
            for(auto child: children[node]) {
                int lost = ori / parentToMeLeaky[child];
                self(self, child, ori - lost);
            }
        }; dfs(dfs);
        
        debug(oriWater);

        int ll = 0;
        int ul = k + 1;
        while(ul - ll > 1) {
            int mid = ll + ul >> 1;
            queue<int> considerNodes;
            vector<bool> originalNodes(n + 1);
            vector<int> requirementFromChild(n + 1, 0);
            int originalNodeCnt = 0;
            for(int i=2;i<=n;++i) if(children[i].size() == 0) {
                considerNodes.push(i);
                requirementFromChild[i] = mid;
                if(oriWater[i] < mid) {
                    originalNodes[i] = true;
                    ++originalNodeCnt;
                }
            }
            
            
            bool chk = originalNodeCnt == 0;
            
            vector<int> nodeIndCnt(n + 1, 0);
            
            while(considerNodes.size()) {
                auto node = considerNodes.front();
                considerNodes.pop();
                if(node == 1) break;
                
                int parentRequirement = parentToMeLeaky[node] == 1 || requirementFromChild[node] == INF ? INF :
                    requirementFromChild[node] < parentToMeLeaky[node] ? requirementFromChild[node] :
                    requirementFromChild[node] + 1 + (
                            requirementFromChild[node] - parentToMeLeaky[node]
                        ) / (parentToMeLeaky[node] - 1);
                        
                requirementFromChild[parent[node]] = max(requirementFromChild[parent[node]], parentRequirement);
                
                if(++nodeIndCnt[parent[node]] == children[parent[node]].size()) considerNodes.push(parent[node]);
            }
            
            debug(mid);
            debug(requirementFromChild);
            
            vector<int> tempImpChildCnt(n + 1, 0);
            
            auto getLCA = [&](auto self, int curNode = 1) -> int {
                tempImpChildCnt[curNode] = originalNodes[curNode];
                for(auto child: children[curNode]) {
                    auto ret = self(self, child);
                    if(ret) return ret;
                    tempImpChildCnt[curNode] += tempImpChildCnt[child];
                }
                if(tempImpChildCnt[curNode] == originalNodeCnt) return curNode;
                else return 0;
            };
            
            int startHere = getLCA(getLCA);

            debug(tempImpChildCnt);
            debug(startHere);
            debug();

            while(startHere != 1) {
                if(requirementFromChild[startHere] <= max(oriWater[startHere], oriWater[parent[startHere]]))
                    {
                        chk = true;
                        break;
                    }
                startHere = parent[startHere];
            }
            
            if(chk) ll = mid;
            else ul = mid;
        }
        
        cout << ll << endl;
    }
}