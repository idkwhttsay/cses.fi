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

int t;
int dp[N][2];

void solve() {
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= 1e6; ++i) {
        dp[i][0] = (dp[i-1][0] * 4ll % mod + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2ll % mod) % mod;
    }

    cin >> t;
    while(t --) {
        int x;
        cin >> x;
        cout << (dp[x][0] + dp[x][1]) % mod << '\n';
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