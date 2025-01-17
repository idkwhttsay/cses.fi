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

int a,b,dp[1000][1000];

int main() {
    speed;
    cin >> a >> b;
    for(int i = 0; i <= a; ++i){
        for(int j = 0; j <= b; ++j){
            if(i == j){
                dp[i][j] = 0;
            } else {
                dp[i][j] = inf;
                for(int k = 1; k < i; ++k){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }

                for(int k = 1; k < j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    cout << dp[a][b];
}