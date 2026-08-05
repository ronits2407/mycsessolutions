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


void solve(vector<string>& board, vector<bool>& columns,vector<bool>& topleft_rightbottom, vector<bool>& topright_leftbottom, int& ans , int row)
{
    if (row == 8)
    {
        ans++;
        return;
    }
    // debug(ans, row);
    for (int i = 0; i < 8; i++)
    {
        if (board[row][i] == '*' || (columns[i] || topleft_rightbottom[(row - i + 15) % 15] || topright_leftbottom[(row + i + 15) % 15 ]))
        {
            continue;
        }
        else
        {
            // serach with queen here

            columns[i] = true;
            topleft_rightbottom[(row - i + 15) % 15] = true;
            topright_leftbottom[(row + i + 15) % 15 ] = true;
            solve(board, columns, topleft_rightbottom, topright_leftbottom, ans, row+1);
            columns[i] = false;
            topleft_rightbottom[(row - i + 15) % 15] = false;
            topright_leftbottom[(row + i + 15) % 15 ] = false;          

        }
        
        
    }
    


    
}

void solve_ronit()
{
    vector<string> board;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }

    vector<bool> columns(8, false);
    vector<bool> topleft_rightbottom(15, false);
    vector<bool> topright_leftbottom(15, false);

    int ans = 0;
    solve(board, columns, topleft_rightbottom, topright_leftbottom, ans, 0);

    cout << ans << endl;
    
}

int32_t main()
{
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}