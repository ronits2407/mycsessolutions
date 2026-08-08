#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define ask(v, n) \
    for (int i = 0; i < (n); ++i) \
        cin >> v[i];
 
#define give(v, n) \
    for (int i = 0; i < (n); ++i) \
        cout << v[i] << ' '; \
    cout << '\n';
 
const int MOD = 1e9 + 7;
const int INF = 1e18;
void _print() { cerr << "]\n"; }
template <typename T, typename... Args>
void _print(T t, Args... args)
{
    cerr << t << (sizeof...(args) ? ", " : "");
    _print(args...);
}
#ifndef ONLINE_JUDGE
#define debug(x...) \
    cerr << "[" << #x << "] = ["; \
    _print(x);
#else
#define debug(x...)
#endif
 
 
 
int32_t main()
{
    cout << fixed << setprecision(20);
    
    int n;
    cin >> n;
 
    vi dp(n+1, 0);
 
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i-6; j < i; j++)
        {
            if (j <= 0)
            {
                continue;
            }
            dp[i] = (dp[j] + dp[i]) % MOD;
            
        }
        
        if (i <= 6)
        {
            dp[i]++;
        }
        // debug(i, dp[i]);
    }
    
 
    cout << dp[n] << endl;
    
 
    return 0;
}