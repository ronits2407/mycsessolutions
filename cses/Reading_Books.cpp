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
 
void solve_ronit()
{
    int n;
    cin >> n;
 
    vi a(n);
    ask(a, n);
 
    sort(all(a));
 
    int sum = 0;
    vi pref(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i+1] = pref[i] + a[i];
        sum += a[i];
    }
 
    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        int currlposition  = i;
 
        int timefromleft = pref[i];
        int timefromright = sum  - pref[i];
 
        
        ans = min(ans, 2 * max(timefromleft, timefromright));
        
    }
    
    cout << ans << '\n';
    
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}