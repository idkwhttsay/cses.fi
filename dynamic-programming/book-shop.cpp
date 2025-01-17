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

int n,x,h[N],s[N],dp[N];

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> h[i];
    }

    for(int i = 1; i <= n; ++i){
        cin >> s[i];
    }

    for(int i = 0; i <= x; ++i){
        dp[i] = -inf;
    }

    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = x - h[i]; j >= 0; --j){
            dp[j + h[i]] = max(dp[j + h[i]], dp[j] + s[i]);
        }
    }

    int ans = -inf;
    for(int i = 0; i <= x; ++i){
        ans = max(ans, dp[i]);
    }

    cout << ans;
}