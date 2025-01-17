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

int n,dp[2001][2001];
char a[2001][2001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }

    dp[1][1] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i][j] == '.'){
                if(a[i - 1][j] == '.'){
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }

                if(a[i][j - 1] == '.'){
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][n] % mod;
}