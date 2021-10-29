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
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != c)
            flag = false;
    }
    if (flag)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int st = n / 2;
        for (int i = st; i < n; i++)
        {
            if (s[i] == c)
            {
                cout << 1 << endl;
                cout << i + 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
        cout << n - 1 << " " << n << endl;
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
