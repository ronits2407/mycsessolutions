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
    int n, k;
    cin >> n >> k;
    set<pii> st;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        st.insert({b, a});
    }
 
    int count = 0;
    while (!st.empty() && k > 0)
    {
        set<pii> todelete;
        int largestfinish = -1;
        for (auto &&ele : st)
        {
            if (ele.second >= largestfinish)
            {
                todelete.insert(ele);
                largestfinish = max(largestfinish, ele.first);
            }
            
        }
        count += todelete.size();
        debug(k, todelete.size());
        for (auto &&ele : todelete)
        {
            st.erase(ele);
        }
        
        k--;
    }
    cout << count;
 
    
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}