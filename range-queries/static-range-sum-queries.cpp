#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define s second
#define f first
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
 
const ll inf = 1e18 + 123;
const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;
 
const double eps = 1e-20;
 
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
 
ll n,q,a[N],p[N];
 
int main() {
    speed;
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
 
    while(q --){
        int l,r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << endl;
    }
}