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
#define cout(x) x?cout<<"YES"<<endl:cout<<"NO"<<endl

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;


void solve(int n, int x, int y, char b, char g)
{
    bool check = false;

    for(int i=0;i<=n;)
    {
        //Case 1:
        {
            int rem = n - i;
            if((x + y - rem)%4 != 0)goto outer1;
            int islands = (x + y - rem)/4;
            if(islands < 0)goto outer1;
            int bc = x - 2*islands;
            int gc = y - 2*islands;
            if(bc < 2 * islands or gc < 2* islands)goto outer1;
            if(bc + gc != rem)goto outer1;
            if(islands == 0 and (bc!=0 or gc!=0))goto outer1;

            debug("case1",islands,bc,gc,rem,i,x,y);

            for(int j=0;j<i;j++)
            {
                cout<<(j&1?g:b);
            }

            for(int j=0;j<islands - 1;j++)
            {
                cout<<b<<b;
                bc-=2;

                cout<<g<<g;
                gc-=2;
            }

            assert(bc >= 0 and gc >=0);
            while(bc--)cout<<b;
            while(gc--)cout<<g;

            exit(0);
        }

        outer1:
        i++;
        y--;
        if(i > n or y < 0)break;

        //Case 2:
        {
            int rem = n - i;
            if((x + y - rem)%4 != 2)goto outer2;
            int islands = (x + y - rem - 2)/4;
            if(islands < 0)goto outer2;
            int bc = x - 2*islands - 2;
            int gc = y - 2*islands;
            if(bc < 2*islands or gc < 2*(islands + 1))goto outer2;
            if(bc + gc != rem)goto outer2;
            if(islands == 0 and bc != 0)goto outer2;

            debug("case2",islands,bc,gc,rem,i,x,y);

            for(int j=0;j<i;j++)
            {
                cout<<(j&1?g:b);
            }

            cout<<g<<g;
            gc-=2;
            
            for(int j=0;j<islands - 1;j++)
            {
                cout<<b<<b;
                bc-=2;

                cout<<g<<g;
                gc-=2;
            }

            assert(bc >= 0 and gc >=0);
            while(bc--)cout<<b;
            while(gc--)cout<<g;

            exit(0);
        }

        outer2:
        i++;
        x--;
        if(x < 0)break;
    }

    if(check)exit(0);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("boysgirls.in","r",stdin);
    freopen("boysgirls.out","w",stdout);
    int n,x,y;
    cin>>n>>x>>y;

    if(x == 0)
    {
        if(y!=n)
        {
            cout<<"Impossible"<<endl;
            exit(0);
        }

        for(int i=0;i<n;i++)cout<<'G';
        exit(0);
    }

    if(y == 0)
    {
        if(x!=n)
        {
            cout<<"Impossible"<<endl;
            exit(0);
        }
        for(int i=0;i<n;i++)cout<<'B';
        exit(0);
    }
    
    solve(n,x,y,'B','G');
    solve(n,y,x,'G','B');
    cout<<"Impossible"<<endl;
}