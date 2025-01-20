#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#pragma optimize ("g",on)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

using namespace std;

const int inf = 1e9 + 123;
const int N = 1e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;

const double eps = 1e-20;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

string s;
ll dp[510][510],p[510][510],f[1200],f1[1200],n;

ll binpow (ll a, ll n) {
    if(n == 0) {
        return 1;
    }

    if (n % 2 == 1){
        return (binpow (a, n-1) * a) % mod;
    } else {
        ll b = binpow (a, n / 2) % mod;
        return (b * b) % mod;
    }
}

ll cnk(ll n, ll k){
    if(k < 0 || n < k){
        return 0;
    } else {
        return (f[n] * f1[k] % mod * f1[n - k] % mod) % mod;
    }
}

ll solve(ll l, ll r){
    if((r - l + 1) % 2 == 1) return 0;
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];

    ll cnt = 0;
    for(int m = l + 1; m <= r; ++m){
        if(s[l] == s[m]){
            ll res = (solve(l + 1, m - 1) * solve(m + 1, r)) % mod;
            ll comb = (res * cnk((r - l + 1) / 2, (m - l + 1) / 2)) % mod;
            cnt = (cnt + comb) % mod;
        }
    }

    return dp[l][r] = cnt;
}

int main() {
    speed;
    f[0] = f[1] = 1;
    f1[0] = f1[1] = 1;
    for(ll i = 2; i <= 1000; ++i){
        f[i] = (f[i - 1] * i) % mod;
        f1[i] = binpow(f[i], mod - 2);
    }

    cin >> s;
    n = s.size();
    for(int i = 0; i <= 500; ++i){
        for(int j = 0; j <= 500; ++j){
            dp[i][j] = -1;
        }
    }

    cout << solve(0, n - 1);
}