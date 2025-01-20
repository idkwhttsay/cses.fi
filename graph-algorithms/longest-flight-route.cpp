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
bool used[N];
int dp[N];
int child[N];
 
void mark_dfs(int v){
    used[v] = 1;
    for(int to: g[v]){
        if(!used[to]){
            mark_dfs(to);
        }
    }
}
 
 
int dfs(int v){
    if(v == n) return dp[n] = 1;
    if(dp[v] != -1) return dp[v];
 
    int len = 0;
    for(auto to: g[v]){
        int tmp = dfs(to);
        int temp_len = tmp == 0 ? 0 : tmp + 1;
 
        if(temp_len > len){
            child[v] = to;
            len = temp_len;
        }
    }
 
    return dp[v] = len;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 
    mark_dfs(1);
 
    if(!used[n]) {
        cout << "IMPOSSIBLE";
        return;
    }
 
    for(int i = 1; i <= n; ++i) {
        dp[i] = -1;
    }
 
    int len = dfs(1);
 
    vector <int> path;
    int node = 1;
    while(node) {
        path.push_back(node);
        node = child[node];
    }
 
    cout << len << '\n';
    for(int e: path) {
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