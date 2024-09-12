#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX/2;
const long long int M = (long long int) 1e9 + 7;//998'244'353;
using namespace std;
//insert policy here

//insert mintcode here

#if defined (ONLINE_JUDGE) || !__has_include (</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
    void _exe() {}
    template <typename T, typename... V>
    const T& _exe(const T &t,const V&... v) {return t;}
    template <typename T, typename... V>
    T& _exe(T &t,V&... v) {return t;}
    
    #define debug(x...) (_exe(x))
    
    class CNothing {};

    template <typename T>
    const CNothing& operator<<(const CNothing& proxy, const T&)
    {
        return proxy;
    }

    const CNothing& operator<<(const CNothing& proxy, std::ostream& (*)(std::ostream&))
    {
        return proxy;
    }
    CNothing cnothing;
    #define cerr cnothing
#else
    #include </home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>
#endif

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define endl "\n" //comment out for interactive problems
// #define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

int p1power(int pow, int p1=31, int m=M)
{
    static int power[1501];
    if(power[1] == 0){power[0] = 1;
    for(int i=1;i<=1500;i++)
    {
        power[i] = power[i-1] * p1 % m;
        assert(power[i] >= 0);
    }
    }
    return (power[pow]);
}

int p2power(int pow, int p2=29, int m=M)
{
    static int power[1501];
    if(power[1] == 0){power[0] = 1;
    for(int i=1;i<=1500;i++)
    {
        power[i] = power[i-1] * p2 % m;
        assert(power[i] >= 0);

    }
    }
    return (power[pow]);
} 

struct pair_hash{
    size_t operator() (const pair<signed,signed> & pair) const{
        auto hash1 = (int) hash<signed>()(pair.first);
        auto hash2 = (int) hash<signed>{}(pair.second);
        return (hash1 << 32)|hash2;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    string aware;
    cin>>aware;
    int k;
    cin>>k;
    vector<pair<int,int>> hash(s.size());
    vector<int> badcount(s.size());
    badcount[0] = aware[s[0] - 'a'] == '0';
    hash[0].first = hash[0].second = s[0] - 'a' + 1;
    for(int i=1;i<s.size();i++)
    {
        hash[i].first = hash[i-1].first + (s[i] -'a' + 1)*p1power(i) % M;
        hash[i].first %= M;
        hash[i].second = hash[i-1].second + (s[i] -'a' + 1)*p2power(i) % M;
        hash[i].second %= M;
        assert(not (hash[i].first < 0 or hash[i].second < 0));
        badcount[i] = (aware[s[i]-'a'] == '0');
    }
    partial_sum(all(badcount),badcount.begin());
    debug(hash);
    int ans =0 ;
    for(int l=0;l<s.size();l++)
    {
        unordered_set<pair<signed,signed>,pair_hash> st;
        
        for(int i = 0;i + l <s.size();i++)
        {

            int j = i+l;
            if(badcount[j] - ((i == 0)?0:badcount[i-1]) > k) continue;
            int hashval1 = hash[j].first - ((i==0)?0:hash[i-1].first);
            int hashval2 = hash[j].second - ((i==0)?0:hash[i-1].second);

            if(hashval1 < 0)hashval1 += M;
            if(hashval2 < 0)hashval2 += M;
            hashval1 = hashval1 * p1power(s.size() - i);
            hashval2 = hashval2 * p2power(s.size() - i);
            hashval1 %= M;
            hashval2 %= M;
            st.insert({hashval1,hashval2});
        }
        ans += st.size();
    }

    cout<<ans<<endl;
}