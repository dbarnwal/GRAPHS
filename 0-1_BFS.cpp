#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
#define int long long
typedef pair<int,int> pii;
#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i <n; i++)
#define repv(i,k,n) for(int i=k; i<=n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define endl '\n'
#define inf LLONG_MAX
const int mod = (int)(1e9+7);
/* ------------------------------------------------------- */
const int maxn = (int)(1e5+7);

// weight is either  0 or 1.

vector<pii> adj[maxn];
vector<int> dis(maxn, inf);
void zobfs(int start)
{
    dis[start] = 0;
    deque<int> q;
    q.push_back(start);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop_front();

        for (auto it : adj[cur])
        {
            int x = it.F;
            int len = it.S;
            if (dis[x] > dis[cur] + len)
            {
                dis[x] = dis[cur] + len;
                if (len)
                {
                    q.pb(x);
                }
                else
                {
                    q.push_front(x);
                }
            }
        }
    }
}
void solve()
{
    int n, i, j, k, m;
    cin >> n >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb({b, 0});
        adj[b].pb({a, 1});
    }
    zobfs(1);
    cout << dis[n] << endl;
}
signed main()
{
    RAGE;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    while (t--)
    {
        solve();
    }

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}
