/* mamba mentality */
#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
#define int long long
typedef pair<int,int> pii;
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
const int maxn = 200005;

/* ------------------------------------------------------- */


struct edge
{
    int a,b,w;
};

edge edges[maxn];
vector<int> dis(maxn , inf);
vector<int> par(maxn , -1);
 
void solve()
{
    int n,i,j,k,m;
    cin>>n>>m;
    rep(i,m)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    dis[1]=0;
    rep(i,n-1)
    {
        bool any =false;
        rep(j,m)
        {
            int a = edges[j].a , b = edges[j].b , w = edges[i].w;
            if(dis[a] != inf && dis[a]+w < dis[b])
            {
                dis[b] = dis[a] + w;
                par[b] = a;
                any  = true;
            }
        }
        if(!any)
            break;
    }
    /*
        IF NOT ANY NEGATIVE CYCLE FOUND;
   */  
    repv(i,1,n)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }

}   
signed main()
{
    RAGE;
    int t=1;
    //  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
