#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX
#define endl '\n'

signed main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin.tie(0),cout.tie(0);

        int n,k;
        cin>>n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];

        set<pair<int,int>> st;

        vector<int> ans(n);
        for(int i=0;i<k;i++)
        {
            st.insert({0,i + 1});
        }

        for(int i=0;i<n;i++)
        {
            if(v[i] == -1)
            {
                auto pr = *st.rbegin();
                st.erase(pr);
                ans[i] = pr.second;
                pr.first --;
                st.insert(pr);
            }
            else
            {
                auto pr = *st.begin();
                st.erase(pr);
                ans[i] = pr.second;
                pr.first ++;
                st.insert(pr);
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}