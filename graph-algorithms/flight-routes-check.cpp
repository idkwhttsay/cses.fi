#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
#define pii pair<int, int>
 
using namespace std;
 
const int N = 1e5+123;
const int INF = 1e18;
const int mod = 1e9+7;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n,m;
vector <int> g[N], gr[N];
bool used[N];
vector <int> order;
vector <pii> edges;
int color[N];
int root[N];
int current = 0;
 
void dfs1(int v) {
    used[v] = 1;
    for(int to: g[v]) {
        if(used[to]) continue;
        dfs1(to);
    }
 
    order.push_back(v);
}
 
void dfs2(int v) {
    used[v] = true;
    color[v] = current;
 
    for(int to: gr[v]) {
        if(used[to]) continue;
        dfs2(to);
    }
}
 
void solve() {
    cin >> n >> m;
 
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
        edges.push_back({u, v});
    }
 
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
            dfs1(i);
        }
    }
 
    reverse(order.begin(), order.end());
    memset(used, false, sizeof(used));
    for(int v: order) {
        if(!used[v]) {
            root[current] = v;
            dfs2(v);
            current ++;
        }
    } 
 
    if(current == 1) {
        cout << "YES";
    } else {
        cout << "NO\n";
        for(auto [v, to]: edges) {
            if(color[v] != color[to]) {
                cout << to << ' ' << v;
                return;
            }
        }
 
        cout << root[current - 1] << ' ' << root[current - 2];
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