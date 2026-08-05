#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int row, col;
    cin >> row >> col;

    if (col >= row)
    {
        if (col % 2 == 0)
        {
            cout << (col - 1) * (col - 1) + row;
        }
        else
        {
            cout << col * col - row + 1;
        }
        
        
    }
    else
    {
        if (row % 2 == 1)
        {
            cout << (row - 1) * (row - 1) + col;
        }
        else
        {
            cout << row * row - col + 1;
        }
    }
    
    cout << endl;
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }

    return 0;
}