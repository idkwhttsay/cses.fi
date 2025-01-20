#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
#define pii pair<int, int>
 
using namespace std;
 
const int N = 1e5+123;
const int inf = 1e18;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n,m;
vector <pii> g[N];
int d[N][2];
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }
 
    for(int i = 1; i <= n; ++i) {
        d[i][0] = inf;
        d[i][1] = inf;
    }
 
    set <pii> q;
    d[1][0] = 0;
    q.insert({d[1][0], 1});
    while(!q.empty()) {
        int v = q.begin()->S;
        // cout << v << '\n';
        q.erase(q.begin());
 
        for(auto [to, w]: g[v]) {
            if(d[v][0] + w < d[to][0]) {
                q.erase({d[to][0], to});
                d[to][0] = d[v][0] + w;
                q.insert({d[to][0], to});
            }
 
            if(d[v][0] + w/2 < d[to][1]) {
                q.erase({d[to][1], to});
                d[to][1] = d[v][0] + w/2;
                q.insert({d[to][1], to});
            }
 
            if(d[v][1] + w < d[to][1]) {
                q.erase({d[to][1], to});
                d[to][1] = d[v][1] + w;
                q.insert({d[to][1], to});
            }
        }
    }
 
    cout << min(d[n][0], d[n][1]);
}
 
signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}