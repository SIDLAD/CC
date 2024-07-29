#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        string a, b;
        cin>>a>>b;

        vector<array<int,26>> pre1(n), pre2(n);

        for(int i=0;i<n;i++)
        {
            pre1[i].fill(0);
            if(i!=0)pre1[i] = pre1[i-1];
            pre1[i][a[i] - 'a']++;

            pre2[i].fill(0);
            if(i!=0)pre2[i] = pre2[i-1];
            pre2[i][b[i] - 'a']++;
        }

        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;

            array<int,26> arr ={};
            for(int i=0;i<26;i++)
            {
                arr[i] = max(pre2[r-1][i] - (l == 1?0:pre2[l-2][i]) - pre1[r-1][i] + (l == 1?0:pre1[l-2][i]),0);
            }
            cout<<accumulate(arr.begin(),arr.end(),0ll)<<endl;
        }
    }
}