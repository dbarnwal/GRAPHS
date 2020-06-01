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
string dir[] = {"D" , "R" , "U" , "L"};
const int maxn = 1005;
//  ------------------------------------------------------------------
int n,m;
string s[maxn];
vector<vector<int> > dist(maxn , vector<int> (maxn , 0));
vector<vector<int>> vis(maxn , vector<int> (maxn , 0));
void dfs(int x , int y)
{
    vis[x][y] = 1;
    if(is_valid(x , y+1))
        dfs(x ,y+1);
    if(is_valid(x,y-1))
        dfs(x,y-1);
    if(is_valid(x-1 ,y))
        dfs(x-1,y);
    if(is_valid(x+1 , y))
        dfs(x+1 ,y);
}
void bfs(int  x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty())
    {
        int cx = q.front().F;
        int cy = q.front().S;

        q.pop();
        for(int i=0; i<4; i++)
        {
            if(is_valid(cx + dx[i] , cy+dy[i]))
            {
                int nx = cx + dx[i],ny = cy+dy[i];
                dist[nx][ny] = dist[cx][cy]+1;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}
void solve()
{
    int i,j;
    cin>>n>>m;
    rep(i,n)
        cin>>s[i];
    pair<int,int> start , end;
    rep(i,n)
    {
        rep(j,m)
        {
            if(s[i][j]=='A')
                start.F = i ,start.S = j;
            else
            if(s[i][j]=='B')
                end.F = i,end.S = j;
        }
    }
    bfs(start.F , start.S);
    if(dist[end.F][end.S]==0)
    {   cout<<"NO"; exit(0);}
    cout<<"YES\n";
        
}   
signed main()
{
    RAGE;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
    int t=1;
    //cin>>t;
    while(t--)
        solve();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}

