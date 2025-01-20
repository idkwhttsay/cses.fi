#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
 
using namespace std;
 
const int N = 1e5+123;
const int inf = 1e18;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n,m,q;
int dist[510][510];
 
void solve() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = inf;
            }
        }
    }
 
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
 
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    while(q --) {
        int u,v;
        cin >> u >> v;
        if(dist[u][v] == inf) {
            cout << "-1\n";
        } else {
            cout << dist[u][v] << '\n';
        }
    }
}
 
signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}