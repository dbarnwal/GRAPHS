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
#define inf LLONG_MAX
#define minf LLONG_MIN 
const int maxn = 100005;


int n,m;
vector<pii> adj[maxn];
vector<int> vis(maxn , 0);
vector<int> dis(maxn , inf);

void dijkstra(int start)
{
    
    dis[start] =0;
    priority_queue<pii ,vector<pii>,greater<pii>>  pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int cur = pq.top().S ,d_cur = pq.top().F; 
        pq.pop();
        
        /* 
            we are using d_cur > dis[cur] because it will be BFS because that keeps going only when 
            new distance would be lower than current minimum distance for this node and that will be 
            very slow in most of the cases.
        */
        if(d_cur>dis[cur])
            continue;
        for(auto it:adj[cur])
        {
            int x = it.F , len = it.S;
            if(dis[cur] + len < dis[x])
            {
                dis[x] = dis[cur] + len;
                //  parent[x] = cur;
                pq.push({dis[x],x});
            }
        }
    }
}
void solve()
{
    int i;
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
    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    */
    int t=1;
    //  cin>>t;
    while(t--)
        solve();
    /*
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    */

    return 0;
}
