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
 
    sort(all(a));
 
    set<pii> occupied;
    int last_room = 0;
    vi ans(n);
 
    for (int i = 0; i < n; i++)
    {
        int arrival = a[i].first.first;
        int departure = a[i].first.second;
        int original_idx = a[i].second;
 
        auto first = occupied.begin();
        int assign;
 
        if (first != occupied.end() && first->first < arrival)
        {
            assign = first->second;
            occupied.erase(first);
        }
        else
        {
            assign = ++last_room;
        }
 
        occupied.insert({departure, assign});
        ans[original_idx] = assign;
    }
 
    cout << last_room << "\n";
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