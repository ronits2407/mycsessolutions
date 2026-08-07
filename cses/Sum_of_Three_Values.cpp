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
 
    map<int, set<int>> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]].insert(i);
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            auto it = freq.find(x - a[i] - a[j]);
            if(it != freq.end())
            {
                bool first = false, second = false;
               if (it->second.count(i) > 0)
               {
                it->second.erase(i);
                first = true;
               }
               if (it->second.count(j) > 0)
               {
                it->second.erase(j);
                second = true;
               }
 
               if (it->second.size() > 0)
               {
                 cout << i + 1<< ' ' << j + 1 << ' ' << *it->second.begin() + 1 << '\n';
                 return; 
               }
               if (first)
               {
                it->second.insert(i);
               }
               if (second)
               {
                it->second.insert(j);
               }
               
                
            }
            
        }
        
    }
    cout << "IMPOSSIBLE" << '\n';
    
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}