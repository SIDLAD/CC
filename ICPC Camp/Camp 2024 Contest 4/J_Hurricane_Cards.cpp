#include <bits/stdc++.h>
const long double EPS = 1e-7;
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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int mapping(char x)
{
    if(x == 'A')return 1;
    if(x >= '2' and x <= '9')return x - '0';
    if(x == 'D')return 10;
    if(x == 'Q')return 11;
    if(x == 'J')return 12;
    if(x == 'K')return 13;
    assert(false);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<map<int,set<int>>> p(n);
    vector<vector<int>> freq(n,vector<int> (14));
    int turnskip = k - 1;
    int turn = k - 1;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(auto ch:s)
        {
            auto& prev = freq[i][mapping(ch)];
            if(prev != 0)
            {
                p[i][prev].erase(mapping(ch));
                if(p[i][prev].empty())p[i].erase(prev);
            }
            prev++;
            p[i][prev].insert(mapping(ch));
        }
        if(turnskip != i  and *max_element(all(freq[i])) == 4)
        {
            cout<<i + 1<<endl;
            return 0;
        }
    }
    bool r = false;
    while(true)
    {
        if(turnskip == turn)
        {
            if(!r)
            {
                r = true;
            }
            else
            {
            turnskip++;
            turnskip %= n;
            turn++;
            turn%=n;
            r = false;
            continue;
            }
        }
        int card = *((p[turn].begin())->second).begin();

        auto& prev = freq[turn][card];
        p[turn][prev].erase(card);
        if(p[turn][prev].empty())p[turn].erase(prev);
        prev--;
        if(prev!=0)
        {
            p[turn][prev].insert(card);
        }
        

        turn++;
        turn%=n;

        auto& prev2 = freq[turn][card];
        p[turn][prev2].erase(card);
        if(p[turn][prev2].empty())p[turn].erase(prev2);
        prev2++;
        p[turn][prev2].insert(card);
        if(prev2 == 4)
        {
            cout<<turn + 1<<endl;
            return 0;
        }
    }
    
}