//jai bholenath
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
#define float double
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define endl "\n"
#define inf 3e18
const int N = 1e5 + 5;

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == b && a == 0)
    {
        cout << 0;
        return;
    }
    if (abs(a - b) == 0)
    {
        cout << 1;
    }
    else if (abs(a - b) % 2 == 0)
    {
        cout << 2;
    }
    else
    {
        cout << -1;
    }
    return;
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q = 1;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        solve();
        cout << "\n";
    }
    return 0;
}
