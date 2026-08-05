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

    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++)
    {
        int max_price;
        cin >> max_price;

        auto it = tickets.upper_bound(max_price);

        if (it == tickets.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
}

int32_t main()
{
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}