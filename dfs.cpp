// VALUE THE SACRIFICES..
//  ~_Aomine_   -> 17/04/20

#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i < n; i++)
#define repv(i,k,n) for(i=k; i<n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
int mod = 1e9+7;
//  ---------------------------------------------------------------
const int MAXN = 100005;
vector<int> adj[MAXN];
vector<bool> visited(MAXN);

void dfs(int node)
{
    visited[node] = true;
    for(int u:adj[node])
        if(!visited[u])
            dfs(u);

}
signed main()
{
    int nodes , edges,i,j,k,m;
    cin>>nodes>>edges;
    while(edges--)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1);
    return 0;
}
