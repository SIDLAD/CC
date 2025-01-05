#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long mxodd = 2 * n - 1;
    long long freq = n / 2 * 2 + 1;
    long long sum = freq * mxodd;
    n = 2 * n - 1;
    n -= freq;
    while(n > 0)
    {
        mxodd -= 2;
        sum += 2*mxodd;
        n -= 2;
    }
    cout<<sum<<endl;
}