#include<bits/stdc++.h>
using namespace std;
#define int long long


// map<pair<int,int>,int> mp;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int g = gcd(a,b);
        a /= g;
        b /= g;
        
        queue<array<int,3>> q;
        q.push({a,b,0});
        int ans = -1;

        while(q.size())
        {
            auto [a,b,cnt] = q.front();
            q.pop();
            if(a == 0 and b == 0)
            {
                ans = cnt;
                break;
            }
            if(a != 0)
            {
                int ac = a;
                int bc = b;
                ac--;
                int g = gcd(ac,bc);
                if(g != 0)
                {
                    ac /= g;
                    bc /= g;
                }
                if(ac > bc)swap(ac,bc);
                q.push({ac,bc,cnt + 1});
            }
            if(b!=0)
            {
                int ac = a;
                int bc = b;
                bc--;
                int g = gcd(ac,bc);
                if(g != 0)
                {
                    ac /= g;
                    bc /= g;
                }
                if(ac > bc)swap(ac,bc);
                q.push({ac,bc,cnt + 1}); 
            }
        }
        cout<<ans<<endl;
    }
}