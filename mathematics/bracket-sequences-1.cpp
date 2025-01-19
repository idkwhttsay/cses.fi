#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()

/*#pragma optimize ("g",on)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")*/

using namespace std;

const int inf = 1e9 + 123;
const int N = 1e6 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;

const double eps = 1e-20;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

ll f[2*N],f1[2*N];

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
        return f[n] * f1[k] % mod * f1[n - k] % mod;
    }
}


int main() {
    speed;
    f[0] = f[1] = 1;
    f1[0] = f1[1] = 1;
    for(ll i = 2; i <= 2 * N; ++i){
        f[i] = (f[i - 1] * i) % mod;
        f1[i] = binpow(f[i] % mod, mod - 2) % mod;
    }

    ll n;
    cin >> n;
    if(n % 2 == 1){
        cout << 0;
        return 0;
    }

    cout << (cnk(n, n / 2) - cnk(n, n / 2 - 1) + mod) % mod;
}