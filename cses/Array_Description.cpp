#include <bits/stdc++.h>
 
// PBDS headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
// PBDS indexed_set definition
typedef tree<
    int, 
    null_type, 
    less<int>, 
    rb_tree_tag, 
    tree_order_statistics_node_update> 
    indexed_set;
 
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
const double PI = 3.1415926535897932384626433832795;
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
 
int power(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp % 2) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}
 
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r;
    
    int num = 1, den = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }
    
    return (num * power(den, MOD - 2)) % MOD;
}
 
void solve_ronit()
{
    int n, m;
    cin >> n >> m;
    vi a(n);ask(a, n);
    vector<vi> dp(n, vi(m, 0));
    if(a[0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = 1;
        }
        
    }
    else
    {
        dp[0][a[0]-1]=1;
    }
    
    for (int i = 1; i < n; i++)
    {
        if(a[i] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                if (j-1>=0)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
                if (j+1<=m-1)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1])%MOD;
                }
                dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;            
            }
            
        }
        else
        {
            if (a[i]-1-1>=0)
                {
                    dp[i][a[i]-1] = (dp[i][a[i]-1] + dp[i-1][a[i]-1-1]) % MOD;
                }
                if (a[i]-1+1<=m-1)
                {
                    dp[i][a[i]-1] = (dp[i][a[i]-1] + dp[i-1][a[i]-1+1])%MOD;
                }
                dp[i][a[i]-1] = (dp[i][a[i]-1]+dp[i-1][a[i]-1])%MOD; 
        }
    }
    int sum = 0;
    for(int i= 0; i< m; i++)sum= (sum+dp[n-1][i])%MOD;
    cout << sum;
    
 
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}