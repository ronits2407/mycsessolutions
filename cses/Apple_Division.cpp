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


int32_t main()
{
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vi a(n);
    ask(a, n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    

    int ans = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        int w1 = 0, w2 = sum;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                int change = a[j];
                w1 += change;
                w2 -= change;
            }
            
        }

        ans = min(ans, abs(w1-w2));    
    }
    cout << ans << endl;


    return 0;
}