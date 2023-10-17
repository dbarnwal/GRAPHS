/* 
    AABRA KA DABRA.. !! 
*/

/**
Sort the Edges: First, sort all the edges of the graph in non-decreasing order of their weights. This can be done using any sorting algorithm, such as quicksort or mergesort.
Create an Empty Tree: Initially, the MST is an empty set of edges.
Iterate Over Edges: Begin iterating through the sorted edges, from the smallest to the largest weight. For each edge, do the following:
a. Check for a Cycle: If adding the current edge to the MST would create a cycle (i.e., if the two endpoints of the edge are already connected in the MST), skip this edge and move on to the next one. You can check for a cycle using techniques like disjoint-set data structures (e.g., Union-Find).
b. Add to MST: If the edge doesn't create a cycle, add it to the MST. This edge is now considered part of the MST.
Repeat: Continue this process until you have added V - 1 edges to the MST, where V is the number of vertices in the graph. This ensures that the resulting tree is indeed a spanning tree, connecting all vertices.
MST is Complete: At the end of the algorithm, you will have constructed a Minimum Spanning Tree that contains all the vertices of the original graph with the minimum possible total weight.

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
