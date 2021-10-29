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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (n > m)
        swap(n, m);
    int ans = 0;
    ans = min((m + n - 2) * x, ((n - 1) * y + (m - n) * x));
    if (n == 1 || (n == m))
    {
        cout << ans;
        return;
    }
    else
    {
        ans = min((n - 1) * y, (2 * n - 2) * x);
        m -= n;
        // if (m == 1)
        // {
        //     ans += x;
        // }
        // else
        // {
        //     // cout << m << endl;
        if (m % 2 == 0)
        {
            ans += min(m * x, m * y);
        }
        else
            ans += min((m - 1) * y + x, m * x);
        // }

        cout << ans << endl;
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
        // cout << "\n";
    }
    return 0;
}
