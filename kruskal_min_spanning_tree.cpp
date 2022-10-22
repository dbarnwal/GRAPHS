/* 
    AABRA KA DABRA.. !! 
*/

/**
A spanning tree is a sub-graph of an undirected connected graph, which includes all the vertices of the graph with a minimum possible number of edges. If a vertex is missed, then it is not a spanning tree.

The edges may or may not have weights assigned to them.

The total number of spanning trees with n vertices that can be created from a complete graph is equal to n(n-2).

If we have n = 4, the maximum number of possible spanning trees is equal to 44-2 = 16. Thus, 16 spanning trees can be formed from a complete graph with 4 vertices.
**/
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
const int maxn = 100005;
/* ------------------------------------------------------- */
int par[maxn] , siize[maxn];
int find_par(int x)
{
    if(x==par[x])
        return x;
    return par[x] = find_par(par[x]);
}
void uni(int x,int y)
{
    int px = find_par(x) , py = find_par(y);
    if(px!=py)
    {
        if(siize[px]>siize[py])
            swap(px,py);
        par[px] = py;
        siize[py] += siize[px];
        siize[px] = 0;
    }
}
 
int n,m;
struct edge
{
    int a,b,w;
};

bool comp(edge A,edge B)
{
    if(A.w < B.w)
        return 1;
    return 0;
}
edge ar[maxn];
void solve()
{
    int n,i,j,k,m;
    cin>>n>>m;
    repv(i,1,n)
        par[i] = i;
    rep(i,m)
    {
        int a,b,w;
        cin>>ar[i].a >>ar[i].b >>ar[i].w;
    }
    int sum=0;
    sort(ar,ar+m,comp);
    rep(i,m)
    {
        int pa = find_par(ar[i].a);
        int pb = find_par(ar[i].b);

        if(pa!=pb)
        {   
            sum += ar[i].w;
            uni(ar[i].a ,ar[i].b);
        }
    }
    cout<<sum<<endl;
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
    {
        solve();
    }
    
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}
