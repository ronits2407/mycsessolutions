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
 
    vector<pair<pii, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first.first;
        cin >> a[i].first.second;
        a[i].second = i;
    }
    vi ans(n);
    sort(all(a), [&](auto& a, auto& b){
        if (a.first.second == b.first.second)
        {
            return a.first.first > b.first.first;
        }
        return a.first.second < b.first.second;
    });
    
    int biggeststart = -1;
    indexed_set values;
    for (int i = 0; i < n; i++)
    {
        ans[a[i].second] = values.size() - (values.order_of_key(a[i].first.first));
        values.insert(a[i].first.first);
    }
    give(ans, n);
    sort(all(a), [&](auto& x, auto& y){
        if (x.first.first == y.first.first)
            return x.first.second > y.first.second;
        return x.first.first < y.first.first;
    });
    int longestfinish = -1;
    values.clear();
    for (int i = 0; i < n ; i++)
    {
        ans[a[i].second] = values.size() - (values.order_of_key(a[i].first.second));
        values.insert(a[i].first.second);
       
    }
 
    
 
 
    give(ans, n);
    
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}