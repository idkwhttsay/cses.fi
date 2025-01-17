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

ll n,c[N],dp[N],x;

int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    for(int i = 0; i <= x; ++i){
        dp[i] = 0;
    }

    dp[0] = 1;
    for(int j = 0; j <= x; ++j){
        for(int i = 1; i <= n; ++i){
            if(j - c[i] >= 0 && dp[j - c[i]] != inf){
                dp[j] += dp[j - c[i]];
                dp[j] %= mod;
            }
        }
    }

    cout << dp[x];
}