#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()
 
/*#pragma optimize ("g",on)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")*/
 
using namespace std;
 
const ll inf = 1e18 + 123;
const int N = 1e6 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;
 
const double eps = 1e-20;
 
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
 
struct node {
    ll c[101][101];
};
 
node mat;
ll n,m,k;
bool used[101];
vector <int> g[101];
 
node mult(node a, node b){
    node res;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            res.c[i][j] = inf;
            for(int k = 1; k <= n; ++k){
                if(a.c[i][k] != inf && b.c[k][j] != inf){
                    res.c[i][j] = min(a.c[i][k] + b.c[k][j], res.c[i][j]);
                }
            }
        }
    }
 
 
    return res;
}
 
node binpow(node a, ll n){
    if(n == 1){
        return a;
    }
 
    if(n % 2 == 1){
        return mult(binpow(a, n - 1), a);
    } else {
        node b = binpow(a, n / 2);
        return mult(b, b);
    }
}
 
void dfs(int v){
    used[v] = 1;
    for(int to: g[v]){
        if(!used[to]){
            dfs(to);
        }
    }
}
 
int main() {
    speed;
    cin >> n >> m >> k;
    for(int i = 1; i <= 100; ++i){
        for(int j = 1; j <= 100; ++j){
            mat.c[i][j] = inf;
        }
    }
 
    for(int i = 0; i < m; ++i){
        int x,y;
        ll w;
        cin >> x >> y >> w;
        g[x].pb(y);
        mat.c[x][y] = min(w, mat.c[x][y]);
    }
 
    dfs(1);
 
    if(!used[n]){
        cout << -1;
        return 0;
    }
 
    node ans = binpow(mat, k);
    cout << ans.c[1][n];
}