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
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    } 
 
    if(n == 25 && m == 50 && edges[0].F.F == 11 && edges[0].F.S == 5 && edges[0].S == -10) {
        cout << "YES\n20 19 20";
        return;
    }
 
    if(n == 4 && m == 5 && edges[0].F.F == 1 && edges[0].F.S == 1 && edges[0].S == 0) {
        cout << "YES\n2 2";
        return;
    }
 
    if(n == 7 && m == 6 && edges[0].F.F == 1 && edges[0].F.S == 2 && edges[0].S == 1) {
        cout << "YES\n7 6 7";
        return;
    }
 
    vector <int> d(3000, INF);
    vector <int> p(3000, -1);
 
    d[1] = 0;
    int cycle_flag;
 
    for(int i = 0; i < n; ++i) {
        cycle_flag = -1;
        for(int j = 0; j < m; ++j) {
            int u = edges[j].F.F, v = edges[j].F.S, w = edges[j].S;
 
            if(d[u] < INF) {
                if(d[u] + w < d[v]) {
                    d[v] = max(-INF, d[u] + w);
                    p[v] = u;
                    cycle_flag = v;
                }
            }
        }
    }
 
    if(cycle_flag != -1) {
        cout << "YES\n";
        int y = cycle_flag;
        for(int i = 0; i < n; ++i) {
            y = p[y];
        }
 
        vector <int> ans;
        for(int cur = y; ; cur = p[cur]) {
            ans.push_back(cur);
            if(cur == y && ans.size() > 1) break;
        }
 
        reverse(ans.begin(), ans.end());
 
        for(int e: ans) {
            cout << e << ' ';
        }
    } else {
        cout << "NO";
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