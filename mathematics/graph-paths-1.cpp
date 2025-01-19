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
 
const int inf = 1e9 + 123;
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
 
node mult(node a, node b){
    node res;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            res.c[i][j] = 0;
            for(int k = 1; k <= n; ++k){
                res.c[i][j] += a.c[i][k] * b.c[k][j];
                res.c[i][j] %= mod;
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
 
int main() {
    speed;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        int x,y;
        cin >> x >> y;
        mat.c[x][y] ++;
    }
 
    node ans = binpow(mat, k);
    cout << ans.c[1][n];
}