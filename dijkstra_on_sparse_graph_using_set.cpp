/* 
    AABRA KA DABRA.. !! 
*/
#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
typedef pair<int,int> pii;
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
{   
    if(n==0)    return 1;
    if(n==1)    return x%mod;
    if(n%2==0)  {   int y = power(x,n/2)%mod;return (y*y)%mod;}
    if(n&1)     {   int y = power(x,n-1);return (x%mod * y%mod)%mod;}
    return 0;
}
bool is_power_2(int n)  { return log2(n)==floor(log2(n));}
bool is_prime(int n){   for(int i=2; i*i<=n; i++)   if(n%i==0)  return 0;   return 1;}

int dx[]    =  {-1 ,  0,  1,  0,  -1,  -1,  1,   1};
int dy[]    =  { 0 ,  1,  0, -1,  -1,   1,  1,  -1};
char dir[]  =  {'U','R','D','L'};

const int maxn = 100005;

/*                                                                  
    ╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩╦═╩═╦═╩═╦═╩═╦═╩═╦═╩╦═╩═╦═╩═╦═╩═╦═╩═╦═╩╦═╩═╦═╩═╦
      #   #   #   #   #  #   #   #   #   #  #   #   #   #   #  #   #   # 
    ╦═╩═╦═╩═╦═╩═╦═╩═╦═╩╦═╩═╦═╩═╦═╩═╦═╩═╦═╩╦═╩═╦═╩═╦═╩═╦═╩═╦═╩╦═╩═╦═╩═╦═╩
*/  


int n,m;
vector<pii> adj[maxn];
vector<int> vis(maxn );
vector<int> dis(maxn , inf);
vector<int> parent(maxn , -1);

void dijkstra(int start)
{
    int i,j;
    dis[start]= 0;
    set<pii> st;
    st.insert({0,start});
    while(!st.empty())
    {
        int cur = st.begin()->S;
        st.erase(st.begin());

        for(auto it:adj[cur])
        {
            int x = it.F , len = it.S;

            if(dis[cur] + len < dis[x])
            {
                st.erase({dis[x] ,x});
                dis[x] = dis[cur] + len;
                parent[x] = cur;
                st.insert({dis[x] , x});
            }
        }
    }
}
void solve()
{
    int i,j,k;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dijkstra(1);
    repv(i,1,n)
        cout<<dis[i]<<" ";
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
