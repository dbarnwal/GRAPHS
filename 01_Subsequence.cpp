#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int a, b, x, y, t;
    cin >> t;
    while (t--)
    {

        int n, k, pp;
        cin >> n >> k;
        int a;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a;
                v.push_back(a);
            }
            pp = n * (n / 2);
        }
        sort(v.begin(), v.end());
        cout << v[pp] << "\n";
    }
    return 0;
}
