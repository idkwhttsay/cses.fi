#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
 
using namespace std;
 
const int N = 1e5+123;
const int inf = 1e9;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n,m;
char a[1010][1010];
int distM[1010][1010];
bool usedM[1010][1010];
 
bool used[1010][1010];
pair<int, int> p[1010][1010];
int dist[1010][1010];
 
int start_x, start_y;
 
queue <pair<int, int>> q;
 
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            distM[i][j] = inf;
 
            if(a[i][j] == 'M') {
                q.push({i, j});
                usedM[i][j] = true;
                distM[i][j] = 0;
            }
 
            if(a[i][j] == 'A') {
                start_x = i, start_y = j;
            }
        }
    }
 
    while(!q.empty()) {
        auto v = q.front();
        q.pop();
 
        for(int k = 0; k < 4; ++k) {
            int to_x = v.F + dx[k], to_y = v.S + dy[k];
 
            if(to_x < 1 || to_y < 1 || to_x > n || to_y > m || usedM[to_x][to_y] || a[to_x][to_y] == '#') continue;
 
            distM[to_x][to_y] = distM[v.F][v.S] + 1;
            usedM[to_x][to_y] = true;
            q.push({to_x, to_y});
        }
    }
 
    queue <pair<int, int>> q1;
    p[start_x][start_y] = {-1, -1};
    used[start_x][start_y] = true;
    q1.push({start_x, start_y});
 
    pair <int, int> ans = {-1, -1};
 
    while(!q1.empty()) {
        auto v = q1.front();
        q1.pop();
        if(v.F == 1 || v.F == n || v.S == 1 || v.S == m) {
            ans = {v.F, v.S};
            break;
        }
 
        for(int k = 0; k < 4; ++k) {
            int to_x = v.F + dx[k], to_y = v.S + dy[k];
 
            if(to_x < 1 || to_y < 1 || to_x > n || to_y > m || a[to_x][to_y] == '#' || used[to_x][to_y] || dist[v.F][v.S] + 1 >= distM[to_x][to_y]) continue;
 
            dist[to_x][to_y] = dist[v.F][v.S] + 1;
            used[to_x][to_y] = true;
            p[to_x][to_y] = {v.F, v.S};
            q1.push({to_x, to_y});
        }
    }
 
    if(ans.F == -1 && ans.S == -1) {
        cout << "NO";
        return;
    }
 
 
    vector <char> path;
    cout << "YES\n";
    cout << dist[ans.F][ans.S] << '\n';
    while(p[ans.F][ans.S].F != -1 && p[ans.F][ans.S].S != -1) {
        int DX = ans.F - p[ans.F][ans.S].F, DY = ans.S - p[ans.F][ans.S].S;
 
        if(DX == 1) {
            path.push_back('D');
        } else if (DX == -1) {
            path.push_back('U');
        } else if(DY == 1) {
            path.push_back('R');
        } else {
            path.push_back('L');
        }
 
        ans = p[ans.F][ans.S];
    }
 
    reverse(path.begin(), path.end());
    for(auto e: path) {
        cout << e;
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