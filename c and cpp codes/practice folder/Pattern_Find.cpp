#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
#define int long long
#define cout(x) x?cout<<"Yes"<<endl:cout<<"Not Found"

int ppow(int pow)
{
    static int power[(int)1e6 + 1];
    if(power[0] == 0)
    {
        power[0] = 1;
        for(int i=1;i<=1e6;i++)
        {
            power[i] = power[i-1] * 31 % M;
        }
    }
    return power[pow];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(;T--;)
    {
        string big,sub;
        cin>>big>>sub;

        vector<int> hash(big.size());
        hash[0] = big[0] - 'a' + 1;
        for(int i=1;i<big.size();i++)
        {
            hash[i] = (hash[i-1] + ppow(i) *( big[i] - 'a' + 1) % M);
            hash[i] %= M;
        }        
        int m = M;

        int tgthash = sub[0] - 'a' + 1;
        for(int i=1;i<sub.size();i++)
        {
            tgthash += ppow(i) * (sub[i] - 'a' + 1) % M;
            tgthash %=m;
        }
        vector<int> ans;

        for(int i=0;i+sub.size() - 1 < big.size();i++)
        {
            int j = i + sub.size() - 1;
            int hashval = hash[j] - (i==0?0:hash[i-1]);
            if(hashval<0)hashval += m;
            if(hashval == tgthash * ppow(i)%m)ans.push_back(i+1);
        }
        if(ans.size())
        cout<<ans.size()<<endl;
        else cout(false);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}