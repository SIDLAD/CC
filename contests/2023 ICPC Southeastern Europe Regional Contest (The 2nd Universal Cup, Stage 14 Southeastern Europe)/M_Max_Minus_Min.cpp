#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX

int getans(vector<int>& v)
{
    int n = v.size();
    int mn = *min_element(v.begin(),v.end());
    int mx = *max_element(v.begin(),v.end()); 

    int ll,ul;
    ll = mn - 1; // will not work
    ul = mx; // will def work
    while(ul - ll > 1)
    {
        int mid = ll + ul >> 1;
        //=>range is mn to mid;
        vector<pair<int,int>> ranges;
        for(int i=0;i<n;i++)
        {
            int up = mid - v[i];
            int down = mn - v[i];
            ranges.push_back({down,up});
        }
        int lefti =  n;
        int righti = -1;
        for(int i=0;i<n;i++)
        {
            if(ranges[i].first <= 0 and ranges[i].second >= 0);
            else
            {
                lefti = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(ranges[i].first <=0 and ranges[i].second >= 0);
            else
            {
                righti = i;
                break;
            }
        }
        bool check = true;
        pair<int,int> curposrange = {-INF,INF};
        for(int i = lefti;i<=righti;i++)
        {
            curposrange.first = max(curposrange.first,ranges[i].first);
            curposrange.second = min(curposrange.second,ranges[i].second);
        }
        if(curposrange.first <= curposrange.second);
        else check = false;

        if(check) ul = mid;
        else ll = mid;
    }
    assert(ul >= mn);
    return ul - mn;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin.tie(0),cout.tie(0);

        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        
        int mn = *min_element(v.begin(),v.end());
        int mx = *max_element(v.begin(),v.end());
        int ans = mx - mn;
        ans = min(ans,getans(v));
        for(auto& ele:v)ele *= -1;
        ans = min(ans,getans(v));
        cout<<ans<<endl;
    }
}