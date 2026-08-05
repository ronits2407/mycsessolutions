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


int getmex(int i, int j, auto& a)
{
    set<int> ele;
    for (int p = 0; p < i; p++)
    {
        ele.insert(a[p][j]);
    }
    for (int p = 0; p < j; p++)
    {
        ele.insert(a[i][p]);
    }
    int ans = 0;
    while (true)
    {
        if (ele.find(ans) != ele.end())
        {
            ans++;
        }
        else
        {
            break;
        }
        
        
    }
    return ans;
    
    
    
    
}

void solve_ronit()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, 0));

     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = getmex(i, j, a);
            cout << a[i][j] << " ";
        }
        cout << "\n";
        
     }
     
     

    
}

int32_t main()
{
    cout << fixed << setprecision(20);
    solve_ronit();
    return 0;
}