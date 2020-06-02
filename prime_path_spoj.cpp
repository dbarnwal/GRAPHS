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
const int maxn = 100005;
//  ------------------------------------------------------------------
vector<int> vis(maxn);
vector<int> dist(maxn);
vector<int> adj[maxn];
vector<int> primes;

bool is_prime(int n)
{
    for(int i=2; i*i<=n; i++)
    {   if(n%i==0)
            return false;
    }
    return true;
}

bool is_valid(int a ,int b)
{
    int cnt=0;
    while(a>0)
    {
        if(a%10 != b%10)
            cnt++;
        a/=10 , b/=10;
    }
    if(cnt==1)
        return true;
    return false;
}
void build_graph()
{
    int i,j;
    for(i=1000; i<=9999; i++)
    {   if(is_prime(i))
            primes.pb(i);
    }

    for(i=0; i<sz(primes); i++)
    {
        for(j=i+1; j<sz(primes); j++)
        {
            int a = primes[i];
            int b = primes[j];

            if(is_valid(a,b))
            {
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }
    }
}

void bfs(int n)
{
    queue<int> q;
    vis[n] = 1;
    dist[n] = 0;
    q.push(n);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x:adj[v])
        {
            if(!vis[x])
            {
                q.push(x);
                dist[x] = dist[v] + 1;
                vis[x]  = 1;
            }
        }
    }
}

void solve()
{
    int n,i,j,k,m;
    vis.assign(maxn , 0);
    dist.assign(maxn , -1);

    cin>>n>>m;
    bfs(n);

    if(dist[m]==-1)
        cout<<"Impossible"<<endl;   
    else
        cout<<dist[m]<<endl;
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
    build_graph();
    while(t--)
        solve();

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

    return 0;
}
