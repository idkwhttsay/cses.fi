#include <bits/stdc++.h>
 
#define int long long
#define F first
#define S second
#define pii pair<int, int>
 
using namespace std;
 
const int N = 2e5+123;
const int INF = 1e18;
const int mod = 1e9+7;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n;
int pref[N];
int cnt[N];
 
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pref[i] = (pref[i-1] + (x % n) + n) % n;
    }
 
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(pref[i] == 0) {
            ans += cnt[0] + 1;
        } else {
            ans += cnt[pref[i]];
        }
 
        cnt[pref[i]] ++;
    }
 
    cout << ans;
}
 
signed main() {
    int tt = 1;
    // cin >> tt;
    while(tt --) {
        solve();
        cout << '\n';
    }
}