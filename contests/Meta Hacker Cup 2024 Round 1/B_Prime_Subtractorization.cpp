#include <bits/stdc++.h>
const long double EPS = 1e-7;
const long long int INF = LONG_LONG_MAX / 2;
const long long int M = (long long int)1e9 + 7; // 998'244'353;
using namespace std;
// insert policy here

// insert mintcode here

#if defined(ONLINE_JUDGE) || !__has_include(</home/sidlad/Desktop/Coding Folder/c and cpp codes/Debug.h>)
void _exe() {}
template <typename T, typename... V>
const T &_exe(const T &t, const V &...v) { return t; }
template <typename T, typename... V>
T &_exe(T &t, V &...v) { return t; }

#define debug(x...) (_exe(x))

class CNothing
{
};

template <typename T>
const CNothing &operator<<(const CNothing &proxy, const T &)
{
    return proxy;
}

const CNothing &operator<<(const CNothing &proxy, std::ostream &(*)(std::ostream &))
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
#define all(x) (x).begin(), (x).end()
#define endl "\n" // comment out for interactive problems
#define cout(x) x ? cout << "Yes" << endl : cout << "No" << endl

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("prime_subtractorization_input.txt","r",stdin);
    freopen("B_output.txt","w",stdout);
    int n = 1e7;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if(is_prime[i])primes.push_back(i);
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> answers;
    for(int i=2;i<primes.size();i++)
    {
        if(primes[i] - primes[i-1] == 2)
        {
            answers.push_back(primes[i]);
        }
    }

    int t;
    cin>>t;
    for(int tt = 1;tt <= t;tt++)
    {
        int n;
        cin>>n;
        int answer;
        if(n < 5)answer = 0;
        else
        {
            answer = 1;
            answer += (upper_bound(all(answers),n)) - answers.begin();
        }
        cout<<"Case #"<<tt<<": "<<answer<<endl;
    }
}