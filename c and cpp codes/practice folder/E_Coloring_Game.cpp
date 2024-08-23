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

using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(),(x).end()
#define cout(x) x?cout<<"Yes"<<endl:cout<<"No"<<endl
// #define endl "\n" //comment out for interactive problems

vector<vector<int>> graph;

void player1()
{
    cout<<"Alice"<<endl;
    for(int i=0;i<graph.size();i++)
    {
        cout<<1<<" "<<2<<endl;
        int ii,c;
        cin>>ii>>c;
    }
}

void player2(vector<int>&color1,vector<int>&color2)
{
    cout<<"Bob"<<endl;
    int n = graph.size();
    
    // first turn

    int a,b;
    cin>>a>>b;

    //assign a as first color
    int firstcolor = a;
    cout<<color1.back()<<" "<<a<<endl;
    color1.pop_back();

    if(n == 1)return;

    //second turn

    cin>>a>>b;
    int secondcolor;
    if(a == firstcolor)secondcolor = b;
    else secondcolor = a;

    cout<<color2.back()<<" "<<secondcolor<<endl;
    color2.pop_back();

    set<int> tmp({1,2,3});
    tmp.erase(firstcolor);
    tmp.erase(secondcolor);

    int thirdcolor = *tmp.begin();

    debug(firstcolor,secondcolor,thirdcolor);
    for(int i=0;i<n-2;i++)
    {
        cin>>a>>b;
        set<int> tmp({a,b});
        tmp.erase(thirdcolor);
        int thirdlabel = -1;
        debug();
        debug(a,b,tmp);
        if(tmp.size() == 1)
        {
            if(*tmp.begin() == firstcolor and color1.size())
            {
                cout<<color1.back()<<" "<<firstcolor<<endl;
                color1.pop_back();
                continue;
            }
            else if(*tmp.begin() == secondcolor and color2.size())
            {
                cout<<color2.back()<<" "<<secondcolor<<endl;
                color2.pop_back();
                continue;
            }
            else if(*tmp.begin() == firstcolor)
            {
                thirdlabel = 2;
            }
            else
            {
                thirdlabel = 1;
            }
        }

        if(thirdlabel == 2 or (tmp.count(secondcolor) and color2.size()))
        {
            int x = (thirdlabel!=-1)?thirdcolor:secondcolor;
            debug(x);
            cout<<color2.back()<<" "<<x<<endl;
            color2.pop_back();
        }
        else if(thirdlabel == 1 or (tmp.count(firstcolor) and color1.size()))
        {
            int x = (thirdlabel!=-1)?thirdcolor:firstcolor;
            debug(x);
            cout<<color1.back()<<" "<<x<<endl;
            color1.pop_back();
        }
        else
        {
            throw exception();
        }

    }

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
        int n,m;
        cin>>n>>m;
        graph = vector<vector<int>>(n);
        vector<int> color(n,-1);
        vector<int> color1;
        vector<int> color2;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        function<void(int,int)> dfs = [&](int node,int c)->void
        {
            debug(node,c);
            color[node] = c;
            if(c == 0)color1.push_back(node);
            else color2.push_back(node);
            for(auto frnd: graph[node])
            {
                if(color[frnd] == -1)
                {
                    dfs(frnd, (c+1)%2);
                }
            }
        };
        dfs(0,0);
        debug(color);
        debug(color1);
        debug(color2);
        vector<int> vcheck;
        for(int i=0;i<color1.size();i++)vcheck.push_back(color1[i]);
        for(int i=0;i<color2.size();i++)vcheck.push_back(color2[i]);
        sort(all(vcheck));
        for(int i=1;i<vcheck.size();i++)
        {
            if(vcheck[i] == vcheck[i-1])
            {
                throw exception();
            }
        }


        bool check = true;

        for(int i=0;i<n;i++)
        {
            for(auto j:graph[i])
            {
                if(color[i] == color[j])
                {
                    check = false;
                    goto outer;
                }
            }
        }
        outer:

        if(check)
        {
            for(int i=0;i<color1.size();i++)color1[i]++;
            for(int i=0;i<color2.size();i++)color2[i]++;
            player2(color1,color2);
        }
        else player1();
    }
}