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
 
struct Node
{
    int maxsublen = 0;
    pii prevbestdes = {-1, -1};
    bool totake = false;
};
 
void solve_ronit()
{
    int n, m;cin >> n >> m;
    vi a(n), b(m);ask(a, n);ask(b, m);
    vector<vector<Node>> dp(n+1, vector<Node>(m+1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j].maxsublen = 1+dp[i-1][j-1].maxsublen;
                dp[i][j].prevbestdes = {i-1, j-1};
                dp[i][j].totake = true;
            }
            else
            {
                dp[i][j].maxsublen = max(dp[i-1][j].maxsublen, dp[i][j-1].maxsublen);
                dp[i][j].totake = false;
                if(dp[i-1][j].maxsublen < dp[i][j-1].maxsublen){
                    dp[i][j].prevbestdes = {i, j-1};
                }
                else
                {
                    dp[i][j].prevbestdes = {i-1, j};
                }
            }
            
        }
        
    }
    cout << dp[n][m].maxsublen << "\n";
    pii previdx = {n, m};
    vi ans;
    while (previdx.first != -1)
    {
        if(dp[previdx.first][previdx.second].totake){
            ans.push_back(a[previdx.first-1]);
        }
        previdx = dp[previdx.first][previdx.second].prevbestdes;
    }
    reverse(all(ans));
    give(ans, ans.size());
    
    
 
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}