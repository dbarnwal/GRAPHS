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

/* 
    Finding the diameter of a tree.
    Diameter of a tree is defined as the longest path between any two 
    nodes. 

    for this - 
        1. find the farthest node from any node taking as root let this
        node be x and fathest from it be y.
        
        2. find fathest node from y. The distance from y will give the 
            diameter of the tree.
    * Generaly taking 1 as x;
*/

vector<int> adj[maxn];
vector<int> vis(maxn,0);

int maxd , max_node;
// maxnode will give the fathest node.
void dfs(int n ,int d)
{
    vis[n] = 1;
    if(d>maxd)
        maxd = d , max_node = n;
    for(int x:adj[n])
        if(!vis[x])
            dfs(x , d+1);
}
void solve()
{
    int n,i,j,k,m;
    cin>>n;
    vis.assign(maxn , 0);
    rep(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // finding y taking 1 as x;
    maxd = -1;
    dfs(1 , 0);
    maxd=-1;
    // finding farthest node.
    vis.assign(maxn , 0);
    dfs(max_node , 0);
    cout<<maxd;
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
