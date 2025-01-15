#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
 
const int N = 1e5+123;
 
int n,m;
vector <int> g[N];
int used[N];
vector <int> ans;
vector <int> cur;
 
void dfs(int v, int prev = -1) {
    // cout << v << '\n';
    used[v] = 1;
    cur.push_back(v);
 
    for(int to: g[v]) {
        if(prev == to || used[to] == 2) continue;
 
        if(used[to] == 1) {
            int ind = cur.size() - 1;
            while(true) {
                ans.push_back(cur[ind]);
                if(cur[ind] == to) break;
                ind --;
            }
 
            reverse(ans.begin(), ans.end());
            ans.push_back(to);
            cout << ans.size() << '\n';
            for(int i = 0; i < ans.size(); ++i) {
                cout << ans[i] << ' ';
            }
 
            exit(0);
        } 
 
        dfs(to, v);
    }
 
    cur.pop_back();
    used[v] = 2;
}
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
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