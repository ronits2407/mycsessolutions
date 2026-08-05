#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    cin >> n;

    if (n >= 2 && n < 4)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n == 4)
    {
        cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3;
    }
    
    else
    {
        for (int i = 0; i < n; i+=2)
        {
            cout << i + 1 << ' ';
        }
        for (int i = 1; i < n; i+=2)
        {
            cout << i + 1 << ' ';
        }
        
        
    }
    
    

    return 0;
}