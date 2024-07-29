#include<bits/stdc++.h>

using namespace std;
int M = (int)1e9 + 7;
int main()
{
    #define int long long
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        vector<int> v(n+1);
        for(int i=0;i<n;i++){v[i + 1] = (s[i] == '1')?1:-1;}
        partial_sum(v.begin(),v.end(),v.begin());
        vector<int> w(2*n + 1, -1);
        int ans = 0;
        for(int i=0;i<=n;i++)
        {
            int fetch = w[v[i] + n];
            if(fetch == -1)w[v[i] + n] = i + 1;
            else
            {
                ans = (ans + (fetch*(n- i + 1))%M)%M;
                w[v[i] + n] += i+1;
            }
        }
        cout<<ans<<endl;
    }
}