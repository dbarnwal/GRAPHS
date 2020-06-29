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
const int maxn = 200005;
/* ------------------------------------------------------- */

int n,m;
set<int> undiscovered;
map<pii,int> mpp;
vector<int> dis(maxn,inf);
void bfs(int start)
{   
    int i,j;
    repv(i,1,n)
    {   
        undiscovered.insert(i);
        dis[i] = inf;
    }
    undiscovered.erase(start);
    dis[start] =0 ;
    queue<int> q;
    q.push(start);
    while(sz(undiscovered) && !q.empty())
    {
        int cur = q.front();
        q.pop();
        vector<int> complement_edges;
        for(int x:undiscovered)
        {
            if(mpp.count({cur,x})==0)
                complement_edges.pb(x);
        }

        for(int x:complement_edges)
        {
            //  cout<<x<<" ";
            if(dis[x] > dis[cur] +1)
            {   
                dis[x] = dis[cur] +1;
                q.push(x);
            }
            undiscovered.erase(x);
        }
    }
} 
void solve()
{
    int i,j,k;
    cin>>n>>m;
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        mpp[{a,b}] =1, mpp[{b,a}] =1;
    }
    int start;
    cin>>start;
    bfs(start);
    repv(i,1,n)
    {
        if(i!=start)   
            cout<<dis[i]<<" ";
    }
    cout<<endl;
    mpp.clear();
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
    {
        solve();
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
