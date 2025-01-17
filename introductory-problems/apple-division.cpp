#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair <int, int>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(v) (int)v.size()
#define f first
#define s second
#define ld double
#define ent "\n"
#define S(x,y,z) ((x)*(x) + (y)*(y) + (z)*(z))
 
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
 
const long double eps = 1e-7;
 
ll n,a[30],ans=inf,sum1,sum2;
 
void rec(int num, int yes){
    if(!yes){
        sum1 += a[num];
    } else {
        sum2 += a[num];
    }
 
    if(num + 1 <= n){
        for(int i = 0; i < 2; ++i){
            rec(num + 1, i);
        }
    } else {
        ans = min(ans, abs(sum1 - sum2));
    }
 
 
    if(!yes){
        sum1 -= a[num];
    } else {
        sum2 -= a[num];
    }
}
 
signed main() {
    speed;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
 
    for(int i = 0; i < 2; ++i){
        rec(1, i);
    }
 
    cout << ans;
}