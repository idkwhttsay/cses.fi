#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
#define pii pair<int, int>
 
using namespace std;
 
const int N = 1e5+123;
const int INF = 1e18;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n,m;
vector <pair<pii, int>> edges;
 
vector <int> gr[3000];
set <int> vertex;
bool used[3000];
 
void dfs(int v) {
    used[v] = true;
    vertex.insert(v);
 
    for(int to: gr[v]) {
        if(used[to]) continue;
        dfs(to);
    }
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
        gr[v].push_back(u);
    }
 
    dfs(n);
 
    vector <int> d(3000, -INF);
    d[1] = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j < m; ++j) {
            int u = edges[j].F.F, v = edges[j].F.S, w = edges[j].S;
 
            if(d[u] > -INF) {
                if(d[u] + w > d[v]) {
                    d[v] = min(INF, d[u] + w);
                    if(i == n && vertex.find(v) != vertex.end()) {
                        cout << -1;
                        return;
                    }
                }
            }
        }
    }
 
    cout << d[n];
}
 
signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}