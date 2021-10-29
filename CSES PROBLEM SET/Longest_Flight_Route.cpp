// DeNsE - EcLiPsE //
// WHAT is DEAD may NEVER die //
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstring>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <cstdlib>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
//using namespace __gnu_pbds;
//template <typename T>
//using ordered_set = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define double long double
#define endl "\n"
 
const int inf = (1ll << 62) - 1;
int mod = 1e9 + 7;
const int N = 1e5 + 10;
const double pi = 3.14159265358979323846;
 
int bPow(int a, int b){
    int res = 1;
    while(b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}
 
int gcd(int a, int b)
{
    if(a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
 
}
 
vector<int> fact(N, 0ll);
void factorial(){
    fact[0] = 1, fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
 
int ncr(int n, int r){
    if(r > n)
        return 0;
    int ans = fact[n] % mod;
    ans *= bPow(fact[r], mod - 2) % mod;
    ans %= mod;
    ans *= bPow(fact[n - r], mod - 2) % mod;
    ans %= mod;
    return ans;
}
 
vector<int> primes(N, -1);
void sieve(){
    iota(primes.begin(), primes.end(), 0);
    for (int i = 2; i < N; ++i) {
        if(primes[i] == i){
            for (int j = 2 * i; j < N; j += i) {
                if(primes[j] == j)
                    primes[j] = i;
            }
        }
    }
}
 
int add(int a, int b){
    return ((a + b) % mod + mod) % mod;
}
int mul(int a, int b){
    return ((a * b) % mod + mod) % mod;
}
 
int n, m;
vector<vector<int>> adj(N);
vector<int> dist(N, -1), p(N, -1), col(N, 0);
 
void dfs(int u){
    if(u == n){
        col[u] = 2, dist[u] = 0;
        return;
    }
    col[u] = 1;
    for(int v : adj[u]){
        if(!col[v])
            dfs(v);
        if(dist[v] == -1)
            continue;
        if(dist[v] + 1 > dist[u]){
            dist[u] = dist[v] + 1;
            p[u] = v;
        }
    }
    col[u] = 2;
}
 
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1);
    if(dist[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;
    int v = 1;
    while (v != n){
        path.push_back(v);
        v = p[v];
    }
    path.push_back(v);
    cout << path.size() << endl;
    for(int pa : path)
        cout << pa << " ";
    cout << endl;
}
 
signed main(){
    nitro
    int tc = 1, test = 1;
    //cin >> tc;
    while(tc--){
        //cout << "Case #" << test++ << ": ";
        solve();
    }
}