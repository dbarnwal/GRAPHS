// PUSH YOUR LIMITS.!!

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long

#define RAGE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for(i=0; i <n; i++)
#define repv(i,k,n) for(i=k; i<n; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define endl '\n'
int mod = 1e9+7;
int power(int x,int n)
{   if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
int dx[]={-1 , 0 , 1 , 0};
int dy[]={ 0 , -1, 0 , 1};
const int maxn = 10005;
//  ------------------------------------------------------------------
vector<int> vis(maxn);
vector<int> adj[maxn];
vector<int> sub_tree_size(maxn);

int dfs(int n)
{
    vis[n] = 1;
    int cur_size=1;
    for(int x:adj[n])
    {
        if(!vis[x])
            cur_size += dfs(x);
    }
    sub_tree_size[n] = cur_size;
    return cur_size;
}
void solve()
{
    vis.assign(maxn , 0);
    sub_tree_size.assign(maxn , 1);

    int n,i,j,k,m;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
            sub_tree_size[i] = dfs(i);
    }
    for(i=1; i<=n; i++)
        cout<<sub_tree_size[i]<<" ";

}
signed main()
{
    RAGE;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
    int t=1;
    //  cin>>t;
    while(t--)
        solve();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}
