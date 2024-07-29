#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];

        int ll = -1;
        int ul = *max_element(a.begin(),a.end());

        while(ul -ll > 1)
        {
            int tot = 0;
            int mid = ll + ul>>1;
            bool check =true;
            for(int i=0;i<n;i++)
            {
                tot += max(0ll,(int) ceill((a[i] - mid) * 1.0 / b[i]));
                if(tot > k)
                {
                    check = false;
                    break;
                }
            }
            if(check)
            {
                ul = mid;
            }
            else ll = mid;
        }
        cerr<<ll<<" "<<ul<<endl;
        int ans= 0;
        int totunits = 0 ;
        for(int i=0;i<n;i++)
        {
            if(ul > a[i])continue;
            int units = (int) ceill((a[i] - ul)*1.0/b[i]);
            totunits += units;
            cerr<<units<<endl;
            int ap = units * a[i] - units*(units- 1) / 2 * b[i];
            ans += ap;
        }

        if(totunits < k)
        {
            ans += -(totunits - k) * ul;
        }
        cout<<ans<<endl;
    }
}