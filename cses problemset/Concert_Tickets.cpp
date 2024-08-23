#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    multiset<int> t;
    vector<int> p(m);
    int x;
    for(int i=0;i<n;i++)cin>>x,t.insert(x);
    for(int i=0;i<m;i++)cin>>p[i];
    for(int i=0;i<m;i++)
    {
        auto ind = t.upper_bound(p[i]);
        if(ind == t.begin()){cout<<-1<<endl;continue;}
        cout<< *(--ind) <<endl;
        t.erase(ind);
    }
}