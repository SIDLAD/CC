#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    bitset<40> b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<40;j++)
        {
            if(v[i] & (1ll<<j))
            {
                b[j] = 1;
            }
        }
    }
    int x = b.count();
    cout<<(1ll<<x)<<endl;
}