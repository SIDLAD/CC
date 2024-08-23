#include<bits/stdc++.h>

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


int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    vector<string> c = b;
    for(int i=0;i<n;i++)c[i] = c[i] + '$' + s;
    vector<vector<int>> zvals;
    vector<vector<int>> ans(n,vector<int>(s.size()));
    for(int i=0;i<n;i++)
    {
        zvals.push_back(vector<int>(c[i].size()));
        int l = 0,r = 0;

        for(int j=1;j<c[i].size();j++)
        {
            if(j<r)
            {
                zvals[i][j] = min(r-j, zvals[i][j-l]); 
            }
            while(j + zvals[i][j] < c[i].size() and c[i][zvals[i][j] + j] == c[i][zvals[i][j]])
            {
                zvals[i][j]++;
            }
            if(r < j + zvals[i][j])
            {
                r = j + zvals[i][j];
                l = j;
            }
        }

        for(int j=0;j<s.length();j++)
        {
            if(zvals[i][j + b[i].size() + 1] == b[i].size())
            {
                ans[i][j] ++;
            }
        }
        partial_sum(ans[i].begin(),ans[i].end(),ans[i].begin());
    }
    int ll = 0;
    int sat_index = 0;
    int ul = debug(s.length()) + 1;
    debug(ans[0]);
    while(ul - ll > 1)
    {
        int mid = ll + ul>>1;
        int index = -1;
        for(int i=0;i<=s.length() - mid ;i++)
        {
            if(mid == 0)
            {
                index= 0;
                break;
            }
            bool check = 1;
            for(int j = 0;j<ans.size();j++)
            {
                if(b[j].size() > mid)continue;
                debug(mid,i,j,i + mid - 1 - b[j].size() + 1 , i-1);
                if(debug(ans[j][i + mid - 1 - b[j].size() + 1]) - debug((i==0)?(0):ans[j][(i-1)])){

                    check = 0;
                    break;
                }
            }
            if(check)
            {
                index = i;
                break;
            }
        }

        if(index != -1)
        {
            sat_index = index;
            ll = mid;
        }
        else ul = mid;
        debug(mid, index);
    }
    cout<<ll<<" "<<sat_index<<endl;
}