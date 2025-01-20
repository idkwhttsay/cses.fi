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
vector <pair<int, pii>> edges;
int p[N];
int sz[N];
 
int root(int v) {
    if(v == p[v]) return v;
    return p[v] = root(p[v]);
}
 
void join(int a, int b) {
    a = root(a), b = root(b);
 
    if(sz[a] < sz[b]) {
        swap(a, b);
    }
 
    sz[a] += sz[b];
    p[b] = a;
}
 
void solve() {
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
 
    for(int i = 1; i <= n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
 
    sort(edges.begin(), edges.end());
 
    int ans = 0;
    for(auto e: edges) {
        int w = e.F, u = e.S.F, v = e.S.S;
 
        u = root(u), v = root(v);
        if(u != v) {
            ans += w;
            join(u, v);
        }
    }
 
    if(sz[root(1)] != n) {
        cout << "IMPOSSIBLE";
    } else {
        cout << ans;
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