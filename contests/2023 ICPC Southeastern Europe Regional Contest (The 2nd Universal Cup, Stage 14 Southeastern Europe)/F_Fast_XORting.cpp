#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
#define debug(x) cerr<<x<<endl

struct fenwick
{
    vector<long long> s;
    fenwick(int n): s(n){}
    void update(int pos , long long dif)
    {
        for(;pos < (int)s.size(); pos |= pos + 1)s[pos] += dif;
    }
    long long query(int pos)
    {
        long long res = 0;
        for(; pos > 0; pos &= pos - 1) res += s[pos - 1];
        return res;
    }
};

long long get_sw(vector<int>& v){
    vector<int> pos(n);
    for(int i=0;i<n;i++)
    {pos[v[i]] = i;}
    long long cnt = 0;
    fenwick ft(n);

    for(int i=0;i<n;i++)
    {
        cnt += ft.query(n) - ft.query(pos[i]);
        ft.update(pos[i],1);
    }

    return cnt;
}

void solve(){
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int bits = bit_width((unsigned)n);
    long long mn = get_sw(v);
    for(int b=0;b<bits - 1;b++)
    {
        vector<int> vc = v;
        for(int i=0;i<n;i++)
        {
            vc[i] ^= (1<<b);
        }
        if(get_sw(vc) < get_sw(v))v = vc;
    }
    
    cout<<min(mn,get_sw(v) + 1)<<endl;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}