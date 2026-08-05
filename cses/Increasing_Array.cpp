#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 1; i < n; i++)
    {
        count += max(0LL, a[i - 1] - a[i]);
        a[i] = max(a[i], a[i - 1]);
    }

    cout << count << endl;
    
    

    return 0;
}