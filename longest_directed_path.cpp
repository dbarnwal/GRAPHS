// PUSH YOUR LIMITS.!!

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long

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
#define deb(x) cout<<#x<<" = "<<x<<endl
#define gcd __gcd
#define inf LLONG_MAX
#define minf LLONG_MIN 
const int mod = (int)(1e9+7);

int power(int x,int n)
{   if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}

int dx[]    =  {-1, 0, 1,  0, -1, -1, 1,  1};
int dy[]    =  { 0, 1, 0, -1, -1,  1, 1, -1};
const int maxn = 200005;
#define eps 1e-9
//  ------------------------------------------------------------------   


/*  
    longest directed path is the number of edges from one node to any
    other node in a DIRECTED ACYCLIC GRAPH (DAG).

    It can be calulated with help of Dp and DFS.
    Initially all is zero.

    dp[node] = max(dp[node] , 1+max(dp[all(child)]));

    problem: 
        https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/social-graph-1-ac58bbdf/

*/
int n,m;
vector<int> vis(maxn ,0);
vector<int> adj[maxn];
vector<int> order , dp(maxn);

void dfs(int n)
{
    vis[n] =1;
    for(int x:adj[n])
        if(!vis[x])
            dfs(x);
    order.pb(n);
}
void solve()
{   
    int i,j,k,r;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    repv(i,1,n)
        if(!vis[i])dfs(i);

    for(int u:order)
    {
        dp[u] = 1;
        for(int x:adj[u])
        {
            dp[u] = max(dp[u] , dp[x]+1);
        }
    }
    cout<<*max_element(dp.begin()+1,dp.end());
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


