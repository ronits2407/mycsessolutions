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

void solve(int curr,int help,int dest, int n)
{
    if (n == 0)
    {
        return;
    }
    
    solve(curr, dest, help, n-1);
    cout << curr << " " << dest << endl;
    solve(help, curr, dest, n-1);
}

int32_t main()
{
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    cout << (int)pow(2, n) - 1 << endl;
    solve(1, 2, 3, n);
    return 0;
}