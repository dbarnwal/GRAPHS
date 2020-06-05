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
#define fill(x , a) x.assign(a)
int mod = 1e9+7;
int power(int x,int n)
{   if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
int dx[]    =  {-1, 0, 1, 0,-1,-1,1, 1};
int dy[]    =  { 0, 1, 0,-1,-1, 1,1,-1};
const int maxn = 200005;
//  ------------------------------------------------------------------
/* 
    CHECK IF A NODE IS IN THE SUBTREE OF ANOTHER.

    PROB - https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/sg-and-trees/description/
    
    CALCULATING IN-TIME AND OUT-TIME HELPS TO SOLVE THE PROBLEM.    
*/

vector<int> vis(maxn , 0);
vector<int> adj[maxn];
int timer = 1;
vector<int> in_time(maxn ,0);
vector<int> out_time(maxn ,0);

void dfs(int n)
{
    vis[n] = 1;
    in_time[n] = timer++;
    for(int x:adj[n])
    {   
        if(!vis[x])
        {   
            dfs(x);
        }
    }
    out_time[n] = timer++;
}
void solve()
{
    int n,i,j,k,m,q;
    cin>>n>>q;
    rep(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(in_time[a]<=in_time[b] && out_time[a]>=out_time[b])
            cout<<"YES\n";
        else
        if(in_time[b]<in_time[a] && out_time[b]>out_time[a])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
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

