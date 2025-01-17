#include <bits/stdc++.h>

#define int long long
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N = 1e6+123;
const int INF = 1e18;
const int mod = 1e9+7;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n,x;
int c[110], dp[N];

void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    for(int i = 0; i <= x; ++i){
        dp[i] = INF;
    }

    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= x-c[i]; ++j){
            if(dp[j] != INF){
                dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1);
            }
        }
    }

    if(dp[x] == INF){
        cout << -1;
    } else {
        cout << dp[x];
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