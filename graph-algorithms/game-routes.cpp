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
vector <int> order;
bool used[N];
int dp[N];
 
void top_sort(int v) {
    used[v] = 1;
 
    for(int to: g[v]) {
        if(!used[to]) {
            top_sort(to);
        }
    }
 
    order.push_back(v);
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
 
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
            top_sort(i);
        }
    }
 
    dp[1] = 1;
    reverse(order.begin(), order.end());
 
    for(int v: order) {
        for(int prev: gr[v]) {
            dp[v] = (dp[v] + dp[prev]) % mod;
        }
    }
 
    cout << dp[n];
}
 
signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}