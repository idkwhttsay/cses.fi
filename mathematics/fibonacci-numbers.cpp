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
 
struct node {
    ll a11,a12,a21,a22;
};
 
node m;
 
node mult(node a, node b){
    node res;
    res.a11 = (a.a11 * b.a11 + a.a12 * b.a21) % mod;
    res.a12 = (a.a11 * b.a12 + a.a12 * b.a22) % mod;
    res.a21 = (a.a21 * b.a11 + a.a22 * b.a21) % mod;
    res.a22 = (a.a21 * b.a12 + a.a22 * b.a22) % mod;
    return res;
}
 
node binpow(node a, ll n){
    if(n == 1){
        node res;
        res.a11 = 0, res.a12 = 1, res.a21 = 1, res.a22 = 1;
        return res;
    }
 
    if(n % 2 == 1){
        return mult(binpow(a, n - 1), a);
    } else {
        node b = binpow(a, n / 2);
        return mult(b, b);
    }
}
 
int main() {
    speed;
    m.a11 = 0, m.a12 = 1, m.a21 = 1, m.a22 = 1;
    ll n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    node p = binpow(m, n);
    cout << p.a12;
}