#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const ll inf = 1e9;
const ll N = 2e5 + 123;
const ll mod = 1e9 + 7;
 
ll n,dp[510][N];
 
int main() {
    speed;
    cin >> n;
    ll sum = ((n + 1) * n) / 2;
    if(sum % 2 == 1){
        cout << 0;
        return 0;
    }
    
    sum /= 2;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= sum; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0){
                (dp[i][j] += dp[i - 1][j - i]) %= mod; 
            }
        }
    }
    
    cout << dp[n - 1][sum];
}