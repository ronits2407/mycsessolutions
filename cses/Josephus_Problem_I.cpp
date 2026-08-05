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

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    

    set<int> elements;
    for (int i = 0; i < n; i++)
    {
        elements.insert(i+1);
    }

    cout << 2 << " ";
    int prev = 2;
    elements.erase(2);
    for (int i = 1; i < n; i++)
    {
        auto ele = elements.lower_bound(prev + 1);
        if (ele != elements.end())
        {
            auto nextele = elements.lower_bound((*ele) + 1);
            if (nextele != elements.end())
            {
                cout << *nextele << " ";
                prev = *nextele;
                elements.erase(nextele);
                continue;
            }
            else
            {
                cout << *elements.begin() << " ";
                prev = *elements.begin();
                elements.erase(elements.begin());
                continue;
            }
            
            
        }
        else
        {
            if (elements.size() == 1)
            {
                cout << *elements.begin() << " ";
                continue;
            }
            
            cout << *(++elements.begin()) << " ";
            prev = *(++elements.begin());
            elements.erase(prev);
            continue;
        }
        
        
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