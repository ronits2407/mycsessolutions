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

    vector<vi> board(n, vi(n, LLONG_MAX));

    vi dx = {1, 1 , -1 , -1 , -2 , -2, 2, 2};
    vi dy = {2, -2 , 2 , -2 , -1 , 1, 1, -1};

    queue<pii> q;
    q.push({0, 0});
    board[0][0] = 0;
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for (int p = 0; p < 8; p++)
        {
            int newi = i + dx[p];
            int newj = j + dy[p];

            if (newi >= 0 && newi < n && newj >= 0 && newj < n && board[newi][newj] == LLONG_MAX)
            {
                q.push({newi, newj});
                board[newi][newj] = 1 + board[i][j];
            }
            
        }
        

    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    
}

int32_t main()
{
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}