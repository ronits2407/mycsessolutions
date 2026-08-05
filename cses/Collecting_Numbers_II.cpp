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
    int n, m;
    cin >> n >> m;
    
    vpii a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        b[i].first = a[i].first;
        b[i].second = i;
    }
    sort(all(b));
    for (int i = 0; i < n; i++)
    {
        a[b[i].second].second = i;
    }

    vector<int> indexmapping(n + 1);
    for (int i = 0; i < n; i++)
    {
        indexmapping[a[i].first] = i;
    }
    
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i].second < b[i-1].second)
        {
            ans++;
        }
        
    }
    debug(ans);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x > y)
        {
            swap(x, y);
        }
        // int temp = ans;

        int u = a[x].first;
        int v = a[y].first;

        if (u + 1 <= n && indexmapping[u + 1] <= y && indexmapping[u + 1] > x)
        {
            ans++;
        }
        if (u - 1 >= 1 && indexmapping[u - 1] <= y && indexmapping[u - 1] > x)
        {
            ans--;
        }
        if (v + 1 <= n && indexmapping[v + 1] < y && indexmapping[v + 1] >= x)
        {
            ans--;
        }
        if (v - 1 >= 1 && indexmapping[v - 1] < y && indexmapping[v - 1] >= x)
        {
            ans++;
        }
        
        if (u + 1 == v) {
            ans--;
        }
        if (u - 1 == v) {
            ans++;
        }

        swap(a[x].first, a[y].first);
        swap(b[a[x].second].second, b[a[y].second].second);
        swap(a[x].second, a[y].second);
        swap(indexmapping[a[x].first], indexmapping[a[y].first]);
        
        cout << ans << '\n';
        // ans = temp;
        

    }
    
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}