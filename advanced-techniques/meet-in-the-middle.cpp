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
 
int n,a[N],x,ans;
unordered_map <int, int> mp;
 
bool bit(int ind, int m){
    return (m & (1 << ind)) > 0;
}
 
signed main() {
    speed;
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    } sort(a, a + n);
 
    if(n == 1){
        cout << (x == a[0]);
        return 0;
    }
 
    mp.reserve(1<<(N/2-1));
    for(int m = 0; m < (1 << (n / 2 - 1)); ++m){
        int sum = 0;
        for(int i = 0; i < n / 2 - 1; ++i){
            if(bit(i, m)){
                sum += a[i];
            }
        }
 
        mp[sum] ++;
        //cout << sum << endl;
    }
 
    for(int m = 0; m < (1 << ((n + 1) / 2 + 1)); ++m){
        int sum = 0;
        for(int i = 0; i < (n + 1) / 2 + 1; ++i){
            if(bit(i, m)){
                sum += a[n / 2 - 1 + i];
            }
        }
 
        if(mp.find(x-sum) != mp.end()){
            ans += mp[x-sum];
        }
    }
 
    cout << ans;
}