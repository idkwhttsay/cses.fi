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
int used[N];
vector <int> cur;
 
void dfs(int v) {
    used[v] = 1;
    cur.push_back(v);
 
    for(int to: g[v]) {
        if(used[to] == 2) continue;
        
        if(used[to] == 1) {
            vector <int> ans;
            int ind = cur.size() - 1;
            ans.push_back(to);
            while(true) {
                ans.push_back(cur[ind]);
                if(cur[ind] == to) break;
                ind --;
            }
 
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for(int e: ans) {
                cout << e << ' ';
            }
 
            exit(0);
        }
 
        dfs(to);
    }
 
    used[v] = 2;
    cur.pop_back();
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
 
    cout << "IMPOSSIBLE";
}
 
signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}