#include <bits/stdc++.h>
#define pb push_back
#define int long long
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
 
const int inf = 1e18 + 123;
const int N = 2e5 + 123;
const int mod = 998244353;
const double PI = 3.1415926536;
 
const long double eps = 1e-7;
 
int n,ans=1,p[N];
 
signed main() {
    speed;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        p[x] = i;
    }
 
    for(int i = 2; i <= n; ++i){
        if(p[i - 1] > p[i]){
            ans ++;
        }
    }
 
 
    cout << ans;
}