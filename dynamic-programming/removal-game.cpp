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

ll n,x[5010],dp[5010][5010],p[5010];

ll s(int l, int r){
    return p[r] - p[l - 1];
}

int main() {
    speed;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
        p[i] = p[i - 1] + x[i];
    }

    for(int i = 1; i <= n; ++i){
        dp[i][i] = x[i];
    }

    for(int l = 2; l <= n; ++l){
        for(int i = 1, j = l; j <= n; ++i, ++j){
            dp[i][j] = s(i, j) - min(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[1][n];
}