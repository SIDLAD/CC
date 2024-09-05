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
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl

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
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        if(b>c)swap(b,c);
        if(a>b)swap(a,b);
        int min_ans = INF;
        int AA,BB,CC;
        for(int A=1;A<=2 * a;A++)
        {
            int at = abs(A-a);
            for(int B=A;B<=2*b;B+=A)
            {
                int bt = abs(B-b);

                int cq = c/B;
                int C  = cq * B;
                if(C == 0 or abs(c-C) > abs(C+B - c))C += B;
                int ct = abs(C-c);
                if(at+bt+ct <min_ans)
                {
                    min_ans = at+ bt + ct;
                    AA = A,BB=B,CC=C;
                }
            }
        }

        cout<<min_ans<<endl;
        cout<<AA<<" "<<BB<<" "<<CC<<endl;
    }
}