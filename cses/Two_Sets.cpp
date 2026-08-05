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



int32_t main()
{
    cout << fixed << setprecision(20);
    
    int n;
    cin >> n;

    if((n * (n + 1) / 2) % 2 == 1)
    {
        cout << "NO" << endl;
    
    }    else
    {
        cout << "YES" << endl;
        set<int> a;
        a.insert(n);
        int sum = n;
        int half = (n * (n + 1))/4;
        while (sum != (half))
        {
            int last = *a.begin();
            if (last - 1 > 0 && sum + last -1 < half)
            {
                a.insert(last-1);
                sum += last-1;
            }
            else
            {
                a.insert(half - sum);
                sum += half-sum;
            }
            
            
        }
        cout << a.size() << endl;
        for (auto &&ele : a)
        {
            cout << ele << " ";
        }
        cout << endl << n - a.size() << endl;
        for (int i = 0; i < n; i++)
        {
            if (a.find(i+1) == a.end())
            {
                cout << i + 1 << " ";
            }
            
        }
        cout << endl;
        
        
        
        
        
        

    }
    
    return 0;
}