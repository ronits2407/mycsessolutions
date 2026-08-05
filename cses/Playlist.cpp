#include <bits/stdc++.h>
using namespace std;
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

    set<int> running;
    int ans = 0;
    int curr = 1;
    int l = 0;
    running.insert(a[0]);
    for (int r = 1; r < n; r++)
    {
        if (!running.count(a[r]))
        {
            running.insert(a[r]);
            curr++;
            ans = max(ans, curr);
        }
        else
        {
            running.erase(a[l]);
            l++;
            curr--;
            r--;
        }
        
        
        
        
    }
    ans = max(curr, ans);
    cout << ans << endl;
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}