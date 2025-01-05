#include<bits/stdc++.h>
using namespace std;

struct chash
{
    size_t operator() (const auto& pr) const
    {
        return hash<int>()(pr.first*31) ^  hash<int>()(pr.second); 
    }
}
;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int k,n;
    cin>>k>>n;
    int nc = n;
    unordered_map<pair<int,int>,int,chash> mp;
    int i = 0,j = -1;
    int l = 0;
    for(;l <2*k;l++)
    {
        if(l&1)
        {
            i = (i + 1) % k;
        }
        else 
        {
            j = (j + 1)% k;
        }

        mp[{i,j}] = l + 1;
        n--;
    }
    for(int i=0;i<k;i++)for(int j=0;j<k;j++)
    {
        if(n == 0)goto outer;
        if(mp.count({i,j}))continue;
        mp[{i,j}] = ++l;
        n--;
    }
    outer:42;
    vector<pair<int,int>> v(nc);
    for(auto [pr,ele]:mp)
    {
        v[ele - 1] = {pr.first + 1, pr.second + 1};
    }
    
    for(int i=0;i<nc;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}

// #include<bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace std;



// #define RANDOM_GEN_MACRO

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());
// vector<unsigned int> hasher((int)1e6);

// struct chash
// {
//     size_t operator() (const pair<int,int>& pr) const
//     {
//         return (hasher[pr.first]*31) ^  hasher[pr.second]; 
//     }
// }
// ;

// int main()
// {
//     for(int i=0;i<1e6;i++)
//     {
//         hasher[i] = rng();
//     }
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int k,n;
//     cin>>k>>n;
//     int nc = n;
//     gp_hash_table<pair<int,int>,int,chash> mp;
//     int i = 0,j = -1;
//     int l = 0;
//     for(;l <2*k;l++)
//     {
//         if(l&1)
//         {
//             i = (i + 1) % k;
//         }
//         else 
//         {
//             j = (j + 1)% k;
//         }

//         mp[{i,j}] = l + 1;
//         n--;
//     }
//     for(int i=0;i<k;i++)for(int j=0;j<k;j++)
//     {
//         if(n == 0)goto outer;
//         if(mp.find({i,j}) != mp.end())continue;
//         mp[{i,j}] = ++l;
//         n--;
//     }
//     outer:42;
//     vector<pair<int,int>> v(nc);
//     for(auto [pr,ele]:mp)
//     {
//         v[ele - 1] = {pr.first + 1, pr.second + 1};
//     }
    
//     for(int i=0;i<nc;i++)
//     {
//         cout<<v[i].first<<" "<<v[i].second<<"\n";
//     }
// }

// // #include<bits/stdc++.h>
// // #include <bits/extc++.h>
// // using namespace __gnu_pbds;
// // using namespace std;

// // struct HASH{
// //     static uint64_t splitmix64(uint64_t x) {
// //         // http://xorshift.di.unimi.it/splitmix64.c
// //         x += 0x9e3779b97f4a7c15;
// //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// //         return x ^ (x >> 31);
// //     }

// //     size_t operator()(const pair<int,int>&x)const{
// //         return splitmix64(((long long)x.first*31)^(((long long)x.second)));
// //     }
// // };

// // int main()
// // {
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);cout.tie(0);
// //     int k,n;
// //     cin>>k>>n;
// //     int nc = n;
// //     gp_hash_table<pair<int,int>,int,HASH> mp;
// //     // mp.reserve(1e6);
// //     // mp.max_load_factor(0.25);
// //     // map<pair<int,int>,int> mp;
// //     int i = 0,j = -1;
// //     int l = 0;
// //     for(;l <2*k;l++)
// //     {
// //         if(l&1)
// //         {
// //             i = (i + 1) % k;
// //         }
// //         else 
// //         {
// //             j = (j + 1)% k;
// //         }

// //         mp[{i,j}] = l + 1;
// //         n--;
// //     }
// //     for(int i=0;i<k;i++)for(int j=0;j<k;j++)
// //     {
// //         if(n == 0)goto outer;
// //         if(mp.find({i,j}) == mp.end()){
// //             mp[{i,j}] = ++l;
// //             n--;
// //         }
// //     }
// //     outer:42;
// //     vector<pair<int,int>> v(nc);
// //     for(auto [pr,ele]:mp)
// //     {
// //         v[ele - 1] = {pr.first + 1, pr.second + 1};
// //     }
    
// //     for(int i=0;i<nc;i++)
// //     {
// //         cout<<v[i].first<<" "<<v[i].second<<"\n";
// //     }
// // }


// // // int main()
// // // {
// // //     ios_base::sync_with_stdio(0);
// // //     cin.tie(0);cout.tie(0);
// // //     int k,n;
// // //     cin>>k>>n;
// // //     int nc = n;
// // //     #define int long long
// // //     gp_hash_table<pair<int,int>,int,chash> mp;
// // //     int i = 0,j = -1;
// // //     int l = 0;
// // //     for(;l <2*k;l++)
// // //     {
// // //         if(l&1)
// // //         {
// // //             i = (i + 1) % k;
// // //         }
// // //         else 
// // //         {
// // //             j = (j + 1)% k;
// // //         }

// // //         mp[{i,j}] = l + 1;
// // //         n--;
// // //     }
// // //     for(int i=0;i<k;i++)for(int j=0;j<k;j++)
// // //     {
// // //         if(n == 0)goto outer;
// // //         if(mp.find({i,j}) == mp.end()){
// // //             mp[{i,j}] = ++l;
// // //             n--;
// // //         }
// // //     }
// // //     outer:
// // //     vector<pair<int,int>> v(nc);
// // //     for(auto [pr,ele]:mp)
// // //     {
// // //         v[ele - 1] = {pr.first + 1, pr.second + 1};
// // //     }
    
// // //     for(int i=0;i<nc;i++)
// // //     {
// // //         cout<<v[i].first<<" "<<v[i].second<<"\n";
// // //     }
// // // }