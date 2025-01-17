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
    for(int i = 0; i <= n; ++i){
        dp[i] = inf;
    }

    dp[n] = 0;
    for(int i = n; i > 0; --i){
        if(dp[i] == inf){
            continue;
        }
        int res = i;
        while(res > 0){
            dp[i - res % 10] = min(dp[i - res % 10], dp[i] + 1);
            res /= 10;
        }
    }

    cout << dp[0];
}