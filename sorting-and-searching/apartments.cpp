#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()
#define f first
#define s second
#define ld long double
#define ent "\n"
 
/*#pragma optimize ("g",on)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("03")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma comment(linker, "/stack:200000000")*/
 
using namespace std;
 
const int inf = 1e18 + 123;
const int N = 2e5 + 123;
const int mod = 1e9 + 7;
const double PI = 3.1415926536;
 
const double eps = 1e-20;
 
int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
 
int n,m,k,a[N],b[N],ans;
 
signed main() {
    speed;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    } sort(a + 1, a + n + 1);
 
    for(int j = 1; j <= m; ++j){
        cin >> b[j];
    } sort(b + 1, b + m + 1);
 
    int j = m, i = n;
    while(i > 0 && j > 0){
        if(a[i] + k >= b[j] && a[i] - k <= b[j]){
            ans ++;
            j --;
            i --;
        } else if(b[j] > a[i] + k) {
            j --;
        } else {
            i --;
        }
    }
 
    cout << ans;
}