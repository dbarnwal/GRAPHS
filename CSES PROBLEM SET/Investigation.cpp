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
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/
 
using namespace std;
 
/*using namespace __gnu_pbds;
template <typename T>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>*/
 
#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define double long double
#define endl "\n"
 
const int inf = (1ll << 62) - 1;
int mod = 1e9 + 7;
const int N = 2e5 + 10;
const double pi = 3.14159265358979323846;
 
vector<int>   dx = {-1,   0,    1,   0, -1, -1, 1,  1};
vector<int>   dy = { 0,   1,   0,   -1, -1,  1, 1, -1};
vector<char> dir = {'U', 'R', 'D', 'L'};
 
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
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    vector<int> minFlights(n + 1, 0), maxFlights(n + 1, -1), dp(n + 1, 0);
    vector<int> dist(n + 1, inf);
    vector<bool> vis(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0, minFlights[1] = 0, maxFlights[1] = 0;
    dp[1] = 1;
    pq.push({0, 1});
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto [v, w] : adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                dp[v] = dp[u];
                minFlights[v] = minFlights[u] + 1, maxFlights[v] = maxFlights[u] + 1;
                pq.push({dist[v], v});
            }else if(dist[v] == dist[u] + w){
                dp[v] = add(dp[v], dp[u]);
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[n] << " " << dp[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
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
