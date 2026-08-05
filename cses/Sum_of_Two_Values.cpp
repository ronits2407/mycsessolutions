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
    int n, x;
    cin >> n >> x;

    map<int, int> mp;
    vi a(n);
    ask(a, n);

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    int found = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] * 2 == x && mp[a[i]] <= 1)
        {
            continue;
        }
        
        if (mp.count(x - a[i]) > 0)
        {
            cout << i + 1 << " ";
            found = i;
            break;
        }
        
    }
    if (found == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x - a[found] && (i != found))
            {
                cout << i + 1 << endl;
                return;
            }
            
        }
        
    }
    
    
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}