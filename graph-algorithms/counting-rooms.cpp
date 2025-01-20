#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll inf = 1e9;
const ll N = 1e6 + 3;
const ll mod = 1e9 + 7;

int n,m,ans;
char a[1010][1010];
bool used[1010][1010];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int i, int j){
    used[i][j] = true;
    for(int k = 0; k < 4; ++k){
        int x = i + dx[k], y = j + dy[k];
        if(x <= 0 || x > n || y <= 0 || y > m){
            continue;
        }
        if(!used[x][y] && a[x][y] == '.'){
            dfs(x, y);
        }
    }
}

int main() {
    speed;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == '.' && !used[i][j]){
                ans ++;
                dfs(i, j);
            }
        }
    }

    cout << ans;
}