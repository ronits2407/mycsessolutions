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

bool grid[9][9];
int path_count = 0;
string s;

void dfs(int row, int col, int stepscount)
{
    if (row == 7 && col == 1)
    {
        if (stepscount == 48) path_count++;
        return;
    }
    
    if (grid[row - 1][col] && grid[row + 1][col] && !grid[row][col - 1] && !grid[row][col + 1]) return;
    if (grid[row][col - 1] && grid[row][col + 1] && !grid[row - 1][col] && !grid[row + 1][col]) return;

    if (s[stepscount] == '?')
    {
        if (!grid[row+1][col]) { grid[row+1][col] = true; dfs(row+1, col, stepscount+1); grid[row+1][col] = false; }
        if (!grid[row-1][col]) { grid[row-1][col] = true; dfs(row-1, col, stepscount+1); grid[row-1][col] = false; }
        if (!grid[row][col-1]) { grid[row][col-1] = true; dfs(row, col-1, stepscount+1); grid[row][col-1] = false; }
        if (!grid[row][col+1]) { grid[row][col+1] = true; dfs(row, col+1, stepscount+1); grid[row][col+1] = false; }
    }
    else if (s[stepscount] == 'U')
    {
        if (!grid[row-1][col]) { grid[row-1][col] = true; dfs(row-1, col, stepscount+1); grid[row-1][col] = false; }
    }
    else if (s[stepscount] == 'D')
    {
        if (!grid[row+1][col]) { grid[row+1][col] = true; dfs(row+1, col, stepscount+1); grid[row+1][col] = false; }
    }
    else if (s[stepscount] == 'L')
    {
        if (!grid[row][col-1]) { grid[row][col-1] = true; dfs(row, col-1, stepscount+1); grid[row][col-1] = false; }
    }
    else if (s[stepscount] == 'R')
    {
        if (!grid[row][col+1]) { grid[row][col+1] = true; dfs(row, col+1, stepscount+1); grid[row][col+1] = false; }
    }
}

void solve_ronit()
{
    cin >> s;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        grid[0][i] = true;
        grid[i][0] = true;
        grid[8][i] = true;
        grid[i][8] = true;
    }

    grid[1][1] = true;
    path_count = 0;
    dfs(1, 1, 0);
    cout << path_count << endl;
}

int32_t main()
{
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}