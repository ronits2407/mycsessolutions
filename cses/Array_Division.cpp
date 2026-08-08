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
 
bool check(vi&a, int k, int maxsum)
{
    int done = 0;
    int n = a.size();
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr + a[i] > maxsum)
        {
            if (curr == 0)
            {
                return false;
            }
            
            done++;
            curr = 0;
            i--;
        }
        else
        {
            curr += a[i];
        }
        
        
    }
    if (curr > 0)
    {
        done++;
    }
    return done <= k;
    
    
}
void solve_ronit()
{
    int n, k;
    cin >> n >> k;
 
    vi a(n);
    ask(a, n);
 
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
 
    int low = 1;
    int high = sum;
 
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if(check(a, k, mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
    cout << ans ;
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}