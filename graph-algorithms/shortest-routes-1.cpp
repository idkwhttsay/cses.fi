#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
 
using namespace std;
 
const int N = 1e5+123;
const int inf = 1e18;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n,m;
vector <pair<int, int>> g[N];
int dist[N];
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }
 
    for(int i = 1; i <= n; ++i) {
        dist[i] = inf;
    }
 
    set <pair<int, int>> q;
    q.insert({0, 1});
    dist[1] = 0;
 
    while(!q.empty()) {
        int v = q.begin()->S;
        q.erase(q.begin());
 
        for(auto [to, w]: g[v]) {
            if(dist[v] + w < dist[to]) {
                q.erase({dist[to], to});
                dist[to] = dist[v] + w;
                q.insert({dist[to], to});
            }
        }
    }
 
    for(int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
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