#include<bits/stdc++.h>
using namespace std;

int main()
{
    #define int long long
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int ans = 0;
        for(int a = 1;a<=x-2;a++)
        {
            int ub = n/a;
            for(int b=1;b<=ub;b++)
            {
                if(a + b > x - 1)break;
                int ll = 0;
                int ul = x;
                while(ul-ll>1)
                {
                    int c = ll + ul >> 1;
                    bool check1 = (a + b + c) <= x;
                    bool check2 = (a*b + b*c + c*a) <= n;
                    if(check1 and check2)
                    {
                        ll = c;
                    }
                    else ul = c;
                }

                ans += ll;
            }
        }
        cout<<ans<<endl;
    }
}