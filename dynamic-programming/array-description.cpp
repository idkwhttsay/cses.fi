#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define s second
#define f first
#define pb push_back

using namespace std;

const int N = 1e6 + 123;
const int mod = 1e9 + 7;
const ll inf = 1e9;

ll n,m,x[N],dp[N][110],ans;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
    }

    if(x[1] == 0){
        for(int i = 1; i <= 101; ++i){
            dp[1][i] = 1;
        }
    } else {
        dp[1][x[1]] = 1;
    }

    for(int i = 2; i <= n; ++i){
        if(x[i] == 0){
            for(int j = 1; j <= m; ++j){
                dp[i][j] += dp[i - 1][j];
                if(j - 1 > 0){
                    dp[i][j] += dp[i - 1][j - 1];
                } if(j + 1 <= m){
                    dp[i][j] += dp[i - 1][j + 1];
                } dp[i][j] %= mod;
            }
        } else {
            dp[i][x[i]] += dp[i - 1][x[i]];
            if(x[i] - 1 > 0){
                dp[i][x[i]] += dp[i - 1][x[i] - 1];
            } if(x[i] + 1 <= m){
                dp[i][x[i]] += dp[i - 1][x[i] + 1];
            } dp[i][x[i]] %= mod;
        }
    }

    for(int j = 1; j <= m; ++j){
        ans += dp[n][j];
        ans %= mod;
    }

    cout << ans;
}