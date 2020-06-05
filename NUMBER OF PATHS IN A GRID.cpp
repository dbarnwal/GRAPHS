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
const int maxn = 22;
//  ------------------------------------------------------------------

/*
    problem - https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/prison-break-5/description/

    CALCULATING NUMBER OF PATHS FROM START TO END IN A GRID.
    
    USES BACK-TRACKING AND DFS.
*/
int n;
int vis[maxn][maxn];
int ar[maxn][maxn];
int cnt=0;

bool is_valid(int x,int y)
{
    if(x<0 || x>=n)
        return false;
    if(y<0 || y>=n)
        return false;
    if(ar[x][y]==1)
        return false;
    return true;
}
void dfs(int x , int y)
{   
    // USES BACK-TRACKING . 
    if(x==n-1 && y==n-1)
    {   cnt++; return;  }

    vis[x][y] = 1;
    for(int i=0; i<4; i++)
    {   
        if(!vis[x+dx[i]][y+dy[i]] && is_valid(x+dx[i] ,y+dy[i]))
            dfs(x+dx[i] ,y+dy[i]);
    }
    vis[x][y] = 0;
}
void solve()
{
    int i,j,k,m;
    cin>>n;
    rep(i,n)
    {   rep(j,n)
            cin>>ar[i][j];
    }
    cnt=0;
    dfs(0 , 0);
    cout<<cnt<<endl;
}   
signed main()
{
    RAGE;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
    int t=1;
    cin>>t;
    while(t--)
        solve();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif


    return 0;
}

