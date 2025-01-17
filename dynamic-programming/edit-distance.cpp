#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;

const ll inf = 1e9;
const ll N = 5100;
const ll mod = 1e9 + 7;

int n,m,dp[N][N];
char a[N], b[N];

int main() {
    speed;
    string s,t;
    cin >> s >> t;
    n = s.size();
    for(int i = 1; i <= n; ++i){
        a[i] = s[i - 1];
    }
    m = t.size();
    for(int j = 1; j <= m; ++j){
        b[j] = t[j - 1];
    }

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            dp[i][j] = inf;
        }
    }

    dp[0][0] = 0;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            if(a[i + 1] == b[j + 1]){
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            } else {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }

    cout << dp[n][m];
}