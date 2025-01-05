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
#define cout(x) (x?cout<<"YES"<<endl:cout<<"NO"<<endl)
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'

const int INF =
#ifdef int
    LONG_LONG_MAX/2
#else
    INT_MAX/2
#endif
;

int getmaxput(int index, int n) // 1 indexed
{
    int leftdist = index;
    int rightdist = n - index + 1;
    int x = min(leftdist,rightdist);
    return x;
}

// int gettreelim(int d)
// {
//     int left = d + 1 >> 1;
//     int right = d - left;
//     return left*(left + 1)/2 + right* (right + 1)/2;
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    debug(getmaxput(2,10));
    int T;
    cin>>T;
    for(;T--;)
    {
        int n,d,l;
        cin>>n>>d>>l;
        

        d++;
        int rem = n;
        rem -= d;
        l -= 2;

        if(d == 2)
        {
            if(l!=0 or n != 2)
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<1<<" "<<2<<endl;
            continue;
        }

        if(l == 0)
        {
            if(d != n)
            {
                cout<<-1<<endl;
                continue;
            }
        }

        int bigguy = d + 1 >> 1;
        int llim = getmaxput(bigguy,d) - 1;

        debug(bigguy,llim);

        if(rem < l)
        {
            cout<<-1<<endl;
            continue;
        }

        if(rem > llim * l)
        {
            cout<<-1<<endl;
            continue;
        }

        for(int i=1;i<d;i++)
        {
            cout<<i<<" "<<i + 1<<endl;
        }

        int curnode = d + 1;
        vector<int> leaves(l,bigguy);
        
        int leafindex = 0;
        while(rem)
        {
            cout<<leaves[leafindex]<<" "<<curnode<<endl;
            leaves[leafindex] = curnode;
            curnode++;
            rem--;

            leafindex = (leafindex + 1) % l;
        }



        /*
        int nc = n;
        d++;
        vector<int> v(d + 1);
        int maxi = d + 1 >> 1;
        int mini = 2;
        int llim = getmaxput(maxi,n) - 1;
        bool check = true;
        debug(maxi,mini);
        if(d == 2)
        {
            if(l!=2 or n != 2)
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<1<<" "<<2<<endl;
            continue;
        }
        if(l == 2)
        {
            if(d != n)
            {
                cout<<-1<<endl;
                continue;
            }
            else goto printpart;
        }

        l -= 2;
        n -= d;
        debug(llim);
        if((n + llim - 1)/llim > l)
        {
            cout<<-1<<endl;
            continue;
        }
        if(n!=0)
        while(l < n)
        {
            n -= llim;
            v[maxi]++;
            if(n < 0)
            {
                n = 0;
                l--;
                break;
            }
            l--;
        }
        if(l > n)
        {
            cout<<-1<<endl;
            continue;
        }
        debug(l,n);
        n = nc - d;
        v[mini] += l;
        printpart:
        for(int i=1;i<d;i++)
        {
            cout<<i<<" "<<i + 1<<endl;
        }
        int cur = d + 1;
        debug(v);
        range(_,0,v[mini])
        {
            cout<<mini<<" "<<cur++<<endl;
            n--;
            debug(n);
        }
        debug();
        if(maxi!=mini)
        range(_,0,v[maxi])
        {
            debug(n);
            cout<<maxi<<" "<<cur<<endl;
            n--;
            debug(n);
            range(_,0,llim - 1)
            {
                if(n <= 0)goto outside;
                cout<<cur<<" "<<cur + 1<<endl;
                cur++;
                n--;
            }
            cur++;
        }
        outside:42;*/

        
    }
}