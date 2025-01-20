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
vector <int> g[N];
bool is_cyclic;
int used[N];
bool used1[N];
vector <int> order;
 
void dfs(int v) {
    used[v] = 1;
    if(is_cyclic) return;
    for(int to: g[v]) {
        if(used[to] == 2) continue;
        if(used[to] == 1) {
            is_cyclic = true;
            return;
        } dfs(to);
    }
 
    used[v] = 2;
}
 
void top_sort(int v) {
    used1[v] = true;
 
    for(int to: g[v]) {
        if(used1[to]) continue;
        top_sort(to);
    }
 
    order.push_back(v);
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
            dfs(i);
        }
    } 
 
    if(is_cyclic) {
        cout << "IMPOSSIBLE";
        return;
    }
 
    for(int i = 1; i <= n; ++i) {
        if(!used1[i]) top_sort(i);
    } 
 
    reverse(order.begin(), order.end());
    for(int e: order) {
        cout << e << ' ';
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