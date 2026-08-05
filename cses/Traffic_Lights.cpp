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
    int x, n;
    cin >> x >> n;

    vi a(n);
    ask(a, n);

    set<int> positions;
    multiset<int> length;
    length.insert(x);;
    positions.insert(0);
    positions.insert(x);
    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        auto it = positions.lower_bound(curr);
        int up = *it;
        int down = *(--it);
        positions.insert(curr);
       auto itt = length.find(up-down);
       length.erase(itt);
       length.insert(curr-down);
       length.insert(up-curr);
        cout << *length.rbegin() << " ";
        
        
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}