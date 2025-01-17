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

int n,dp[N];

int main() {
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    for(int i = 6; i <= n; ++i){
        for(int j = 1; j <= 6; ++j){
            dp[i] += dp[i - j];
            dp[i] %= mod;
        }
    }

    cout << dp[n];
}
