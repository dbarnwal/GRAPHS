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
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; */
 
using namespace std;
 
 
#define oset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define double long double
//#define endl "\n"
 
const int inf = (1ll << 62) - 1;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const double pi = 3.14159265358979323846;
const double eps = 1e-8;
 
int     dx []    =  {-1 , 0 , 1 , 0 ,-1,-1, 1,  1};
int     dy []    =  { 0 , 1 , 0 ,-1 ,-1, 1, 1, -1};
char    dir[]    =  {'U','R','D','L'};
 
 
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
 
int gcd(int a, int b){
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
 
int npr(int n, int r){
    if(r > n)
        return 0;
    int ans = fact[n] % mod;
    ans *= bPow(fact[n - r], mod - 2) % mod;
    ans %= mod;
    return ans;
}
 
vector<int> primes(N, -1);
void sieve(){
    iota(primes.begin(), primes.end(), 0);
    for (int i = 2; i < N; ++i) {
        if(primes[i] == i){
            for (int j = i; j < N; j += i) {
                if(primes[j] == j) {
                    primes[j] = i;
                }
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
 
/*
const int M = 1e5 + 5;
vector<pair<int, int> > segTree(4 * M, make_pair(inf, -1));
vector<int> a;
void build(int i, int tl, int tr){
    if(tl == tr){
        segTree[i] = {a[tl], tl};
        return;
    }
    int tm = (tl + tr) / 2;
    build(i * 2, tl, tm);
    build(i * 2 + 1, tm + 1, tr);
    auto left = segTree[i * 2], right = segTree[i * 2 + 1];
    if(left.first <= right.first){
        segTree[i] = left;
    }else{
        segTree[i] = right;
    }
}
void update(int i, int tl, int tr, int l, int r){
    if(l > r)
        return;
    if(l == tl and r == tr){
        segTree[i].first++;
        return;
    }
    int tm = (tl + tr) / 2;
    update(i * 2, tl, tm, l, min(tm, r));
    update(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    auto left = segTree[i * 2], right = segTree[i * 2 + 1];
    if(left.first <= right.first){
        segTree[i] = left;
    }else{
        segTree[i] = right;
    }
}
 
pair<int, int> query(int i, int tl, int tr, int l, int r){
    if(l > tr or r < tl)
        return {inf,-1};
    if(tl >= l and tr <= r){
        return segTree[i];
    }
    int tm = (tl + tr) / 2;
    auto left = query(i * 2, tl, tm, l, r);
    auto right = query(i * 2 + 1, tm + 1, tr, l, r);
    if(left.first <= right.first){
        return left;
    }else{
        return right;
    }
}*/
 
int n, m;
vector<int> par(N), cmpSize(N, 1);
 
int findPar(int u){
    if(par[u] == u){
        return u;
    }
    return par[u] = findPar(par[u]);
}
 
void solve(){
    iota(par.begin(), par.end(), 0);
    cin >> n >> m;
    int cmp = n, maxSize = 1;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        int pu = findPar(u), pv = findPar(v);
        if(pu != pv){
            cmp--;
            if(cmpSize[pu] < cmpSize[pv]){
                swap(pu, pv);
            }
            par[pv] = pu;
            cmpSize[pu] += cmpSize[pv];
            maxSize = max(maxSize, cmpSize[pu]);
        }
        cout << cmp << " " << maxSize << endl;
    }
}
 
signed main(){
    //#ifndef ONLINE_JUDGE
    //freopen("little.in", "r", stdin);
    //freopen("little.out", "wb", stdout);
    //#endif*
    nitro;
    int tc = 1, test = 1;
    //cin >> tc;
    while(tc--){
        //cout << "Case #" << test++ << ": ";
        solve();
    }
}