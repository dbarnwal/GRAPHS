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
 
using namespace std;
 
#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define double long double
#define endl " \n"
 
const int inf = (1ll << 62) - 1;
int mod = 1e9 + 7;
const int N = 1e3 + 4;
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
vector<string> grid(N);
int monster[N][N], hero[N][N];
vector<int> par(N, -1);
vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, - 1};
 
bool atBoundary(int x, int y){
    return x == 0 or y == 0 or x == n - 1 or y == m - 1;
}
bool inRange(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}
 
void bfs(queue<pair<int, pair<int, int>>> q){
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int x = it.second.first, y = it.second.second, d = it.first;
        monster[x][y] = d;
        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if(inRange(xx, yy) and monster[xx][yy] > d + 1 and grid[xx][yy] != '#' and grid[xx][yy] != 'M'){
                monster[xx][yy] = d + 1;
                q.push({d + 1, {xx, yy}});
            }
        }
    }
}
 
string backTracking(int xx, int yy, int x, int y, int d){
    int cur = d - 1;
    string path;
    while (xx != x or yy != y){
        if(xx > 0 and hero[xx - 1][yy] == cur){
            xx--;
            path += "D";
        }else if(xx < n - 1 and hero[xx + 1][yy] == cur){
            xx++;
            path += "U";
        }else if(yy > 0 and hero[xx][yy - 1] == cur){
            yy--;
            path += "R";
        }else{
            yy++;
            path += "L";
        }
        cur--;
    }
    reverse(path.begin(), path.end());
    return path;
}
 
bool bfs2(int x, int y){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {x, y}});
    hero[x][y] = 0;
    if(atBoundary(x, y)){
        cout << "YES" << endl << 0 << endl;
        return true;
    }
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        int cx = it.second.first, cy = it.second.second;
        int d = it.first;
        for (int i = 0; i < 4; ++i) {
            int xx = cx + dx[i], yy = cy + dy[i];
            if(!inRange(xx, yy) or grid[xx][yy] == '#' or grid[xx][yy] == 'M')
                continue;
            if(hero[xx][yy] < d + 1 or monster[xx][yy] <= d + 1)
                continue;
            hero[xx][yy] = d + 1;
            q.push({d + 1, {xx, yy}});
            if(atBoundary(xx, yy)){
                cout << "YES" << endl << d + 1 << endl << backTracking(xx, yy, x, y, d + 1) << endl;
                return true;
            }
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            hero[i][j] = inf, monster[i][j] = inf;
        }
    }
    int x = -1, y = -1;
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == 'M'){
                q.push({0, {i, j}});
            }
            if(grid[i][j] == 'A'){
                x = i, y = j;
            }
        }
    }
    bfs(q);
    if(!bfs2(x, y))
        cout << "NO" << endl;
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