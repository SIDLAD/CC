#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    map<int,int> dp;
    int mx = 0;
    int prevmx;
    int prev = -1;
    for(auto [ele,f]: mp)
    {
        assert(ele > prev);
        prev = ele;
        if(dp.empty() or dp.lower_bound(ele - 1) == dp.begin())
        {
            if(dp.empty())
            dp[ele] = (ele*f);
            else dp[ele] = ele*f;
            dp[ele] = max(dp[ele],(--dp.find(ele))->second);
        }

        mx = max(mx,dp[ele]);
    }
    cout<<mx<<endl;
}