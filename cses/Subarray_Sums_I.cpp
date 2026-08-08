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
    int n, x;
    cin >> n >> x;
    vi a(n);
    ask(a, n);
 
    int l = 0;
    // int r = 0;
    int count = 0;
    int currsum = 0;
    for (int r = 0; r < n; r++)
    {
        currsum += a[r];
        if (currsum < x)
        {
            continue;
        }
        else if (currsum == x)
        {
            count++;
            currsum -= a[r];
            currsum -= a[l];
            r--;
            l++;
        }
        else
        {
            currsum -= a[l];
            currsum -= a[r];
            r--;
            l++;
        }
        
        
        
    }
    cout << count ;
 
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}