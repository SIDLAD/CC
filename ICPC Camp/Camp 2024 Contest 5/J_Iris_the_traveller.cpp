#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(13,0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x-1]++;
    }

    vector<pair<int,int>> dp(1 << 13, {LONG_LONG_MAX,0});

    dp[0] = {0,0};

    for(int i = 1; i < 1 << 13; i++){
        for(int k = 0; k < 13; k++){
            if(i & (1 << k)){
                pair<int,int> p = dp[i ^ (1<<k)];
                int days = p.first; 
                int rem = p.second;
                if(rem >= a[k]){
                    rem -= a[k];
                }else{
                    days++;
                    rem = m-a[k];
                }

                if(dp[i].first > days or (dp[i].first == days && dp[i].second < rem)){
                    dp[i] = {days, rem};
                }
            }
        }
    }
    cout << dp[(1 << 13)-1].first << endl;
}