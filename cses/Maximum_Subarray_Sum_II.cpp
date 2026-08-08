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
    int n, a, b;
    cin >> n >> a >> b;
 
    vi arr(n);
    ask(arr, n);
 
    int curr = 0;
    for(int i = 0; i < a; i++)curr+=arr[i];
    int ans = curr;
 
    int l = 0;
    for (int r = a; r < n; r++)
    {
        curr += arr[r];
        if (curr <= 0 )
        {
            while (curr <= 0)
            {
                if (r -l + 1 == a)
                {
                    ans = max(curr, ans);
                    break;
                }
                else
                {
                    curr -= arr[l];
                    l++;
                    ans = max(curr, ans);
                }
                
                
            }
 
            
        }
        else
        {
            if (r - l + 1 > b)
            {
                curr -= arr[l];
                curr -= arr[r];
                l++;
                r--;
                continue;
            }
            
            ans = max(ans, curr);
 
        }
        
        
    }
    while ((n-1 - l + 1) > a)
    {
        curr -= arr[l];
        l++;
        ans = max(ans, curr);
    }
    
    cout << ans;
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}